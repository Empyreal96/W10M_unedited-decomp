// PopPepGetDeviceVetoMasks 
 
int __fastcall PopPepGetDeviceVetoMasks(_DWORD *a1, _DWORD *a2)
{
  unsigned int *v3; // r4
  int v5; // r6
  int v6; // r10
  int v7; // r0
  unsigned int v8; // r1
  BOOL v9; // r5
  unsigned int v10; // r1
  unsigned int v11; // r2
  int v12; // r2
  int v13; // r3

  v3 = a1 + 11;
  v5 = 0;
  v6 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockSharedAtDpcLevelInstrumented(v3);
  }
  else
  {
    v7 = *v3 & 0x7FFFFFFF;
    do
      v8 = __ldrex(v3);
    while ( v8 == v7 && __strex(v7 + 1, v3) );
    __dmb(0xBu);
    if ( v8 != v7 )
      ExpWaitForSpinLockSharedAndAcquire(v3);
  }
  v9 = a1[28] == 2;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v3);
  }
  else
  {
    __dmb(0xBu);
    do
      v10 = __ldrex(v3);
    while ( __strex(v10 & 0xBFFFFFFF, v3) );
    __dmb(0xBu);
    do
      v11 = __ldrex(v3);
    while ( __strex(v11 - 1, v3) );
  }
  KfLowerIrql(v6);
  if ( v9 )
  {
    v12 = a1[25];
    v13 = a1[26];
    *a2 = a1[24];
    a2[1] = v12;
    a2[2] = v13;
    v5 = 1;
  }
  return v5;
}
