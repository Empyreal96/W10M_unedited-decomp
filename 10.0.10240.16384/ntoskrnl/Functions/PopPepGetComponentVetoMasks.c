// PopPepGetComponentVetoMasks 
 
int __fastcall PopPepGetComponentVetoMasks(int a1, int a2, _DWORD *a3)
{
  int v3; // r6
  unsigned int *v5; // r4
  int v7; // r7
  int v8; // r10
  int v9; // r0
  unsigned int v10; // r1
  BOOL v11; // r5
  unsigned int v12; // r1
  unsigned int v13; // r2
  unsigned int v14; // r1
  int v15; // r2
  int v16; // r3

  v3 = a1 + 168 * a2;
  v5 = (unsigned int *)(a1 + 44);
  v7 = 0;
  v8 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockSharedAtDpcLevelInstrumented(v5);
  }
  else
  {
    v9 = *v5 & 0x7FFFFFFF;
    do
      v10 = __ldrex(v5);
    while ( v10 == v9 && __strex(v9 + 1, v5) );
    __dmb(0xBu);
    if ( v10 != v9 )
      ExpWaitForSpinLockSharedAndAcquire(v5);
  }
  v11 = *(_DWORD *)(a1 + 112) == 2;
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
  KfLowerIrql(v8);
  if ( v11 )
  {
    v14 = 0;
    if ( *(_DWORD *)(v3 + 284) )
    {
      v15 = 0;
      do
      {
        ++v14;
        v16 = *(_DWORD *)(*(_DWORD *)(v3 + 288) + v15 + 16);
        v15 += 24;
        *a3++ = v16;
      }
      while ( v14 < *(_DWORD *)(v3 + 284) );
    }
    v7 = 1;
  }
  return v7;
}
