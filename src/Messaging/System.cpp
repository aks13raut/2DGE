#include "System.hpp"
#include "spdlog/spdlog.h"

MessageBus::MessageBus(){}
MessageBus::~MessageBus(){}
void MessageBus::addReceiver(std::function<void (Message)> messageReceiver){
    receivers.push_back(messageReceiver);
}
void MessageBus::sendMessage(Message _message){
    messages.push(_message);
}
void MessageBus::notify(){
    while(!messages.empty()){
        for (auto iter = receivers.begin(); iter != receivers.end(); iter++) {
            (*iter)(messages.front());
        }
        messages.pop();
    }
}

System::System(MessageBus *_messageBus){
    messageBus = _messageBus;
    this->messageBus->addReceiver(this->getNotifyFunc());
};
System::~System(){};
void System::send(Message message){
    messageBus->sendMessage(message);
}
void System::update() {};
std::function<void (Message)> System::getNotifyFunc(){
    auto messageListener = [=](Message message) -> void {
        this->handleMessage(message);
    };
    return messageListener;
}
void System::handleMessage(Message msg){
    spdlog::info("Handling message: ID={} TYPE={}",msg.getMessageType(),msg.getMessageId());
}