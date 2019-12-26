#pragma once

#include <vector>
#include <queue>
#include <functional>

#include "Message.hpp"

class MessageBus
{
public: 
    MessageBus();
    ~MessageBus();
    void addReceiver(std::function<void (Message)> messageReceiver);
    void sendMessage(Message _message);
    void notify();

private:
    std::vector<std::function<void (Message)>> receivers;
    std::queue<Message> messages;
};