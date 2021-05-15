// RtlpImageDirectoryEntryToData32 
 
int __fastcall RtlpImageDirectoryEntryToData32(unsigned int a1, int a2, unsigned int a3, _DWORD *a4, int a5, int *a6)
{
  unsigned int v8; // r2
  int v9; // r3
  int v11; // r0

  if ( a3 >= *(_DWORD *)(a5 + 116) )
    return -1073741811;
  v8 = *(_DWORD *)(a5 + 8 * (a3 + 15));
  __dmb(0xBu);
  if ( v8 )
  {
    if ( a1 < MmHighestUserAddress && v8 + a1 >= MmHighestUserAddress )
      return -1073741811;
    v9 = *(_DWORD *)(a5 + 8 * a3 + 124);
    __dmb(0xBu);
    *a4 = v9;
    if ( a2 || v8 < *(_DWORD *)(a5 + 84) )
    {
      *a6 = v8 + a1;
    }
    else
    {
      v11 = RtlAddressInSectionTable();
      *a6 = v11;
      if ( !v11 )
        return -1073741811;
    }
    return 0;
  }
  return -1073741822;
}
