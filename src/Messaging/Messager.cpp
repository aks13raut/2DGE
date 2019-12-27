#include "Messager.hpp"
#include "spdlog/spdlog.h"

Messager::Messager(MessageBus *_messageBus)
{
    messageBus = _messageBus;
    //this->messageBus->addReceiver(this->getNotifyFunc());
};

Messager::~Messager(){};

std::function<void (Message)> Messager::getNotifyFunc(){
    auto messageListener = [=](Message message) -> void {
        this->handleMessage(message);
    };
    spdlog::warn("hi");
    return messageListener;
}

void Messager::send(Message message){
    messageBus->sendMessage(message);
}

void Messager::handleMessage(Message msg){
    spdlog::info("{} Handling message: ID={} TYPE={}",typeid(*this).name(),msg.getMessageType(),msg.getMessageId());
}