#ifndef BOTANWRAPPER_H
#define BOTANWRAPPER_H

#include <QObject>
#include "botan.h"

class DuCrypt: public QObject
{
	Q_OBJECT
public:
    explicit DuCrypt(QObject *parent = nullptr);

	/**
	 * Creates a hash
	 * @param Data The string to hash
	 */
    QString hash(QString data);

	/**
	 * Creates a hash in hex format
	 * @param Data The string to hash
	 */
    QString hexHash(QString data);

	/**
	 * Returns a Base64 encoded QString
	 * @param Data The string to encode
	 */
    QString encode(QString data);

	/**
	 * Returns a decoded string from a Base64 encoded string
	 * @param Data The string to decode
	 */
    QString decode(QString data);

	/**
	 * Returns a Base64 encrypted QString
	 * @param Data The string to encypt
	 */
    QString encrypt(QString data);

	/**
	 * Returns a decrypted string from a Base64 encypted string
	 * @param Data The string to encypt
	 */
    QString decrypt(QString data);

	/**
	 * Encrypts a file and returns a bool indicating success
	 * @param Source The source file
	 * @param Destination The destination file
	 */
    bool encryptFile(QString source, QString destination);

	/**
	 * Decrypts a file and returns a bool indicating success
	 * @param Source The source file
	 * @param Destination The destination file
	 */
    bool decryptFile(QString source, QString destination);

	/**
	 * Sets the Password
	 * @param Password The password
	 */
    void setPassword(QString password);

	/**
	 * Sets the Salt
	 * @param Salt The salt value
	 */
    void setSalt(QString salt);
private:
	Botan::LibraryInitializer mInit;
    Botan::SecureVector<Botan::byte> mSalt;
	QString mPassword;
};

#endif // BOTANWRAPPER_H
