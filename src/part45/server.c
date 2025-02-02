#include <fcgi_stdio.h>
#include <fcgiapp.h>
#include <stdio.h>

int main() {
  FCGX_Init();
  int Socket = FCGX_OpenSocket("127.0.0.1:8080", 100);
  FCGX_Request req;
  FCGX_InitRequest(&req, Socket, 0);
  while (FCGX_Accept_r(&req) >= 0) {
    FCGX_FPrintF(req.out, "Content-Type: text/html\n\n");
    FCGX_FPrintF(req.out, "Hello world");
    FCGX_Finish_r(&req);
  }
  return 0;
}