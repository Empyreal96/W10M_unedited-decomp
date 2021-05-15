// BgConsoleGetInterface 
 
void **__fastcall BgConsoleGetInterface(unsigned int a1)
{
  void **v1; // r4

  v1 = 0;
  BgpFwAcquireLock(a1);
  if ( (dword_619018 & 1) != 0 && dword_619088 )
    v1 = &BgpConsoleInterface;
  BgpFwReleaseLock();
  return v1;
}
