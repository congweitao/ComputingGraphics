#include <stdio.h>
#include <stdlib.h>
#include <openssl/bio.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <openssl/engine.h>
#include <openssl/rsa.h>

const char* PRIVATE_KEY="./private_key.pem";
const char* PUBLIC_KEY="./public_key.pem";

int main(int argc, char **argv)
{
    /* Initializing OpenSSL*/
    SSL_load_error_strings();
    ERR_load_BIO_strings();
    OpenSSL_add_all_algorithms();

    /* You can use ENGINE_by_id Function to get the handle of Huawei Accelerator Enine */
    ENGINE *e = ENGINE_by_id("afalg");
    if(!e) {
        printf("the engine isn't avaiable.\n");
        return;
    } else { printf("engine successfully enabled!\n");}
    // ENGINE_ctrl_cmd_string(e, "KAE_CMD_ENABLE_ASYNC", "1", 0);
    
    RSA *rsa = RSA_new_method(e); // 指定引擎用于RSA加解密

   /* the user code */  
   FILE* fp1 = NULL, *fp2 = NULL;
   if ((fp1 = fopen((PUBLIC_KEY), "r")) == NULL) { 
        printf("public key open failed.\n");
        return;
   }
   
   if ((rsa = PEM_read_RSA_PUBKEY(fp1, NULL, NULL, NULL)) == NULL) {
        printf("pub key read failed!\n");
        return;
   }

   RSA_print_fp(stdout, rsa, 0);    

   if ((fp2 = fopen((PRIVATE_KEY), "r")) == NULL) { 
        printf("private key open failed.\n");
        return;
   }

   if ((rsa = PEM_read_RSAPrivateKey(fp2, NULL, NULL, NULL)) == NULL) {
        printf("private key read failed!\n");
        return;
   }

   RSA_print_fp(stdout, rsa, 0);    

   fclose(fp1);
   fclose(fp2);

   ENGINE_free(e);
}
