#include "messagehandler.h"
#include<sstream>

MessageHandler::MessageHandler():QAbstractMessageHandler(0){}

QString MessageHandler::statusMessage() const
{
    QString message(m_description);
    message.chop(18);
    message.remove(0,53);

    //Convertion int->string
    std::string s;
    std::stringstream out;
    out << m_sourceLocation.line();
    s = out.str();

    message+=QObject::tr(" Line ")+QString(s.c_str());
    return message;
}

void MessageHandler::handleMessage(QtMsgType type, const QString &description,
                           const QUrl &identifier, const QSourceLocation &sourceLocation)
{
    Q_UNUSED(type);
    Q_UNUSED(identifier);

    m_messageType = type;
    m_description = description;
    m_sourceLocation = sourceLocation;
}
