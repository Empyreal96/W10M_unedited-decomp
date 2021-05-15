// BgkSolidColorFill 
 
unsigned __int8 *__fastcall BgkSolidColorFill(unsigned __int8 *result, int a2, int a3, int a4, unsigned int a5)
{
  int v5; // r0
  unsigned int v6; // r4
  unsigned int v7; // r1

  if ( !result && !a2 && a3 == 639 && a4 == 479 && a5 < 0x10 )
  {
    result = (unsigned __int8 *)BgkpAcquireConsole();
    if ( result )
    {
      v5 = (*(int (__fastcall **)(_DWORD, int *))(dword_637614 + 8))(0, &Palette[a5]);
      (*(void (__fastcall **)(int))(dword_637614 + 4))(v5);
      result = (unsigned __int8 *)&dword_61646C;
      __pld(&dword_61646C);
      v6 = dword_61646C & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v7 = __ldrex((unsigned int *)&dword_61646C);
      while ( v7 == v6 && __strex(v6 - 2, (unsigned int *)&dword_61646C) );
      if ( v7 != v6 )
        result = ExfReleaseRundownProtection((unsigned __int8 *)&dword_61646C);
    }
  }
  return result;
}
