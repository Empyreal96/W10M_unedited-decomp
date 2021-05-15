// PpmIdleSnapConcurrency 
 
int __fastcall PpmIdleSnapConcurrency(int a1, _DWORD *a2, int a3, int a4)
{
  int v6; // r0
  int v7; // r9
  int result; // r0
  unsigned int v9; // r2
  unsigned __int64 v10; // kr08_8
  int v11; // r1
  unsigned __int64 v12; // kr10_8
  int v13; // r3
  unsigned __int64 v16; // [sp+8h] [bp-28h] BYREF

  v6 = KeQueryPerformanceCounter(&v16, 0);
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
    return sub_540CB4(v6);
  do
    v9 = __ldrex((unsigned int *)a1);
  while ( __strex(1u, (unsigned int *)a1) );
  __dmb(0xBu);
  if ( v9 )
    KxWaitForSpinLockAndAcquire(a1);
  v10 = *(_QWORD *)(a1 + 16);
  v11 = HIDWORD(v16);
  if ( v16 > v10 )
  {
    v12 = v16 - v10;
    *(_DWORD *)(a1 + 16) = v16;
    *(_DWORD *)(a1 + 20) = v11;
    v13 = *(_DWORD *)(a1 + 8);
    *(_QWORD *)(a1 + 24) += v12;
    *(_QWORD *)(a1 + 8 * v13 + 32) += v12;
  }
  *a2 = *(_DWORD *)(a1 + 24);
  a2[1] = *(_DWORD *)(a1 + 28);
  result = memmove(a4, a1 + 32, 8 * a3);
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
