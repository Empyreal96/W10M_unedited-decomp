// BgpConsoleDisplayString 
 
int __fastcall BgpConsoleDisplayString(unsigned int a1)
{
  unsigned __int16 *v1; // r5
  int v2; // r4
  int v3; // r0
  int v4; // r0
  int v5; // t1

  v1 = (unsigned __int16 *)a1;
  BgpFwAcquireLock(a1);
  if ( v1 )
  {
    if ( *v1 )
    {
      if ( (dword_610350 & 0x10000) != 0 )
      {
        AnFwFadeCompletion();
        dword_610350 &= 0xFFFEFFFF;
      }
      v3 = *v1;
      v2 = 0;
      while ( v3 )
      {
        v4 = BgpConsoleDisplayCharacterEx(v3, dword_610384, dword_610388, dword_610354, dword_610358);
        if ( v4 < 0 && v2 >= 0 )
          v2 = v4;
        v5 = v1[1];
        ++v1;
        v3 = v5;
      }
    }
    else
    {
      v2 = 0;
    }
  }
  else
  {
    v2 = -1073741811;
  }
  BgpFwReleaseLock();
  return v2;
}
