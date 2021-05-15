// KeInvalidateAllCaches 
 
int __fastcall KeInvalidateAllCaches(int a1, int a2, int a3, int a4)
{
  int v4; // r9
  int v5; // r0
  int v6; // r1
  unsigned int v8; // r2
  int v9; // r5
  unsigned int v10; // r2
  unsigned int v11; // r2
  int v12[8]; // [sp+8h] [bp-20h] BYREF

  v12[0] = a4;
  v4 = KfRaiseIrql(12);
  __pld(&KiCacheFlushTimeStamp);
  v5 = 1;
  v6 = KiCacheFlushTimeStamp;
  if ( (KiCacheFlushTimeStamp & 1) != 0 )
    return sub_50A9B0(1, v6);
  __dmb(0xBu);
  do
    v8 = __ldrex((unsigned __int8 *)&KiCacheFlushTimeStamp);
  while ( __strex(v8 | 1, (unsigned __int8 *)&KiCacheFlushTimeStamp) );
  __dmb(0xBu);
  if ( (v8 & 1) != 0 )
    return sub_50A9B0(1, v6);
  if ( KiExternalCacheGlobalSyncRequired )
  {
    if ( (dword_682604 & 0x210000) != 0 )
    {
      v5 = KiAcquireSpinLockInstrumented(&KiReverseStallIpiLock);
    }
    else
    {
      do
        v11 = __ldrex((unsigned int *)&KiReverseStallIpiLock);
      while ( __strex(1u, (unsigned int *)&KiReverseStallIpiLock) );
      __dmb(0xBu);
      if ( v11 )
        v5 = KxWaitForSpinLockAndAcquire(&KiReverseStallIpiLock);
    }
  }
  v12[0] = KeNumberProcessors_0 - 1;
  if ( KeNumberProcessors_0 != 1 )
    v5 = KiIpiSendPacket(1, 0, KiInvalidateAllCachesTarget, v12, 0, 0);
  KiInvalidateCurrentCache(v5);
  while ( v12[0] )
  {
    __dmb(0xAu);
    __yield();
  }
  __dmb(0xFu);
  if ( (__get_CPSR() & 0x80) != 0 )
  {
    v9 = 0;
  }
  else
  {
    __disable_irq();
    v9 = 1;
  }
  off_617A84(1);
  if ( v9 )
    __enable_irq();
  __dmb(0xBu);
  do
    v10 = __ldrex((unsigned int *)&KiCacheFlushTimeStamp);
  while ( __strex(v10 + 1, (unsigned int *)&KiCacheFlushTimeStamp) );
  __dmb(0xBu);
  if ( KiExternalCacheGlobalSyncRequired )
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(&KiReverseStallIpiLock);
    }
    else
    {
      __dmb(0xBu);
      KiReverseStallIpiLock = 0;
    }
  }
  KfLowerIrql(v4);
  return 1;
}
