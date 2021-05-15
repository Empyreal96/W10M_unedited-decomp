// MiSelectUserAddress 
 
int __fastcall MiSelectUserAddress(int a1, int a2, int a3, int a4, int a5, _DWORD *a6, _DWORD *a7)
{
  int v9; // r2
  int result; // r0
  int v11; // r1

  *a6 = 0;
  *a7 = 0;
  v9 = MmHighestUserAddress - 0x10000;
  if ( a2 )
    return sub_802378(a1, a2, v9);
  v11 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  if ( (a1 & 0x100000) != 0 || (*(_DWORD *)(v11 + 192) & 0x200000) != 0 )
    result = MiFindEmptyAddressRangeDown(v11 + 636, a3, a4);
  else
    result = MiFindEmptyAddressRange(a3, a4, v9, a5, a7, a6);
  if ( a4 != 0x10000 )
    *a6 = 0;
  return result;
}
