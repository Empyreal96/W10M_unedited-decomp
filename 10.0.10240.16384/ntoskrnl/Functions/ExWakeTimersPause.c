// ExWakeTimersPause 
 
__int64 ExWakeTimersPause()
{
  int v0; // r0
  int v1; // r4
  unsigned int v2; // r2
  int v3; // r10
  int v4; // r0
  unsigned int v5; // r1
  int *v6; // r5
  int v7; // r7
  unsigned int *v8; // r4
  int v9; // r1
  unsigned int v10; // r2
  int v11; // r6
  unsigned int v13; // [sp+8h] [bp-38h]
  int v14; // [sp+Ch] [bp-34h]
  unsigned __int64 v15[5]; // [sp+18h] [bp-28h] BYREF
  int vars4; // [sp+44h] [bp+4h]

  v0 = KeAbPreAcquire((unsigned int)&ExpWakeTimerLock, 0, 0);
  v1 = v0;
  do
    v2 = __ldrex((unsigned __int8 *)&ExpWakeTimerLock);
  while ( __strex(v2 | 1, (unsigned __int8 *)&ExpWakeTimerLock) );
  __dmb(0xBu);
  if ( (v2 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&ExpWakeTimerLock, v0, (unsigned int)&ExpWakeTimerLock);
  if ( v1 )
    *(_BYTE *)(v1 + 14) |= 1u;
  v3 = KfRaiseIrql(2);
  v4 = KeQueryInterruptTime();
  v13 = v5;
  v14 = v4;
  KeQuerySystemTime(v15);
  v6 = (int *)ExpWakeTimerList;
  while ( v6 != &ExpWakeTimerList )
  {
    v7 = (int)(v6 - 38);
    v6 = (int *)*v6;
    v8 = (unsigned int *)(v7 + 48);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented(v7 + 48);
    }
    else
    {
      v9 = 1;
      do
        v10 = __ldrex(v8);
      while ( __strex(1u, v8) );
      __dmb(0xBu);
      if ( v10 )
        KxWaitForSpinLockAndAcquire((unsigned int *)(v7 + 48));
    }
    v11 = *(_DWORD *)(v7 + 148);
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented((_DWORD *)(v7 + 48), vars4);
    }
    else
    {
      __dmb(0xBu);
      *v8 = 0;
    }
    if ( v11 )
      ExpTimerPause(v7, v9, v15[0], __PAIR64__(v13, v14));
  }
  return KfLowerIrql(v3);
}
