#pragma once

#include <memory>
#include <stack>

#include "State.hpp"
#include "../Util/NonCopyable.hpp"
#include "../Util/NonMoveable.hpp"

class StateMachine : public NonCopyable, public NonMovable {
public:
    StateMachine(Game& game);
    ~StateMachine() {}
    template<typename T, typename... Args>
        void pushState(Args&&... args);
    template<typename T, typename... Args>
        void changeState(Args&&... args);
    void pushState(std::unique_ptr<State> state);
    void popState();
    void clear();
    bool isEmpty();
    State& getCurrentState();
    void tryPop();

    void update(sf::Time deltaTime);
    void fixedUpdate(sf::Time deltaTime);
    void render(sf::RenderTarget& renderer);
    void handleEvent(sf::Event e);
    
private:

    std::stack<std::unique_ptr<State>> m_states;
    std::unique_ptr<State> m_newState;

    Game* m_pGame;

    bool m_shouldPop = false;
    bool m_shouldExit = false;
    bool m_shouldChageState = false;
};

template<typename T, typename... Args>
inline void StateMachine::pushState(Args&&... args)
{
    pushState(std::make_unique<T>(std::forward<Args>(args)...));
}

template<typename T, typename ...Args>
inline void StateMachine::changeState(Args && ...args)
{
    m_newState = std::make_unique<T>(std::forward<Args>(args)...);
    m_shouldPop = true;
    m_shouldChageState = true;
}
