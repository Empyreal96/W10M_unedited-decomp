// BgMarkHiberPhase 
 
int __fastcall BgMarkHiberPhase(unsigned int a1)
{
  unsigned int v1; // r0
  int v2; // r4

  v1 = BgpFwAcquireLock(a1);
  if ( (dword_619018 & 1) != 0 )
    v2 = BgpFwMarkHiberPhase(v1);
  else
    v2 = -1073741823;
  BgpFwReleaseLock();
  return v2;
}
