#ifndef CRLDATALOADER_H
#define CRLDATALOADER_H
#include <DataLoader.h>
static const int NUM_BYTES_CRC = 2;
class CRLDataLoader : public DataLoader
{
public:
    CRLDataLoader();
    ~CRLDataLoader();
    void getCRLPathFile(QString);
    std::vector <unsigned char> loadFile() override;
};

#endif // CRLDATALOADER_H
