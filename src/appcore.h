#ifndef APPCORE_H
#define APPCORE_H

#include <QObject>
#include <array>

class AppCore : public QObject {
    Q_OBJECT
public:
    explicit  AppCore(QObject *parent = nullptr);

signals:
    void changeBit(QString bit, int index);
    void changeNum(QString number);

public slots:
    void newBit(int index);
    void newNum(QString num);
    void invertBits();
    void addFileAmount();

private:
    int fileAmount(const char* path = "input.txt");
    std::array<QString, 8> boolArrToStringArr();

    std::array<bool, 8> numToBits();
    uint8_t bitsToNum();

    QString numToString();
    QString decIntToHexSymbol(uint8_t symbol);
    uint8_t stringToNum(QString num);
    uint8_t hexSymbolToDecInt(QString symbol);

private:
    std::array<bool, 8> m_bits;
    uint8_t m_num;
};

#endif // APPCORE_H
