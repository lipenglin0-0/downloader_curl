//
// Created by lipenglin on 2019-01-31.
//

#include "Downloader.h"

Downloader::Downloader() {
    Downloader::res = curl_global_init(CURL_GLOBAL_ALL);
    Downloader::curl = curl_easy_init();
}

void Downloader::download(const string target, const string uri) {
    FILE *file;
    if (curl) {
        file = fopen(target.data(), "wb+");

        res = curl_easy_setopt(curl, CURLOPT_URL, uri.data());
        if (checkOperation()) {
            curl_easy_cleanup(curl);
            fclose(file);
            printf("set url error.");
            return;
        }

        res = curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeFunc);
        if (checkOperation()) {
            curl_easy_cleanup(curl);
            fclose(file);
            printf("set write function error.");
            return;
        }

        res = curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);
        if (checkOperation()) {
            curl_easy_cleanup(curl);
            fclose(file);
            printf("set data error.");
            return;
        }

        res = curl_easy_perform(curl);
        fclose(file);
        if (checkOperation()) {
            curl_easy_cleanup(curl);
            printf("error. [type='%s']", curl_easy_strerror(res));
            return;
        }
        curl_easy_cleanup(curl);
    }
}

bool Downloader::checkOperation() const {
    return res != CURLE_OK;
}

Downloader::~Downloader() {
    curl_global_cleanup();
}

size_t Downloader::writeFunc(void *buffer, size_t size, size_t count, void *f) {
    return fwrite(buffer, size, count, (FILE *) f);
}
