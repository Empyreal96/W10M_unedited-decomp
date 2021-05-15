// KeSynchronizeExecution 
 
int __fastcall KeSynchronizeExecution(int a1, int (__fastcall *a2)(int, int), int a3)
{
  int v4; // r0
  int v7; // r7
  unsigned int *v8; // r0
  int v9; // r1
  unsigned int v10; // r2
  int v11; // r5
  _DWORD *v12; // r0

  v4 = *(unsigned __int8 *)(a1 + 49);
  if ( !v4 )
    return KiSynchronizePassiveInterruptExecution(a1, a2, a3);
  v7 = KfRaiseIrql(v4);
  v8 = *(unsigned int **)(a1 + 36);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented(v8);
  }
  else
  {
    v9 = 1;
    do
      v10 = __ldrex(v8);
    while ( __strex(1u, v8) );
    __dmb(0xBu);
    if ( v10 )
      KxWaitForSpinLockAndAcquire(v8);
  }
  v11 = a2(a3, v9);
  v12 = *(_DWORD **)(a1 + 36);
  if ( (dword_682604 & 0x10000) != 0 )
    return sub_54A260(v12);
  __dmb(0xBu);
  *v12 = 0;
  KfLowerIrql(v7);
  return v11;
}
