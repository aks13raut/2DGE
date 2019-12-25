#include "StateMachine.hpp"

#include "../Game.hpp"
#include "SplashState.hpp"

StateMachine::StateMachine(Game& game){
     pushState<SplashState>(game);
}

void StateMachine::pushState(std::unique_ptr<State> state)
{
    m_states.push(std::move(state));
}

//Flags a boolean for the game to pop state
void StateMachine::popState(){
    m_shouldPop = true;
}

void StateMachine::clear(){
    while(!m_states.empty()){
        m_states.pop();
    }
}

bool StateMachine::isEmpty(){
    return m_states.empty();
}

//Tries to pop the current game state
void StateMachine::tryPop(){
    if (m_shouldPop) {
        m_shouldPop = false;
        if (m_shouldExit) {
            clear();
            return;
        }
        else if (m_shouldChageState) {
            m_shouldChageState = false;
            m_states.pop();
            pushState(std::move(m_newState));
            return;
        }
        
        m_states.pop();
    }
}

//Returns a reference to the current game state
State& StateMachine::getCurrentState(){
    return *m_states.top();
}

void StateMachine::update(sf::Time deltaTime){
    auto& state = getCurrentState();
    state.handleInput();
    state.update(deltaTime);
}

void StateMachine::fixedUpdate(sf::Time deltaTime){
    auto& state = getCurrentState();
    state.fixedUpdate(deltaTime);
}

void StateMachine::render(sf::RenderTarget& renderer){
    auto& state = getCurrentState();
    state.render(renderer);
}

void StateMachine::handleEvent(sf::Event e)
{
    getCurrentState().handleEvent(e);
}