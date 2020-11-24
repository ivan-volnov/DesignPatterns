#include <catch2/catch.hpp>


class Context;



class State
{
    friend class Context;

public:
    virtual ~State() = default;
    virtual std::string handle() = 0;

protected:
    Context *m_context = nullptr;
};



class Context
{
public:
    Context(std::unique_ptr<State> &&state)
    {
        switch_to(std::move(state));
    }

    void switch_to(std::unique_ptr<State> &&state)
    {
        if ((m_state = std::move(state))) {
            m_state->m_context = this;
        }
    }

    std::string handle_request()
    {
        return m_state ? m_state->handle() : "do nothing";
    }

private:
    std::unique_ptr<State> m_state;
};



class StateB : public State
{
public:
    std::string handle() override;
};



class StateA : public State
{
public:
    std::string handle() override;
};



std::string StateA::handle()
{
    m_context->switch_to(std::make_unique<StateB>());
    return "StateA::handle()";
}



std::string StateB::handle()
{
    m_context->switch_to(std::make_unique<StateA>());
    return "StateB::handle()";
}



TEST_CASE("Behavioral/State")
{
    auto context = std::make_unique<Context>(std::make_unique<StateA>());

    REQUIRE(context->handle_request() == "StateA::handle()");
    REQUIRE(context->handle_request() == "StateB::handle()");
    REQUIRE(context->handle_request() == "StateA::handle()");
}
