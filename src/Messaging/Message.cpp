#include "Message.hpp"

#define MAX_NO_OF_MSG 500000000

unsigned int Message::ID = 0;

Message::Message(MessageType type)
:   m_type(type)
,   m_id(ID++){
    if(ID == MAX_NO_OF_MSG){

    }
}

MessageType Message::getMessageType(){
    return m_type;
}

unsigned int Message::getMessageId(){
    return m_id;
}