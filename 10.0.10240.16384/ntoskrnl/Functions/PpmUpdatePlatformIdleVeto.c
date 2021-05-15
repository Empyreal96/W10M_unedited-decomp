// PpmUpdatePlatformIdleVeto 
 
int __fastcall PpmUpdatePlatformIdleVeto(int a1)
{
  int v2; // r5
  unsigned int v3; // r1
  int v4; // r8
  int v5; // r9
  unsigned int v6; // r2
  unsigned int v7; // r3
  unsigned int v8; // r3
  __int16 v10[2]; // [sp+0h] [bp-28h] BYREF
  int v11; // [sp+4h] [bp-24h]
  int v12; // [sp+8h] [bp-20h]
  int vars4; // [sp+2Ch] [bp+4h]

  if ( !PpmPlatformStates )
    return -1073741637;
  v3 = *(_DWORD *)(a1 + 4);
  if ( v3 >= *(_DWORD *)PpmPlatformStates )
    return -1073741811;
  v4 = PpmPlatformStates + (v3 << 8) + 128;
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
  v2 = PpmUpdateIdleVeto(*(unsigned __int8 *)(a1 + 12), *(_DWORD *)(a1 + 8), (unsigned int *)(v4 + 8));
  if ( v2 < 0
    || (PpmEventPlatformVetoRequest(*(_DWORD *)(a1 + 4), *(_DWORD *)(a1 + 8), *(unsigned __int8 *)(a1 + 12)),
        ((*(_DWORD *)(v4 + 44) >> *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594)) & 1) != 0) )
  {
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
  }
  else
  {
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
    v12 = 0;
    v7 = *(_DWORD *)(v4 + 44);
    if ( v7 )
      v8 = 31 - __clz(v7);
    else
      LOBYTE(v8) = -1;
    v12 = 1 << v8;
    PopExecuteOnTargetProcessors((int)v10, (int)xHalTimerWatchdogStop, 0, 0);
  }
  return v2;
}
