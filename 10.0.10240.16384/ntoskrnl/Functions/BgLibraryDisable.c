// BgLibraryDisable 
 
int __fastcall BgLibraryDisable(int a1)
{
  unsigned int v1; // r0

  if ( BgpFwGetCurrentIrql(a1) )
    return -1073741823;
  v1 = BgpFwAcquireLock(0);
  if ( (dword_619018 & 1) != 0 )
    BgpFwLibraryDisable(v1);
  BgpFwReleaseLock();
  return 0;
}
