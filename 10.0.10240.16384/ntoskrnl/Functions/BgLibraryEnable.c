// BgLibraryEnable 
 
int __fastcall BgLibraryEnable(unsigned int a1, int a2)
{
  unsigned __int8 *v2; // r5
  char v3; // r3
  int v4; // r4
  int v5; // r1
  int v6; // r2

  v2 = (unsigned __int8 *)a1;
  v3 = dword_619018;
  if ( a2 )
  {
    v3 = dword_619018;
    dword_619018 |= 0xC00u;
  }
  if ( a1 )
  {
    if ( a2 || (a1 = KeGetCurrentIrql(a1)) == 0 )
    {
      BgpFwAcquireLock(a1);
      if ( (dword_619018 & 1) != 0 )
        v4 = BgpFwLibraryEnable(v2, v5, v6);
      else
        v4 = -1073741637;
      BgpFwReleaseLock();
    }
    else
    {
      v4 = -1073741823;
    }
  }
  else if ( (v3 & 2) != 0 )
  {
    v4 = 0;
  }
  else
  {
    v4 = -1073741585;
  }
  return v4;
}
