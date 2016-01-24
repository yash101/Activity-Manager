#include "DAF/entry.h"
#include "DAF/ApplicationServer.h"

#include "AppInit.h"

bool ErrorFunc(daf::HttpServer::Session& session)
{
  session.StatusCode = 404;
  session.Response.DataType = daf::Http::STRING;
  session.Response.string = "Error 404!";
  session.Headers["content-type"] = "text/plain";
  return true;
}

int main(int argc, char** argv)
{
  set_signal_handlers();
  init(argc, argv);
  check_configuration_values();

  daf::ApplicationServer server;
  server["(.*)"].setStatic("(.*)", "HttpRes");
  server.defaultHostname().pointerFunction("(.*)") = ErrorFunc;
  server.setPort(1234);
  server.startServer();
}
