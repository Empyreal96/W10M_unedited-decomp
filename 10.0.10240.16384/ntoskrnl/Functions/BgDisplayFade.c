// BgDisplayFade 
 
int __fastcall BgDisplayFade(int a1)
{
  unsigned int v1; // r0
  int v2; // r4

  v1 = BgpFwGetCurrentIrql(a1);
  if ( v1 > 2 )
    return -1073741823;
  BgpFwAcquireLock(v1);
  if ( (dword_619018 & 1) != 0 )
    v2 = AnFwDisplayFade();
  else
    v2 = -1073741823;
  BgpFwReleaseLock();
  return v2;
}
