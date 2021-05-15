// BiIsWindowsEfiEntry 
 
BOOL __fastcall BiIsWindowsEfiEntry(int a1)
{
  unsigned int v2; // r2
  BOOL result; // r0

  result = 0;
  if ( *(_DWORD *)(a1 + 4) >= 0x1Cu && *(_DWORD *)(a1 + 24) >= 0x14u && !strncmp((_BYTE *)(a1 + 28), "WINDOWS", 7u) )
  {
    v2 = *(_DWORD *)(a1 + 40);
    if ( v2 >= 0x14 && *(_DWORD *)(a1 + 36) && wcsnlen((unsigned __int16 *)(a1 + 48), v2 - 20) != v2 - 20 )
      result = 1;
  }
  return result;
}
