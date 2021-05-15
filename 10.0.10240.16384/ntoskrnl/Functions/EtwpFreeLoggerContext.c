// EtwpFreeLoggerContext 
 
unsigned int __fastcall EtwpFreeLoggerContext(unsigned int a1, int a2, int a3, int a4)
{
  unsigned int result; // r0
  int v6; // r10
  unsigned int v7; // r1
  void **v8; // r2
  _DWORD *v9; // r3
  int v10; // r3
  int v11; // r0
  unsigned int v12; // r0
  unsigned int *v13; // r2
  unsigned int v14; // r0
  _DWORD *v15; // r5
  int v16; // r0
  int v17; // r0
  unsigned int v18; // r1
  unsigned int v19; // r1
  unsigned int v20; // r5
  unsigned int v21; // r3
  unsigned int v22; // r7
  int v23; // r6
  _DWORD *v24; // r5
  unsigned int v25; // r0
  unsigned int v26; // r0
  int v27[8]; // [sp+0h] [bp-20h] BYREF

  v27[0] = a4;
  if ( *(_WORD *)(a1 + 644) )
    return sub_7EECEC();
  EtwpShutdownConsumers(a1);
  v6 = *(_DWORD *)a1;
  ExReleaseRundownProtectionCacheAwareEx((_DWORD *)EtwpLoggerRundown[*(_DWORD *)a1], 1);
  ExWaitForRundownProtectionReleaseCacheAware((_DWORD *)EtwpLoggerRundown[v6]);
  if ( *(_DWORD *)(a1 + 224) != 1 )
    KeGenericCallDpc((int)EtwpSynchronizationDpc, 0);
  KeCancelTimer(a1 + 392);
  KeRemoveQueueDpc(a1 + 440);
  EtwpFreeTraceBufferPool(a1);
  v7 = 0;
  if ( KeNumberProcessors_0 )
  {
    v8 = &KiProcessorBlock;
    if ( !KeNumberProcessors_0 )
    {
      v9 = 0;
      goto LABEL_8;
    }
    do
    {
      v9 = *v8;
LABEL_8:
      ++v7;
      ++v8;
      v10 = v9[899] + 8 * v6;
      *(_DWORD *)(v10 + 384) = 0;
      *(_DWORD *)(v10 + 388) = 0;
    }
    while ( v7 < KeNumberProcessors_0 );
  }
  RtlFreeAnsiString((_DWORD *)(a1 + 100));
  RtlFreeAnsiString((_DWORD *)(a1 + 108));
  RtlFreeAnsiString((_DWORD *)(a1 + 116));
  RtlFreeAnsiString((_DWORD *)(a1 + 276));
  v11 = *(_DWORD *)(a1 + 524);
  if ( v11 )
    ObfDereferenceObject(v11);
  v12 = *(_DWORD *)(a1 + 572);
  if ( v12 )
    ExFreePoolWithTag(v12);
  __dmb(0xBu);
  v13 = (unsigned int *)(a1 + 576);
  do
    v14 = __ldrex(v13);
  while ( __strex(0, v13) );
  __dmb(0xBu);
  ObDereferenceSecurityDescriptor(v14 & 0xFFFFFFF8, (v14 & 7) + 1);
  if ( (*(_DWORD *)(a1 + 608) & 0x80) != 0 )
    ExFreePoolWithTag(*(_DWORD *)(a1 + 620));
  if ( (*(_DWORD *)(a1 + 608) & 0x2000) != 0 )
  {
    __dmb(0xBu);
    do
      v19 = __ldrex((unsigned int *)&dword_61ABF8);
    while ( __strex(v19 - 1, (unsigned int *)&dword_61ABF8) );
    __dmb(0xBu);
  }
  if ( (*(_DWORD *)(a1 + 608) & 0x1000000) != 0 )
    EtwpFreeStackCache(*(_DWORD *)(a1 + 624));
  if ( (*(_DWORD *)(a1 + 12) & 0x2000000) != 0 )
    EtwpFreeSystemLoggerIndex(*(unsigned __int8 *)(a1 + 610));
  v20 = *(_DWORD *)(a1 + 628);
  if ( v20 )
  {
    v21 = KeNumberProcessors_0;
    v22 = 0;
    if ( KeNumberProcessors_0 )
    {
      v23 = *(_DWORD *)(a1 + 628);
      do
      {
        if ( *(_DWORD *)(v23 + 32) )
        {
          ((void (__cdecl *)())off_617A98)();
          v21 = KeNumberProcessors_0;
        }
        ++v22;
        v23 += 4;
      }
      while ( v22 < v21 );
    }
    ExFreePoolWithTag(v20);
  }
  v24 = *(_DWORD **)(a1 + 80);
  while ( v24 != (_DWORD *)(a1 + 80) )
  {
    v25 = (unsigned int)v24;
    v24 = (_DWORD *)*v24;
    ExFreePoolWithTag(v25);
  }
  v15 = *(_DWORD **)(a1 + 632);
  while ( v15 != (_DWORD *)(a1 + 632) )
  {
    v26 = (unsigned int)v15;
    v15 = (_DWORD *)*v15;
    ExFreePoolWithTag(v26);
  }
  ExReInitializeRundownProtectionCacheAware((_DWORD *)EtwpLoggerRundown[v6]);
  PsGetMonitorContextServerSilo(EtwSiloMonitor, -1, v27);
  v16 = v27[0];
  if ( *(_DWORD *)(v27[0] + 360) == v6 )
    *(_DWORD *)(v27[0] + 360) = 64;
  PsDereferenceMonitorContextServerSilo(v16);
  v17 = *(_DWORD *)(a1 + 652);
  if ( v17 )
    PspDereferenceSiloObject(v17);
  WmipLoggerContext[v6] = 1;
  result = ExFreePoolWithTag(a1);
  __dmb(0xBu);
  do
    v18 = __ldrex((unsigned int *)&dword_61AD6C);
  while ( __strex(v18 - 1, (unsigned int *)&dword_61AD6C) );
  __dmb(0xBu);
  return result;
}
