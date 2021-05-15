// BgpConsoleClearScreen 
 
int __fastcall BgpConsoleClearScreen(unsigned int a1)
{
  unsigned int v1; // r0
  int v2; // r4

  v1 = BgpFwAcquireLock(a1);
  v2 = BgpConsoleClearScreenEx(v1);
  BgpFwReleaseLock();
  return v2;
}
