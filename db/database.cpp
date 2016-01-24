/*
 * database.cpp
 *
 *  Created on: Dec 1, 2015
 *      Author: yash
 */

#include "database.h"
#include "../DAF/entry.h"
#include <stdio.h>

bool init_db()
{
  if(Configuration()["db.location"].size() != 0)
  {
    if(Configuration()["db.location"].back() == '/')
    {
      Configuration()["db.location"].pop_back();
      Configuration().flush();
    }
  }

  return true;
}

std::string db::getdbpath(std::string loc)
{
  return Configuration()["db.location"] + "/" + loc;
}
