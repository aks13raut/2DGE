#pragma once

enum MessageType {
    MSG_TEST,
    MSG_UNDEFINED
};

class Message {
public:
    Message(MessageType type);
    MessageType     getMessageType();
    unsigned int    getMessageId();
private:
    MessageType     m_type;
    unsigned int    m_id;

    static unsigned int ID;
};