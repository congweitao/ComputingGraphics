#include <stdio.h>
#include <stdlib.h>
#include <openssl/bio.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <openssl/engine.h>

int main(int argc, char **argv)
{
    /* Initializing OpenSSL*/
    SSL_load_error_strings();
    ERR_load_BIO_strings();
    OpenSSL_add_all_algorithms();

    /* You can use ENGINE_by_id Function to get the handle of Huawei Accelerator Enine */
    ENGINE *e = ENGINE_by_id("ACME");

    ENGINE_ctrl_cmd_string(e, "ACME_CMD_ENABLE_ASYNC", "1", 0);
    
    RSA *rsa = RSA_new_method(e); // 指定引擎用于RSA加解密



    ENGINE_free(e);
}
