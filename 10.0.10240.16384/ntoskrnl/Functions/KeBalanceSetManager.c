// KeBalanceSetManager 
 
int KeBalanceSetManager()
{
  int v0; // r9
  int v2; // r0
  unsigned int v3; // r2
  unsigned int v4; // r2
  int v5; // r1
  void **v6; // r0
  int v7; // t1
  int v8; // r0
  unsigned int v9; // r5
  void **v10; // r8
  int v11; // r6
  unsigned int v12; // r10
  int v13; // r2
  int v14; // t1
  int v15; // r3
  int v16; // lr
  unsigned int *v17; // r2
  unsigned int v18; // r4
  int v19; // r3
  unsigned int *v20; // r2
  unsigned int v21; // r4
  unsigned int v22[10]; // [sp+10h] [bp-28h] BYREF

  KeSetPriorityThread(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, 17);
  if ( !KeMaximumIncrement )
    __brkdiv0();
  KiStackProtectTime = _rt_udiv64((unsigned int)KeMaximumIncrement, 0x8F0D180ui64);
  v22[0] = (unsigned int)&KiBalanceSetManagerPeriodicEvent;
  v0 = 8;
  v22[1] = dword_6404B8 + 72;
  while ( !KeWaitForMultipleObjects(2u, v22, 1, 0, 0, 0, 0, 0) )
  {
    if ( IopIrpCreditsEnabled > 1 && (unsigned int)KeNumberProcessors_0 > 1 )
    {
      v4 = 0;
      v5 = 0;
      v6 = &KiProcessorBlock;
      do
      {
        v7 = (int)*v6++;
        ++v4;
        v5 += *(_DWORD *)(v7 + 1616);
      }
      while ( v4 < KeNumberProcessors_0 );
      if ( !KeNumberProcessors_0 )
        __brkdiv0();
      v8 = v5 / KeNumberProcessors_0;
      v9 = 0;
      v10 = &KiProcessorBlock;
      v11 = 0;
      v12 = KeNumberProcessors_0 - 1;
      do
      {
        v14 = (int)*v10++;
        v13 = v14;
        v15 = *(_DWORD *)(v14 + 1616);
        v16 = v8 - v15;
        if ( v8 != v15 )
        {
          __dmb(0xBu);
          v17 = (unsigned int *)(v13 + 1616);
          do
            v18 = __ldrex(v17);
          while ( __strex(v18 + v16, v17) );
          __dmb(0xBu);
          v11 += v16;
        }
        ++v9;
      }
      while ( v9 < v12 );
      if ( v11 )
      {
        v19 = (int)*(&KiProcessorBlock + v9);
        __dmb(0xBu);
        v20 = (unsigned int *)(v19 + 1616);
        do
          v21 = __ldrex(v20);
        while ( __strex(v21 - v11, v20) );
        __dmb(0xBu);
      }
    }
    ExAdjustLookasideDepth();
    v2 = EtwAdjustTraceBuffers();
    MiWorkingSetManager(v2, 0);
    PsEnforceExecutionLimits();
    if ( !--v0 )
    {
      v0 = 8;
      __dmb(0xBu);
      do
        v3 = __ldrex(&KiStackOutSwapRequest);
      while ( !v3 && __strex(1u, &KiStackOutSwapRequest) );
      __dmb(0xBu);
      if ( !v3 )
        KeSetEvent((int)&KiSwapEvent, 1, 0);
    }
  }
  return sub_551BD0();
}
