#include "DAF/entry.h"
#include "DAF/ApplicationServer.h"

#include "AppInit.h"

int main(int argc, char** argv)
{
  set_signal_handlers();
  init(argc, argv);
  check_configuration_values();

  daf::ApplicationServer server;
  server["(.*)"].setStatic("(.*)", "HttpRes");
  server.setPort(1234);
  server.startServer();
}
