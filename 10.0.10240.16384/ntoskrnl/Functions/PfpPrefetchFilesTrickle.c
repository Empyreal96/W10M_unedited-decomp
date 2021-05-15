// PfpPrefetchFilesTrickle 
 
int __fastcall PfpPrefetchFilesTrickle(_DWORD *a1)
{
  _DWORD *v2; // r6
  unsigned int v3; // r8
  unsigned __int16 v4; // r1
  int v5; // r3
  int v6; // r2
  int v7; // r0
  int v8; // r4
  int v9; // r3
  unsigned int v10; // r1
  int v11; // r2
  _DWORD *v12; // r4
  int v13; // r2
  unsigned int v14; // r7
  int v15; // r2
  _DWORD *v16; // r7
  unsigned int v17; // r8
  unsigned int v18; // r9
  int v19; // r10
  int v20; // r0
  int v21; // r3
  int result; // r0
  int v23; // r2
  int v24; // r3
  int v25; // r2
  int v26; // r4
  int v27; // r3
  int v28; // r3
  int v29; // r2
  unsigned int v30; // r3
  unsigned int v31; // r3
  int v32; // r6
  _DWORD *v33; // [sp+8h] [bp-80h]
  unsigned int v34; // [sp+Ch] [bp-7Ch]
  unsigned int v35; // [sp+10h] [bp-78h]
  unsigned int v36; // [sp+18h] [bp-70h] BYREF
  int v37; // [sp+1Ch] [bp-6Ch]
  int v38; // [sp+20h] [bp-68h]
  unsigned int v39; // [sp+24h] [bp-64h]
  int v40; // [sp+28h] [bp-60h]
  int v41; // [sp+2Ch] [bp-5Ch]
  _DWORD *v42; // [sp+30h] [bp-58h] BYREF
  int v43; // [sp+34h] [bp-54h]
  int v44; // [sp+38h] [bp-50h]
  int v45; // [sp+3Ch] [bp-4Ch]
  int v46; // [sp+40h] [bp-48h]
  int v47[16]; // [sp+48h] [bp-40h] BYREF

  v2 = (_DWORD *)*a1;
  KeQueryTickCount((int *)&v36);
  v3 = 0;
  v35 = 0;
  v43 = ((__int64)(v36 * (unsigned __int64)MEMORY[0xFFFF9004]) >> 24) + ((MEMORY[0xFFFF9004] * v37) << 8);
  v4 = *(_WORD *)(*a1 + 30);
  v5 = v2[2];
  v44 = v4;
  if ( v5 )
  {
    v6 = 0;
    v7 = 0;
    v38 = 0;
    v41 = 0;
    v45 = v4 & 7;
    while ( 1 )
    {
      v8 = v7 + v2[8];
      v9 = a1[2];
      v46 = v8;
      if ( (*(_DWORD *)(v9 + v6 + 16) & 4) != 0 )
      {
        v10 = 0;
        v34 = 0;
        if ( (*(_DWORD *)(v8 + 12) & 0xFFFFFFFE) != 0 )
          break;
      }
LABEL_38:
      v31 = v2[2];
      ++v3;
      v7 += 32;
      v6 += 40;
      v35 = v3;
      v41 = v7;
      v38 = v6;
      if ( v3 >= v31 )
        goto LABEL_39;
    }
    v11 = 0;
    v40 = 0;
    while ( 1 )
    {
      v12 = (_DWORD *)(v11 + *(_DWORD *)(v8 + 16));
      v13 = *v12;
      v33 = v12;
      if ( (*v12 & 2) == 0 )
      {
        if ( v12[4] )
          break;
      }
LABEL_36:
      v8 = v46;
      ++v10;
      v30 = *(_DWORD *)(v46 + 12);
      v11 = v40 + 32;
      v34 = v10;
      v40 += 32;
      if ( v10 >= v30 >> 1 )
      {
        v6 = v38;
        v7 = v41;
        goto LABEL_38;
      }
    }
    v14 = 0;
    v39 = 0;
    while ( 1 )
    {
      if ( v14 )
      {
        if ( (v13 & 1) == 0 )
          goto LABEL_33;
      }
      else if ( (v13 & 1) != 0 )
      {
        goto LABEL_33;
      }
      PfpReadSupportInitialize(v47);
      if ( PfpFileBuildReadSupport(a1, v12, v3, v14, v47) >= 0 )
      {
        v16 = (_DWORD *)v47[0];
        v17 = 0;
        *(_DWORD *)v47[0] = v47[2];
        v18 = v16[1];
        v42 = v16;
        v19 = 0;
        v20 = MmQueryMemoryListInformation((int)(a1 + 6), 0x58u, v15, &v36);
        if ( v18 )
        {
          do
          {
            v21 = *(_DWORD *)(*a1 + 52);
            if ( v21 && *(_DWORD *)(v21 + 4) )
              return sub_80ED24(v20);
            if ( (*(_DWORD *)(*a1 + 56) & 4) != 0 )
            {
              v23 = a1[5];
              if ( *(_DWORD *)(v23 + 44) || (*(_DWORD *)(v23 + 40) & 4) != 0 )
                return sub_80ED24(v20);
            }
            v20 = PfpAvailablePagesForPrefetch(a1 + 6, v44);
            if ( !v20 )
              return sub_80ED24(v20);
            if ( v17 + 16 > v18 )
              v24 = v18 - v17;
            else
              v24 = 16;
            v16[1] = v24;
            memmove((int)(v16 + 4), (int)&v16[2 * v17 + 4], 8 * v24);
            v25 = v16[5];
            v16[4] |= *(_DWORD *)(*a1 + 28) & 7 | (8 * v45);
            v16[5] = v25;
            v26 = MmPrefetchPages(1, (int)&v42);
            v20 = PfpUpdateRepurposedByPrefetch(a1 + 6, v16[1]);
            if ( v26 < 0 )
              break;
            v27 = v16[1];
            v17 += v27;
            v19 += v27;
          }
          while ( v17 < v18 );
          v12 = v33;
        }
        LOBYTE(v14) = v39;
        v3 = v35;
        if ( v39 )
          v2[19] += v19;
        else
          v2[18] += v19;
      }
      PfpReadSupportCleanup(a1[5], v47);
      v28 = *(_DWORD *)(*a1 + 52);
      if ( v28 && *(_DWORD *)(v28 + 4)
        || (*(_DWORD *)(*a1 + 56) & 4) != 0
        && ((v29 = a1[5], *(_DWORD *)(v29 + 44)) || (*(_DWORD *)(v29 + 40) & 4) != 0) )
      {
        v32 = -1073741248;
        goto LABEL_40;
      }
      v13 = *v12;
      if ( (*v12 & 8) != 0 )
      {
LABEL_34:
        v10 = v34;
        if ( (*v12 & 8) == 0 )
          ++v2[15];
        goto LABEL_36;
      }
LABEL_33:
      v14 = (unsigned __int8)(v14 + 1);
      v39 = v14;
      if ( v14 > 1 )
        goto LABEL_34;
    }
  }
LABEL_39:
  v32 = 0;
LABEL_40:
  KeQueryTickCount((int *)&v36);
  result = v32;
  *(_DWORD *)(*a1 + 88) += ((__int64)(v36 * (unsigned __int64)MEMORY[0xFFFF9004]) >> 24)
                         + ((MEMORY[0xFFFF9004] * v37) << 8)
                         - v43;
  return result;
}
