// KeTerminateThread 
 
int __fastcall KeTerminateThread(int a1)
{
  int v2; // r3
  int v3; // r5
  __int64 v4; // r2
  unsigned int v5; // r2
  __int64 v6; // r0
  unsigned int v7; // r1
  int v8; // r1
  unsigned int v9; // r10
  unsigned int v10; // r2
  int *v11; // r8
  int *v12; // r7
  unsigned int v13; // r1
  int *v14; // r6
  int v15; // r0
  int v16; // r1
  unsigned int v17; // r2
  unsigned int *v18; // r1
  int v19; // r3
  int *v21; // r5
  int v22; // r3
  int v23; // r2
  int v24; // r6
  unsigned int v25; // r0
  int v26; // r9
  unsigned int v27; // r2
  _DWORD *v28; // r1
  unsigned int v29; // r1
  __int64 v30; // r0
  int v31; // r0
  unsigned int *v32; // r1
  int *v33; // r0
  unsigned int *v34; // r2
  unsigned int v35; // r0
  BOOL v36; // r2
  unsigned int v37; // r2
  unsigned int v38; // r1
  unsigned int v39; // r2
  unsigned int v40; // r2
  char v41[4]; // [sp+8h] [bp-30h] BYREF
  unsigned int v42; // [sp+Ch] [bp-2Ch]
  int var28[12]; // [sp+10h] [bp-28h] BYREF

  if ( (*(_DWORD *)(a1 + 76) & 0x1000) != 0 )
    sub_5154C0();
  v2 = *(_DWORD *)(a1 + 236);
  if ( v2 )
    KeDisableProfiling(a1, *(_DWORD *)(v2 + 8));
  v3 = *(_DWORD *)(a1 + 336);
  *(_BYTE *)(a1 + 395) = 22;
  KiAcquireProcessLockExclusive(v3, v41);
  v4 = *(_QWORD *)(a1 + 468);
  if ( (_DWORD)v4 != HIDWORD(v4) )
    goto LABEL_6;
  KeAcquireInStackQueuedSpinLockAtDpcLevel(&KiProcessListLock, var28, v4, HIDWORD(v4));
  v30 = *(_QWORD *)(v3 + 120);
  if ( *(_DWORD *)(v30 + 4) != v3 + 120 || *(_DWORD *)HIDWORD(v30) != v3 + 120 )
    __fastfail(3u);
  *(_DWORD *)HIDWORD(v30) = v30;
  *(_DWORD *)(v30 + 4) = HIDWORD(v30);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseQueuedSpinLockInstrumented(var28, var28[11]);
  }
  else
  {
    v31 = var28[0];
    if ( !var28[0] )
    {
      v32 = (unsigned int *)var28[1];
      __dmb(0xBu);
      do
        v33 = (int *)__ldrex(v32);
      while ( v33 == var28 && __strex(0, v32) );
      if ( v33 == var28 )
        goto LABEL_6;
      v31 = KxWaitForLockChainValid(var28);
    }
    var28[0] = 0;
    __dmb(0xBu);
    v34 = (unsigned int *)(v31 + 4);
    do
      v35 = __ldrex(v34);
    while ( __strex(v35 ^ 1, v34) );
  }
  do
LABEL_6:
    v5 = __ldrex((unsigned __int8 *)v3);
  while ( __strex(v5 | 0x80, (unsigned __int8 *)v3) );
  while ( 1 )
  {
    __dmb(0xBu);
    if ( !(v5 >> 7) )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
    }
    while ( (*(_DWORD *)v3 & 0x80) != 0 );
    do
      v5 = __ldrex((unsigned __int8 *)v3);
    while ( __strex(v5 | 0x80, (unsigned __int8 *)v3) );
  }
  v6 = *(_QWORD *)(a1 + 468);
  if ( *(_DWORD *)(v6 + 4) != a1 + 468 || *(_DWORD *)HIDWORD(v6) != a1 + 468 )
    __fastfail(3u);
  *(_DWORD *)HIDWORD(v6) = v6;
  *(_DWORD *)(v6 + 4) = HIDWORD(v6);
  __dmb(0xBu);
  do
    v7 = __ldrex((unsigned int *)v3);
  while ( __strex(v7 & 0xFFFFFF7F, (unsigned int *)v3) );
  if ( *(_DWORD *)(a1 + 68) )
    KiRemoveThreadFromSchedulingGroup(a1);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v3 + 48);
  }
  else
  {
    __dmb(0xBu);
    *(_DWORD *)(v3 + 48) = 0;
  }
  v8 = *(_DWORD *)(a1 + 152);
  if ( v8 )
    KiActivateWaiterQueueWithNoLocks(a1, v8, a1 + 312);
  v9 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
  do
    v10 = __ldrex((unsigned __int8 *)a1);
  while ( __strex(v10 | 0x80, (unsigned __int8 *)a1) );
  while ( 1 )
  {
    __dmb(0xBu);
    if ( !(v10 >> 7) )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
    }
    while ( (*(_DWORD *)a1 & 0x80) != 0 );
    do
      v10 = __ldrex((unsigned __int8 *)a1);
    while ( __strex(v10 | 0x80, (unsigned __int8 *)a1) );
  }
  v11 = *(int **)(a1 + 8);
  *(_DWORD *)(a1 + 4) = 1;
  v12 = (int *)(a1 + 8);
  while ( v11 != v12 )
  {
    v21 = v11;
    v22 = *((unsigned __int8 *)v11 + 8);
    v11 = (int *)*v11;
    if ( v22 == 1 )
    {
      v23 = *((unsigned __int16 *)v21 + 5);
      goto LABEL_38;
    }
    if ( v22 == 2 )
    {
      *((_BYTE *)v21 + 9) = 5;
      v24 = v21[3];
      *v21 = 0;
      KfRaiseIrql(2);
      v25 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
      v26 = *(_DWORD *)(v25 + 4);
      v42 = v25;
      if ( (dword_682604 & 0x1000000) != 0 )
      {
        v36 = *(_BYTE *)(v26 + 132) == 2
           && *(_DWORD *)(v26 + 328) == *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
        EtwTraceEnqueueWork(v26, v21, v36);
      }
      do
        v27 = __ldrex((unsigned __int8 *)v24);
      while ( __strex(v27 | 0x80, (unsigned __int8 *)v24) );
      while ( 1 )
      {
        __dmb(0xBu);
        if ( !(v27 >> 7) )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( (*(_DWORD *)v24 & 0x80) != 0 );
        do
          v27 = __ldrex((unsigned __int8 *)v24);
        while ( __strex(v27 | 0x80, (unsigned __int8 *)v24) );
      }
      if ( *(_DWORD *)(v24 + 12) == v24 + 8
        || *(_DWORD *)(v24 + 24) >= *(_DWORD *)(v24 + 28)
        || *(_DWORD *)(v26 + 152) == v24 && *(_BYTE *)(v26 + 395) == 15
        || !KiWakeQueueWaiter() )
      {
        ++*(_DWORD *)(v24 + 4);
        v28 = *(_DWORD **)(v24 + 20);
        *v21 = v24 + 16;
        v21[1] = (int)v28;
        if ( *v28 != v24 + 16 )
          __fastfail(3u);
        *v28 = v21;
        *(_DWORD *)(v24 + 20) = v21;
      }
      __dmb(0xBu);
      do
        v29 = __ldrex((unsigned int *)v24);
      while ( __strex(v29 & 0xFFFFFF7F, (unsigned int *)v24) );
    }
    else
    {
      v23 = 256;
LABEL_38:
      KiTryUnwaitThread(v9, v21, v23, 0);
    }
  }
  *v12 = (int)v12;
  *(_DWORD *)(a1 + 12) = a1 + 8;
  __dmb(0xBu);
  do
    v13 = __ldrex((unsigned int *)a1);
  while ( __strex(v13 & 0xFFFFFF7F, (unsigned int *)a1) );
  *(_BYTE *)(a1 + 132) = 4;
  if ( *(_DWORD *)(v9 + 1540) )
    KiProcessThreadWaitList(v9, 1, 0, 0);
  v14 = (int *)(a1 + 860);
  __pld(&PsReaperListHead);
  v15 = PsReaperListHead;
  do
  {
    *v14 = v15;
    v16 = v15;
    __dmb(0xBu);
    do
      v17 = __ldrex((unsigned int *)&PsReaperListHead);
    while ( v17 == v15 && __strex((unsigned int)v14, (unsigned int *)&PsReaperListHead) );
    v15 = v17;
  }
  while ( v17 != v16 );
  if ( v17 )
  {
    if ( dword_61DAEC )
    {
      __dmb(0xBu);
      do
        v38 = __ldrex((unsigned __int8 *)&dword_61DAEC);
      while ( __strex(v38 & 0xFE, (unsigned __int8 *)&dword_61DAEC) );
      __dmb(0xBu);
      if ( (v38 & 1) != 0 && !ExQueueWorkItemEx(&PsReaperWorkItem, 2, 0xFFFF) )
      {
        __dmb(0xBu);
        do
          v39 = __ldrex((unsigned __int8 *)&dword_61DAEC);
        while ( __strex(v39 | 1, (unsigned __int8 *)&dword_61DAEC) );
        goto LABEL_95;
      }
    }
  }
  else
  {
    if ( ExQueueWorkItemEx(&PsReaperWorkItem, 2, -1) )
      goto LABEL_34;
    __dmb(0xBu);
    do
      v37 = __ldrex((unsigned __int8 *)&dword_61DAEC);
    while ( __strex(v37 | 1, (unsigned __int8 *)&dword_61DAEC) );
LABEL_95:
    __dmb(0xBu);
  }
LABEL_34:
  __dmb(0xFu);
  v18 = (unsigned int *)(a1 + 44);
  v19 = *(_DWORD *)(a1 + 44);
  __dmb(0xBu);
  if ( v19 )
  {
    while ( 1 )
    {
      do
        v40 = __ldrex(v18);
      while ( __strex(1u, v18) );
      __dmb(0xBu);
      if ( !v40 )
        break;
      do
      {
        __dmb(0xAu);
        __yield();
      }
      while ( *v18 );
    }
    __dmb(0xBu);
    *v18 = 0;
  }
  return KiSwapThread(a1, v9);
}
