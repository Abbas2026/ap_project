#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include "form.h"

class Client : public QObject
{
    Q_OBJECT

public:

    explicit Client(QObject *parent = nullptr);
    void connectToServer(const QString &host, quint16 port);
    void onConnected();
    void sendForgotPasswordRequest(const QString &email, const QString &username);
    void sendWallet(const QStringList &words, const QString &name  , const QString &address);
    void sendRecoveryRequest();
    void walletsdata(const QString &address);
    void Walletassets(const QString &email,const QString &namewallet);
    void processResponse(const QByteArray& message);
    void processSimpleResponse(const QString& responseStr);
    void senduserprofiletoserver(const QString &name,const QString &address,const QString &phone,const QString &firstname,const QString &lastname,const QString &password,const QString &user_level);
    void getuserprofile();
    void depositcheckserver(const QString &coin,const QString &address,const QString &amounth);
    void transferCurrency(const QString &fromAddress, const QString &toEmail, const QString &toWalletName, const QMap<QString, double> &transferCurrencies);
    void withdrawalcheckserver(const QString &coin, const QString &amounth,const QString &address, const QList<QString>& selectedWords);
    void getsupplyfromserver(QString &address);
    void buycoin(const QString &coin, const QString &amounth, const QString &address);
    void sellcoin(const QString &coin, const QString &amounth, const QString &address);
    void exchangeCoins(const QString &coin1, const QString &coin2, const QString &amount1, const QString &amount2, const QString &address);

    static int bb;
    static int x;
    static int warname;
    static int number_wallets;
    static int Activated;
    static QString user_level;
    static QString globalEmail ;
    static QString password_creator;
    static QString walletactive;

signals:

    void sendinventorytowalletdetails(const QString &coinname,const double &coinamount,const double &Currentvalue);
    void receivedMessage(const QString &message);
    void receivedMessagetodash(const QString &message);
    void receivedMessagetosign(const QString &message);
    void registrationSuccessful();
    void loginSuccessful();
    void triggerSigninSlot();
    void sendWalletToMywallet(const QString &name, const QString &address, double balance);
    void sendusertoprofile(const QString email,const QString name,const QString password,const QString phone,const QString address,const QString firstname,const QString lastname);
     void sendsupplytootherfile(const QMap<QString, double>& walletCurrencies);

public slots:

    void sendMessage(const QString &message);
    void sendCredentials(const QString &email, const QString &password, const QString &name, const QString &phone);
    void requestUserData(const QString &email);
    void sendservertologin(const QString &email, const QString &password);

private slots:

    void readServerResponse();

private:

    QTcpSocket *socket;
};

#endif
