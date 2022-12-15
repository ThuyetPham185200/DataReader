#include "CRLDataLoader.h"

CRLDataLoader::CRLDataLoader()
{
    this->pbuf_ = nullptr;
    this->isEndFile_ = false;
}

CRLDataLoader::~CRLDataLoader()
{ 
    printf("Destroy CRLDataLoader\n");
    //if(this->pbuf_ != nullptr) delete this->pbuf_;
}

std::vector<unsigned char> CRLDataLoader::loadFile()
{
    int count_ = INIT_COUNT;
    unsigned char arrData[MAX_LENGHT_BUFFER];
    std::vector<unsigned char> buffer_;
    if (this->fileInput_.is_open()) {
       this->isEndFile_ = false;
       if (this->fileInput_) {
            this->pbuf_ = this->fileInput_.rdbuf();
           do {
               count_ ++;
               unsigned char tempFirst_ = (unsigned char)this->pbuf_->sgetc();
               unsigned char tempSecond_ = (unsigned char)this->pbuf_->snextc();
               arrData[count_] = tempFirst_;
               arrData[++count_] = tempSecond_;
               if(count_ % NUM_BYTES_CRC == 1 && tempFirst_ == CRC_FRIST && tempSecond_ == CRC_SECOND)
               {
                   buffer_.resize(count_ + 1);
                   for (int i = 0; i <= count_; i++)
                   {
                       buffer_[i] = arrData[i];
//                           printf("%02x ", buffer_[i]);
//                           if(i > 0 && i % 16 == 0) printf("\n");
                   }
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


void CRLDataLoader::getCRLPathFile(QString pathOfFile)
{
    std::cout << "path of file CRLDataLoader: " << pathOfFile.toStdString() << std::endl;
    if(this->fileInput_.is_open()) this->fileInput_.close();
    this->fileInput_.open(pathOfFile.toStdString(), std::ios::binary);
}
