#pragma once
#include "StateMachine.hpp"

#include "PlayingState.hpp"
#include "MenuState.hpp"
#include "SplashState.hpp"
#include "PCGState.hpp"

class StateHandler
{
    public:
        static StateHandler& get(){
            static StateHandler sh;
            return sh;
        }
        void setStateMachinePtr(StateMachine *sm_ptr){
            sm = sm_ptr;
        }
        void setGamePtr(Game* game_ptr){
            m_game = game_ptr;
        }
        template<typename T, typename... Args>
            void pushState(Args&&... args);
        void popState(){
            sm->popState();
        }
        Game& game(){
            return *m_game;
        }
    private:
        StateMachine* sm;
        Game* m_game;
};

template<typename T, typename... Args>
inline void StateHandler::pushState(Args&&... args)
{
    sm->pushState<T>(std::forward<Args>(args)...);
}

static StateHandler& stateHandler = StateHandler::get();