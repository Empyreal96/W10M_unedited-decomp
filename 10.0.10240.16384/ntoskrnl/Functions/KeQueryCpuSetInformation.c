// KeQueryCpuSetInformation 
 
int __fastcall KeQueryCpuSetInformation(_BYTE *a1, unsigned int a2, _DWORD *a3, int a4)
{
  _DWORD *v4; // r5
  unsigned int v5; // r9
  _BYTE *v6; // r10
  int v7; // r6
  __int64 v8; // r0
  int v9; // r3
  int v10; // r2
  int v12; // r5
  int v13; // r0
  unsigned int v14; // r2
  unsigned int v15; // r10
  unsigned int v16; // r3
  int v17; // r1
  _BYTE *v18; // r9
  int v19; // r1
  char v20; // r2
  int v21; // lr
  int v22; // r2
  _BYTE *v24; // [sp+4h] [bp-64h]
  int v25; // [sp+10h] [bp-58h]
  _DWORD *v26; // [sp+14h] [bp-54h]
  unsigned int v27; // [sp+18h] [bp-50h]
  int v28; // [sp+24h] [bp-44h]
  unsigned int v29; // [sp+2Ch] [bp-3Ch]
  unsigned int v30; // [sp+30h] [bp-38h]
  __int64 v31; // [sp+34h] [bp-34h]

  v4 = a3;
  v26 = a3;
  v5 = a2;
  v27 = a2;
  v6 = a1;
  v24 = a1;
  if ( a4 )
    v7 = a4 + 880;
  else
    v7 = 0;
  do
  {
    LODWORD(v8) = RtlBeginReadTickLock(&KiCpuSetSequence);
    v31 = v8;
    v9 = KiTotalCpuSetCount;
    v29 = KiTotalCpuSetCount;
    v10 = 32 * KiTotalCpuSetCount;
    *v4 = 32 * KiTotalCpuSetCount;
    if ( v5 < 32 * v9 )
      return -1073741789;
    memset(v6, 0, v10);
    v12 = 0;
    v13 = 0;
    v14 = 0;
    v25 = 0;
    v15 = KiGroupBlock[0];
    v16 = (unsigned __int16)KiActiveGroups;
    v30 = (unsigned __int16)KiActiveGroups;
    do
    {
      if ( v15 )
      {
        v17 = __clz(__rbit(v15));
        v15 &= ~(1 << v17);
        v18 = &v24[32 * v14];
        v28 = KiGetCpuSetData(v13, v17);
        *(_DWORD *)v18 = 32;
        *((_DWORD *)v18 + 1) = 0;
        *((_DWORD *)v18 + 2) = v19 | (v12 << 16) | 0x100;
        *((_WORD *)v18 + 6) = v12;
        v18[14] = *(_BYTE *)(v28 + 1);
        v18[15] = *(_BYTE *)(v28 + 2);
        v18[16] = *(_BYTE *)(v28 + 3);
        v18[17] = *(_BYTE *)(v28 + 4);
        v18[18] = *(_BYTE *)(v28 + 5);
        v20 = 0;
        v13 = 1;
        v21 = 1 << v19;
        if ( (KiNonParkedCpuSets[v12] & (1 << v19)) == 0 )
        {
          v20 = 1;
          v18[19] |= 1u;
        }
        if ( (KiSystemAllowedCpuSets[v12] & v21) == 0 )
        {
          if ( v7 && (*(_DWORD *)(v7 + 4 * v12) & v21) != 0 )
            v20 |= 4u;
          v20 |= 0xAu;
        }
        v18[19] = v20;
        v22 = *(_DWORD *)(v28 + 12);
        *((_DWORD *)v18 + 6) = *(_DWORD *)(v28 + 8);
        *((_DWORD *)v18 + 7) = v22;
        v14 = ++v25;
      }
      else
      {
        if ( ++v12 >= v16 )
          break;
        v15 = KiGroupBlock[2 * v12];
      }
      v16 = v30;
    }
    while ( v14 < v29 );
    v4 = v26;
    v5 = v27;
    v6 = v24;
  }
  while ( !RtlTryEndReadTickLock(&KiCpuSetSequence, v31) );
  return 0;
}
