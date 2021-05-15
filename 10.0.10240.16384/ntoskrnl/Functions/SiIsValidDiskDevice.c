// SiIsValidDiskDevice 
 
BOOL __fastcall SiIsValidDiskDevice(int a1, int a2)
{
  int v5; // r2
  unsigned int v6; // r3
  int v7; // r1
  unsigned int v8; // t1

  if ( wcsicmp(a2, L"Directory") && wcsicmp(a2, L"SymbolicLink") )
    return 0;
  if ( wcsnicmp(a1, L"Harddisk", 8) )
    return 0;
  v5 = a1 + 16;
  v6 = *(unsigned __int16 *)(a1 + 16);
  if ( !*(_WORD *)(a1 + 16) )
    return 0;
  if ( v6 != 48 )
  {
    v7 = 0;
    while ( v6 >= 0x30 )
    {
      if ( v6 > 0x39 )
        break;
      if ( (unsigned int)++v7 > 0xA )
        break;
      v8 = *(unsigned __int16 *)(v5 + 2);
      v5 += 2;
      v6 = v8;
      if ( !v8 )
        return 1;
    }
    return 0;
  }
  return !*(_WORD *)(a1 + 18);
}
