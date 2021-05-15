// CmpParseCacheLookupByHash 
 
int __fastcall CmpParseCacheLookupByHash(int a1, int a2, int a3, unsigned int *a4, unsigned int a5, int a6, int a7, _DWORD *a8)
{
  int v8; // lr
  int v9; // r2
  int v10; // r6
  unsigned int v13; // r8
  unsigned int v14; // t1
  _DWORD *v15; // r5
  int v16; // r4
  int v17; // r2
  int v18; // r0

  v8 = a3;
  v9 = a1;
  v10 = 0;
  if ( !a5 )
    return -1073741772;
  while ( 1 )
  {
    v14 = *a4++;
    v13 = v14;
    v15 = *(_DWORD **)(v9
                     + 4
                     * (((unsigned __int8)(-93 * (v14 ^ (v14 >> 9))) ^ (unsigned __int8)((101027 * (v14 ^ (v14 >> 9))) >> 9)) & 0x1F)
                     + 4);
    if ( v15 )
      break;
LABEL_6:
    if ( ++v10 >= a5 )
      return -1073741772;
  }
  while ( 1 )
  {
    if ( v15[5] != v13 || v15[6] != a2 )
      goto LABEL_4;
    if ( CmpParseCacheCompareUnicodeStrings(v15 + 3, v8, a6, a7) )
      break;
    v8 = a3;
LABEL_4:
    v15 = (_DWORD *)*v15;
    if ( !v15 )
    {
      v9 = a1;
      goto LABEL_6;
    }
  }
  v17 = v15[7];
  if ( (*(_DWORD *)(v17 + 4) & 0x20000) != 0 )
    return -1073741444;
  if ( CmpIsHiveLoadingOnOtherThread(*(_DWORD *)(v17 + 20)) )
    return -1073741772;
  v18 = v15[7];
  if ( (*(_DWORD *)(v18 + 4) & 0x40000) != 0 )
    return -1073740763;
  v16 = 0;
  if ( !CmpReferenceKeyControlBlockUnsafe(v18) )
    return -1073741670;
  *a8 = v15[7];
  return v16;
}
