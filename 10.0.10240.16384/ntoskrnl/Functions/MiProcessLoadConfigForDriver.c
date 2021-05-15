// MiProcessLoadConfigForDriver 
 
int __fastcall MiProcessLoadConfigForDriver(int a1)
{
  ExGenRandom(0);
  LdrInitSecurityCookie(*(_DWORD *)(a1 + 24), *(_DWORD *)(a1 + 32));
  return 0;
}
