#pragma once
#include <cstdint>
#include <stdio.h>
#include <stdlib.h>

#ifndef CRC32_H
#define CRC32_H

#include <QtCore>
#include <QString>
#include <QMap>

class Crc32
{
    uint32_t update_crc_32( uint32_t crc, unsigned char c );
private:
    quint32 crc_table[256];
    QMap<int, quint32> instances;

public:
    Crc32();

    unsigned int crc32c(const char *message, unsigned short size);
    quint32 calculateFromFile(QString filename);

    void initInstance(int i);
    void pushData(int i, char *data, int len);
    quint32 releaseInstance(int i);
};

#endif // CRC32_H
