#include "appcore.h"
#include <fstream>

AppCore::AppCore(QObject *parent) : QObject(parent), m_num(0) {
    for(auto& it: m_bits){
        it = false;
    }
}

void AppCore::newBit(int index) {
    m_bits[index] = !m_bits[index];
    m_num = bitsToNum();
    QString num = numToString();
    if(m_bits[index]) {
        emit changeNum(num);
        emit changeBit("1", index);
    } else {
        emit changeNum(num);
        emit changeBit("0", index);
    }
}
void AppCore::newNum(QString num) {
    m_num = stringToNum(num);
    m_bits = numToBits();
    std::array<QString, 8> stringBits = boolArrToStringArr();

    for(int i = 0; i < 8; i++){
        emit changeBit(stringBits[i], i);
    }
}
void AppCore::invertBits() {
    for(auto& it: m_bits){
        it = !it;
    }
    m_num = bitsToNum();
    m_bits = numToBits();

    QString num = numToString();
    std::array<QString, 8> stringBits = boolArrToStringArr();

    emit changeNum(num);
    for(int i = 0; i < 8; i++){
        emit changeBit(stringBits[i], i);
    }
}
void AppCore::addFileAmount() {
    m_num = (m_num + fileAmount()) % 256;

    QString num = numToString();
    m_bits = numToBits();
    std::array<QString, 8> stringBits = boolArrToStringArr();

    emit changeNum(num);
    for(int i = 0; i < 8; i++){
        emit changeBit(stringBits[i], i);
    }
}

int AppCore::fileAmount(const char *path) {
    std::ifstream fin(path);

    if(fin.eof()){
        return 0;
    }

    QVector<int> summands;

    std::string line;
    while (fin >> line) {
        summands.push_back(stoi(line));
    }

    int sum = 0;
    for(auto var: summands){
        sum += var;
    }
    return sum;
}
std::array<QString, 8> AppCore::boolArrToStringArr() {
    std::array<QString, 8> stringBits;
    for(int i = 0; i < (int)m_bits.size(); i++){
        if(m_bits[i]){
            stringBits[i] = "1";
        } else {
            stringBits[i] = "0";
        }
    }
    return stringBits;
}

std::array<bool, 8> AppCore::numToBits() {
    uint8_t var = 1;
    std::array<bool, 8> bits;
    for(int i = bits.size() - 1; i >= 0; i--){
        if(m_num & var){
            bits[i] = true;
        } else {
            bits[i] = false;
        }
        var = var << 1;
    }
    return bits;
}
uint8_t AppCore::bitsToNum() {
    uint8_t num = 0;
    for(auto& it: m_bits){
        if(it){
            num = (num << 1) | 1;
        } else {
            num = num << 1;
        }
    }
    return num;
}

QString AppCore::numToString() {
    uint8_t highBit_ = m_num / 16;
    uint8_t leastBit_ = m_num % 16;

    QString highBit = decIntToHexSymbol(highBit_);
    QString leastBit = decIntToHexSymbol(leastBit_);

    QString res = highBit + leastBit;

    return res;
}
QString AppCore::decIntToHexSymbol(uint8_t num) {
    QString digit = QString::number(num);
    if(digit == "10"){
        digit = "A";
    } else if(digit == "11"){
        digit = "B";
    } else if(digit == "12"){
        digit = "C";
    } else if(digit == "13"){
        digit = "D";
    } else if(digit == "14"){
        digit = "E";
    } else if(digit == "15"){
        digit = "F";
    }
    return digit;
}
uint8_t AppCore::stringToNum(QString num) {
    uint8_t highBit = hexSymbolToDecInt(QString(num[0]));
    uint8_t leastBit = hexSymbolToDecInt(QString(num[1]));

    uint8_t res = highBit * 16 + leastBit;

    return res;
}
uint8_t AppCore::hexSymbolToDecInt(QString digit) {
    uint8_t num = 0;
    if(digit == "A" || digit == "a"){
        num = 10;
    } else if(digit == "B" || digit == "b"){
        num = 11;
    } else if(digit == "C" || digit == "c"){
        num = 12;
    } else if(digit == "D" || digit == "d"){
        num = 13;
    } else if(digit == "E" || digit == "e"){
        num = 14;
    } else if(digit == "F" || digit == "f"){
        num = 15;
    } else {
        num = digit.toInt();
    }
    return num;
}
