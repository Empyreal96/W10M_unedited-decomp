// CcFetchDataForRead 
 
int __fastcall CcFetchDataForRead(int a1, int *a2, unsigned int a3, int a4, _DWORD *a5, int *a6, int a7)
{
  int v7; // r7
  int v10; // r6
  unsigned int v11; // r1
  unsigned int v12; // r4
  unsigned int v13; // r2
  unsigned int v14; // r6
  unsigned __int64 v15; // kr20_8
  unsigned int v16; // r4
  int v18; // [sp+20h] [bp-28h]

  v7 = a2[1];
  v10 = *a2;
  v12 = (*(_QWORD *)a2 + (unsigned __int64)a3) >> 32;
  v11 = *a2 + a3;
  v13 = (v11 + 4095) & 0xFFFFF000;
  v14 = v10 & 0xFFFFF000;
  v15 = __PAIR64__(v12, 4095) + v11;
  v16 = 0x40000 - (((v14 & 0x3FFFF) + *a6) & 0x3FFFF);
  if ( v16 >= v13 - v14 )
    v16 = v13 - v14;
  v18 = *a6;
  if ( !MmHardFaultBytesRequired(a1, HIDWORD(v15), v14, v7, v16) )
    goto LABEL_4;
  if ( a4 )
  {
    MmPrefetchForCacheManager(a1, a7, v14, v7);
    *a5 = 1;
LABEL_4:
    MmCheckCachedPageStates(v18 + (v14 & 0x3FFFF), v16, 0, 0);
    return 1;
  }
  return 0;
}
