#pragma once

#include "MessageBus.hpp"

class Messager {
    protected:
    MessageBus *messageBus;

    public:
    Messager(MessageBus *messageBus);
    ~Messager();
    
    std::function<void (Message)> getNotifyFunc();
    virtual void send(Message msg);
    virtual void handleMessage(Message msg);

};