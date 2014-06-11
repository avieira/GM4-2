/*!
  * \class MessageHandler
  * \brief Implémentation de la classe abstraite organissant des messages d'erreur
  * \author Alexandre Vieira
  * \version 1.0
  * \date avril 2014
  *
  * Classe servant à récupérer des informations venant de différents messages d'erreur et à les traiter.
  */

#ifndef MESSAGEHANDLER_H
#define MESSAGEHANDLER_H

#include <QString>
#include<QAbstractMessageHandler>


class MessageHandler : public QAbstractMessageHandler
{
public:
/**
 * \fn MessageHandler()
 * \brief Constructeur d'une instance de classe
 */
    MessageHandler();
/**
 * \fn QString statusMessage() const
 * \brief Mets le message d'erreur récupéré sous une forme plus compréhensible par un humain.
 */
    QString statusMessage() const;
protected:
    virtual void handleMessage(QtMsgType type, const QString &description,
                               const QUrl &identifier, const QSourceLocation &sourceLocation);
private:
    QtMsgType m_messageType;
    QString m_description;
    QSourceLocation m_sourceLocation;
};

#endif // MESSAGEHANDLER_H
