// MiValidatePagefilePageHash 
 
int __fastcall MiValidatePagefilePageHash(int a1)
{
  int v1; // r4
  int *v2; // r9
  int v3; // r7
  unsigned int v4; // r6
  unsigned int v5; // r8
  int v6; // r5
  int *v7; // lr
  int v8; // r10
  int v9; // t1
  int v10; // r4
  unsigned int v11; // r2
  int v12; // r8
  unsigned int v13; // r3
  unsigned int v14; // r7
  int v16; // r2
  int v17; // [sp+8h] [bp-70h]
  unsigned int v18; // [sp+Ch] [bp-6Ch]
  unsigned int v19; // [sp+10h] [bp-68h]
  _DWORD v20[24]; // [sp+18h] [bp-60h]

  v1 = a1 + 152;
  if ( *(_DWORD *)(a1 + 144) )
    v1 = *(_DWORD *)(a1 + 144);
  v2 = (int *)(v1 + 28);
  v3 = 0;
  v4 = 0;
  v19 = 0;
  v5 = v1
     + 28
     + 4
     * (((((unsigned __int16)*(_DWORD *)(v1 + 24) + (unsigned __int16)*(_DWORD *)(v1 + 16)) & 0xFFFu)
       + *(_DWORD *)(a1 + 52)
       + 4095) >> 12);
  v17 = 0;
  v18 = v5;
  if ( (*(_WORD *)(v1 + 6) & 5) != 0 )
    v6 = *(_DWORD *)(v1 + 12);
  else
    v6 = MmMapLockedPagesSpecifyCache(v1, 0, 1, 0, 0, -1073741808);
  if ( (unsigned int)v2 < v5 )
  {
    v7 = MiState;
    v8 = v5 - (_DWORD)v2;
    do
    {
      v9 = *v2++;
      v10 = MmPfnDatabase + 24 * v9;
      if ( v10 != v7[1950] && (*(_DWORD *)(v10 + 12) & 0x40000000) == 0 )
      {
        if ( (v11 = (*(_DWORD *)(v10 + 8) >> 5) & 0x1F, (dword_681260 & 1) != 0)
          || v11 == 31
          || (v11 >> 3 != 3 || ((*(_DWORD *)(v10 + 8) >> 5) & 7) == 0) && v11 >> 3 != 1 )
        {
          v12 = MiComputePageHash(v10, v6, v11);
          if ( !v3 )
            v17 = *(_DWORD *)&MiSystemPartition[2 * ((*(_DWORD *)(v10 + 8) >> 2) & 1) + 1800];
          v13 = *(_DWORD *)(v10 + 8);
          if ( (v13 & 0x10) != 0 && (v14 = v13 >> 13) != 0 )
          {
            if ( v4 >= v19 )
            {
              v19 = v8 >> 2;
              if ( (unsigned int)(v8 >> 2) > 0x10 )
                return sub_5492CC();
              MiObtainPagefileHashes();
              v4 = 0;
            }
            v16 = v20[v4];
            if ( v12 == v16 || (*(_DWORD *)(v10 + 12) & 0x40000000) != 0 || v16 == 2 )
            {
              v7 = MiState;
            }
            else if ( v16 )
            {
              v7 = MiState;
              if ( byte_634580 != 1 )
              {
LABEL_39:
                ++v7[1636];
                KeBugCheckEx(26, 63, v14);
              }
            }
            else
            {
              v7 = MiState;
              if ( MiComparePageHash(v17, v14, v12) < 0 )
                goto LABEL_39;
            }
            v3 = v17;
          }
          else
          {
            v3 = 0;
            v7 = MiState;
            v17 = 0;
          }
          v5 = v18;
        }
      }
      ++v4;
      if ( v6 )
        v6 += 4096;
      v8 -= 4;
    }
    while ( (unsigned int)v2 < v5 );
  }
  return 0;
}
