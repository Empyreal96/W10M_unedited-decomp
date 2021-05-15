// PpmInstallFeedbackCounters 
 
int __fastcall PpmInstallFeedbackCounters(int a1, _DWORD *a2)
{
  int v4; // r5
  int v5; // r0
  unsigned int v7; // r2
  int v8; // r4
  int v9; // r10
  int v10; // r9
  int v11; // r1
  int v12; // r2
  int v13; // r3
  int v14[3]; // [sp+0h] [bp-48h] BYREF
  int v15; // [sp+Ch] [bp-3Ch]
  char v16[8]; // [sp+10h] [bp-38h] BYREF
  _DWORD v17[12]; // [sp+18h] [bp-30h] BYREF

  v14[0] = 0;
  v14[1] = 0;
  v14[2] = 0;
  v14[0] = 1 << *(_DWORD *)(a1 + 20);
  KeSetSystemGroupAffinityThread((int)v14, v17);
  v15 = KfRaiseIrql(2);
  v4 = a1 + 3008;
  KeQueryPerformanceCounter(v14, 0);
  v5 = PpmContinueActiveTimeAccumulation(a1);
  if ( (__get_CPSR() & 0x80) != 0 )
    return sub_553644(v5);
  __disable_irq();
  v14[0] = 1;
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented(a1 + 3008);
  }
  else
  {
    do
      v7 = __ldrex((unsigned int *)v4);
    while ( __strex(1u, (unsigned int *)v4) );
    __dmb(0xBu);
    if ( v7 )
      KxWaitForSpinLockAndAcquire((unsigned int *)(a1 + 3008));
  }
  v8 = a1 + 3008;
  v9 = v4 - (_DWORD)a2;
  v10 = 2;
  do
  {
    if ( *a2 )
    {
      *(_DWORD *)((char *)a2 + v9 + 24) = *a2;
      *(_QWORD *)(v8 + 56) = 100i64 * *(_QWORD *)(v4 + 40);
      PpmPerfFeedbackCounterRead(*a2, 1, v16);
    }
    v8 += 8;
    ++a2;
    --v10;
  }
  while ( v10 );
  if ( *(_DWORD *)(v4 + 28) )
  {
    *(_BYTE *)(v4 + 96) = 1;
  }
  else if ( *(_DWORD *)(v4 + 24) )
  {
    *(_BYTE *)(v4 + 96) = 0;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(v4);
  }
  else
  {
    __dmb(0xBu);
    *(_DWORD *)v4 = 0;
  }
  if ( v14[0] )
    __enable_irq();
  KfLowerIrql(v15);
  return KeRevertToUserGroupAffinityThread((int)v17, v11, v12, v13);
}
