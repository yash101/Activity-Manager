var express = require('express');
var router = express.Router();
var utils = require("../utilities");

//Get index page (home)
router.get('/', function(req, res) {
  res.render('index', { });
});

//Login page
router.get("/login", function(req, res) {
  res.render("login", { });
});

//Logs you in
router.get("/login/auth", function(req, res) {
  var db = req.db;
  var users = db.get("users");
  users.find({ }, { }, function(e, docs) {
    res.render("login/auth", {
      "userlist": docs
    });
  });
});


//Signs a user up
router.post("/login/signup", function(req, res) {
  var db = req.db;
  var users = db.get("users");
  var passwd = req.body.passwd;
  var cpasswd = req.body.chkpasswd;

  if(  !utils.Password.isValid(req.body.passwd)
    || req.body.passwd != req.body.chkpasswd
  ) {
    res.send("Password invalid");
    return;
  }

  if(!utils.Username.isValid(req.body.uname)) {
    res.send("Username invalid");
    return;
  }

  if(!utils.Username.checkName(req.body.fname)) {
    res.send("Invalid first name");
    return;
  }

  if(!utils.Username.checkName(req.body.lname)) {
    res.send("Invalid last name");
    return;
  }

  var collection = req.db.get("users");

  collection.insert({
    "username": req.body.uname,
    "email": req.body.email,
    "passwd": req.body.passwd,
    "fname": req.body.fname,
    "lname": req.body.lname
  }, function(err, doc) {
    if(err) {
      res.send("Problem adding user");
    }
    else
    {
      res.redirect("/login/auth");
    }
  });

});

router.get("/signup", function(req, res) {
  res.render("signup", { });
});

module.exports = router;
