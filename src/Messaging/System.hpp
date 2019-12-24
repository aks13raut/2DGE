#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include <functional>

#include "Message.hpp"

class MessageBus {
    std::vector<std::function<void (Message)>> receivers;
    std::queue<Message> messages;
    public:
    MessageBus();
    ~MessageBus();
    void addReceiver(std::function<void (Message)> messageReceiver);
    void sendMessage(Message _message);
    void notify();
};

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