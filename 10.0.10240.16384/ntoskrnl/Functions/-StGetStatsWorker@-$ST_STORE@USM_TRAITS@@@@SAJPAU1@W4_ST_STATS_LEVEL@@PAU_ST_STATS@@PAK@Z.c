// -StGetStatsWorker@-$ST_STORE@USM_TRAITS@@@@SAJPAU1@W4_ST_STATS_LEVEL@@PAU_ST_STATS@@PAK@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StGetStatsWorker(int a1, int a2, int a3, unsigned int *a4)
{
  unsigned int v4; // r5
  int result; // r0
  unsigned int v10; // r8
  int v11; // r1
  int v12; // r3
  int v13; // r5
  int v14; // r2
  int v15; // r3
  int v16; // r2
  int v17; // r2
  int v18; // r2
  int v19; // r1
  int v20; // r2
  int v21; // r3
  int v22; // r1
  int v23; // r0
  int v24; // r5
  int v25; // r9
  int v26; // r1
  int v27; // r0
  int v28; // r1
  _WORD *v29; // r2
  unsigned int v30; // r1
  _WORD *v31; // r0
  int v32; // r3
  unsigned int v33; // r5
  int v34; // r0
  unsigned int v35; // r4
  unsigned int v36; // [sp+0h] [bp-28h] BYREF
  int v37; // [sp+4h] [bp-24h]
  unsigned int *v38; // [sp+8h] [bp-20h]

  v36 = a2;
  v37 = a3;
  v38 = a4;
  v4 = *a4;
  v36 = 0;
  if ( a2 >= 4 )
    return -1073741811;
  if ( a2 )
  {
    switch ( a2 )
    {
      case 1:
        v10 = 1528;
        break;
      case 2:
        v10 = 4 * *(_DWORD *)(a1 + 12) - a3 + ((a3 + 1529) & 0xFFFFFFFE);
        break;
      case 3:
        v11 = *(_DWORD *)(a1 + 12);
        v12 = 512;
        if ( (unsigned int)(*(_DWORD *)(a1 + 152) + 1) <= 0x200 )
          v12 = *(_DWORD *)(a1 + 152) + 1;
        v36 = ((unsigned int)(v12 + 7) >> 3) * v11;
        v10 = ((((a3 + 1529) & 0xFFFFFFFE) + 4 * v11 + 7) & 0xFFFFFFF8) - a3 + 12 + v36;
        break;
      default:
        v10 = -1;
        break;
    }
  }
  else
  {
    v10 = 180;
  }
  if ( v4 < v10 )
  {
    result = -1073741789;
LABEL_40:
    *a4 = v10;
    return result;
  }
  *(_BYTE *)a3 = 10;
  v13 = a3 + 28;
  v14 = ((unsigned __int16)*(_DWORD *)a3 ^ (unsigned __int16)((_WORD)a2 << 8)) & 0xF00;
  v15 = *(_DWORD *)a3;
  v38 = (unsigned int *)(a1 + 56);
  v16 = v14 ^ v15;
  *(_DWORD *)a3 = v16;
  v17 = v16 ^ ((unsigned __int16)v16 ^ (unsigned __int16)(*(_WORD *)a1 << 12)) & 0xF000;
  *(_DWORD *)a3 = v17;
  v18 = v17 ^ (v17 ^ (*(_DWORD *)a1 << 8)) & 0x10000;
  *(_DWORD *)a3 = v18;
  v19 = (v18 ^ (*(_DWORD *)a1 << 7)) & 0x20000 ^ v18;
  *(_DWORD *)a3 = v19;
  v20 = (v19 ^ (*(_DWORD *)(a1 + 1684) << 21)) & 0x3FFC0000 ^ v19;
  *(_DWORD *)a3 = v20;
  v21 = *(_DWORD *)(a1 + 128);
  *(_DWORD *)(a3 + 4) = v10;
  *(_DWORD *)a3 = (v20 ^ (v21 << 12)) & 0x40000000 ^ v20;
  *(_WORD *)(a3 + 8) = *(_WORD *)(a1 + 1656);
  *(_DWORD *)(a3 + 12) = *(_DWORD *)(a1 + 8);
  *(_DWORD *)(a3 + 16) = *(_DWORD *)(a1 + 184) + *(_DWORD *)(a1 + 952);
  *(_DWORD *)(a3 + 20) = *(_DWORD *)(a1 + 12);
  *(_DWORD *)(a3 + 24) = 16;
  memset((_BYTE *)(a3 + 28), 0, 76);
  *(_DWORD *)(a3 + 28) = *(_DWORD *)(a1 + 184);
  *(_DWORD *)(a3 + 32) = *(_DWORD *)(a1 + 60);
  *(_DWORD *)(a3 + 36) = RtlNumberOfClearBits((_DWORD *)(a1 + 176));
  if ( *(_BYTE *)(a1 + 128) )
    v22 = 1;
  else
    v22 = 8;
  v23 = a1 + 56 - v13;
  do
  {
    *(_DWORD *)(v13 + 12) = *(_DWORD *)(v23 + v13 + 684);
    *(_DWORD *)(v13 + 16) = *(_DWORD *)(v23 + v13 + 688);
    v13 += 8;
    --v22;
  }
  while ( v22 );
  v24 = a3 + 104;
  v25 = a1 + 824;
  memset((_BYTE *)(a3 + 104), 0, 76);
  *(_DWORD *)(a3 + 104) = *(_DWORD *)(a1 + 952);
  *(_DWORD *)(a3 + 108) = *(_DWORD *)(a1 + 828);
  *(_DWORD *)(a3 + 112) = RtlNumberOfClearBits((_DWORD *)(a1 + 944));
  if ( *(_BYTE *)(a1 + 896) )
    v26 = 1;
  else
    v26 = 8;
  v27 = v25 - v24;
  do
  {
    *(_DWORD *)(v24 + 12) = *(_DWORD *)(v27 + v24 + 684);
    *(_DWORD *)(v24 + 16) = *(_DWORD *)(v27 + v24 + 688);
    v24 += 8;
    --v26;
  }
  while ( v26 );
  if ( !a2 )
    goto LABEL_39;
  ST_STORE<SM_TRAITS>::StCopyIoStats((unsigned int *)(a3 + 180), a1 + 1832);
  StLcBucketsCopy(a3 + 1464, v28, *(_DWORD *)(a1 + 3136), *(_DWORD *)(a1 + 3132));
  if ( a2 == 1 )
    goto LABEL_39;
  v29 = *(_WORD **)(a1 + 44);
  v30 = (a3 + 1529) & 0xFFFFFFFE;
  v31 = &v29[*(_DWORD *)(a1 + 12)];
  while ( v29 < v31 )
  {
    *(_WORD *)v30 = *v29 & 0x1FFF;
    if ( *(_BYTE *)(a1 + 128) )
      LOBYTE(v32) = 0;
    else
      v32 = (unsigned __int16)*v29 >> 13;
    *(_BYTE *)(v30 + 2) = v32;
    ++v29;
    v30 += 4;
  }
  if ( a2 == 2 )
    goto LABEL_39;
  v33 = (((a3 + 1529) & 0xFFFFFFFE) + 4 * *(_DWORD *)(a3 + 20) + 7) & 0xFFFFFFF8;
  memset((_BYTE *)(v33 + 12), 0, v36);
  v34 = (int)v38;
  v35 = *(_DWORD *)(a1 + 8) >> 9;
  if ( v35 <= 0x10 )
    v35 = 16;
  *(_DWORD *)(v33 + 8) = v35;
  result = ST_STORE<SM_TRAITS>::StDmGetStatsBitmap(v34, v35 >> 4, v33 + 12, &v36);
  if ( result >= 0 )
  {
    *(_DWORD *)v33 = v36;
    *(_DWORD *)(v33 + 4) = v37;
    result = ST_STORE<SM_TRAITS>::StDmGetStatsBitmap(v25, v35 >> 4, v33 + 12, &v36);
    if ( result >= 0 )
    {
LABEL_39:
      result = 0;
      goto LABEL_40;
    }
  }
  return result;
}
