/*
 * authdb.h
 *
 *  Created on: Nov 30, 2015
 *      Author: yash
 */

#ifndef DB_AUTHDB_H_
#define DB_AUTHDB_H_
#include "../DAF/HttpServer.h"
namespace web
{
  bool signup(daf::HttpServer::Session&);
  bool login(daf::HttpServer::Session&);
}

namespace db
{
  bool init();
}
#endif /* DB_AUTHDB_H_ */
