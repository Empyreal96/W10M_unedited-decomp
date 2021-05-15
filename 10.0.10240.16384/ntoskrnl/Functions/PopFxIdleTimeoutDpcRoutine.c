// PopFxIdleTimeoutDpcRoutine 
 
int __fastcall PopFxIdleTimeoutDpcRoutine(int a1, int a2)
{
  unsigned int *v3; // r4
  int v4; // r9
  unsigned int v6; // r2
  unsigned int *v7; // r6
  unsigned int v8; // r1
  unsigned int v9; // r1
  unsigned int *v10; // r7
  unsigned int v11; // r1
  unsigned int v12; // r2

  v3 = (unsigned int *)(a2 + 184);
  v4 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_523AFC();
  do
    v6 = __ldrex(v3);
  while ( __strex(1u, v3) );
  __dmb(0xBu);
  if ( v6 )
    KxWaitForSpinLockAndAcquire(v3);
  __dmb(0xBu);
  v7 = (unsigned int *)(a2 + 16);
  do
    v8 = __ldrex(v7);
  while ( __strex(v8, v7) );
  __dmb(0xBu);
  if ( (v8 & 4) != 0 )
  {
    __dmb(0xBu);
    do
      v9 = __ldrex(v7);
    while ( __strex(v9 & 0xFFFFFFFB, v7) );
    __dmb(0xBu);
    v10 = (unsigned int *)(a2 + 24);
    if ( *(_DWORD *)(a2 + 24) != 2 )
      PopFxBugCheck(1555, a2, 0, 0);
    PopDiagTraceFxDevicePowerRequirement(*(_DWORD *)(a2 + 28), 0, 0);
    (*(void (__fastcall **)(_DWORD))(a2 + 76))(*(_DWORD *)(a2 + 88));
    __dmb(0xBu);
    do
      v11 = __ldrex(v7);
    while ( __strex(v11 | 0x40, v7) );
    __dmb(0xBu);
    do
      v12 = __ldrex(v10);
    while ( __strex(v12 - 1, v10) );
  }
  else
  {
    PopFxDeliverDevicePowerRequired(a2, 0);
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(v3);
  }
  else
  {
    __dmb(0xBu);
    *v3 = 0;
  }
  return KfLowerIrql(v4);
}
