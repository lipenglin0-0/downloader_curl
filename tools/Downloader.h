//
// Created by lipenglin on 2019-01-31.
//

#include <curl/curl.h>
#include <string>

using namespace std;

class Downloader {
private:
    CURLcode res;
    void *curl;

public:
    Downloader();

    ~Downloader();

    void download(const string target,const string uri);

    bool checkOperation() const;

    static size_t writeFunc(void *buffer, size_t size, size_t count, void *f);

};
