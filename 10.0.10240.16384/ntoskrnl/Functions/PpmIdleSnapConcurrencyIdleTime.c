// PpmIdleSnapConcurrencyIdleTime 
 
void __fastcall PpmIdleSnapConcurrencyIdleTime(int a1, _DWORD *a2, unsigned __int64 a3)
{
  _DWORD *v5; // r8
  int v6; // r6
  unsigned int v7; // r2
  unsigned __int64 v8; // kr00_8
  int v9; // r1
  bool v10; // cf
  unsigned int v11; // r0
  __int64 v12; // kr08_8
  unsigned int v13; // r4
  int v14; // r3
  unsigned __int64 v15; // [sp+0h] [bp-20h] BYREF
  int vars4; // [sp+24h] [bp+4h]

  v15 = a3;
  v5 = (_DWORD *)a3;
  KeQueryPerformanceCounter(&v15, 0);
  if ( (__get_CPSR() & 0x80) != 0 )
  {
    v6 = 0;
  }
  else
  {
    __disable_irq();
    v6 = 1;
  }
  if ( (dword_682604 & 0x210000) != 0 )
  {
    sub_50F780();
  }
  else
  {
    do
      v7 = __ldrex((unsigned int *)a1);
    while ( __strex(1u, (unsigned int *)a1) );
    __dmb(0xBu);
    if ( v7 )
      KxWaitForSpinLockAndAcquire((unsigned int *)a1);
    v8 = *(_QWORD *)(a1 + 16);
    v9 = HIDWORD(v15);
    if ( v15 > v8 )
    {
      v10 = (unsigned int)v15 >= (unsigned int)v8;
      v11 = v15 - v8;
      *(_DWORD *)(a1 + 16) = v15;
      *(_DWORD *)(a1 + 20) = v9;
      v12 = *(_QWORD *)(a1 + 24);
      v13 = v9 - (HIDWORD(v8) + !v10);
      *(_DWORD *)(a1 + 24) = v12 + v11;
      v14 = *(_DWORD *)(a1 + 8);
      *(_DWORD *)(a1 + 28) = v13 + __CFADD__((_DWORD)v12, v11) + HIDWORD(v12);
      *(_QWORD *)(a1 + 8 * v14 + 32) += __PAIR64__(v13, v11);
    }
    *a2 = *(_DWORD *)(a1 + 24);
    a2[1] = *(_DWORD *)(a1 + 28);
    *v5 = *(_DWORD *)(a1 + 32);
    v5[1] = *(_DWORD *)(a1 + 36);
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented((_DWORD *)a1, vars4);
    }
    else
    {
      __dmb(0xBu);
      *(_DWORD *)a1 = 0;
    }
    if ( v6 )
      __enable_irq();
  }
}
