// PpmIdleUpdateConcurrency 
 
int __fastcall PpmIdleUpdateConcurrency(int a1, int a2, unsigned int a3, unsigned int a4, char a5, char a6)
{
  int v9; // r5
  int result; // r0
  unsigned int v11; // r2
  unsigned __int64 v12; // kr08_8
  __int64 v13; // kr10_8
  int v14; // r3

  if ( (__get_CPSR() & 0x80) != 0 )
  {
    v9 = 0;
  }
  else
  {
    __disable_irq();
    v9 = 1;
  }
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_5535B4();
  do
    v11 = __ldrex((unsigned int *)a1);
  while ( __strex(1u, (unsigned int *)a1) );
  __dmb(0xBu);
  if ( v11 )
    KxWaitForSpinLockAndAcquire((unsigned int *)a1);
  v12 = *(_QWORD *)(a1 + 16);
  result = *(_DWORD *)(a1 + 8);
  if ( __PAIR64__(a4, a3) > v12 )
  {
    v13 = __PAIR64__(a4, a3) - v12;
    *(_DWORD *)(a1 + 16) = a3;
    *(_DWORD *)(a1 + 20) = a4;
    if ( a6 )
    {
      *(_QWORD *)(a1 + 24) += v13;
      *(_QWORD *)(a1 + 8 * result + 32) += v13;
    }
  }
  if ( a5 )
    v14 = result - 1;
  else
    v14 = result + 1;
  *(_DWORD *)(a1 + 8) = v14;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    result = KiReleaseSpinLockInstrumented(a1);
  }
  else
  {
    __dmb(0xBu);
    *(_DWORD *)a1 = 0;
  }
  if ( v9 )
    __enable_irq();
  return result;
}
