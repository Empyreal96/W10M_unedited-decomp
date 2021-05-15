// __report_rangecheckfailure 
 
void __noreturn _report_rangecheckfailure()
{
  KeBugCheckEx(247, 0, _security_cookie, _security_cookie_complement, 0);
}
