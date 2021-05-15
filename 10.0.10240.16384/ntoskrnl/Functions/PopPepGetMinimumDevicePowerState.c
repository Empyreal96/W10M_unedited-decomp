// PopPepGetMinimumDevicePowerState 
 
int __fastcall PopPepGetMinimumDevicePowerState(int a1, char a2, _DWORD *a3)
{
  int v3; // r10
  int v4; // r5
  unsigned int *v5; // r4
  int v7; // r7
  int v9; // r0
  unsigned int v10; // r1
  BOOL v11; // r6
  unsigned int v12; // r1
  unsigned int v13; // r2
  unsigned int i; // r2
  int v15; // [sp+0h] [bp-20h]

  v3 = 1 << a2;
  v4 = a1;
  v5 = (unsigned int *)(a1 + 44);
  v7 = 0;
  v15 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_550F58();
  v9 = *v5 & 0x7FFFFFFF;
  do
    v10 = __ldrex(v5);
  while ( v10 == v9 && __strex(v9 + 1, v5) );
  __dmb(0xBu);
  if ( v10 != v9 )
    ExpWaitForSpinLockSharedAndAcquire(v5);
  v11 = *(_DWORD *)(v4 + 112) == 2;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v5);
  }
  else
  {
    __dmb(0xBu);
    do
      v12 = __ldrex(v5);
    while ( __strex(v12 & 0xBFFFFFFF, v5) );
    __dmb(0xBu);
    do
      v13 = __ldrex(v5);
    while ( __strex(v13 - 1, v5) );
  }
  KfLowerIrql(v15);
  if ( v11 )
  {
    for ( i = 0; i < 3; ++i )
    {
      if ( (v3 & *(_DWORD *)(v4 + 96)) == 0 )
        break;
      v4 += 4;
    }
    *a3 = i + 1;
    v7 = 1;
  }
  return v7;
}
