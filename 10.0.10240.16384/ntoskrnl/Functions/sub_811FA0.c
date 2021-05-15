// sub_811FA0 
 
int sub_811FA0()
{
  unsigned int v0; // r1
  void **v1; // r6
  char *v2; // lr
  _DWORD *v3; // r0
  unsigned int v4; // r0
  void **v5; // r6
  int v6; // lr
  unsigned int v7; // r4
  unsigned int v8; // r2
  int v9; // r6
  int *v10; // r0
  char *v11; // r9
  int *v12; // r6
  int *v13; // r10
  unsigned int v14; // r8
  int v15; // r4
  int v16; // r7
  int *v17; // r10
  int v18; // r4
  int v19; // r1
  unsigned int v20; // r0
  unsigned int v21; // r1
  void **v22; // r5
  int v23; // r3
  int v24; // r3
  int v25; // r0
  int v26; // r1
  _DWORD *v27; // r1
  char *v28; // r5
  int v29; // r4
  int v30; // r0
  unsigned int v31; // r4
  int v32; // r10
  void **v33; // lr
  _DWORD *v34; // r3
  int v35; // r2
  char *v36; // r2
  unsigned int v37; // r6
  int *v38; // r5
  _DWORD *v39; // r3
  int *v40; // r10
  _DWORD *v41; // r2
  unsigned int v42; // r4
  int v43; // r3
  unsigned int v44; // r3
  int v45; // r1
  unsigned int v46; // r0
  _DWORD *v47; // r10
  int v48; // r6
  unsigned int v49; // r0
  unsigned int v50; // r1
  int v51; // r4
  int v52; // lr
  unsigned int v53; // r3
  int v54; // r2
  unsigned int v55; // r2
  unsigned int v56; // r2
  int v57; // r4
  int v58; // r1
  int v59; // r3
  unsigned int v60; // r8
  _DWORD *v61; // r3
  int v62; // r1
  unsigned int v63; // r2
  char v64; // r3
  unsigned int v65; // r4
  unsigned int v66; // r3
  unsigned int v67; // r2
  int v68; // r0
  unsigned int v69; // r1
  __int16 v70; // r3
  char *v72; // [sp+0h] [bp-48h]
  int v73; // [sp+0h] [bp-48h]
  char *v74; // [sp+0h] [bp-48h]
  unsigned int v75; // [sp+0h] [bp-48h]
  int v76; // [sp+4h] [bp-44h]
  unsigned int v77; // [sp+8h] [bp-40h]
  _DWORD *v78; // [sp+8h] [bp-40h]
  int v79; // [sp+Ch] [bp-3Ch]
  unsigned int v80; // [sp+14h] [bp-34h]
  int v81; // [sp+18h] [bp-30h]
  unsigned int v82; // [sp+1Ch] [bp-2Ch]
  unsigned int v83; // [sp+20h] [bp-28h]
  int v84; // [sp+20h] [bp-28h]
  int (__fastcall *v85)(int); // [sp+44h] [bp-4h]

  ExfAcquirePushLockExclusiveEx(v17, v15, (unsigned int)v17);
  if ( v15 )
    *(_BYTE *)(v15 + 14) |= 1u;
  v17[1] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( PpmPlatformStates && !*(_BYTE *)(v16 + 28) )
  {
    v18 = -1073741431;
    goto LABEL_37;
  }
  v7 = *(_DWORD *)(v16 + 4);
  if ( !v7 )
    goto LABEL_36;
  v8 = *(_DWORD *)(v16 + 8);
  if ( v8 > v7 )
    goto LABEL_36;
  v60 = KeNumberProcessors_0;
  v20 = 0;
  v79 = KeNumberProcessors_0;
  if ( v8 )
  {
    v19 = v16 + 32;
    while ( *(_DWORD *)(v19 + 16) <= (unsigned int)KeNumberProcessors_0 )
    {
      ++v20;
      v19 += 32;
      if ( v20 >= v8 )
        goto LABEL_104;
    }
    goto LABEL_36;
  }
LABEL_104:
  v25 = 0;
  v26 = 0;
  if ( v8 )
  {
    v21 = 0;
    if ( KeNumberProcessors_0 )
    {
      v22 = &KiProcessorBlock;
      do
      {
        v23 = (int)(v21 >= KeNumberProcessors_0 ? 0 : *v22);
        v24 = *(_DWORD *)(v23 + 2944);
        if ( !v24 )
          goto LABEL_36;
        ++v21;
        ++v22;
        v25 += *(_DWORD *)(v24 + 28);
      }
      while ( v21 < KeNumberProcessors_0 );
    }
    v25 = (v25 + KeNumberProcessors_0) * v8;
    v26 = v8 * KeNumberProcessors_0;
  }
  if ( !PpmPlatformStates )
  {
    v80 = ((((v7 << 8) + 131) & 0xFFFFFFFC) + 12 * v26 + 3) & 0xFFFFFFFC;
    v77 = (v80 + 16 * v25 + 7) & 0xFFFFFFF8;
    v82 = (v77 + 992 * v7 + 31) & 0xFFFFFFF8;
    v83 = (4 * v7 + 15) & 0xFFFFFFF8;
    v9 = (v82 + v83 * KeNumberProcessors_0 + 3) & 0xFFFFFFFC;
    v73 = v9;
    if ( PpmIdleVetoList )
      v9 += 16 * *(_DWORD *)PpmIdleVetoList * v7;
    v10 = (int *)ExAllocatePoolWithTag(512, v9, 1766674512);
    v38 = v10;
    v76 = (int)v10;
    if ( !v10 )
    {
      v18 = -1073741670;
      goto LABEL_37;
    }
    memset(v10, 0, v9);
    *v38 = v7;
    v38[1] = *(_DWORD *)(v16 + 8) != 0;
    v38[2] = v60;
    v38[4] = *(_DWORD *)(v16 + 12);
    v38[5] = *(_DWORD *)(v16 + 16);
    v38[6] = *(_DWORD *)(v16 + 20);
    v38[7] = *(_DWORD *)(v16 + 24);
    v38[8] = (int)v38 + v77;
    *(int *)((char *)v38 + v77 + 4) = v7;
    PpmResetPlatformIdleAccounting((__int64 *)((char *)v38 + v77));
    if ( *(_DWORD *)(v16 + 4) )
    {
      v11 = (char *)v38 + v73;
      v12 = v38 + 32;
      v13 = (int *)PpmIdleVetoList;
      v14 = 0;
      do
      {
        *((_BYTE *)v12 + 29) = 1;
        KeQueryActiveProcessorAffinity(v12 + 9);
        v12[3] = (int)(v12 + 3);
        v12[4] = (int)(v12 + 3);
        if ( v13 )
        {
          v12[5] = *v13;
          v12[6] = (int)v11;
          v11 += 16 * *v13;
        }
        ++v14;
        v12 += 64;
      }
      while ( v14 < *(_DWORD *)(v16 + 4) );
      v38 = (int *)v76;
      v60 = v79;
      v17 = &PpmIdlePolicyLock;
    }
    v37 = 0;
    v36 = (char *)v38 + v80;
    v74 = (char *)v38 + v80;
    if ( *(_DWORD *)(v16 + 8) )
    {
      v27 = v38 + 32;
      v28 = (char *)v38 + (((v7 << 8) + 131) & 0xFFFFFFFC);
      v29 = 3 * v60;
      v30 = v16 + 32;
      do
      {
        v27[12] = *(_DWORD *)(v30 + 20);
        v27[13] = *(_DWORD *)(v30 + 24);
        v27[14] = v28;
        v28 += 4 * v29;
        v31 = 0;
        v27[8] = v60;
        if ( v60 )
        {
          v32 = 0;
          v33 = &KiProcessorBlock;
          do
          {
            v78 = (_DWORD *)(v27[14] + v32);
            if ( v31 >= KeNumberProcessors_0 )
              v34 = 0;
            else
              v34 = *v33;
            v35 = v34[736];
            v32 += 12;
            *v78 = v31++;
            ++v33;
            v78[1] = *(_DWORD *)(v35 + 28);
            v78[2] = v74;
            v36 = &v74[16 * *(_DWORD *)(v35 + 28)];
            v74 = v36;
          }
          while ( v31 < v60 );
          v16 = v81;
        }
        ++v37;
        v30 += 32;
        v27 += 64;
        v29 = 3 * v60;
      }
      while ( v37 < *(_DWORD *)(v16 + 8) );
      v38 = (int *)v76;
      v17 = &PpmIdlePolicyLock;
    }
    v0 = 0;
    if ( v60 )
    {
      v1 = &KiProcessorBlock;
      v2 = (char *)v38 + v82;
      do
      {
        if ( v0 >= KeNumberProcessors_0 )
          v39 = 0;
        else
          v39 = *v1;
        v3 = (_DWORD *)v39[736];
        v42 = 0;
        v3[54] = v2;
        v3[57] = *(_DWORD *)(v16 + 8);
        v3[58] = v36;
        v44 = *(_DWORD *)(v16 + 8);
        v36 += 16 * v44;
        v72 = v36;
        if ( v44 )
        {
          v40 = v38 + 32;
          do
          {
            v41 = (_DWORD *)(v3[58] + 16 * (v44 - v42 - 1));
            v41[1] = v42++;
            v41[2] = v40[8];
            v43 = v40[14];
            v40 += 64;
            v41[3] = v43;
            v44 = *(_DWORD *)(v16 + 8);
          }
          while ( v42 < v44 );
          v36 = v72;
        }
        ++v0;
        ++v1;
        v2 += v83;
      }
      while ( v0 < v60 );
      v17 = &PpmIdlePolicyLock;
    }
    goto LABEL_93;
  }
  v38 = (int *)PpmPlatformStates;
  v76 = PpmPlatformStates;
  if ( *(_DWORD *)(PpmPlatformStates + 8) != KeNumberProcessors_0
    || *(_DWORD *)PpmPlatformStates != v7
    || *(_DWORD *)(PpmPlatformStates + 4) != 1 )
  {
LABEL_36:
    v18 = -1073741811;
    goto LABEL_37;
  }
LABEL_93:
  v55 = 0;
  v75 = 0;
  if ( *(_DWORD *)(v16 + 8) )
  {
    v47 = v38 + 32;
    v48 = v16 + 32;
    do
    {
      v49 = 0;
      *v47 = *(_DWORD *)(v48 + 8);
      v47[1] = *(_DWORD *)(v48 + 12);
      if ( *(_DWORD *)(v48 + 16) )
      {
        do
        {
          v50 = 0;
          v51 = *(_DWORD *)(v48 + 28) + 8 * v49;
          v52 = v47[14] + 12 * *(_DWORD *)v51;
          v53 = *(_DWORD *)(v52 + 4);
          if ( v53 )
          {
            do
            {
              v54 = *(_DWORD *)(v52 + 8) + 16 * (v53 - v50 - 1);
              *(_DWORD *)v54 = 0;
              *(_DWORD *)(v54 + 4) = 0;
              *(_DWORD *)(v54 + 8) = 0;
              *(_DWORD *)(v54 + 12) = 0;
              *(_DWORD *)(v54 + 4) = v50;
              if ( !*(_BYTE *)(v48 + 4) && v50 == *(unsigned __int8 *)(v48 + 5) )
                *(_BYTE *)(v54 + 1) = 1;
              if ( v50 >= *(unsigned __int8 *)(v51 + 4) )
              {
                *(_BYTE *)(v54 + 2) = 1;
                if ( !*(_BYTE *)(v51 + 6) )
                  *(_BYTE *)v54 = 1;
              }
              v53 = *(_DWORD *)(v52 + 4);
              ++v50;
            }
            while ( v50 < v53 );
          }
          ++v49;
        }
        while ( v49 < *(_DWORD *)(v48 + 16) );
        v55 = v75;
      }
      if ( *(_BYTE *)(v48 + 4) )
      {
        if ( *(_BYTE *)(v48 + 3) || *(_WORD *)v48 || (v56 = *(unsigned __int8 *)(v48 + 2), v56 >= KeNumberProcessors_0) )
          v56 = -1;
        v57 = v47[14] + 12 * v56;
        memset(*(_BYTE **)(v57 + 8), 0, 16 * *(_DWORD *)(v57 + 4));
        v58 = *(unsigned __int8 *)(v48 + 5);
        v59 = *(_DWORD *)(v57 + 8) + 16 * (*(_DWORD *)(v57 + 4) - v58 - 1);
        v55 = v75;
        *(_DWORD *)(v59 + 4) = v58;
        *(_BYTE *)(v59 + 1) = 1;
      }
      ++v55;
      v48 += 32;
      v75 = v55;
      v47 += 64;
    }
    while ( v55 < *(_DWORD *)(v16 + 8) );
    v38 = (int *)v76;
    v60 = v79;
    v17 = &PpmIdlePolicyLock;
  }
  v4 = 0;
  if ( v60 )
  {
    v5 = &KiProcessorBlock;
    do
    {
      if ( v4 >= KeNumberProcessors_0 )
        v61 = 0;
      else
        v61 = *v5;
      v6 = v61[736];
      v65 = 0;
      v66 = *(_DWORD *)(v6 + 228);
      if ( v66 )
      {
        v62 = v16 + 32;
        do
        {
          v84 = *(_DWORD *)(v6 + 232) + 16 * (v66 - v65 - 1);
          if ( !*(_BYTE *)(v62 + 4) )
            goto LABEL_70;
          if ( *(_BYTE *)(v62 + 3)
            || *(_WORD *)v62
            || (v63 = *(unsigned __int8 *)(v62 + 2), v63 >= KeNumberProcessors_0) )
          {
            v63 = -1;
          }
          if ( v63 == v4 )
LABEL_70:
            v64 = 1;
          else
            v64 = 0;
          ++v65;
          v62 += 32;
          *(_BYTE *)(v84 + 1) = v64;
          v66 = *(_DWORD *)(v6 + 228);
        }
        while ( v65 < v66 );
      }
      ++v4;
      ++v5;
    }
    while ( v4 < v60 );
  }
  if ( !PpmPlatformStates )
    PpmEnableCoordinatedIdleStates(v38, 0);
  v18 = 0;
LABEL_37:
  v17[1] = 0;
  __pld(v17);
  v45 = *v17;
  if ( (*v17 & 0xFFFFFFF0) <= 0x10 )
    v46 = 0;
  else
    v46 = v45 - 16;
  if ( (v45 & 2) != 0 )
    goto LABEL_79;
  __dmb(0xBu);
  do
    v67 = __ldrex((unsigned int *)v17);
  while ( v67 == v45 && __strex(v46, (unsigned int *)v17) );
  if ( v67 != v45 )
LABEL_79:
    ExfReleasePushLock(v17, v45);
  v68 = KeAbPostRelease((unsigned int)v17);
  v69 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v70 = *(_WORD *)(v69 + 0x134) + 1;
  *(_WORD *)(v69 + 308) = v70;
  if ( !v70 && *(_DWORD *)(v69 + 100) != v69 + 100 && !*(_WORD *)(v69 + 310) )
    KiCheckForKernelApcDelivery(v68);
  return v85(v18);
}
