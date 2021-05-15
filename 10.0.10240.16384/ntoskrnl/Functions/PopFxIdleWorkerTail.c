// PopFxIdleWorkerTail 
 
// local variable allocation has failed, the output may be wrong!
_DWORD *__fastcall PopFxIdleWorkerTail(int a1, int a2, int *a3)
{
  int v4; // r10
  unsigned int *v6; // r7
  int v7; // r4
  unsigned __int64 v8; // kr00_8
  int v9; // r5
  _DWORD *result; // r0
  unsigned int v11; // r2
  int v12; // r3
  unsigned __int64 *v13; // lr
  unsigned int v14; // r5 OVERLAPPED
  unsigned int v15; // r6 OVERLAPPED
  unsigned __int64 v16; // r0
  unsigned __int64 v17; // r2
  unsigned int v18; // r1
  unsigned int i; // r4
  unsigned int v20; // r2
  unsigned int v21; // r2
  unsigned int v22; // r0
  unsigned __int64 v23; // kr08_8
  int v24; // r2
  unsigned int v25; // r3
  bool v26; // cf
  int v27; // r3
  unsigned int v28; // r2
  unsigned int v29; // r0
  int v30; // r5
  unsigned int v31; // r2
  int v32; // r3
  void (__fastcall *v33)(_DWORD, int); // r3

  v4 = *(_DWORD *)(*(_DWORD *)(a1 + 392) + 4 * a2);
  v6 = (unsigned int *)(v4 + 52);
  v7 = v4 + 144;
  v8 = KeQueryInterruptTime(a1);
  v9 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return (_DWORD *)sub_54043C();
  do
    v11 = __ldrex((unsigned int *)v7);
  while ( __strex(1u, (unsigned int *)v7) );
  __dmb(0xBu);
  if ( v11 )
    KxWaitForSpinLockAndAcquire(v4 + 144);
  v12 = *(_DWORD *)(v4 + 156);
  if ( v12 && v12 >= 0 )
  {
    v23 = *(_QWORD *)(v4 + 160);
    if ( *(_BYTE *)(v4 + 148) && v8 > v23 )
    {
      v24 = *(_DWORD *)(v4 + 180);
      v25 = *(_DWORD *)(v4 + 176);
      v26 = v25 >= (unsigned int)v23;
      v27 = v25 - v23;
      *(_DWORD *)(v4 + 176) = v27 + v8;
      *(_DWORD *)(v4 + 180) = HIDWORD(v8) + __CFADD__(v27, (_DWORD)v8) + v24 - (HIDWORD(v23) + !v26);
    }
    *(_BYTE *)(v4 + 148) = 0;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(v4 + 144);
  }
  else
  {
    __dmb(0xBu);
    *(_DWORD *)v7 = 0;
  }
  KfLowerIrql(v9);
  PopDiagTraceFxComponentLogicalCondition(*(_DWORD *)(a1 + 28), a2, 0);
  v13 = (unsigned __int64 *)(a1 + 280);
  *(_QWORD *)&v14 = *(_QWORD *)(a1 + 280);
  if ( *(_QWORD *)&v14 < v8 )
  {
    do
    {
      v16 = __PAIR64__(v14, v15);
      do
        v17 = __ldrexd(v13);
      while ( v17 == __PAIR64__(v15, v14) && __strexd(v8, v13) );
      v15 = HIDWORD(v17);
      v14 = v17;
      if ( v16 == __PAIR64__(v17, HIDWORD(v17)) )
        break;
      __dmb(0xAu);
      __yield();
    }
    while ( v17 < v8 );
    v7 = v4 + 144;
    v6 = (unsigned int *)(v4 + 52);
  }
  do
    v18 = __ldrex(v6);
  while ( __strex(v18, v6) );
  if ( v18 == 0x40000000 )
  {
    result = (_DWORD *)PopPluginComponentActive(a1, a2, 0, a3);
    if ( result == (_DWORD *)1 )
      result = PopFxProcessWork(0, a3);
    for ( i = 0; i < *(_DWORD *)(v4 + 120); ++i )
      result = (_DWORD *)PoFxIdleComponent(a1, *(_DWORD *)(*(_DWORD *)(v4 + 124) + 8 * i), 2);
    __dmb(0xBu);
    do
      v20 = __ldrex(v6);
    while ( v20 == 0x40000000 && __strex(0, v6) );
    __dmb(0xBu);
    if ( v20 != 0x40000000 )
    {
      __dmb(0xBu);
      do
        v21 = __ldrex(v6);
      while ( __strex(v21 + 1, v6) );
      __dmb(0xBu);
      do
        v22 = __ldrex(v6);
      while ( __strex(v22 & 0xBFFFFFFF, v6) );
      __dmb(0xBu);
      result = (_DWORD *)PopFxActivateComponentWorker(a1, v4, 0, 0);
    }
  }
  else
  {
    PopFxAddRefDevice(a1);
    __dmb(0xBu);
    do
      v28 = __ldrex(v6);
    while ( __strex(v28 + 1, v6) );
    __dmb(0xBu);
    do
      v29 = __ldrex(v6);
    while ( __strex(v29 & 0xBFFFFFFF, v6) );
    __dmb(0xBu);
    v30 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented(v7);
    }
    else
    {
      do
        v31 = __ldrex((unsigned int *)v7);
      while ( __strex(1u, (unsigned int *)v7) );
      __dmb(0xBu);
      if ( v31 )
        KxWaitForSpinLockAndAcquire(v7);
    }
    v32 = *(_DWORD *)(v7 + 12);
    if ( v32 && v32 >= 0 )
    {
      *(_QWORD *)(v7 + 16) = v8;
      *(_BYTE *)(v7 + 4) = 1;
    }
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(v7);
    }
    else
    {
      __dmb(0xBu);
      *(_DWORD *)v7 = 0;
    }
    KfLowerIrql(v30);
    PopDiagTraceFxComponentLogicalCondition(*(_DWORD *)(a1 + 28), a2, 1);
    v33 = *(void (__fastcall **)(_DWORD, int))(a1 + 60);
    if ( v33 )
      v33(*(_DWORD *)(a1 + 88), a2);
    result = (_DWORD *)PopFxCompleteComponentActivation(a1, (_DWORD *)v4, 1);
  }
  return result;
}
