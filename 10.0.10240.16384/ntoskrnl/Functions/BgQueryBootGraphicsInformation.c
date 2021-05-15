// BgQueryBootGraphicsInformation 
 
int __fastcall BgQueryBootGraphicsInformation(int a1, int a2)
{
  int v4; // r4

  if ( KeGetCurrentIrql(a1) )
    return -1073741823;
  if ( !a2 || a1 >= 4 )
    return -1073741811;
  BgpFwAcquireLock();
  if ( (dword_619018 & 1) != 0 )
    v4 = BgpFwQueryBootGraphicsInformation(a1, a2);
  else
    v4 = -1073741823;
  BgpFwReleaseLock();
  return v4;
}
