// PfpPrefetchFiles 
 
int __fastcall PfpPrefetchFiles(_DWORD *a1, int a2)
{
  _DWORD *v2; // r5
  _DWORD *v3; // r8
  int v4; // r10
  int v5; // r9
  int v6; // lr
  int v7; // r2
  int v8; // r0
  unsigned int v9; // r4
  int v10; // r1
  _DWORD *v11; // r3
  int v12; // r7
  _BYTE *v13; // r0
  unsigned int v14; // r6
  int v15; // r4
  unsigned int v16; // r9
  int v17; // r2
  int v18; // r0
  int v19; // r10
  unsigned int v20; // r10
  unsigned int *v21; // r4
  int v22; // r6
  int v23; // r3
  int v24; // r2
  _DWORD *v25; // r8
  _DWORD *v26; // r1
  int v27; // r3
  int v28; // r2
  int v29; // r0
  int v30; // r10
  _DWORD *v31; // r8
  unsigned int v32; // r4
  int v33; // lr
  _DWORD *v34; // r1
  _DWORD *v35; // t1
  int v36; // r3
  __int64 v37; // kr00_8
  _DWORD *v38; // r5
  int v40; // [sp+8h] [bp-58h]
  int v42; // [sp+10h] [bp-50h]
  int v43; // [sp+14h] [bp-4Ch]
  int v44; // [sp+18h] [bp-48h]
  int v45; // [sp+1Ch] [bp-44h]
  int v46; // [sp+24h] [bp-3Ch]
  _BYTE *v47; // [sp+2Ch] [bp-34h]
  _DWORD *v48; // [sp+30h] [bp-30h]
  unsigned int v49; // [sp+38h] [bp-28h] BYREF
  int v50; // [sp+3Ch] [bp-24h]

  v2 = (_DWORD *)*a1;
  v3 = a1;
  v40 = a2;
  v48 = (_DWORD *)*a1;
  v4 = a2;
  KeQueryTickCount((int *)&v49);
  v5 = v2[2];
  v6 = 0;
  v42 = 0;
  v45 = ((__int64)(v49 * (unsigned __int64)MEMORY[0xFFFF9004]) >> 24) + ((MEMORY[0xFFFF9004] * v50) << 8);
  v49 = *(_DWORD *)(*v3 + 28) & 7 | (8 * (*(_WORD *)(*v3 + 30) & 7));
  if ( !v5 )
    goto LABEL_58;
  v7 = v2[8];
  v8 = 0;
  do
  {
    if ( (*(_DWORD *)(v3[2] + v8 + 16) & 4) != 0 )
    {
      v9 = 0;
      if ( (*(_DWORD *)(v7 + 12) & 0xFFFFFFFE) != 0 )
      {
        v10 = 0;
        while ( 1 )
        {
          v11 = (_DWORD *)(*(_DWORD *)(v7 + 16) + v10);
          if ( (*v11 & 0xA) != 0 || !v11[4] )
            goto LABEL_12;
          if ( !v4 )
            break;
          if ( (*v11 & 1) != 0 )
            goto LABEL_11;
LABEL_12:
          ++v9;
          v10 += 32;
          if ( v9 >= *(_DWORD *)(v7 + 12) >> 1 )
          {
            v3 = a1;
            v42 = v6;
            goto LABEL_14;
          }
        }
        ++v2[15];
LABEL_11:
        ++v6;
        goto LABEL_12;
      }
    }
LABEL_14:
    v7 += 32;
    v8 += 40;
    --v5;
  }
  while ( v5 );
  v12 = 0;
  if ( !v6 )
  {
LABEL_58:
    v15 = -1073741275;
    goto LABEL_59;
  }
  v13 = (_BYTE *)ExAllocatePoolWithTag(1, 36 * v6, 1095984720);
  v14 = (unsigned int)v13;
  v47 = v13;
  if ( !v13 )
  {
    v15 = -1073741670;
    goto LABEL_59;
  }
  memset(v13, 0, 36 * v6);
  v16 = 0;
  if ( !v2[2] )
  {
LABEL_53:
    v15 = -1073741275;
    goto LABEL_54;
  }
  v17 = 0;
  v18 = v40;
  v43 = 0;
  v44 = 0;
  v19 = 0;
  do
  {
    v46 = v17 + v2[8];
    if ( (*(_DWORD *)(v3[2] + v19 + 16) & 4) != 0 && (*(_DWORD *)(v17 + v2[8] + 12) & 0xFFFFFFFE) != 0 )
    {
      v20 = 0;
      v21 = (unsigned int *)(v14 + 32 * v12);
      v22 = 0;
      do
      {
        v23 = *(_DWORD *)(v46 + 16);
        v24 = *(_DWORD *)(v22 + v23);
        v25 = (_DWORD *)(v22 + v23);
        if ( (v24 & 0xA) != 0 || !v25[4] || v18 && (v24 & 1) == 0 )
        {
          v3 = a1;
        }
        else
        {
          PfpReadSupportInitialize(v21);
          v26 = v25;
          v3 = a1;
          if ( PfpFileBuildReadSupport(a1, v26, v16, v40, v21) < 0 )
          {
            PfpReadSupportCleanup(a1[5], v21);
            PfpReadSupportInitialize(v21);
          }
          else
          {
            ++v12;
            v21 += 8;
          }
          v18 = v40;
        }
        ++v20;
        v22 += 32;
      }
      while ( v20 < *(_DWORD *)(v46 + 12) >> 1 );
      v14 = (unsigned int)v47;
      v2 = v48;
      v17 = v43;
      v19 = v44;
    }
    ++v16;
    v17 += 32;
    v19 += 40;
    v43 = v17;
    v44 = v19;
  }
  while ( v16 < v2[2] );
  if ( !v12 )
  {
    v4 = v40;
    goto LABEL_53;
  }
  v27 = *(_DWORD *)(*v3 + 52);
  if ( v27 && *(_DWORD *)(v27 + 4)
    || (*(_DWORD *)(*v3 + 56) & 4) != 0 && ((v28 = v3[5], *(_DWORD *)(v28 + 44)) || (*(_DWORD *)(v28 + 40) & 4) != 0) )
  {
    v15 = -1073741248;
    v4 = v40;
  }
  else
  {
    v29 = 0;
    if ( v12 > 0 )
    {
      v30 = v49;
      v31 = (_DWORD *)(v14 + 32 * v42);
      v32 = v14;
      v33 = v12;
      do
      {
        **(_DWORD **)v32 = *(_DWORD *)(v32 + 8);
        *v31++ = *(_DWORD *)v32;
        v35 = *(_DWORD **)v32;
        v32 += 32;
        v34 = v35;
        v36 = v35[1];
        v29 += v36;
        if ( v36 )
        {
          v37 = *((_QWORD *)v34 + 2);
          v34[4] = v37 | v30;
          v34[5] = HIDWORD(v37);
        }
        --v33;
      }
      while ( v33 );
      v3 = a1;
    }
    v4 = v40;
    if ( v40 )
      v2[19] += v29;
    else
      v2[18] += v29;
    v15 = MmPrefetchPages(v12, v14 + 32 * v42);
  }
LABEL_54:
  if ( v12 > 0 )
  {
    v38 = (_DWORD *)v14;
    do
    {
      PfpReadSupportCleanup(v3[5], v38);
      v38 += 8;
      --v12;
    }
    while ( v12 );
  }
  ExFreePoolWithTag(v14);
LABEL_59:
  KeQueryTickCount((int *)&v49);
  if ( v4 )
    *(_DWORD *)(*v3 + 92) += ((__int64)(v49 * (unsigned __int64)MEMORY[0xFFFF9004]) >> 24)
                           + ((MEMORY[0xFFFF9004] * v50) << 8)
                           - v45;
  else
    *(_DWORD *)(*v3 + 88) += ((__int64)(v49 * (unsigned __int64)MEMORY[0xFFFF9004]) >> 24)
                           + ((MEMORY[0xFFFF9004] * v50) << 8)
                           - v45;
  return v15;
}
