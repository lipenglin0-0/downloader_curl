# env

1. openssl
    - [download](https://www.openssl.org/source/)
    - install
    ```sh
    sudo ./config --prefix=/usr/local/openssl
    make
    make install
    openssl version
    ```
2. curl
    - [download](https://curl.haxx.se/)
    - install
    ```sh
    ./configure LDFLAGS="-ldl -lm" --prefix=/usr/local/curl --with-darwinssl
    make
    sudo make install
    /usr/local/curl/bin/curl -V
    ```

# c make list

1. 头
    ```c++
    set(INCLUDE_CURL /usr/local/curl/include/curl)
    ```
2. 链接
    ```c++
    set(LIB_LIBCURL /usr/local/curl/lib/libcurl.dylib)
    set(LIB_LIBCURL_4 /usr/local/curl/lib/libcurl.4.dylib)
    ```
3. 设置
    ```c++
    link_libraries(${INCLUDE_CURL} ${LIB_LIBCURL} ${LIB_LIBCURL_4})
    ```