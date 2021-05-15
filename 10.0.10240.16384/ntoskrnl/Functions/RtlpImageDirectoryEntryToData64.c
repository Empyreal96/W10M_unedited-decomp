// RtlpImageDirectoryEntryToData64 
 
int __fastcall RtlpImageDirectoryEntryToData64(unsigned int a1, int a2, unsigned int a3, _DWORD *a4, int a5, int *a6)
{
  unsigned int v8; // r2
  int v9; // r0

  if ( a3 >= *(_DWORD *)(a5 + 132) )
    return -1073741811;
  v8 = *(_DWORD *)(a5 + 8 * (a3 + 17));
  __dmb(0xBu);
  if ( !v8 )
    return -1073741822;
  if ( a1 < MmHighestUserAddress && v8 + a1 >= MmHighestUserAddress )
    return -1073741811;
  *a4 = *(_DWORD *)(a5 + 8 * a3 + 140);
  if ( a2 || v8 < *(_DWORD *)(a5 + 84) )
  {
    *a6 = v8 + a1;
  }
  else
  {
    v9 = RtlAddressInSectionTable(a5, a1, v8);
    *a6 = v9;
    if ( !v9 )
      return -1073741811;
  }
  return 0;
}
