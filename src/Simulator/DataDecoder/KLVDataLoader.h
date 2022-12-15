#ifndef KLVDATALOADER_H
#define KLVDATALOADER_H
#include <DataLoader.h>

class KLVDataLoader : public DataLoader
{
public:
    KLVDataLoader();
    ~KLVDataLoader();
    void getKLVPathFile(QString);
    int hexToInt(std::vector <unsigned char> data);
    std::vector <unsigned char> loadFile() override;
};

#endif // KLVDATALOADER_H
