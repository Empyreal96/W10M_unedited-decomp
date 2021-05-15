// PpmInstallCoordinatedIdleStates 
 
int __fastcall PpmInstallCoordinatedIdleStates(unsigned int *a1)
{
  unsigned int *v1; // r8
  unsigned int v2; // r2
  int v3; // r0
  int v4; // r4
  unsigned int v5; // r2
  int v6; // r4
  unsigned int v7; // r5
  unsigned int v8; // r4
  int v9; // r6
  int v10; // lr
  int *v11; // r1
  unsigned int v12; // r0
  __int64 v13; // kr00_8
  unsigned int v14; // r2
  int v15; // r10
  _BYTE *v16; // r0
  int v17; // r6
  unsigned int v18; // lr
  int v19; // r0
  _DWORD *v20; // r2
  _DWORD *v21; // r1
  unsigned int v22; // r10
  unsigned int v23; // r9
  unsigned int v24; // r7
  _DWORD *v25; // lr
  _DWORD *v26; // r4
  int v27; // r2
  int v28; // r3
  int v29; // r3
  unsigned int v30; // r1
  int v31; // r2
  int v32; // r2
  unsigned int v33; // r0
  unsigned int v34; // lr
  void **v35; // r2
  unsigned int v36; // r8
  _DWORD *v37; // r3
  _DWORD *v38; // r1
  unsigned int v39; // r7
  int v40; // r9
  int v41; // lr
  int v42; // r2
  int v43; // r3
  unsigned int v44; // r2
  int *v45; // r0
  int v46; // r4
  unsigned int v47; // r1
  int v48; // r10
  unsigned int v49; // lr
  _DWORD *v50; // r8
  _DWORD *v51; // r7
  unsigned int v52; // r2
  int v53; // r1
  unsigned __int8 *v54; // r2
  int v55; // r2
  unsigned int v56; // r8
  void **v57; // r10
  _DWORD *v58; // r3
  int v59; // r3
  int v60; // r7
  unsigned int v61; // r9
  int v62; // r5
  int v63; // r4
  int v64; // r1
  unsigned int v65; // r0
  unsigned int v66; // r2
  int v67; // r0
  unsigned int v68; // r1
  __int16 v69; // r3
  int v71; // [sp+0h] [bp-48h]
  int v72; // [sp+4h] [bp-44h]
  void **v73; // [sp+4h] [bp-44h]
  int v74; // [sp+4h] [bp-44h]
  unsigned int v75; // [sp+8h] [bp-40h]
  int v76; // [sp+8h] [bp-40h]
  unsigned int v77; // [sp+Ch] [bp-3Ch]
  unsigned int v78; // [sp+14h] [bp-34h]
  unsigned int v79; // [sp+18h] [bp-30h]
  unsigned int v80; // [sp+1Ch] [bp-2Ch]
  unsigned int v81; // [sp+1Ch] [bp-2Ch]
  unsigned int v82; // [sp+20h] [bp-28h]

  v1 = a1;
  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  v3 = KeAbPreAcquire((unsigned int)&PpmIdlePolicyLock, 0, 0);
  v4 = v3;
  do
    v5 = __ldrex((unsigned __int8 *)&PpmIdlePolicyLock);
  while ( __strex(v5 | 1, (unsigned __int8 *)&PpmIdlePolicyLock) );
  __dmb(0xBu);
  if ( (v5 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&PpmIdlePolicyLock, v3, (unsigned int)&PpmIdlePolicyLock);
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  dword_61E89C = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( PpmPlatformStates && !*((_BYTE *)v1 + 20) )
  {
    v6 = -1073741431;
    goto LABEL_73;
  }
  v7 = *v1;
  v77 = *v1;
  if ( !*v1 )
    goto LABEL_72;
  v8 = KeNumberProcessors_0;
  v9 = 0;
  v71 = KeNumberProcessors_0;
  v10 = KeNumberProcessors_0 * v7;
  if ( v7 )
  {
    v11 = (int *)(v1 + 6);
    v12 = *v1;
    do
    {
      v13 = *(_QWORD *)(v11 + 7);
      v11 += 11;
      v9 += HIDWORD(v13);
      --v12;
      v10 += HIDWORD(v13) * v13;
    }
    while ( v12 );
  }
  if ( !PpmPlatformStates )
  {
    v78 = ((((v7 << 8) + 131) & 0xFFFFFFFC) + 12 * v9 + 3) & 0xFFFFFFFC;
    v14 = v78 + 16 * v10;
    v79 = (v14 + 3) & 0xFFFFFFFC;
    v75 = (v14 + 4 * KeNumberProcessors_0 * v7 + 7) & 0xFFFFFFF8;
    v80 = (v75 + 992 * v7 + 31) & 0xFFFFFFF8;
    v82 = (4 * v7 + 15) & 0xFFFFFFF8;
    v15 = (v80 + v82 * KeNumberProcessors_0 + 3) & 0xFFFFFFFC;
    v72 = v15;
    if ( PpmIdleVetoList )
      v15 += 16 * *(_DWORD *)PpmIdleVetoList * v7;
    v16 = (_BYTE *)ExAllocatePoolWithTag(512, v15, 1766674512);
    v17 = (int)v16;
    if ( !v16 )
    {
      v6 = -1073741670;
      goto LABEL_73;
    }
    memset(v16, 0, v15);
    *(_DWORD *)v17 = v7;
    *(_DWORD *)(v17 + 4) = 1;
    *(_BYTE *)(v17 + 12) = 1;
    *(_DWORD *)(v17 + 8) = v8;
    *(_DWORD *)(v17 + 16) = v1[1];
    *(_DWORD *)(v17 + 20) = v1[2];
    *(_DWORD *)(v17 + 24) = v1[3];
    *(_DWORD *)(v17 + 28) = v1[4];
    *(_DWORD *)(v17 + 32) = v17 + v75;
    *(_DWORD *)(v17 + v75 + 4) = v7;
    PpmResetPlatformIdleAccounting((__int64 *)(v17 + v75));
    v18 = 0;
    v19 = v17 + v72;
    if ( *v1 )
    {
      v20 = (_DWORD *)(v17 + 128);
      v21 = (_DWORD *)PpmIdleVetoList;
      do
      {
        v20[3] = v20 + 3;
        v20[4] = v20 + 3;
        if ( v21 )
        {
          v20[5] = *v21;
          v20[6] = v19;
          v19 += 16 * *v21;
        }
        ++v18;
        v20 += 64;
      }
      while ( v18 < *v1 );
    }
    v22 = v17 + v78;
    if ( v7 )
    {
      v23 = (((v7 << 8) + 131) & 0xFFFFFFFC) + v17;
      v24 = v7;
      v25 = (_DWORD *)(v17 + 128);
      v26 = v1 + 6;
      do
      {
        v25[12] = v26[3];
        v25[13] = v26[4];
        v27 = v26[1];
        v28 = v26[2];
        v25[9] = *v26;
        v25[10] = v27;
        v25[11] = v28;
        v29 = v26[8];
        v25[14] = v23;
        v30 = 0;
        v25[8] = v29;
        v31 = v26[8];
        v23 += 12 * v31;
        if ( v31 )
        {
          v32 = 0;
          do
          {
            ++v30;
            *(_DWORD *)(v25[14] + v32 + 8) = v22;
            v32 += 12;
            v22 += 16 * v26[7];
          }
          while ( v30 < v26[8] );
        }
        v26 += 11;
        --v24;
        v25 += 64;
      }
      while ( v24 );
      v7 = v77;
      v8 = v71;
    }
    v33 = 0;
    v34 = v17 + v79;
    if ( v8 )
    {
      v35 = &KiProcessorBlock;
      v73 = &KiProcessorBlock;
      v36 = v17 + v80;
      do
      {
        if ( v33 >= KeNumberProcessors_0 )
          v37 = 0;
        else
          v37 = *v35;
        v38 = (_DWORD *)v37[736];
        v39 = 0;
        v38[62] = v34;
        v34 += 4 * v7;
        v38[57] = v7;
        v38[58] = v22;
        v81 = v34;
        v38[54] = v36;
        v22 += 16 * v7;
        v38[59] = v7;
        if ( v7 )
        {
          v40 = 16 * v7;
          v41 = v17 + 128;
          do
          {
            v42 = v40 + v38[58];
            *(_DWORD *)(v42 - 12) = v39++;
            v40 -= 16;
            *(_DWORD *)(v42 - 8) = *(_DWORD *)(v41 + 32);
            v43 = *(_DWORD *)(v41 + 56);
            v41 += 256;
            *(_DWORD *)(v42 - 4) = v43;
          }
          while ( v39 < v7 );
          v8 = v71;
          v35 = v73;
          v34 = v81;
        }
        ++v33;
        ++v35;
        v36 += v82;
        v73 = v35;
      }
      while ( v33 < v8 );
      v1 = a1;
    }
    goto LABEL_45;
  }
  v17 = PpmPlatformStates;
  if ( *(_DWORD *)(PpmPlatformStates + 8) != KeNumberProcessors_0
    || *(_DWORD *)PpmPlatformStates != v7
    || *(_DWORD *)(PpmPlatformStates + 4) != 1 )
  {
LABEL_72:
    v6 = -1073741811;
    goto LABEL_73;
  }
LABEL_45:
  if ( v7 )
  {
    v44 = v7;
    v76 = v7;
    v45 = (int *)(v1 + 6);
    v46 = v17 + 128;
    do
    {
      v47 = 0;
      v74 = 0;
      *(_DWORD *)v46 = v45[5];
      *(_DWORD *)(v46 + 4) = v45[6];
      *(_BYTE *)(v46 + 29) = *((_BYTE *)v45 + 36);
      if ( v45[8] )
      {
        v48 = 0;
        do
        {
          v49 = 0;
          v50 = (_DWORD *)(v48 + v45[10]);
          v51 = (_DWORD *)(v48 + *(_DWORD *)(v46 + 56));
          *v51 = *v50;
          v51[1] = v50[1];
          v52 = v50[1];
          if ( v52 )
          {
            do
            {
              v53 = v51[2] + 16 * (v52 - v49 - 1);
              v54 = (unsigned __int8 *)(v50[2] + 4 * v49);
              *(_DWORD *)v53 = 0;
              *(_DWORD *)(v53 + 4) = 0;
              *(_DWORD *)(v53 + 8) = 0;
              *(_DWORD *)(v53 + 12) = 0;
              *(_DWORD *)(v53 + 4) = *v54;
              *(_BYTE *)v53 = v54[1] == 0;
              *(_BYTE *)(v53 + 1) = v54[2];
              *(_BYTE *)(v53 + 2) = v54[3];
              if ( *v51 == -1 )
              {
                v55 = v17 + (*(_DWORD *)(v53 + 4) << 8);
                *(_DWORD *)(v53 + 8) = *(_DWORD *)(v55 + 160);
                *(_DWORD *)(v53 + 12) = *(_DWORD *)(v55 + 184);
              }
              else
              {
                *(_DWORD *)(v53 + 8) = 0;
                *(_DWORD *)(v53 + 12) = 0;
              }
              v52 = v50[1];
              ++v49;
            }
            while ( v49 < v52 );
            v47 = v74;
          }
          v74 = ++v47;
          v48 += 12;
        }
        while ( v47 < v45[8] );
        v44 = v76;
      }
      v45 += 11;
      v76 = --v44;
      v46 += 256;
    }
    while ( v44 );
    v8 = v71;
  }
  v56 = 0;
  if ( v8 )
  {
    v57 = &KiProcessorBlock;
    do
    {
      if ( v56 >= KeNumberProcessors_0 )
        v58 = 0;
      else
        v58 = *v57;
      v59 = v58[736];
      if ( v7 )
      {
        v60 = 16 * v7;
        v61 = v7;
        v62 = v59;
        do
        {
          v63 = v60 + *(_DWORD *)(v62 + 232);
          v60 -= 16;
          *(_BYTE *)(v63 - 15) = PpmCheckCoordinatedStateInitiator(v56, *(_DWORD *)(v63 - 8), *(_DWORD **)(v63 - 4));
          --v61;
        }
        while ( v61 );
        v7 = v77;
        v8 = v71;
      }
      ++v56;
      ++v57;
    }
    while ( v56 < v8 );
  }
  if ( !PpmPlatformStates )
    PpmEnableCoordinatedIdleStates((int *)v17, 1);
  v6 = 0;
LABEL_73:
  dword_61E89C = 0;
  __pld(&PpmIdlePolicyLock);
  v64 = PpmIdlePolicyLock;
  v65 = PpmIdlePolicyLock - 16;
  if ( (PpmIdlePolicyLock & 0xFFFFFFF0) <= 0x10 )
    v65 = 0;
  if ( (PpmIdlePolicyLock & 2) != 0 )
    goto LABEL_80;
  __dmb(0xBu);
  do
    v66 = __ldrex((unsigned int *)&PpmIdlePolicyLock);
  while ( v66 == v64 && __strex(v65, (unsigned int *)&PpmIdlePolicyLock) );
  if ( v66 != v64 )
LABEL_80:
    ExfReleasePushLock(&PpmIdlePolicyLock, v64);
  v67 = KeAbPostRelease((unsigned int)&PpmIdlePolicyLock);
  v68 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v69 = *(_WORD *)(v68 + 0x134) + 1;
  *(_WORD *)(v68 + 308) = v69;
  if ( !v69 && *(_DWORD *)(v68 + 100) != v68 + 100 && !*(_WORD *)(v68 + 310) )
    KiCheckForKernelApcDelivery(v67);
  return v6;
}
