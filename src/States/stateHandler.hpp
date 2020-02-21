#pragma once
#include "StateMachine.hpp"

#include "PlayingState.hpp"
#include "MenuState.hpp"
#include "SplashState.hpp"

enum StateName {
    SPLASH,
    MENU,
    PLAYING
};

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
            g = game_ptr;
        }
        void pushState(enum StateName stateName){
            switch (stateName)
            {
            case SPLASH:
                sm->pushState<SplashState>(*g);
                break;
            case MENU:
                sm->pushState<MenuState>(*g);
                break;
            case PLAYING:
                sm->pushState<PlayingState>(*g);
                break;
    
            default:
                break;
            }
        }
    private:
        StateMachine* sm;
        Game* g;
};

static StateHandler& stateHandler = StateHandler::get();