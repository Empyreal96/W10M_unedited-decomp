// PfSnDeactivateTrace 
 
int __fastcall PfSnDeactivateTrace(int a1)
{
  int v2; // r4
  unsigned int v4; // r1
  unsigned int *v5; // r6
  unsigned int v6; // r4
  unsigned int v7; // r1
  unsigned int v8; // r1
  int v9; // r4
  unsigned int v10; // r1
  __int64 v11; // r0

  v2 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_54B7D8();
  do
    v4 = __ldrex((unsigned int *)&dword_637378);
  while ( __strex(1u, (unsigned int *)&dword_637378) );
  __dmb(0xBu);
  if ( v4 )
    KxWaitForSpinLockAndAcquire((unsigned int *)&dword_637378);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&dword_637378);
  }
  else
  {
    __dmb(0xBu);
    dword_637378 = 0;
  }
  KfLowerIrql(v2);
  PfSnRemoveProcessTrace(*(_DWORD *)(a1 + 264));
  v5 = (unsigned int *)(a1 + 268);
  __pld((void *)(a1 + 268));
  v6 = *(_DWORD *)(a1 + 268) & 0xFFFFFFFE;
  __dmb(0xBu);
  do
    v7 = __ldrex(v5);
  while ( v7 == v6 && __strex(v6 - 2, v5) );
  if ( v7 != v6 )
    ExfReleaseRundownProtection((unsigned __int8 *)(a1 + 268));
  PfSnCancelTraceTimer(a1);
  do
    v8 = __ldrex(v5);
  while ( !v8 && __strex(1u, v5) );
  __dmb(0xBu);
  if ( v8 && v8 != 1 )
    ExfWaitForRundownProtectionRelease(a1 + 268, v8, 1);
  v9 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented(&dword_637378);
  }
  else
  {
    do
      v10 = __ldrex((unsigned int *)&dword_637378);
    while ( __strex(1u, (unsigned int *)&dword_637378) );
    __dmb(0xBu);
    if ( v10 )
      KxWaitForSpinLockAndAcquire((unsigned int *)&dword_637378);
  }
  v11 = *(_QWORD *)(a1 + 4);
  if ( *(_DWORD *)(v11 + 4) != a1 + 4 || *(_DWORD *)HIDWORD(v11) != a1 + 4 )
    __fastfail(3u);
  *(_DWORD *)HIDWORD(v11) = v11;
  *(_DWORD *)(v11 + 4) = HIDWORD(v11);
  --PfSnNumActiveTraces;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&dword_637378);
  }
  else
  {
    __dmb(0xBu);
    dword_637378 = 0;
  }
  KfLowerIrql(v9);
  return 0;
}
