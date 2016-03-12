var signup = function()
{
  $.post("/signup",
  {
    "uname": document.querySelectorAll("body > #loginfrm > form > #uname").value,
    "email": document.querySelectorAll("body > #loginfrm > form > #email").value,
    "passwd": document.querySelectorAll("body > #loginfrm > form > #passwd").value,
    "chkpasswd": document.querySelectorAll("body > #loginfrm > form > #chkpasswd").value,
    "fname": document.querySelectorAll("body > #loginfrm > form > #fname").value,
    "lname": document.querySelectorAll("body > #loginfrm > form > #lname").value
  }, function()
  {
  })
}
