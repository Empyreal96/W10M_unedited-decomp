// KeStartDynamicProcessor 
 
int __fastcall KeStartDynamicProcessor(int a1, int a2, int a3, _DWORD *a4)
{
  int v7; // r4
  unsigned int v8; // r8
  int v9; // r4
  unsigned int v10; // r0
  int v11; // r2
  int v12; // r4
  unsigned int v13; // r1
  int v14; // r0

  v7 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  if ( v7 != PsInitialSystemProcess || !KeDynamicPartitioningSupported )
    return -1073741823;
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v9 = KeAbPreAcquire((unsigned int)&KiDynamicProcessorLock, 0, 0);
  do
    v10 = __ldrex((unsigned __int8 *)&KiDynamicProcessorLock);
  while ( __strex(v10 & 0xFE, (unsigned __int8 *)&KiDynamicProcessorLock) );
  __dmb(0xBu);
  if ( (v10 & 1) == 0 )
    v10 = ExpAcquireFastMutexContended((int)&KiDynamicProcessorLock, v9);
  if ( v9 )
    *(_BYTE *)(v9 + 14) |= 1u;
  v11 = KeNumberProcessors_0;
  dword_624E44 = v8;
  if ( KeNumberProcessors_0 >= (unsigned int)KeMaximumProcessors )
  {
    v12 = -1073741223;
  }
  else
  {
    *a4 = KeNumberProcessors_0;
    v12 = KiStartDynamicProcessor(v10, a2, a3, v11);
  }
  dword_624E44 = 0;
  __dmb(0xBu);
  do
    v13 = __ldrex((unsigned int *)&KiDynamicProcessorLock);
  while ( !v13 && __strex(1u, (unsigned int *)&KiDynamicProcessorLock) );
  if ( v13 )
    ExpReleaseFastMutexContended((unsigned int *)&KiDynamicProcessorLock, v13);
  KeAbPostRelease((unsigned int)&KiDynamicProcessorLock);
  if ( v12 >= 0 )
  {
    v14 = PnpInitializeProcessor();
    PsUpdateActiveProcessAffinity(v14);
  }
  return v12;
}
