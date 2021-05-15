// DbgkpWerDeferredWriteRoutine 
 
_DWORD *__fastcall DbgkpWerDeferredWriteRoutine(_DWORD *a1)
{
  unsigned int v2; // r2
  unsigned int v3; // r1
  int v4; // r6
  __int64 v5; // r2
  int v6; // r5
  const char *v7; // r2
  int v8; // r3
  int v9; // r0
  unsigned int v10; // r1
  unsigned int v11; // r1
  __int16 v12; // r3
  _DWORD *v14; // [sp+0h] [bp-20h]

  v14 = a1;
  DbgPrintEx(5, 3, (int)"DBGK: DbgkpWerDeferredWriteRoutine entered, context 0x%p\n", (int)a1);
  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  v3 = a1[22];
  v4 = *(_DWORD *)(v3 + 12);
  v5 = -10000000i64 * DbgkpWerDeferredWriteTimeoutSeconds;
  if ( v4 )
    KiSetTimerEx(*(_DWORD *)(v3 + 12), v3, v5, 0, 0, 0);
  v6 = IoWriteDeferredLiveDumpData(a1[23], v3, v5, HIDWORD(v5));
  KeCancelTimer(v4);
  a1[23] = 0;
  if ( v6 >= 0 )
  {
    v9 = WerLiveKernelSubmitReport_0();
    if ( v9 >= 0 )
    {
      a1[20] |= 1u;
      goto LABEL_9;
    }
    v7 = "DBGK: DbgkpWerDeferredWriteRoutine: WerLiveKernelSubmitReport failed with status 0x%X\n";
    v8 = v9;
  }
  else
  {
    v7 = "DBGK: DbgkpWerDeferredWriteRoutine: dump write failed with status 0x%X\n";
    v8 = v6;
  }
  DbgPrintEx(5, 0, (int)v7, v8);
LABEL_9:
  DbgkpWerCleanupContext(a1);
  __dmb(0xBu);
  do
    v10 = __ldrex((unsigned int *)&DbgkpBusy);
  while ( __strex(0, (unsigned int *)&DbgkpBusy) );
  __dmb(0xBu);
  v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v12 = *(_WORD *)(v11 + 0x134) + 1;
  *(_WORD *)(v11 + 308) = v12;
  if ( !v12 && *(_DWORD *)(v11 + 100) != v11 + 100 && !*(_WORD *)(v11 + 310) )
    KiCheckForKernelApcDelivery(0);
  return v14;
}
