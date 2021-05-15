// PfpServiceMainThreadBoost 
 
int __fastcall PfpServiceMainThreadBoost(_DWORD *a1, int *a2)
{
  __int64 v3; // kr00_8
  unsigned int *v6; // r4
  int v7; // r9
  unsigned int v8; // r2
  int v9; // r3
  int v10; // r0
  unsigned int v11; // r1
  int vars4; // [sp+34h] [bp+4h]

  v3 = *(_QWORD *)a2;
  if ( !*a2 )
    return -2147483614;
  *(_DWORD *)(HIDWORD(v3) + 96) = 1;
  v6 = a1 + 16;
  v7 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)(a1 + 16));
  }
  else
  {
    do
      v8 = __ldrex(v6);
    while ( __strex(1u, v6) );
    __dmb(0xBu);
    if ( v8 )
      KxWaitForSpinLockAndAcquire(a1 + 16);
  }
  v9 = a1[17] + 1;
  a1[17] = v9;
  *(_DWORD *)(HIDWORD(v3) + 100) = v9;
  if ( !a1[14] )
  {
    v10 = *a2;
    *a2 = 0;
    a1[14] = v10;
    a1[15] = KeSetActualBasePriorityThread(v10, 12);
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(a1 + 16, vars4);
  }
  else
  {
    __dmb(0xBu);
    *v6 = 0;
  }
  KfLowerIrql(v7);
  KeInitializeTimerEx((_DWORD *)(HIDWORD(v3) + 32), 0);
  *(_BYTE *)HIDWORD(v3) = 19;
  *(_BYTE *)(HIDWORD(v3) + 1) = 1;
  *(_DWORD *)(HIDWORD(v3) + 12) = PfpPowerActionDpcRoutine;
  *(_DWORD *)(HIDWORD(v3) + 16) = HIDWORD(v3);
  *(_WORD *)(HIDWORD(v3) + 2) = 0;
  *(_DWORD *)(HIDWORD(v3) + 28) = 0;
  *(_DWORD *)(HIDWORD(v3) + 8) = 0;
  KiSetTimerEx(HIDWORD(v3) + 32, v11, -200000000i64, 0, 0, SHIDWORD(v3));
  a2[1] = 0;
  return 0;
}
