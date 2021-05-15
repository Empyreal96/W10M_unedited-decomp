// sub_7FDD70 
 
// local variable allocation has failed, the output may be wrong!
void __fastcall sub_7FDD70(int a1, int a2, int a3, int a4, int a5, unsigned __int8 a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13)
{
  int v13; // r5
  int v14; // r6
  _DWORD *v15; // r7
  _DWORD *v16; // r8
  _DWORD *v17; // r9
  _DWORD *v18; // r10
  unsigned int v19; // r0
  unsigned int v20; // r2
  int v21; // r1
  unsigned int v22; // r2
  int v23; // r0
  unsigned int v24; // r1
  int v25; // r0
  unsigned int v26; // r1
  __int16 v27; // r3
  int v28; // r3
  unsigned int v29; // r1
  int v30; // r0
  unsigned int v31; // r1
  __int16 v32; // r3
  _BYTE *v33; // r0
  int v34; // r1
  int v35; // r2
  int v36; // r3
  int v37; // r1
  int v38; // r2
  int v39; // r3
  unsigned int v40; // r1
  int v41; // r0
  unsigned int v42; // r1
  int v43; // r3
  int v44; // r3
  _DWORD *v45; // t2
  unsigned int *v46; // lr
  unsigned int v47; // r0
  unsigned int v48; // r1
  _DWORD *v49; // r1
  unsigned int v50; // r1
  __int16 v51; // r3
  unsigned int v52; // r1
  int v53; // r0
  unsigned int v54; // r1
  __int16 v55; // r3
  unsigned int v56; // r1
  int v57; // r0
  unsigned int v58; // r1
  __int16 v59; // r3
  unsigned int v60; // r2
  int v61; // r0
  int v62; // r7
  unsigned int v63; // r2
  int v64; // r1 OVERLAPPED
  _DWORD *v65; // r2 OVERLAPPED
  unsigned int v66; // r2
  int v67; // r0
  int v68; // r7
  unsigned int v69; // r2
  int v70; // r1 OVERLAPPED
  _DWORD *v71; // r2 OVERLAPPED
  unsigned int v72; // r1
  int v73; // r0
  unsigned int v74; // r1
  __int16 v75; // r3
  _DWORD *v76; // t2
  unsigned int *v77; // r0
  unsigned int v78; // r4
  unsigned int v79; // r1
  __int16 v80; // r3
  unsigned int v81; // r1
  int v82; // r0
  unsigned int v83; // r1
  __int16 v84; // r3
  _DWORD *v85; // t2
  unsigned __int8 *v86; // r0
  unsigned int v87; // r4
  unsigned int v88; // r1
  unsigned int v89; // r1
  int v90; // r3
  _DWORD *v91; // [sp+10h] [bp-40h]
  _DWORD *v92; // [sp+14h] [bp-3Ch]
  int v93; // [sp+18h] [bp-38h]
  int v94; // [sp+1Ch] [bp-34h]
  int v95; // [sp+1Ch] [bp-34h]
  int v96; // [sp+20h] [bp-30h]
  unsigned int v97[11]; // [sp+24h] [bp-2Ch] BYREF

  ObfReferenceObject((int)v16);
  if ( !TmIsTransactionActive() )
  {
    v14 = -1072103421;
    v19 = 0;
LABEL_144:
    if ( v16 )
    {
      ObfDereferenceObject((int)v16);
      v19 = (unsigned int)v91;
    }
    if ( v19 )
      ExFreePoolWithTag(v19);
    if ( v14 >= 0 )
      *v17 = v18;
    goto LABEL_175;
  }
  v19 = 0;
  if ( a13 )
  {
    v28 = *(_DWORD *)(a13 + 4);
    if ( (v28 & 1) != 0 )
      v28 ^= 1u;
    v13 = *(_DWORD *)(v28 + 20);
    v94 = v13;
LABEL_28:
    v92 = *(_DWORD **)(v13 + 3256);
    if ( v92 )
      goto LABEL_3;
    if ( v13 && (*(_DWORD *)(v13 + 3228) & 8) == 0 )
    {
      v14 = 0;
      goto LABEL_144;
    }
LABEL_32:
    v14 = -1072103419;
    goto LABEL_144;
  }
  if ( !a10 )
  {
    if ( !v13 )
      goto LABEL_32;
    goto LABEL_28;
  }
  while ( 1 )
  {
    while ( 1 )
    {
LABEL_3:
      v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v20 + 308);
      v97[0] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v21 = KeAbPreAcquire((unsigned int)&CmpTransactionListLock, 0, 0);
      v96 = v21;
      do
        v22 = __ldrex((unsigned __int8 *)&CmpTransactionListLock);
      while ( __strex(v22 & 0xFE, (unsigned __int8 *)&CmpTransactionListLock) );
      __dmb(0xBu);
      if ( (v22 & 1) == 0 )
      {
        ExpAcquireFastMutexContended((int)&CmpTransactionListLock, v21);
        v21 = v96;
      }
      if ( v21 )
        *(_BYTE *)(v21 + 14) |= 1u;
      dword_632184 = v97[0];
      v23 = CmpSearchForTrans(v92, v16, v15);
      v18 = (_DWORD *)v23;
      if ( !v23 )
        break;
      if ( (*(_DWORD *)(v23 + 64) & 8) == 0 )
      {
        if ( v16 && (*(_DWORD *)(v23 + 64) & 7) != 0 )
          v14 = -1072103422;
        else
          CmpBindHiveToTrans(v13, v23);
        dword_632184 = 0;
        __dmb(0xBu);
        do
          v40 = __ldrex((unsigned int *)&CmpTransactionListLock);
        while ( !v40 && __strex(1u, (unsigned int *)&CmpTransactionListLock) );
        if ( v40 )
          ExpReleaseFastMutexContended((unsigned int *)&CmpTransactionListLock, v40);
        v41 = KeAbPostRelease((unsigned int)&CmpTransactionListLock);
        v42 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v43 = (__int16)(*(_WORD *)(v42 + 0x134) + 1);
        *(_WORD *)(v42 + 308) = v43;
        if ( !v43 && *(_DWORD *)(v42 + 100) != v42 + 100 && !*(_WORD *)(v42 + 310) )
          goto LABEL_142;
        goto LABEL_143;
      }
      v97[0] = CmpTransactionInitializingCount;
      dword_632184 = 0;
      __dmb(0xBu);
      do
        v24 = __ldrex((unsigned int *)&CmpTransactionListLock);
      while ( !v24 && __strex(1u, (unsigned int *)&CmpTransactionListLock) );
      if ( v24 )
        ExpReleaseFastMutexContended((unsigned int *)&CmpTransactionListLock, v24);
      v25 = KeAbPostRelease((unsigned int)&CmpTransactionListLock);
      v26 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v27 = *(_WORD *)(v26 + 0x134) + 1;
      *(_WORD *)(v26 + 308) = v27;
      if ( !v27 && *(_DWORD *)(v26 + 100) != v26 + 100 && !*(_WORD *)(v26 + 310) )
        KiCheckForKernelApcDelivery(v25);
      if ( !a6 )
        goto LABEL_49;
      ExBlockOnAddressPushLock(
        (int)&CmpTransactionInitializingEvent,
        (unsigned __int64 *)&CmpTransactionInitializingCount,
        v97,
        4,
        0);
    }
    if ( v91 )
      break;
    dword_632184 = 0;
    __dmb(0xBu);
    do
      v29 = __ldrex((unsigned int *)&CmpTransactionListLock);
    while ( !v29 && __strex(1u, (unsigned int *)&CmpTransactionListLock) );
    if ( v29 )
      ExpReleaseFastMutexContended((unsigned int *)&CmpTransactionListLock, v29);
    v30 = KeAbPostRelease((unsigned int)&CmpTransactionListLock);
    v31 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v32 = *(_WORD *)(v31 + 0x134) + 1;
    *(_WORD *)(v31 + 308) = v32;
    if ( !v32 && *(_DWORD *)(v31 + 100) != v31 + 100 && !*(_WORD *)(v31 + 310) )
      KiCheckForKernelApcDelivery(v30);
    if ( !a6 )
    {
LABEL_49:
      v14 = -1072103422;
      goto LABEL_143;
    }
    v33 = (_BYTE *)ExAllocatePoolWithTag(1, 104, 1918127427);
    v18 = v33;
    if ( !v33 )
    {
      v14 = -1073741670;
      goto LABEL_143;
    }
    memset(v33, 0, 104);
    v18[6] = v16;
    v18[14] = 0;
    v18[7] = v92;
    v18[15] = -1;
    v18[16] = 8;
    if ( v15 )
    {
      v34 = v15[1];
      v35 = v15[2];
      v36 = v15[3];
      v18[10] = *v15;
      v18[11] = v34;
      v18[12] = v35;
      v18[13] = v36;
    }
    else
    {
      v37 = v16[25];
      v38 = v16[26];
      v39 = v16[27];
      v18[10] = v16[24];
      v18[11] = v37;
      v18[12] = v38;
      v18[13] = v39;
      v13 = v94;
    }
    v18[2] = v18 + 2;
    v18[3] = v18 + 2;
    v18[4] = v18 + 4;
    v18[5] = v18 + 4;
    CmpBindHiveToTrans(v13, v18);
    v91 = v18;
  }
  v18 = v91;
  if ( !v92[12] )
    goto LABEL_70;
  v44 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v44 & 0xFFFFFFC0) + 0x134);
  v45 = (_DWORD *)(v92[12] + 1832);
  __pld(v45);
  v46 = v45;
  v47 = *v45 & 0xFFFFFFFE;
  do
    v48 = __ldrex(v46);
  while ( v48 == v47 && __strex(v47 + 2, v46) );
  __dmb(0xBu);
  if ( v48 == v47 )
  {
    v93 = 1;
    goto LABEL_70;
  }
  v93 = ExfAcquireRundownProtection(v46);
  if ( !v93 )
  {
    v50 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v51 = *(_WORD *)(v50 + 0x134) + 1;
    *(_WORD *)(v50 + 308) = v51;
    if ( !v51 && *(_DWORD *)(v50 + 100) != v50 + 100 && !*(_WORD *)(v50 + 310) )
      KiCheckForKernelApcDelivery(0);
    dword_632184 = 0;
    __dmb(0xBu);
    do
      v52 = __ldrex((unsigned int *)&CmpTransactionListLock);
    while ( !v52 && __strex(1u, (unsigned int *)&CmpTransactionListLock) );
    if ( v52 )
      ExpReleaseFastMutexContended((unsigned int *)&CmpTransactionListLock, v52);
    v53 = KeAbPostRelease((unsigned int)&CmpTransactionListLock);
    v54 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v55 = *(_WORD *)(v54 + 0x134) + 1;
    *(_WORD *)(v54 + 308) = v55;
    if ( !v55 && *(_DWORD *)(v54 + 100) != v54 + 100 && !*(_WORD *)(v54 + 310) )
      KiCheckForKernelApcDelivery(v53);
    v14 = -1072103422;
LABEL_133:
    if ( v93 )
    {
      v76 = (_DWORD *)(v92[12] + 1832);
      __pld(v76);
      v77 = v76;
      v78 = *v76 & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v79 = __ldrex(v77);
      while ( v79 == v78 && __strex(v78 - 2, v77) );
      if ( v79 != v78 )
        ExfReleaseRundownProtection((unsigned __int8 *)v77);
      v41 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v80 = *(_WORD *)(v41 + 0x134) + 1;
      *(_WORD *)(v41 + 308) = v80;
      if ( !v80 && *(_DWORD *)(v41 + 100) != v41 + 100 && !*(_WORD *)(v41 + 310) )
LABEL_142:
        KiCheckForKernelApcDelivery(v41);
    }
LABEL_143:
    v19 = (unsigned int)v91;
    goto LABEL_144;
  }
LABEL_70:
  v49 = (_DWORD *)v92[3];
  *v91 = v92 + 2;
  v91[1] = v49;
  if ( (_DWORD *)*v49 != v92 + 2 )
    __fastfail(3u);
  *v49 = v91;
  v92[3] = v91;
  ++CmpTransactionInitializingCount;
  dword_632184 = 0;
  __dmb(0xBu);
  do
    v56 = __ldrex((unsigned int *)&CmpTransactionListLock);
  while ( !v56 && __strex(1u, (unsigned int *)&CmpTransactionListLock) );
  if ( v56 )
    ExpReleaseFastMutexContended((unsigned int *)&CmpTransactionListLock, v56);
  v57 = KeAbPostRelease((unsigned int)&CmpTransactionListLock);
  v58 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v59 = *(_WORD *)(v58 + 0x134) + 1;
  *(_WORD *)(v58 + 308) = v59;
  if ( !v59 && *(_DWORD *)(v58 + 100) != v58 + 100 && !*(_WORD *)(v58 + 310) )
    KiCheckForKernelApcDelivery(v57);
  v91 = 0;
  v95 = 64;
  if ( v16 )
  {
    if ( v92 != (_DWORD *)CmRmSystem
      && (v14 = CmpSearchAddTrans(0, 0, (int)off_60E8A4, (int)v16, (int)v15, a6, v97), v14 < 0)
      || (v14 = CmpStartRMLogs(v92), v14 < 0)
      || (v14 = CmTmCreateEnlistment(v18 + 9, v92[7], v16, v18), v14 < 0) )
    {
      v66 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v66 + 308);
      v97[0] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v67 = KeAbPreAcquire((unsigned int)&CmpTransactionListLock, 0, 0);
      v68 = v67;
      do
        v69 = __ldrex((unsigned __int8 *)&CmpTransactionListLock);
      while ( __strex(v69 & 0xFE, (unsigned __int8 *)&CmpTransactionListLock) );
      __dmb(0xBu);
      if ( (v69 & 1) == 0 )
        ExpAcquireFastMutexContended((int)&CmpTransactionListLock, v67);
      if ( v68 )
        *(_BYTE *)(v68 + 14) |= 1u;
      dword_632184 = v97[0];
      *(_QWORD *)&v70 = *(_QWORD *)v18;
      if ( *(_DWORD **)(*v18 + 4) != v18 || (_DWORD *)*v71 != v18 )
        __fastfail(3u);
      *v71 = v70;
      *(_DWORD *)(v70 + 4) = v71;
      --CmpTransactionInitializingCount;
      dword_632184 = 0;
      __dmb(0xBu);
      do
        v72 = __ldrex((unsigned int *)&CmpTransactionListLock);
      while ( !v72 && __strex(1u, (unsigned int *)&CmpTransactionListLock) );
      if ( v72 )
        ExpReleaseFastMutexContended((unsigned int *)&CmpTransactionListLock, v72);
      v73 = KeAbPostRelease((unsigned int)&CmpTransactionListLock);
      v74 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v75 = *(_WORD *)(v74 + 0x134) + 1;
      *(_WORD *)(v74 + 308) = v75;
      if ( !v75 && *(_DWORD *)(v74 + 100) != v74 + 100 && !*(_WORD *)(v74 + 310) )
        KiCheckForKernelApcDelivery(v73);
      __dmb(0xFu);
      if ( CmpTransactionInitializingEvent )
        ExfUnblockPushLock((int)&CmpTransactionInitializingEvent, 0);
      goto LABEL_132;
    }
    v14 = ObReferenceObjectByHandle(v18[9], 0, 0, 0, (int)v97, 0);
    v18[8] = v97[0];
    if ( CmpAccountForLogReservation(v92) >= 0 )
      v95 = 96;
  }
  v60 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v60 + 308);
  v97[0] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v61 = KeAbPreAcquire((unsigned int)&CmpTransactionListLock, 0, 0);
  v62 = v61;
  do
    v63 = __ldrex((unsigned __int8 *)&CmpTransactionListLock);
  while ( __strex(v63 & 0xFE, (unsigned __int8 *)&CmpTransactionListLock) );
  __dmb(0xBu);
  if ( (v63 & 1) == 0 )
    ExpAcquireFastMutexContended((int)&CmpTransactionListLock, v61);
  if ( v62 )
    *(_BYTE *)(v62 + 14) |= 1u;
  dword_632184 = v97[0];
  --CmpTransactionInitializingCount;
  if ( (v18[16] & 6) != 0 )
  {
    *(_QWORD *)&v64 = *(_QWORD *)v18;
    if ( *(_DWORD **)(*v18 + 4) != v18 || (_DWORD *)*v65 != v18 )
      __fastfail(3u);
    v14 = -1072103422;
    *v65 = v64;
    *(_DWORD *)(v64 + 4) = v65;
  }
  else
  {
    v18[16] = v95;
  }
  dword_632184 = 0;
  __dmb(0xBu);
  do
    v81 = __ldrex((unsigned int *)&CmpTransactionListLock);
  while ( !v81 && __strex(1u, (unsigned int *)&CmpTransactionListLock) );
  if ( v81 )
    ExpReleaseFastMutexContended((unsigned int *)&CmpTransactionListLock, v81);
  v82 = KeAbPostRelease((unsigned int)&CmpTransactionListLock);
  v83 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v84 = *(_WORD *)(v83 + 0x134) + 1;
  *(_WORD *)(v83 + 308) = v84;
  if ( !v84 && *(_DWORD *)(v83 + 100) != v83 + 100 && !*(_WORD *)(v83 + 310) )
    KiCheckForKernelApcDelivery(v82);
  __dmb(0xFu);
  if ( CmpTransactionInitializingEvent )
    ExfUnblockPushLock((int)&CmpTransactionInitializingEvent, 0);
  if ( v14 >= 0 )
  {
    *v17 = v18;
    if ( v93 )
    {
      v85 = (_DWORD *)(v92[12] + 1832);
      __pld(v85);
      v86 = (unsigned __int8 *)v85;
      v87 = *v85 & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v88 = __ldrex((unsigned int *)v86);
      while ( v88 == v87 && __strex(v87 - 2, (unsigned int *)v86) );
      if ( v88 != v87 )
        v86 = ExfReleaseRundownProtection(v86);
      v89 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v90 = (__int16)(*(_WORD *)(v89 + 0x134) + 1);
      *(_WORD *)(v89 + 308) = v90;
      if ( !v90 && *(_DWORD *)(v89 + 100) != v89 + 100 && !*(_WORD *)(v89 + 310) )
        KiCheckForKernelApcDelivery((int)v86);
    }
LABEL_175:
    JUMPOUT(0x733CDE);
  }
LABEL_132:
  ExFreePoolWithTag((unsigned int)v18);
  goto LABEL_133;
}
