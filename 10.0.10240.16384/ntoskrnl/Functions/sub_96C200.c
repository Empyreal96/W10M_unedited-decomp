// sub_96C200 
 
int __fastcall sub_96C200(int a1, int a2, int a3)
{
  int v3; // r3
  __int64 v4; // r0
  __int64 v5; // r0
  unsigned int v6; // r2
  unsigned __int8 *v7; // r5
  int v8; // r0
  int v9; // r4
  unsigned int v10; // r2
  unsigned int v11; // r0
  int *v12; // r5
  int v13; // r3
  int v14; // t1
  unsigned int *v15; // r5
  int v16; // r1
  unsigned int v17; // r2
  int v18; // r0
  unsigned int v19; // r1
  __int16 v20; // r3
  unsigned __int64 v21; // r0
  int v22; // r2
  int v23; // r2
  unsigned int v24; // r2
  char *v25; // r3
  char v26; // r7
  char v27; // lr
  char v28; // r4
  int v29; // r10
  __int64 v30; // kr18_8
  unsigned int v31; // r1
  unsigned int v32; // r5
  int v33; // r4
  __int64 v34; // kr28_8
  unsigned int v35; // r7
  unsigned int v36; // r9
  unsigned __int64 v37; // r0
  __int64 v38; // r2
  int *v40; // r8
  int v41; // r3
  unsigned int v42; // r6
  unsigned int v43; // r9
  int v44; // r5
  int v45; // r3
  int v46; // r1
  int v47; // r2
  _DWORD *v48; // r3
  int v49; // r3
  unsigned int v50; // r4
  unsigned int v51; // r9
  unsigned int v52; // r0
  __int64 *v53; // r9
  unsigned int v54; // t1
  unsigned int v55; // r1
  unsigned int v56; // r5
  int v57; // r4
  unsigned int v58; // r1
  int v59; // r0
  int v60; // r8
  unsigned __int16 v61; // [sp+10h] [bp-58h] BYREF
  int v62; // [sp+14h] [bp-54h] BYREF
  int v63; // [sp+18h] [bp-50h]
  int v64; // [sp+1Ch] [bp-4Ch] BYREF
  int v65[4]; // [sp+20h] [bp-48h] BYREF
  _DWORD v66[14]; // [sp+30h] [bp-38h] BYREF

  *v40 = a3;
  if ( a3 < 32 )
    *v40 = 32;
  v41 = ExpWorkerThreadTimeoutInSeconds;
  if ( ExpWorkerThreadTimeoutInSeconds > 3600 )
  {
    v41 = 3600;
    ExpWorkerThreadTimeoutInSeconds = 3600;
  }
  if ( v41 < 60 )
    ExpWorkerThreadTimeoutInSeconds = 60;
  __dmb(0xBu);
  v42 = 0;
  ExpInstanceAllocationMask = -2;
  if ( KeNumberNodes )
  {
    v43 = 0;
    do
    {
      v44 = (int)*(&KeNodeBlock + v42);
      if ( (_UNKNOWN *)v44 == (_UNKNOWN *)((char *)&KiNodeInit + 384 * v43) )
        v44 = 0;
      __dmb(0xBu);
      *(_DWORD *)(v44 + 1016) = 0;
      KeQueryNodeActiveAffinity(*(unsigned __int16 *)(v44 + 266), v65, &v61);
      memset((_BYTE *)(v44 + 416), 0, 440);
      v45 = *(_DWORD *)(v44 + 844);
      *(_DWORD *)(v44 + 828) = v44;
      v46 = v61;
      *(_DWORD *)(v44 + 844) = v45 & 0x80000000;
      *(_DWORD *)(v44 + 848) = *v40;
      *(_DWORD *)(v44 + 852) = 0;
      KeInitializePriQueue(v44 + 416, v46);
      __dmb(0xBu);
      v47 = 7;
      v48 = (_DWORD *)(v44 + 388);
      *(_DWORD *)(v44 + 384) = v44 + 416;
      do
      {
        __dmb(0xBu);
        *v48++ = 0;
        --v47;
      }
      while ( v47 );
      *(_BYTE *)(v44 + 856) = 1;
      *(_BYTE *)(v44 + 857) = 0;
      *(_BYTE *)(v44 + 858) = 4;
      *(_DWORD *)(v44 + 860) = 1;
      *(_DWORD *)(v44 + 864) = v44 + 864;
      *(_DWORD *)(v44 + 868) = v44 + 864;
      KeInitializeTimerEx((_DWORD *)(v44 + 872), 1);
      *(_BYTE *)(v44 + 920) = 1;
      *(_BYTE *)(v44 + 922) = 4;
      *(_BYTE *)(v44 + 921) = 0;
      *(_DWORD *)(v44 + 924) = 0;
      *(_DWORD *)(v44 + 928) = v44 + 928;
      *(_DWORD *)(v44 + 932) = v44 + 928;
      v3 = *(_DWORD *)(v44 + 1016) | 2;
      __dmb(0xBu);
      *(_DWORD *)(v44 + 1016) = v3;
      if ( v65[0] )
      {
        *(_DWORD *)(v44 + 1012) = KeSelectIdealProcessor(v44, (int)v65, 0);
        v63 = ExpCreateSystemThreadForNode((int)&v62, v44);
        if ( v63 < 0 )
          break;
        ObReferenceObjectByHandle(v62, 0x100000, 0, 0, (int)&v64, 0);
        *(_DWORD *)(v44 + 1008) = v64;
        ZwClose();
        v49 = *(_DWORD *)(v44 + 1016) | 1;
        __dmb(0xBu);
        *(_DWORD *)(v44 + 1016) = v49;
      }
      v42 = (unsigned __int16)(v43 + 1);
      v43 = v42;
    }
    while ( v42 < (unsigned __int16)KeNumberNodes );
  }
  KeInitializeTimer2((int)ExpThreadReaperTimer, (int)ExpSetThreadReaperEvents, 0, 8);
  v66[0] = 0;
  v66[1] = 0;
  v66[2] = -1;
  v66[3] = -1;
  KeSetTimer2(
    ExpThreadReaperTimer,
    -((ExpWorkerThreadTimeoutInSeconds * (__int64)(int)dword_989680) >> 2),
    (ExpWorkerThreadTimeoutInSeconds * (__int64)(int)dword_989680) >> 2,
    (int)v66);
  ExpLegacyWorkerInitialization();
  if ( !qword_646250 )
  {
    LODWORD(v4) = ReadTimeStampCounter();
    qword_646250 = (41929663 * (unsigned int)(v4 >> 4)) ^ 0xB8Ai64;
    if ( !(_DWORD)qword_646250 )
      qword_646250 = 1i64;
    LODWORD(v5) = ReadTimeStampCounter();
    dword_646258 = (41929663 * (v5 >> 4)) ^ 0x5C5;
    dword_64625C = 0;
    v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v6 + 310);
    v7 = (unsigned __int8 *)(ObpTypeObjectType + 128);
    v8 = KeAbPreAcquire(ObpTypeObjectType + 128, 0, 0);
    v9 = v8;
    do
      v10 = __ldrex(v7);
    while ( __strex(v10 | 1, v7) );
    __dmb(0xBu);
    if ( (v10 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(v7, v8, (unsigned int)v7);
    if ( v9 )
      *(_BYTE *)(v9 + 14) |= 1u;
    v11 = 0;
    v50 = *(_DWORD *)(ObpTypeObjectType + 24);
    dword_646268 = v50;
    unk_64626C = 0;
    v51 = v50;
    if ( v50 )
    {
      v12 = ObpObjectTypes;
      while ( 1 )
      {
        v14 = *v12++;
        v13 = v14;
        if ( !v14 )
          break;
        if ( (*(_BYTE *)(v13 + 42) & 0x40) != 0 )
          byte_646270[v11 >> 3] |= 1 << (v11 & 7);
        if ( ++v11 >= v50 )
          goto LABEL_39;
      }
      dword_646268 = v11;
      unk_64626C = 0;
      v50 = v11;
      v51 = v11;
    }
LABEL_39:
    v15 = (unsigned int *)(ObpTypeObjectType + 128);
    __pld((void *)(ObpTypeObjectType + 128));
    v16 = *v15;
    if ( (*v15 & 0xFFFFFFF0) > 0x10 )
      v52 = v16 - 16;
    else
      v52 = 0;
    if ( (v16 & 2) != 0 )
      goto LABEL_16;
    __dmb(0xBu);
    do
      v17 = __ldrex(v15);
    while ( v17 == v16 && __strex(v52, v15) );
    if ( v17 != v16 )
LABEL_16:
      ExfReleasePushLock(v15, v16);
    v18 = KeAbPostRelease((unsigned int)v15);
    v19 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v20 = *(_WORD *)(v19 + 0x136) + 1;
    *(_WORD *)(v19 + 310) = v20;
    if ( !v20 && *(_DWORD *)(v19 + 100) != v19 + 100 )
      KiCheckForKernelApcDelivery(v18);
    if ( v50 )
    {
      LODWORD(v21) = ReadTimeStampCounter();
      if ( !v51 )
        __brkdiv0();
      _rt_udiv64(v51, 41929663 * (v21 >> 4));
      v23 = ObpObjectTypes[v22];
      *(_QWORD *)&dword_646290 = v23;
      v53 = (__int64 *)(v23 + 88);
      v24 = v23 + 120;
      v25 = (char *)v53;
      if ( (unsigned int)v53 < v24 )
      {
        do
        {
          __pld(v25);
          v25 += 128;
        }
        while ( (unsigned int)v25 < v24 );
      }
      v59 = HIDWORD(qword_646250);
      v58 = qword_646250;
      v60 = 32;
      v26 = dword_646258 & 0x3F;
      v27 = 64 - (dword_646258 & 0x3F);
      v28 = 32 - (dword_646258 & 0x3F);
      v29 = 4;
      do
      {
        v30 = *v53++;
        v60 -= 8;
        v32 = (__PAIR64__(v59, v58) - v30) >> 32;
        v31 = v58 - v30;
        v33 = (v32 << v27) | (v31 >> ((dword_646258 & 0x3F) - 32)) | (v31 << v28);
        v58 = (v31 << v27) | (__PAIR64__(v32, v31) >> v26);
        v59 = v33 | (v32 >> v26);
        v28 = 32 - (dword_646258 & 0x3F);
        --v29;
      }
      while ( v29 );
      for ( ; v60; --v60 )
      {
        v54 = *(unsigned __int8 *)v53;
        v53 = (__int64 *)((char *)v53 + 1);
        v56 = (__PAIR64__(v59, v58) - v54) >> 32;
        v55 = v58 - v54;
        v57 = __PAIR64__(v56, v55) << v27 >> 32;
        v58 = (v55 << v27) | (__PAIR64__(v56, v55) >> v26);
        v59 = v57 | (v56 >> v26);
      }
      *(_DWORD *)&algn_646294[4] = v58;
      *(_DWORD *)&algn_646294[8] = v59;
      do
      {
        v34 = MEMORY[0xFFFF93B0];
        while ( 1 )
        {
          v35 = MEMORY[0xFFFF900C];
          __dmb(0xBu);
          v36 = MEMORY[0xFFFF9008];
          __dmb(0xBu);
          if ( v35 == MEMORY[0xFFFF9010] )
            break;
          __dmb(0xAu);
          __yield();
        }
      }
      while ( v34 != MEMORY[0xFFFF93B0] );
      LODWORD(v37) = ReadTimeStampCounter();
      _rt_udiv64(80000000000i64, 41929663 * (v37 >> 4));
      qword_646260 = v38 - v34 + __PAIR64__(v35, v36) + 288000000000i64;
    }
    else
    {
      qword_646250 = 0i64;
    }
  }
  ExpDebuggerDpc = 19;
  byte_61A041 = 1;
  word_61A042 = 0;
  dword_61A04C = (int)ExpDebuggerDpcRoutine;
  dword_61A050 = 0;
  dword_61A05C = 0;
  dword_61A048 = 0;
  dword_619FC8 = (int)ExpDebuggerWorker;
  dword_619FCC = 0;
  ExpDebuggerWorkItem = 0;
  __dmb(0xBu);
  ExpDebuggerWork = 1;
  ExQueueDebuggerWorker();
  return ((int (__fastcall *)(int))v66[13])(v63);
}
