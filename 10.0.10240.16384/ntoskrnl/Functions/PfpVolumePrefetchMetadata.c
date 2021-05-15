// PfpVolumePrefetchMetadata 
 
int __fastcall PfpVolumePrefetchMetadata(_DWORD *a1, int a2)
{
  int v3; // r8
  int v4; // r10
  _DWORD *v5; // r7
  unsigned int v6; // lr
  int v7; // r9
  int v8; // r3
  int v9; // r2
  unsigned int v10; // r6
  int v11; // r1
  int v12; // r2
  unsigned int v14; // r7
  int v15; // r6
  int v16; // r4
  int v17; // r4
  int v18; // r3
  int v19; // r2
  int v20; // r2
  unsigned int v21; // r1
  unsigned int v22; // r6
  int v23; // r9
  int v24; // lr
  unsigned int *v25; // r3
  unsigned int v26; // r0
  unsigned int v27; // r4
  unsigned __int64 v28; // kr08_8
  _DWORD *v29; // r3
  unsigned int v30; // r2
  int v31; // r3
  int v32; // r2
  int v33; // r2
  int v34; // r0
  int v35; // r0
  unsigned int v37; // [sp+1Ch] [bp-6Ch]
  int v38; // [sp+20h] [bp-68h]
  unsigned int v39; // [sp+24h] [bp-64h]
  int v40; // [sp+28h] [bp-60h] BYREF
  int v41[2]; // [sp+30h] [bp-58h] BYREF
  int v42[2]; // [sp+38h] [bp-50h] BYREF
  char v43[8]; // [sp+40h] [bp-48h] BYREF
  char v44[8]; // [sp+48h] [bp-40h] BYREF
  int v45[14]; // [sp+50h] [bp-38h] BYREF

  v3 = 0;
  v38 = 0;
  v4 = a2;
  KeQueryTickCount(v42);
  v5 = (_DWORD *)a1[3];
  v42[0] = ((__int64)((unsigned int)v42[0] * (unsigned __int64)MEMORY[0xFFFF9004]) >> 24)
         + ((MEMORY[0xFFFF9004] * v42[1]) << 8);
  v6 = *(unsigned __int16 *)(*a1 + 30);
  v39 = v6;
  v7 = *(_DWORD *)(*a1 + 32) + 32 * v4;
  *v5 = 3;
  v8 = *a1;
  v41[0] = v7;
  v9 = *(_DWORD *)(v8 + 28) & 7;
  v5[2] = v9 | (8 * (v6 & 7));
  if ( (*(_DWORD *)(*a1 + 56) & 4) != 0 )
    MmQueryMemoryListInformation((int)(a1 + 6), 0x58u, v9, &v40);
  v10 = 0;
  if ( (*(_DWORD *)(v7 + 12) & 0xFFFFFFFE) != 0 )
  {
    while ( 1 )
    {
      v5[1] = 0;
      if ( v10 >= *(_DWORD *)(v7 + 12) >> 1 )
        break;
      v11 = 32 * v10;
      do
      {
        ++v10;
        v12 = v11 + *(_DWORD *)(v7 + 16);
        v11 += 32;
        if ( (*(_DWORD *)v12 & 0x10) != 0 )
          v3 = v12;
        if ( *(_QWORD *)(v12 + 8) )
          return sub_80EE60();
      }
      while ( v10 < *(_DWORD *)(v7 + 12) >> 1 );
      v38 = v3;
      if ( !v5[1] )
        break;
      v18 = *(_DWORD *)(*a1 + 52);
      if ( v18 && *(_DWORD *)(v18 + 4)
        || ((*(_DWORD *)(*a1 + 56) >> 2) & 1) != 0
        && ((v19 = a1[5], *(_DWORD *)(v19 + 44))
         || (*(_DWORD *)(v19 + 40) & 4) != 0
         || !PfpAvailablePagesForPrefetch(a1 + 6, v6)) )
      {
LABEL_31:
        v17 = -1073741248;
        goto LABEL_18;
      }
      v17 = NtFsControlFile(*(_DWORD *)(a1[2] + 40 * a2), 0, 0, 0, (int)v43, 590112, (int)v5);
      if ( (*(_DWORD *)(*a1 + 56) & 4) != 0 )
        PfpUpdateRepurposedByPrefetch((int)(a1 + 6), v5[1], v20);
      if ( v17 < 0 )
        goto LABEL_18;
      if ( v17 == 259 )
        KeBugCheckEx(401, 5552, 0, 0, 0);
      if ( v10 >= *(_DWORD *)(v7 + 12) >> 1 )
        break;
      v6 = v39;
    }
    v4 = a2;
    if ( v3 )
    {
      v21 = 0;
      v22 = 0;
      v37 = 0;
      ++*(_DWORD *)(*a1 + 64);
      v40 = 0;
      if ( *(_DWORD *)(v3 + 16) )
      {
        while ( 1 )
        {
          v5[1] = 0;
          if ( v22 >= *(_DWORD *)(v3 + 16) )
            break;
          v23 = v40;
          v24 = 16 * v22;
          do
          {
            v25 = (unsigned int *)(*(_DWORD *)(v3 + 20) + v24);
            v27 = v25[1];
            v26 = *v25;
            v28 = *(_QWORD *)v25 + v25[2];
            if ( *(_QWORD *)v25 < __PAIR64__(v23, v21) )
            {
              v26 = v21;
              v27 = v23;
            }
            if ( __PAIR64__(v27, v26) < v28 )
            {
              while ( 1 )
              {
                v29 = &v5[2 * v5[1]];
                v29[4] = (v27 << 22) | (v26 >> 10);
                v29[5] = v27 >> 10;
                v30 = v5[1] + 1;
                v5[1] = v30;
                if ( v30 >= a1[4] )
                  break;
                v27 = (__PAIR64__(v27, v26) + 4096) >> 32;
                v26 += 4096;
                if ( __PAIR64__(v27, v26) >= v28 )
                {
                  v21 = v37;
                  goto LABEL_42;
                }
              }
              v23 = (__PAIR64__(v27, v26) + 4096) >> 32;
              v21 = v26 + 4096;
              v40 = v23;
              v37 = v26 + 4096;
            }
LABEL_42:
            v3 = v38;
            if ( v5[1] >= a1[4] )
              break;
            ++v22;
            v24 += 16;
          }
          while ( v22 < *(_DWORD *)(v38 + 16) );
          v7 = v41[0];
          if ( !v5[1] )
          {
            v4 = a2;
            break;
          }
          v31 = *(_DWORD *)(*a1 + 52);
          if ( v31 && *(_DWORD *)(v31 + 4) )
            goto LABEL_31;
          if ( ((*(_DWORD *)(*a1 + 56) >> 2) & 1) != 0 )
          {
            v32 = a1[5];
            if ( *(_DWORD *)(v32 + 44) || (*(_DWORD *)(v32 + 40) & 4) != 0 || !PfpAvailablePagesForPrefetch(a1 + 6, v39) )
              goto LABEL_31;
          }
          v4 = a2;
          v17 = NtFsControlFile(*(_DWORD *)(a1[2] + 40 * a2), 0, 0, 0, (int)v43, 590112, (int)v5);
          if ( (*(_DWORD *)(*a1 + 56) & 4) != 0 )
            PfpUpdateRepurposedByPrefetch((int)(a1 + 6), v5[1], v33);
          if ( v17 < 0 )
            goto LABEL_18;
          if ( v17 == 259 )
            KeBugCheckEx(401, 5653, 0, 0, 0);
          if ( v22 >= *(_DWORD *)(v38 + 16) )
            break;
          v21 = v37;
        }
      }
    }
  }
  v14 = 0;
  if ( (*(_DWORD *)(v7 + 12) & 0xFFFFFFFE) != 0 )
  {
    v15 = 0;
    do
    {
      v16 = *(_DWORD *)(v7 + 16);
      if ( (*(_DWORD *)(v15 + v16) & 2) != 0 )
      {
        v34 = PfpFileSetupObjectAttributes((int)a1, (_DWORD *)(v15 + v16), v4, (int)v44, v45, v41);
        v35 = PfpPrefetchDirectoryStream(v34, a1[2] + 40 * v4, v15 + v16);
        v17 = v35;
        if ( v35 < 0 )
        {
          if ( v35 == -1073741248 )
            goto LABEL_18;
        }
        else
        {
          ++*(_DWORD *)(*a1 + 64);
        }
      }
      ++v14;
      v15 += 32;
    }
    while ( v14 < *(_DWORD *)(v7 + 12) >> 1 );
  }
  v17 = 0;
LABEL_18:
  KeQueryTickCount(v41);
  *(_DWORD *)(*a1 + 84) += ((__int64)((unsigned int)v41[0] * (unsigned __int64)MEMORY[0xFFFF9004]) >> 24)
                         + ((MEMORY[0xFFFF9004] * v41[1]) << 8)
                         - v42[0];
  return v17;
}
