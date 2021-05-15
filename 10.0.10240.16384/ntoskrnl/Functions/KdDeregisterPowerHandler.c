// KdDeregisterPowerHandler 
 
int __fastcall KdDeregisterPowerHandler(int *a1)
{
  int v2; // r9
  unsigned int v3; // r2
  int *v4; // r6
  int v5; // r5
  int *i; // r2
  __int64 v7; // r0
  int vars4; // [sp+1Ch] [bp+4h]

  v2 = KfRaiseIrql(15);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)&KdpPowerSpinLock);
  }
  else
  {
    do
      v3 = __ldrex((unsigned int *)&KdpPowerSpinLock);
    while ( __strex(1u, (unsigned int *)&KdpPowerSpinLock) );
    __dmb(0xBu);
    if ( v3 )
      KxWaitForSpinLockAndAcquire((unsigned int *)&KdpPowerSpinLock);
  }
  v4 = 0;
  v5 = 0;
  for ( i = (int *)KdpPowerListHead; i != &KdpPowerListHead; i = (int *)*i )
  {
    v4 = i;
    if ( a1 == i )
    {
      v7 = *(_QWORD *)i;
      if ( *(int **)(*i + 4) != i || *(int **)HIDWORD(v7) != i )
        __fastfail(3u);
      *(_DWORD *)HIDWORD(v7) = v7;
      *(_DWORD *)(v7 + 4) = HIDWORD(v7);
      v5 = 1;
      break;
    }
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&KdpPowerSpinLock, vars4);
  }
  else
  {
    __dmb(0xBu);
    KdpPowerSpinLock = 0;
  }
  KfLowerIrql(v2);
  if ( !v5 )
    return -1073741275;
  ExFreePoolWithTag(v4);
  return 0;
}
