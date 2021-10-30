#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "CRC32.h"
#include <cstdint>
//#include "crc32.h"

#include <QFile>

Crc32::Crc32()
{
    quint32 crc;

    // initialize CRC table
    for (int i = 0; i < 256; i++)
    {
        crc = i;
        for (int j = 0; j < 8; j++)
            crc = crc & 1 ? (crc >> 1) ^ 0xEDB88320UL : crc >> 1;

        crc_table[i] = crc;
    }
}

quint32 Crc32::calculateFromFile(QString filename)
{
    quint32 crc;
    QFile file;

    char buffer[16000];
    int len, i;

    crc = 0xFFFFFFFFUL;

    file.setFileName(filename);
    if (file.open(QIODevice::ReadOnly))
    {
        while (!file.atEnd())
        {
            len = file.read(buffer, 16000);
            for (i = 0; i < len; i++)
                crc = crc_table[(crc ^ buffer[i]) & 0xFF] ^ (crc >> 8);
        }

        file.close();
    }

    return crc ^ 0xFFFFFFFFUL;
}

void Crc32::initInstance(int i)
{
    instances[i] = 0xFFFFFFFFUL;
}

void Crc32::pushData(int i, char *data, int len)
{
    quint32 crc = instances[i];
    if (crc)
    {
        for (int j = 0; j < len; j++)
            crc = crc_table[(crc ^ data[j]) & 0xFF] ^ (crc >> 8);

        instances[i] = crc;
    }
}

quint32 Crc32::releaseInstance(int i)
{
    quint32 crc32 = instances[i];
    if (crc32) {
        instances.remove(i);
        return crc32 ^ 0xFFFFFFFFUL;
    }
    else {
        return 0;
    }
}


// ----------------------------- crc32c --------------------------------

/* This is derived from crc32b but does table lookup. First the table
itself is calculated, if it has not yet been set up.
Not counting the table setup (which would probably be a separate
function), when compiled to Cyclops with GCC, this function executes in
7 + 13n instructions, where n is the number of bytes in the input
message. It should be doable in 4 + 9n instructions. In any case, two
of the 13 or 9 instrucions are load byte.
   This is Figure 14-7 in the text. */

unsigned int Crc32::crc32c(const char *message, unsigned short size) {
   int i, j;
   unsigned int byte, crc, mask;
   static unsigned int table[256];

   /* Set up the table, if necessary. */

   if (table[1] == 0) {
      for (byte = 0; byte <= 255; byte++) {
         crc = byte;
         for (j = 7; j >= 0; j--) {    // Do eight times.
            mask = -(crc & 1);
            crc = (crc >> 1) ^ (0xEDB88320 & mask);
         }
         table[byte] = crc;
      }
   }

   /* Through with table setup, now calculate the CRC. */

   i = 0;
   crc = 0xFFFFFFFF;
   while (size != 0) {
	   byte = message[i];
      crc = (crc >> 8) ^ table[(crc ^ byte) & 0xFF];
      i = i + 1;
	  size --;
//	  std::cout << "CRC is " << crc << std::endl; 
   }
   return ~crc;
}
