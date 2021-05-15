// PopPepRegisterComponentPerfStates 
 
__int64 __fastcall PopPepRegisterComponentPerfStates(int a1, int a2, int a3, int a4)
{
  int v5; // r6
  unsigned int *v7; // r4
  int v9; // r10
  int v10; // r0
  unsigned int v11; // r1
  unsigned int v12; // r1
  unsigned int v13; // r2

  v5 = a1 + 168 * a2;
  v7 = (unsigned int *)(a1 + 44);
  v9 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockSharedAtDpcLevelInstrumented(v7);
  }
  else
  {
    v10 = *v7 & 0x7FFFFFFF;
    do
      v11 = __ldrex(v7);
    while ( v11 == v10 && __strex(v10 + 1, v7) );
    __dmb(0xBu);
    if ( v11 != v10 )
      ExpWaitForSpinLockSharedAndAcquire(v7);
  }
  *(_BYTE *)(v5 + 280) = 1;
  *(_DWORD *)(v5 + 152) = a3;
  *(_DWORD *)(v5 + 156) = a4;
  if ( (a3 & 2) != 0 )
    *(_BYTE *)(a1 + 116) = 1;
  if ( (a3 & 4) != 0 )
    *(_BYTE *)(a1 + 117) = 1;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v7);
  }
  else
  {
    __dmb(0xBu);
    do
      v12 = __ldrex(v7);
    while ( __strex(v12 & 0xBFFFFFFF, v7) );
    __dmb(0xBu);
    do
      v13 = __ldrex(v7);
    while ( __strex(v13 - 1, v7) );
  }
  return KfLowerIrql(v9);
}
