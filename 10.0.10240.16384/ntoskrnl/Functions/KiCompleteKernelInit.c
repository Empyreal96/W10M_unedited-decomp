// KiCompleteKernelInit 
 
int __fastcall KiCompleteKernelInit(int a1, int a2, int a3)
{
  int v6; // r2
  int v7; // r1
  int v8; // r0
  unsigned __int8 *v9; // r3
  unsigned int v10; // r2
  int v11; // r6
  unsigned int *v12; // r4
  unsigned int v13; // r2
  unsigned int v15; // r6
  unsigned int v16; // r1
  unsigned int *v17; // r0
  unsigned int v18; // r2
  unsigned int v19; // r2

  if ( !a3 )
  {
    *(_DWORD *)(a1 + 1736) = KiMaximumDpcQueueDepth;
    *(_DWORD *)(a1 + 1744) = KiMinimumDpcRate;
    *(_DWORD *)(a1 + 2324) = KiAdjustDpcThreshold;
    RtlInitializeHistoryTable();
  }
  KfRaiseIrql(2);
  __enable_irq();
  KeAttachProcess(PsInitialSystemProcess);
  if ( !a3 )
  {
    v15 = *(_DWORD *)(PsInitialSystemProcess + 28);
    v16 = *(_DWORD *)(PsInitialSystemProcess + 36);
    v17 = (unsigned int *)&KiAsidTable[32 * v16];
    do
    {
      v18 = __ldrex(v17);
      v19 = v18 + 1;
    }
    while ( __strex(v19, v17) );
    if ( (v19 & 0xFFFFC000) != (v15 & 0xFFFFC000) )
      return sub_6943EC();
    if ( KiAsidA9Errata )
    {
      __dsb(0xFu);
      __mcr(15, 0, 0xFFu, 13, 0, 1);
      __isb(0xFu);
      __mcr(15, 0, v15, 2, 0, 0);
      __isb(0xFu);
      __dsb(0xFu);
    }
    else
    {
      __mcr(15, 0, 0xFFu, 13, 0, 1);
      __isb(0xFu);
      __mcr(15, 0, v15, 2, 0, 0);
      __isb(0xFu);
    }
    __mcr(15, 0, v16, 13, 0, 1);
    __isb(0xFu);
    KeAbInitialize();
    dword_624EFC = (int)&dword_624EF8;
    dword_624EF8 = (int)&dword_624EF8;
    dword_624F00 = 0;
    KeInitializeTimer2((int)KiForegroundState, (int)KiForegroundTimerCallback, 0, 8);
    KeInitializeDpc((int)&unk_624EB8, (int)KiProcessPendingForegroundBoosts, 0);
    KeInitializeDpc((int)&unk_624ED8, (int)KiTriggerForegroundBoostDpc, 0);
  }
  v6 = *(unsigned __int8 *)(a1 + 1053);
  v7 = *(_DWORD *)(a1 + 2360) + 136;
  __dmb(0xBu);
  v8 = 1 << (v6 & 7);
  v9 = (unsigned __int8 *)(v7 + (v6 >> 3));
  do
    v10 = __ldrex(v9);
  while ( __strex(v10 | v8, v9) );
  __dmb(0xBu);
  v11 = 0;
  v12 = (unsigned int *)(a1 + 24);
  while ( 1 )
  {
    do
      v13 = __ldrex(v12);
    while ( __strex(1u, v12) );
    __dmb(0xBu);
    if ( !v13 )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
    }
    while ( *v12 );
  }
  *(_BYTE *)(a1 + 19) = 1;
  if ( !*(_DWORD *)(a1 + 8) )
  {
    v11 = 1;
    KiSetProcessorIdle(a1, 1, 1);
  }
  KiAbProcessThreadPriorityModification(a2, 0, 1);
  *(_BYTE *)(a2 + 123) = 0;
  if ( v11 )
    KiUpdatePriorityMatrix(a1, a2);
  __dmb(0xBu);
  *v12 = 0;
  return KiCreateCpuSetForProcessor(a1);
}
