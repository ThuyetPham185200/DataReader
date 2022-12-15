#include "KLVDataLoader.h"
static const int LENGTH_KEY = 2;
static const int LENGTH_PAYLOAD = 4;
KLVDataLoader::KLVDataLoader()
{
    this->pbuf_ = nullptr;
    this->isEndFile_ = false;
}

KLVDataLoader::~KLVDataLoader()
{
    printf("Destroy KLVDataLoader\n");
    if(this->pbuf_ != nullptr) delete this->pbuf_;
}

std::vector<unsigned char> KLVDataLoader::loadFile()
{
    int count_ = INIT_COUNT;
    int lengthPayload_;
    unsigned char arrData[LENGTH_KEY + LENGTH_PAYLOAD];
    std::vector<unsigned char> buffer_;
    if (this->fileInput_.is_open()) {
        this->isEndFile_ = false;
           if (this->fileInput_) {
                this->pbuf_ = this->fileInput_.rdbuf();
               do {
                   count_ ++;
                   if(count_ < LENGTH_KEY + LENGTH_PAYLOAD)
                   {
                       arrData[count_] = (unsigned char)this->pbuf_->sgetc();
                       if (count_ ==  LENGTH_KEY + LENGTH_PAYLOAD -1)
                       {
                           std::vector <unsigned char> temp_(4);
                           for(int i = LENGTH_KEY; i < LENGTH_KEY + LENGTH_PAYLOAD; i++)
                           {
                               temp_[i - LENGTH_KEY] = arrData[i];
                           }
                           lengthPayload_ = this->hexToInt(temp_);
                       }
                   };
                   buffer_.resize(lengthPayload_);
                   if(count_ < lengthPayload_ + LENGTH_KEY + LENGTH_PAYLOAD)
                   {
                       buffer_[count_ - LENGTH_KEY - LENGTH_PAYLOAD] = (unsigned char)this->pbuf_->sgetc();
                   }
                   else if (count_ == lengthPayload_ + LENGTH_KEY + LENGTH_PAYLOAD - 1)
                   {
                       if(this->pbuf_->snextc() == EOF)
                       {
                           this->fileInput_.close();
                       }
                       return buffer_;
                   }
               } while ( this->pbuf_->snextc() != EOF );
           }
    }
    else this->isEndFile_ = true;
}


void KLVDataLoader::getKLVPathFile(QString pathOfFile)
{
    std::cout << "path of file KLVDataLoader: " << pathOfFile.toStdString() << std::endl;
    this->fileInput_.open(pathOfFile.toStdString(), std::ios::binary);
}
int KLVDataLoader::hexToInt(std::vector <unsigned char> data)
{
    int num = 0;
    for (int32_t i = 0; i < 4; i++) {
        num = (num << 4) + (data[i] & 0xFF);
    }
    return num;
}
