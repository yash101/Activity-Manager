/*
 * authdb.cpp
 *
 *  Created on: Nov 30, 2015
 *      Author: yash
 */

#include "../db/database.h"
#include "../db/authdb.h"
#include "../DAF/Configuration.h"
#include "../DAF/HttpServer.h"

#include <string.h>
#include <string>

static daf::Config Users(db::getdbpath("users.dat"));

bool db::init()
{
  return true;
}

bool web::signup(daf::HttpServer::Session& session)
{
  std::string username = session.Post["uname"].string;
  std::string email = session.Post["email"].string;
  std::string passwd = session.Post["passwd"].string;
  std::string chpasswd = session.Post["chkpasswd"].string;
  std::string fname = session.Post["fname"].string;
  std::string lname = session.Post["lname"].string;

  if(username.size() < 4 || username.size() > 32)
  {
    session.Response.string = "Username was too short or long. Must be between 4 and 32 characters long.";
    session.StatusCode = 200;
    return true;
  }

  if(Users[daf::Http::encodeURI(username)].size() != 0)
  {
    session.Response.string = "Username is already taken. Sorry!";
    session.StatusCode = 200;
    return true;
  }

  if(email.size() < 4 || email.size() > 128)
  {
    session.Response.string = "Email was too short or long. Must be between 4 and 128 characters";
    session.StatusCode = 200;
    return true;
  }

  if(passwd != chpasswd)
  {
    session.Response.string = "Passwords must match!";
    session.StatusCode = 200;
    return true;
  }

  if(fname.size() > 128 || lname.size() > 128 || fname.size() == 0 || lname.size() == 0)
  {
    session.Response.string = "Invalid name!";
    session.StatusCode = 200;
    return true;
  }

  Users[daf::Http::encodeURI(username)] = daf::Http::encodeURI(passwd);

  return true;
}

bool web::login(daf::HttpServer::Session& session)
{
  return true;
}
