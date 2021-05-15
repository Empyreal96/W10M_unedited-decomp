// KeThawExecution 
 
int __fastcall KeThawExecution(int a1, int a2, int a3, int a4)
{
  int v5; // r6
  int result; // r0
  int v7; // r0
  int v8; // r0
  int v9; // r10
  char v10; // r3
  int *v11; // r3
  unsigned int v12; // r3
  unsigned int v13; // r6
  __int64 v14; // r0
  __int64 v15; // kr00_8
  unsigned __int64 *v16; // r3
  unsigned __int64 v17; // kr08_8
  unsigned __int64 *v18; // r5
  unsigned __int64 v19; // kr10_8
  unsigned __int64 v20; // kr20_8
  int v21; // r0
  int *v22; // r0
  int v23; // [sp+0h] [bp-28h] BYREF
  int v24; // [sp+4h] [bp-24h]
  int v25; // [sp+8h] [bp-20h]

  v23 = a2;
  v24 = a3;
  v25 = a4;
  v5 = (unsigned __int8)KdPortLocked;
  if ( (KiFreezeFlag & 8) != 0 )
    return sub_51C050();
  off_617A44(0, 0);
  v7 = KeQueryPerformanceCounter(&v23, 0);
  MEMORY[0xFFFF9350] = v23;
  MEMORY[0xFFFF9354] = v24;
  KiInterruptTimeErrorAccumulator = 0;
  MEMORY[0x6376B4] = 0;
  v8 = KiSendThawExecution(v7);
  v9 = (unsigned __int8)KiOldIrql;
  v10 = KiFreezeFlag;
  KiFreezeFlag = 0;
  if ( (v10 & 1) != 0 )
  {
    if ( (dword_682604 & 0x10000) == 0 )
    {
      __dmb(0xBu);
      v11 = &KiFreezeLockBackup;
      goto LABEL_6;
    }
    v22 = &KiFreezeLockBackup;
LABEL_27:
    v8 = KiReleaseSpinLockInstrumented(v22);
    goto LABEL_7;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    v22 = &KiFreezeExecutionLock;
    goto LABEL_27;
  }
  __dmb(0xBu);
  v11 = &KiFreezeExecutionLock;
LABEL_6:
  *v11 = 0;
LABEL_7:
  if ( v5 )
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      v8 = KiReleaseSpinLockInstrumented(&KdDebuggerLock);
    }
    else
    {
      __dmb(0xBu);
      KdDebuggerLock = 0;
    }
  }
  __dsb(0xFu);
  __mcr(15, 0, 0, 8, 7, 0);
  __dsb(0xFu);
  __isb(0xFu);
  KiSweepCurrentIcache(v8);
  v12 = (unsigned int)KeGetPcr();
  v13 = (v12 & 0xFFFFF000) + 1408;
  if ( !*(_BYTE *)((v12 & 0xFFFFF000) + 0x590) && !PoAllProcIntrDisabled )
  {
    LODWORD(v14) = ReadTimeStampCounter();
    v15 = v14 - *(_QWORD *)(v13 + 2376);
    __dmb(0xBu);
    v16 = (unsigned __int64 *)(v13 + 2744);
    do
      v17 = __ldrexd(v16);
    while ( __strexd(v17 + v15, v16) );
    __dmb(0xBu);
    if ( (*(_BYTE *)(*(_DWORD *)(v13 + 4) + 2) & 0x20) != 0 )
    {
      v18 = (unsigned __int64 *)(v13 + 8 * (*(unsigned __int8 *)(v13 + 2986) + 2 * (PoGetFrequencyBucket(v13) + 1144)));
      v19 = *v18;
      __dmb(0xBu);
      do
        v20 = __ldrexd(v18);
      while ( __strexd(v19 + v15, v18) );
      __dmb(0xBu);
    }
    v21 = *(_DWORD *)(v13 + 4);
    *(_QWORD *)(v13 + 2376) += v15;
    if ( (*(_BYTE *)(v21 + 2) & 2) != 0 )
      KiBeginCounterAccumulation(v21, 0);
  }
  result = KfLowerIrql(v9);
  if ( a1 )
    __enable_irq();
  return result;
}
