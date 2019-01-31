#include <iostream>
#include "tools/Downloader.h"

int main() {
    Downloader *pDownloader = new Downloader();
    pDownloader->download("index.html", "https://www.sensorsdata.cn/");
}