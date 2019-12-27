#pragma once

enum MessageType {
    MSG_TEST
,   MSG_SPLASH_STATE_FINISHED
,   MSG_MENU_STATE_FINISHED
,   MSG_UNDEFINED
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