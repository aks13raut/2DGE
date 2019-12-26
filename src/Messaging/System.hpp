#pragma once

#include "MessageBus.hpp"

class System {
    protected:
    MessageBus *messageBus;
    public:
    System(MessageBus *_messageBus);
    ~System();
    void send(Message message);
    virtual void update();
    std::function<void (Message)> getNotifyFunc();
    virtual void handleMessage(Message msg);
};