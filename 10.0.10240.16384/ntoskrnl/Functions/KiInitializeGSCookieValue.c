// KiInitializeGSCookieValue 
 
int __fastcall KiInitializeGSCookieValue(int a1, int a2, int a3, int a4)
{
  int result; // r0
  int v5[2]; // [sp+0h] [bp-8h] BYREF

  v5[0] = a3;
  v5[1] = a4;
  result = KeQueryPerformanceCounter(v5, 0);
  _security_cookie = v5[0] ^ ExpSecurityCookieRandomData;
  _security_cookie_complement = ~(v5[0] ^ ExpSecurityCookieRandomData);
  return result;
}
