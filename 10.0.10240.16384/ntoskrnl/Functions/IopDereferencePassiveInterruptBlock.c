// IopDereferencePassiveInterruptBlock 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall IopDereferencePassiveInterruptBlock(unsigned int *a1)
{
  int v2; // r7
  int v3; // r9
  int result; // r0
  unsigned int v5; // r2
  int v6; // r10
  unsigned int *v7; // r6
  unsigned int v8; // r2
  unsigned int *v9; // r2
  unsigned int v10; // r1
  unsigned int v11; // r1
  unsigned int *v12; // r1 OVERLAPPED
  unsigned int **v13; // r2 OVERLAPPED

  v2 = 0;
  v3 = KfRaiseIrql(12);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_527240();
  do
    v5 = __ldrex((unsigned int *)&PassiveInterruptListLock);
  while ( __strex(1u, (unsigned int *)&PassiveInterruptListLock) );
  __dmb(0xBu);
  if ( v5 )
    KxWaitForSpinLockAndAcquire(&PassiveInterruptListLock);
  v6 = KfRaiseIrql(12);
  v7 = a1 + 9;
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented(a1 + 9);
  }
  else
  {
    do
      v8 = __ldrex(v7);
    while ( __strex(1u, v7) );
    __dmb(0xBu);
    if ( v8 )
      KxWaitForSpinLockAndAcquire(a1 + 9);
  }
  __dmb(0xBu);
  v9 = a1 + 27;
  do
  {
    v10 = __ldrex(v9);
    v11 = v10 - 1;
  }
  while ( __strex(v11, v9) );
  __dmb(0xBu);
  if ( !v11 )
  {
    *(_QWORD *)&v12 = *(_QWORD *)a1;
    if ( *(unsigned int **)(*a1 + 4) != a1 || *v13 != a1 )
      __fastfail(3u);
    *v13 = v12;
    v12[1] = (unsigned int)v13;
    v2 = 1;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(a1 + 9);
  }
  else
  {
    __dmb(0xBu);
    *v7 = 0;
  }
  KfLowerIrql(v6);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&PassiveInterruptListLock);
  }
  else
  {
    __dmb(0xBu);
    PassiveInterruptListLock = 0;
  }
  result = KfLowerIrql(v3);
  if ( v2 )
    result = ExFreePoolWithTag(a1, 1651077195);
  return result;
}
