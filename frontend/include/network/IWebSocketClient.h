/**
 * CLASSIFICATION: UNCLASSIFIED
 * EXPORT CONTROL: NOT SUBJECT TO EAR/ITAR
 * CONTRACT: SIREN-2025
 *
 * @file IWebSocketClient.h
 * @brief WebSocket client interface for dependency injection and testability
 * @author KostasAndroulidakis
 * @date 2025
 *
 * MISRA C++ 2008 Compliant
 * DO-178C Level A Certifiable
 */

#ifndef SIREN_NETWORK_IWEBSOCKET_CLIENT_H
#define SIREN_NETWORK_IWEBSOCKET_CLIENT_H

#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtCore/QUrl>

namespace siren {
namespace Network {

/**
 * @brief WebSocket client interface
 *
 * MISRA C++ 2008: 10-3-1 - Virtual functions defined
 * MISRA C++ 2008: 10-3-2 - Virtual destructor provided
 */
class IWebSocketClient : public QObject {
    Q_OBJECT

public:
    /**
     * @brief Explicit constructor
     * @param parent Parent QObject (Qt memory management)
     */
    explicit IWebSocketClient(QObject* parent = nullptr) : QObject(parent) {}

    // MISRA C++ 2008: 10-3-2 - Virtual destructor
    virtual ~IWebSocketClient() = default;

    // Connection Management
    virtual void connectToServer(const QUrl& url) = 0;
    virtual void disconnectFromServer() = 0;
    virtual bool isConnected() const = 0;

    // Data Transmission
    virtual void sendTextMessage(const QString& message) = 0;
    virtual void sendBinaryMessage(const QByteArray& data) = 0;

    // Connection State
    enum class State {
        Disconnected,
        Connecting,
        Connected,
        Closing
    };

    virtual State state() const = 0;

signals:
    // Connection Events
    void connected();
    void disconnected();
    void stateChanged(State state);

    // Data Events
    void textMessageReceived(const QString& message);
    void binaryMessageReceived(const QByteArray& data);

    // Error Events
    void errorOccurred(const QString& errorString);
    void reconnectScheduled(int attemptNumber, int delayMs);
};

} // namespace Network
} // namespace siren

#endif // SIREN_NETWORK_IWEBSOCKET_CLIENT_H