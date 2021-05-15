// PpmIdleSnapConcurrencyIdleTime 
 
int __fastcall PpmIdleSnapConcurrencyIdleTime(int a1, _DWORD *a2, unsigned __int64 a3)
{
  _DWORD *v5; // r8
  int result; // r0
  int v7; // r6
  unsigned int v8; // r2
  unsigned __int64 v9; // kr00_8
  int v10; // r1
  bool v11; // cf
  __int64 v12; // kr08_8
  unsigned int v13; // r4
  int v14; // r3
  unsigned __int64 v15; // [sp+0h] [bp-20h] BYREF

  v15 = a3;
  v5 = (_DWORD *)a3;
  result = KeQueryPerformanceCounter(&v15, 0);
  if ( (__get_CPSR() & 0x80) != 0 )
  {
    v7 = 0;
  }
  else
  {
    __disable_irq();
    v7 = 1;
  }
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_50F780(result);
  do
    v8 = __ldrex((unsigned int *)a1);
  while ( __strex(1u, (unsigned int *)a1) );
  __dmb(0xBu);
  if ( v8 )
    result = KxWaitForSpinLockAndAcquire(a1);
  v9 = *(_QWORD *)(a1 + 16);
  v10 = HIDWORD(v15);
  if ( v15 > v9 )
  {
    v11 = (unsigned int)v15 >= (unsigned int)v9;
    result = v15 - v9;
    *(_DWORD *)(a1 + 16) = v15;
    *(_DWORD *)(a1 + 20) = v10;
    v12 = *(_QWORD *)(a1 + 24);
    v13 = v10 - (HIDWORD(v9) + !v11);
    *(_DWORD *)(a1 + 24) = v12 + result;
    v14 = *(_DWORD *)(a1 + 8);
    *(_DWORD *)(a1 + 28) = v13 + __CFADD__((_DWORD)v12, result) + HIDWORD(v12);
    *(_QWORD *)(a1 + 8 * v14 + 32) += __PAIR64__(v13, result);
  }
  *a2 = *(_DWORD *)(a1 + 24);
  a2[1] = *(_DWORD *)(a1 + 28);
  *v5 = *(_DWORD *)(a1 + 32);
  v5[1] = *(_DWORD *)(a1 + 36);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    result = KiReleaseSpinLockInstrumented(a1);
  }
  else
  {
    __dmb(0xBu);
    *(_DWORD *)a1 = 0;
  }
  if ( v7 )
    __enable_irq();
  return result;
}
