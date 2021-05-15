// PpmUpdateProcessorIdleVeto 
 
int __fastcall PpmUpdateProcessorIdleVeto(int a1)
{
  unsigned int v2; // r5
  int v3; // r9
  int v4; // r6
  int v5; // r10
  unsigned int v6; // r2
  int v7; // r2
  unsigned int v8; // r1
  __int16 v10[2]; // [sp+0h] [bp-30h] BYREF
  int v11; // [sp+4h] [bp-2Ch]
  int v12; // [sp+8h] [bp-28h]
  int vars4; // [sp+34h] [bp+4h]

  if ( *(_BYTE *)(a1 + 7) || *(_WORD *)(a1 + 4) || (v2 = *(unsigned __int8 *)(a1 + 6), v2 >= KeNumberProcessors_0) )
  {
    v2 = -1;
    v3 = 0;
  }
  else
  {
    v3 = (int)*(&KiProcessorBlock + v2);
  }
  if ( v2 == -1 )
    return -1073741811;
  v5 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)&PpmIdleVetoLock);
  }
  else
  {
    do
      v6 = __ldrex((unsigned int *)&PpmIdleVetoLock);
    while ( __strex(1u, (unsigned int *)&PpmIdleVetoLock) );
    __dmb(0xBu);
    if ( v6 )
      KxWaitForSpinLockAndAcquire((unsigned int *)&PpmIdleVetoLock);
  }
  v7 = *(_DWORD *)(v3 + 2944);
  if ( !v7 )
  {
    v4 = -1073741637;
    goto LABEL_15;
  }
  v8 = *(_DWORD *)(a1 + 8);
  if ( v8 >= *(_DWORD *)(v7 + 28) )
  {
    v4 = -1073741811;
    goto LABEL_15;
  }
  v4 = PpmUpdateIdleVeto(*(unsigned __int8 *)(a1 + 16), *(_DWORD *)(a1 + 12), (unsigned int *)(v7 + (v8 << 6) + 288));
  if ( v4 < 0
    || (PpmEventProcessorVetoRequest(v3, *(_DWORD *)(a1 + 8), *(_DWORD *)(a1 + 12), *(unsigned __int8 *)(a1 + 16)),
        v3 == ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408) )
  {
LABEL_15:
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(&PpmIdleVetoLock, vars4);
    }
    else
    {
      __dmb(0xBu);
      PpmIdleVetoLock = 0;
    }
    KfLowerIrql(v5);
    return v4;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&PpmIdleVetoLock, vars4);
  }
  else
  {
    __dmb(0xBu);
    PpmIdleVetoLock = 0;
  }
  KfLowerIrql(v5);
  v10[0] = 1;
  v10[1] = 1;
  v11 = 0;
  v12 = 1 << v2;
  PopExecuteOnTargetProcessors((int)v10, (int)xHalTimerWatchdogStop, 0, 0);
  return v4;
}
