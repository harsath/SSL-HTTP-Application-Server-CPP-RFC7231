### Asynchronous/event-driven HTTP Server/REST API Framework C++ Implementation (SSL and Authentication support)
![Linux Actions Status](https://github.com/harsathAI/SSL-HTTP-Application-Server-CPP-RFC7231/workflows/Linux/badge.svg) ![GitHub](https://img.shields.io/github/license/harsathAI/SSL-HTTP-Application-Server-CPP-RFC7231)

```
Project  : Asynchronous C++ HTTP Application Server & REST API Framework (from scratch)
RFC      : 7231
Language : C++ (with POSIX APIs)

This project is under active development
```

##### Steps:
1. Generate a Self-signed SSL CERT and Private Key 
```
$ openssl req -x509 -nodes -newkey rsa:4096 -keyout key.pem -out cert.pem -days 365
```

2. Run, `$ mkdir build && cd build && CC=gcc-9 CXX=g++-9 cmake .. && make`

3. Note that, you need to have OpenSSL installed on your machine to build.

4. Copy the the sample html files (or point to your own files) with `$ cp -r ../configs .`

Now, run the server with `./server`

#### Note: The examples in `./examples` are NOT updated. I will update them when I find time ASAP. Checkout main.cpp and main-plain.cpp for updated code for now.
Checkout the `./examples` dir for more info on using Callbacks and REST API examples.

5. You can now, test the SSL/HTTPS server through cURL or openssl's s_client
```
$ curl --insecure -u 'username:password$324'-v -H "Content-Type: application/json" -d '{"value_one":123,"value_two":"Hello"}' https://127.0.0.1:9876/poster
*   Trying 127.0.0.1:9876...
* Connected to 127.0.0.1 (127.0.0.1) port 9876 (#0)
* ALPN, offering http/1.1
* successfully set certificate verify locations:
*   CAfile: /cacert.pem
  CApath: none
* TLSv1.3 (OUT), TLS handshake, Client hello (1):
* TLSv1.3 (IN), TLS handshake, Server hello (2):
* TLSv1.3 (IN), TLS handshake, Encrypted Extensions (8):
* TLSv1.3 (IN), TLS handshake, Certificate (11):
* TLSv1.3 (IN), TLS handshake, CERT verify (15):
* TLSv1.3 (IN), TLS handshake, Finished (20):
* TLSv1.3 (OUT), TLS change cipher, Change cipher spec (1):
* TLSv1.3 (OUT), TLS handshake, Finished (20):
* SSL connection using TLSv1.3 / TLS_AES_256_GCM_SHA384
* ALPN, server did not agree to a protocol
* Server certificate:
*  subject: C=DE; ST=Some-State; O=Internet Widgits Pty Ltd
*  start date: Nov 28 02:56:27 2020 GMT
*  expire date: Nov 28 02:56:27 2021 GMT
*  issuer: C=DE; ST=Some-State; O=Internet Widgits Pty Ltd
*  SSL certificate verify result: self signed certificate (18), continuing anyway.
> POST /poster HTTP/1.1
> Host: 127.0.0.1:9876
> Authorization: Basic dXNlcl90d286UGFzc3dvcmQy
> User-Agent: curl/7.71.1
> Accept: */*
> Content-Type: application/json
> Content-Length: 37
............
............
```
