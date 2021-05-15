// KsepResolveApplicableShimsForDriver 
 
int __fastcall KsepResolveApplicableShimsForDriver(unsigned int a1, unsigned int a2, int a3, int *a4)
{
  int v4; // r7
  int v5; // r10
  unsigned int v8; // r2
  int v9; // r6
  unsigned int v10; // r4
  unsigned int v11; // r4
  unsigned int v12; // r6
  int v13; // r2
  int v14; // r3
  unsigned int v15; // r0
  int v16; // r0
  int v17; // r2
  int v18; // r1
  __int16 v19; // r3
  unsigned int v20; // r4
  int v21; // r6
  int v22; // r0
  unsigned int v23; // r2
  int v24; // r4
  unsigned int v25; // r1
  unsigned int v26; // r4
  unsigned int v27; // r6
  int v28; // r2
  unsigned int v29; // r0
  int v30; // r0
  unsigned int v31; // r1
  int v32; // r3
  unsigned int v33; // r1
  unsigned int v34; // r1
  _WORD *v35; // r3
  int *v36; // r10
  unsigned int v37; // r0
  int v38; // r0
  unsigned int v39; // r1
  __int16 v40; // r3
  unsigned int v41; // r1
  unsigned int v42; // r1
  _WORD *v43; // r3
  unsigned int v44; // r2
  int v45; // r4
  unsigned int v46; // r1
  int v47; // r2
  unsigned int v48; // r4
  unsigned int v49; // r6
  unsigned int v50; // r0
  int v51; // r0
  unsigned int v52; // r1
  int v53; // r3
  unsigned int v54; // r0
  int v55; // r0
  unsigned int v56; // r1
  __int16 v57; // r3
  unsigned int v58; // r1
  unsigned int v59; // r1
  _WORD *v60; // r3
  unsigned int v61; // r1
  unsigned int v62; // r1
  char *v63; // r3
  int v65; // [sp+0h] [bp-28h]
  int *v66[9]; // [sp+4h] [bp-24h] BYREF

  v66[1] = a4;
  v4 = 0;
  v5 = 0;
  v65 = 0;
  v66[0] = 0;
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v8 + 308);
  v9 = KeAbPreAcquire((unsigned int)dword_6416EC, 0, 0);
  do
    v10 = __ldrex((unsigned __int8 *)dword_6416EC);
  while ( __strex(v10 | 1, (unsigned __int8 *)dword_6416EC) );
  __dmb(0xBu);
  if ( (v10 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(dword_6416EC, v9, (unsigned int)dword_6416EC);
  if ( v9 )
    *(_BYTE *)(v9 + 14) |= 1u;
  if ( a2 )
  {
    v11 = a1;
    v12 = a2;
    do
    {
      if ( KsepIsShimRegistered((int)&KseEngine, v11) == 1 )
      {
        v13 = *(_DWORD *)(v11 + 48);
        v14 = *(_DWORD *)(v13 + 12);
        if ( !v14 )
          v65 = 1;
        *(_DWORD *)(v13 + 12) = v14 + 1;
      }
      else
      {
        v65 = 1;
        *(_DWORD *)(v11 + 48) = 0;
        v5 = 1;
      }
      v11 += 52;
      --v12;
    }
    while ( v12 );
    v4 = 0;
  }
  __dmb(0xBu);
  do
    v15 = __ldrex(dword_6416EC);
  while ( __strex(v15 - 1, dword_6416EC) );
  if ( (v15 & 2) != 0 && (v15 & 4) == 0 )
    ExfTryToWakePushLock(dword_6416EC);
  v16 = KeAbPostRelease((unsigned int)dword_6416EC);
  v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v19 = *(_WORD *)(v18 + 0x134) + 1;
  *(_WORD *)(v18 + 308) = v19;
  if ( !v19 )
  {
    v17 = v18 + 100;
    if ( *(_DWORD *)(v18 + 100) != v18 + 100 && !*(_WORD *)(v18 + 310) )
      KiCheckForKernelApcDelivery(v16);
  }
  if ( !v5 )
  {
LABEL_69:
    if ( v65 )
    {
      v4 = KsepGetLoadedModulesList(v66);
      if ( v4 < 0 )
      {
        v36 = v66[0];
        goto LABEL_112;
      }
      v44 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v44 + 308);
      v45 = KeAbPreAcquire((unsigned int)dword_6416EC, 0, 0);
      do
      {
        v46 = __ldrex((unsigned __int8 *)dword_6416EC);
        v47 = __strex(v46 | 1, (unsigned __int8 *)dword_6416EC);
      }
      while ( v47 );
      __dmb(0xBu);
      if ( (v46 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx(dword_6416EC, v45, (unsigned int)dword_6416EC);
      if ( v45 )
        *(_BYTE *)(v45 + 14) |= 1u;
      v36 = v66[0];
      v48 = 0;
      if ( a2 )
      {
        v49 = a1;
        while ( 1 )
        {
          v4 = KsepResolveShimHooks(
                 (int)v36,
                 *(int **)(*(_DWORD *)(*(_DWORD *)(v49 + 48) + 8) + 24),
                 v47,
                 *(_DWORD *)(*(_DWORD *)(v49 + 48) + 8));
          if ( v4 < 0 )
            break;
          ++v48;
          v49 += 52;
          if ( v48 >= a2 )
            goto LABEL_81;
        }
        __dmb(0xBu);
        do
          v54 = __ldrex(dword_6416EC);
        while ( __strex(v54 - 1, dword_6416EC) );
        if ( (v54 & 2) != 0 && (v54 & 4) == 0 )
          ExfTryToWakePushLock(dword_6416EC);
        v55 = KeAbPostRelease((unsigned int)dword_6416EC);
        v56 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v57 = *(_WORD *)(v56 + 0x134) + 1;
        *(_WORD *)(v56 + 308) = v57;
        if ( !v57 && *(_DWORD *)(v56 + 100) != v56 + 100 && !*(_WORD *)(v56 + 310) )
          KiCheckForKernelApcDelivery(v55);
        __dmb(0xBu);
        do
        {
          v58 = __ldrex(&KsepHistoryErrorsIndex);
          v59 = v58 + 1;
        }
        while ( __strex(v59, &KsepHistoryErrorsIndex) );
        __dmb(0xBu);
        v60 = &KsepHistoryErrors[4 * (v59 & 0x3F)];
        *((_DWORD *)v60 + 1) = v4;
        v60[1] = 7;
        *v60 = 536;
        if ( (KsepDebugFlag & 2) != 0 )
          KsepDebugPrint(6, (int)"KSE: Failed to resolve hooks for shim [0x%08X]. Status 0x%x.\n");
        KsepLogError(
          6,
          (int)"KSE: Failed to resolve hooks for shim [0x%08X]. Status 0x%x.\n",
          *(_DWORD *)(52 * v48 + a1),
          v4);
      }
      else
      {
LABEL_81:
        __dmb(0xBu);
        do
          v50 = __ldrex(dword_6416EC);
        while ( __strex(v50 - 1, dword_6416EC) );
        if ( (v50 & 2) != 0 && (v50 & 4) == 0 )
          ExfTryToWakePushLock(dword_6416EC);
        v51 = KeAbPostRelease((unsigned int)dword_6416EC);
        v52 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v53 = (__int16)(*(_WORD *)(v52 + 0x134) + 1);
        *(_WORD *)(v52 + 308) = v53;
        if ( !v53 && *(_DWORD *)(v52 + 100) != v52 + 100 && !*(_WORD *)(v52 + 310) )
          KiCheckForKernelApcDelivery(v51);
      }
    }
    else
    {
      v36 = 0;
    }
    goto LABEL_106;
  }
  v20 = 0;
  if ( a2 )
  {
    v21 = a1;
    while ( 1 )
    {
      if ( !*(_DWORD *)(v21 + 48) )
      {
        v22 = KsepLoadShimProvider(v21, v18, v17, 0);
        v4 = v22;
        if ( v22 < 0 )
          break;
      }
      ++v20;
      v21 += 52;
      if ( v20 >= a2 )
        goto LABEL_31;
    }
    __dmb(0xBu);
    do
    {
      v33 = __ldrex(&KsepHistoryErrorsIndex);
      v34 = v33 + 1;
    }
    while ( __strex(v34, &KsepHistoryErrorsIndex) );
    __dmb(0xBu);
    v35 = &KsepHistoryErrors[4 * (v34 & 0x3F)];
    *((_DWORD *)v35 + 1) = v22;
    v35[1] = 7;
    *v35 = 459;
    if ( (KsepDebugFlag & 2) != 0 )
      KsepDebugPrint(6, (int)"KSE: Failed to load provider for shim [0x%08X]. Status: 0x%x\n");
    KsepLogError(
      6,
      (int)"KSE: Failed to load provider for shim [0x%08X]. Status: 0x%x\n",
      *(_DWORD *)(52 * v20 + a1),
      v4);
    v36 = 0;
LABEL_106:
    if ( v4 >= 0 )
    {
      __dmb(0xBu);
      do
      {
        v61 = __ldrex(KsepHistoryMessagesIndex);
        v62 = v61 + 1;
      }
      while ( __strex(v62, KsepHistoryMessagesIndex) );
      __dmb(0xBu);
      v63 = (char *)&KsepHistoryMessages + 8 * (v62 & 0x3F);
      *((_DWORD *)v63 + 1) = 0;
      *((_WORD *)v63 + 1) = 7;
      *(_WORD *)v63 = 550;
      if ( (KsepDebugFlag & 1) != 0 )
        KsepDebugPrint(6, (int)"KSE: Successfully resolved %d shim(s).\n");
      KsepLogInfo(6, (int)"KSE: Successfully resolved %d shim(s).\n", a2);
    }
    goto LABEL_112;
  }
LABEL_31:
  v23 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v23 + 308);
  v24 = KeAbPreAcquire((unsigned int)dword_6416EC, 0, 0);
  do
    v25 = __ldrex((unsigned __int8 *)dword_6416EC);
  while ( __strex(v25 | 1, (unsigned __int8 *)dword_6416EC) );
  __dmb(0xBu);
  if ( (v25 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(dword_6416EC, v24, (unsigned int)dword_6416EC);
  if ( v24 )
    *(_BYTE *)(v24 + 14) |= 1u;
  v26 = 0;
  if ( !a2 )
  {
LABEL_41:
    __dmb(0xBu);
    do
      v29 = __ldrex(dword_6416EC);
    while ( __strex(v29 - 1, dword_6416EC) );
    if ( (v29 & 2) != 0 && (v29 & 4) == 0 )
      ExfTryToWakePushLock(dword_6416EC);
    v30 = KeAbPostRelease((unsigned int)dword_6416EC);
    v31 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v32 = (__int16)(*(_WORD *)(v31 + 0x134) + 1);
    *(_WORD *)(v31 + 308) = v32;
    if ( !v32 && *(_DWORD *)(v31 + 100) != v31 + 100 && !*(_WORD *)(v31 + 310) )
      KiCheckForKernelApcDelivery(v30);
    goto LABEL_69;
  }
  v27 = a1;
  while ( KsepIsShimRegistered((int)&KseEngine, v27) )
  {
    v28 = *(_DWORD *)(v27 + 48);
    ++v26;
    v27 += 52;
    ++*(_DWORD *)(v28 + 12);
    if ( v26 >= a2 )
      goto LABEL_41;
  }
  __dmb(0xBu);
  do
    v37 = __ldrex(dword_6416EC);
  while ( __strex(v37 - 1, dword_6416EC) );
  if ( (v37 & 2) != 0 && (v37 & 4) == 0 )
    ExfTryToWakePushLock(dword_6416EC);
  v38 = KeAbPostRelease((unsigned int)dword_6416EC);
  v39 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v40 = *(_WORD *)(v39 + 0x134) + 1;
  *(_WORD *)(v39 + 308) = v40;
  if ( !v40 && *(_DWORD *)(v39 + 100) != v39 + 100 && !*(_WORD *)(v39 + 310) )
    KiCheckForKernelApcDelivery(v38);
  v4 = -1073740782;
  __dmb(0xBu);
  do
  {
    v41 = __ldrex(&KsepHistoryErrorsIndex);
    v42 = v41 + 1;
  }
  while ( __strex(v42, &KsepHistoryErrorsIndex) );
  __dmb(0xBu);
  v43 = &KsepHistoryErrors[4 * (v42 & 0x3F)];
  *((_DWORD *)v43 + 1) = -1073740782;
  v43[1] = 7;
  *v43 = 488;
  if ( (KsepDebugFlag & 2) != 0 )
    KsepDebugPrint(6, (int)"KSE: The provider did not register shim [0x%08X] in time\n");
  KsepLogError(6, (int)"KSE: The provider did not register shim [0x%08X] in time\n", *(_DWORD *)(52 * v26 + a1));
  v36 = 0;
LABEL_112:
  KsepPoolFreePaged((int)v36);
  return v4;
}
