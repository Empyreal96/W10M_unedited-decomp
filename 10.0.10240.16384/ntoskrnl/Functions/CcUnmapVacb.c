// CcUnmapVacb 
 
int __fastcall CcUnmapVacb(unsigned int *a1, _DWORD *a2, char a3)
{
  char v3; // r5
  int v7; // r3
  int v8; // r3
  int v9; // r0
  int v10; // r2
  int result; // r0

  v3 = 0;
  if ( (a3 & 1) != 0 && (a2[24] & 0x40) != 0 )
  {
    v3 = 1;
    goto LABEL_8;
  }
  v7 = a2[24];
  if ( (v7 & 0x200000) == 0 || (v7 & 0x200) != 0 )
    goto LABEL_8;
  v8 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v9 = a2[90];
  v10 = *(_DWORD *)(v8 + 408);
  if ( v10 != v9 )
    goto LABEL_20;
  if ( (*(_DWORD *)(v8 + 192) & 0x4000) != 0 )
    return sub_80117C();
  if ( v10 != v9 )
  {
LABEL_20:
    if ( PfCheckDeprioritizeImage(v9, (int)a2) )
      return sub_80117C();
  }
  CcUpdateSharedCacheMapFlag((int)a2, 0x200000, 0);
LABEL_8:
  if ( (a3 & 2) != 0 )
    v3 |= 2u;
  result = MmUnmapViewInSystemCache(*a1, a2[27], v3);
  if ( (a3 & 2) == 0 )
    *a1 = 0;
  return result;
}
