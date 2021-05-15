// ExTimerRundown 
 
int ExTimerRundown()
{
  unsigned int v0; // r7
  unsigned int *v1; // r4
  int v2; // r6
  unsigned int v4; // r2
  int i; // r5
  int v6; // r9
  unsigned int *v7; // r6
  unsigned int v8; // r2
  unsigned int *v9; // r6
  unsigned int v10; // r0
  unsigned int v11; // r2
  int v12; // [sp+8h] [bp-20h]

  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v1 = (unsigned int *)(v0 + 864);
  v2 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_5222A8();
  do
    v4 = __ldrex(v1);
  while ( __strex(1u, v1) );
  __dmb(0xBu);
  if ( v4 )
    KxWaitForSpinLockAndAcquire(v1);
  for ( i = *(_DWORD *)(v0 + 868); i != v0 + 868; i = *(_DWORD *)(v0 + 868) )
  {
    ObfReferenceObjectWithTag(i - 132, 1953261124);
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(v1);
    }
    else
    {
      __dmb(0xBu);
      *v1 = 0;
    }
    KfLowerIrql(v2);
    v6 = 1;
    v7 = (unsigned int *)(i - 84);
    v12 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented(i - 84);
    }
    else
    {
      do
        v8 = __ldrex(v7);
      while ( __strex(1u, v7) );
      __dmb(0xBu);
      if ( v8 )
        KxWaitForSpinLockAndAcquire(i - 84);
    }
    if ( (*(_BYTE *)(i + 12) & 1) != 0 && v0 == *(_DWORD *)(i - 72) )
      v6 = ExpCancelTimer(i - 132) + 1;
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(i - 84);
    }
    else
    {
      __dmb(0xBu);
      *v7 = 0;
    }
    KfLowerIrql(v12);
    v9 = (unsigned int *)(i - 156);
    if ( ObpTraceFlags )
      ObpPushStackInfo(i - 156, 0, v6, 1953261124);
    __dmb(0xBu);
    do
      v10 = __ldrex(v9);
    while ( __strex(v10 - v6, v9) );
    if ( (int)(v10 - v6) <= 0 )
    {
      if ( v10 != v6 )
        KeBugCheckEx(24, 0, i - 132);
      ObpDeferObjectDeletion(i - 156);
    }
    v2 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented(v1);
    }
    else
    {
      do
        v11 = __ldrex(v1);
      while ( __strex(1u, v1) );
      __dmb(0xBu);
      if ( v11 )
        KxWaitForSpinLockAndAcquire(v1);
    }
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(v1);
  }
  else
  {
    __dmb(0xBu);
    *v1 = 0;
  }
  return KfLowerIrql(v2);
}
