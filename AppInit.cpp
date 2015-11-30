/*
 * AppInit.cpp
 *
 *  Created on: Nov 29, 2015
 *      Author: yash
 */
#include "AppInit.h"
#include "DAF/ApplicationServer.h"

#include <string>

bool check_configuration_values()
{
  daf::pollMime("html", "text/html");
  daf::pollMime("css", "text/css");
  daf::pollMime("js", "text/javascript");
  daf::pollMime("png", "image/png");
  daf::pollMime("jpg", "image/jpeg");
  daf::pollMime("gif", "image/gif");

  return true;
}
