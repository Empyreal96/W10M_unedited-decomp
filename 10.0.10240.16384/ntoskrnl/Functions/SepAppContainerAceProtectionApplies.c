// SepAppContainerAceProtectionApplies 
 
int __fastcall SepAppContainerAceProtectionApplies(unsigned __int16 *a1)
{
  int v3; // r2
  unsigned int v4; // r3
  unsigned int v5; // r1

  if ( RtlEqualUnicodeString(a1, (unsigned __int16 *)&dword_41CF08, 0) )
    return 1;
  if ( RtlPrefixUnicodeString(L"FH", a1, 1) && *a1 >= 0x4Cu )
  {
    v3 = *((_DWORD *)a1 + 1);
    v4 = 0;
    while ( 1 )
    {
      v5 = *(unsigned __int16 *)(v3 + 70);
      if ( v5 < 0x30 || v5 > 0x39 )
        break;
      ++v4;
      v3 += 2;
      if ( v4 >= 3 )
        return 1;
    }
  }
  return 0;
}
