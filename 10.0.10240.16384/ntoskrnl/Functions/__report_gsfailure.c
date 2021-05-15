// __report_gsfailure 
 
void __fastcall __noreturn _report_gsfailure(int a1)
{
  KeBugCheck2(247, a1, _security_cookie, _security_cookie_complement, 0, 0);
}
