// EtwSendTraceBuffer 
 
int __fastcall EtwSendTraceBuffer(int a1, int a2, unsigned int a3, int a4, int a5, int a6)
{
  int v6; // r9
  int v7; // r6
  int v10; // r8
  unsigned int v11; // r2
  int v12; // r0
  unsigned int v13; // r1
  __int16 v14; // r3
  int v15; // r5
  unsigned int *v16; // r2
  unsigned int v17; // r0
  int v18; // r2
  int v19; // r3
  unsigned int *v20; // r0
  unsigned int v21; // r1
  unsigned int v22; // r2
  BOOL v23; // r0
  unsigned int v24; // r0
  unsigned __int8 *v25; // r3
  unsigned int v26; // r1
  int v27; // r0
  unsigned int v28; // r1
  __int16 v29; // r3
  unsigned int varg_r2; // [sp+38h] [bp+10h]
  int varg_r3; // [sp+3Ch] [bp+14h]

  varg_r2 = a3;
  varg_r3 = a4;
  v6 = (unsigned __int16)a1;
  v7 = 0;
  if ( (unsigned __int16)a1 >= 0x40u )
    return -1073741816;
  v10 = 0;
  if ( (unsigned int)KeGetCurrentIrql(a1) < 2 )
  {
    v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v11 + 308);
    v12 = ExAcquireRundownProtectionCacheAwareEx((_DWORD *)EtwpLoggerRundown[v6], 1);
    if ( !v12 )
    {
LABEL_5:
      v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v14 = *(_WORD *)(v13 + 0x134) + 1;
      *(_WORD *)(v13 + 308) = v14;
      if ( !v14 && *(_DWORD *)(v13 + 100) != v13 + 100 && !*(_WORD *)(v13 + 310) )
        KiCheckForKernelApcDelivery(v12);
      return -1073741162;
    }
    v10 = 1;
  }
  v15 = WmipLoggerContext[v6];
  if ( (v15 & 1) != 0 )
  {
    if ( v10 )
    {
      v12 = ExReleaseRundownProtectionCacheAwareEx((_DWORD *)EtwpLoggerRundown[v6], 1);
      goto LABEL_5;
    }
    return -1073741162;
  }
  if ( !v15 )
    return -1073741162;
  if ( *(_DWORD *)(v15 + 248) )
  {
    if ( (*(_DWORD *)(v15 + 12) & 0x40000) != 0 )
    {
      if ( a4 )
      {
        __dmb(0xBu);
        v16 = (unsigned int *)(v15 + 168);
        do
          v17 = __ldrex(v16);
        while ( __strex(v17 + a4, v16) );
        __dmb(0xBu);
      }
      v18 = *(_DWORD *)(a3 + 48);
      v19 = *(_DWORD *)a3;
      *(_DWORD *)(a3 + 4) = v18;
      __dmb(0xBu);
      *(_DWORD *)(a3 + 8) = v19 + v18;
      *(_DWORD *)(a3 + 44) = 3;
      *(_WORD *)(a3 + 54) = 5;
      if ( (*(_WORD *)(a3 + 52) & 0x20) == 0 )
        *(_WORD *)(a3 + 40) = *(unsigned __int8 *)(a3 + 40);
      *(_DWORD *)(a3 + 56) = a5;
      *(_DWORD *)(a3 + 60) = a6;
      *(_QWORD *)(a3 + 16) = ((__int64 (*)(void))*(_DWORD *)(v15 + 32))();
      v20 = (unsigned int *)(v15 + 88);
      do
      {
        v21 = *v20;
        __dmb(0xBu);
        *(_DWORD *)(a3 + 32) = v21;
        __dmb(0xBu);
        do
          v22 = __ldrex(v20);
        while ( v22 == v21 && __strex(a3, v20) );
        __dmb(0xBu);
      }
      while ( v22 != v21 );
      if ( !v21 )
      {
        v23 = KeAreInterruptsEnabled();
        if ( v23 )
          v24 = KeGetCurrentIrql(v23);
        else
          v24 = 15;
        if ( v24 > 2 )
        {
          __dmb(0xBu);
          v25 = (unsigned __int8 *)(v15 + 613);
          do
            v26 = __ldrex(v25);
          while ( __strex(v26 | 1, v25) );
          __dmb(0xBu);
          if ( (v26 & 1) == 0 )
          {
            *(_WORD *)(v15 + 442) = KiClockTimerOwner + 32;
            KiInsertQueueDpc(v15 + 440, 0, 0, 0, 0);
          }
        }
        else
        {
          KeSetEvent(v15 + 372, 0, 0);
        }
      }
    }
    else
    {
      v7 = -1073741816;
    }
  }
  else
  {
    v7 = -1073741054;
  }
  if ( v10 )
  {
    v27 = ExReleaseRundownProtectionCacheAwareEx((_DWORD *)EtwpLoggerRundown[v6], 1);
    v28 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v29 = *(_WORD *)(v28 + 0x134) + 1;
    *(_WORD *)(v28 + 308) = v29;
    if ( !v29 && *(_DWORD *)(v28 + 100) != v28 + 100 && !*(_WORD *)(v28 + 310) )
      KiCheckForKernelApcDelivery(v27);
  }
  return v7;
}
