// BgDisplayString 
 
int __fastcall BgDisplayString(int a1)
{
  unsigned int v2; // r0
  int v3; // r4

  v2 = BgpFwGetCurrentIrql(a1);
  if ( v2 > 2 )
    return -1073741823;
  BgpFwAcquireLock(v2);
  if ( (dword_619018 & 1) == 0 || (dword_619018 & 0x100) != 0 )
  {
    v3 = -1073741823;
  }
  else if ( dword_61908C && dword_619098 )
  {
    v3 = BgpTxtDisplayString(dword_619098, a1);
  }
  else
  {
    v3 = -1073741670;
  }
  BgpFwReleaseLock();
  return v3;
}
