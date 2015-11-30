#include "DAF/entry.h"
#include "DAF/ApplicationServer.h"

int main(int argc, char** argv)
{
  set_signal_handlers();
  init(argc, argv);

  daf::ApplicationServer server;
  server.defaultHostname().setStatic("(.*)", "resources");
}
