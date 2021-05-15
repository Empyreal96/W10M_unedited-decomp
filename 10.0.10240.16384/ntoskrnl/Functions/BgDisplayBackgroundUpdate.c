// BgDisplayBackgroundUpdate 
 
int __fastcall BgDisplayBackgroundUpdate(unsigned int a1)
{
  int v2; // r4

  BgpFwAcquireLock(a1);
  if ( (dword_619018 & 1) != 0 )
    v2 = AnFwDisplayBackgroundUpdate(a1);
  else
    v2 = -1073741823;
  BgpFwReleaseLock();
  return v2;
}
