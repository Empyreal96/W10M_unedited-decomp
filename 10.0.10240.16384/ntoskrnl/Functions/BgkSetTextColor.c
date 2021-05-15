// BgkSetTextColor 
 
int __fastcall BgkSetTextColor(unsigned int a1)
{
  unsigned int v2; // r4
  unsigned int v3; // r1

  if ( a1 < 0x10 && BgkpAcquireConsole() )
  {
    (*(void (__fastcall **)(int *, _DWORD))(dword_637614 + 8))(&Palette[a1], 0);
    __pld(&dword_61646C);
    v2 = dword_61646C & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v3 = __ldrex((unsigned int *)&dword_61646C);
    while ( v3 == v2 && __strex(v2 - 2, (unsigned int *)&dword_61646C) );
    if ( v3 != v2 )
      ExfReleaseRundownProtection((unsigned __int8 *)&dword_61646C);
  }
  return 0;
}
