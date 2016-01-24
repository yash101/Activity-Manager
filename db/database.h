/*
 * database.h
 *
 *  Created on: Dec 1, 2015
 *      Author: yash
 */

#ifndef DB_DATABASE_H_
#define DB_DATABASE_H_

#include <string>
#include "../DAF/Configuration.h"

bool init_db();

namespace db
{
  std::string getdbpath(std::string loc);
}

#endif /* DB_DATABASE_H_ */
