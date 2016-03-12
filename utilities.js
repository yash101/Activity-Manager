;
(function utilities() {
  var utils = utils || {};

  utils.Username = utils.Username || {};
  utils.Username.isValid = function(username) {
    var nochars = /\W/;

    if(  username == null
      || username.value == ""
      || username.length < 4
      || username.length > 16
      || nochars.test(username)
    ) {
      return false;
    }

    return true;
  };

  utils.Username.checkName = function(name) {
    var nochars = /\W/;
    if(  name == null
      || name == ""
      || name.length > 128
      || nochars.test(name)
    ) {
      return false;
    }

    return true;
  }

  utils.Password = utils.Password || {};
  utils.Password.isValid = function(password) {
    var nochars = /\W+$/;

    if(  password == null
      || password.value == ""
      || password.length < 8
      || password.length > 32
    ) {
      return false;
    }

    return true;
  };

  module.exports = utils;
})();
