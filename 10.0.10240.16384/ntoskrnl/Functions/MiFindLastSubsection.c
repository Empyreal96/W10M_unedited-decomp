// MiFindLastSubsection 
 
int __fastcall MiFindLastSubsection(int a1, int a2)
{
  int v3; // r5
  int v4; // r3
  int v5; // r4
  unsigned int *v7; // r4
  int v8; // r0
  unsigned int v9; // r1
  unsigned int *v10; // r0
  unsigned int v11; // r1
  unsigned int v12; // r2

  if ( a2 == 1 )
  {
    v3 = 17;
  }
  else
  {
    v7 = (unsigned int *)(a1 + 36);
    v3 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
      return sub_51AD9C();
    v8 = *v7 & 0x7FFFFFFF;
    do
      v9 = __ldrex(v7);
    while ( v9 == v8 && __strex(v8 + 1, v7) );
    __dmb(0xBu);
    if ( v9 != v8 )
      ExpWaitForSpinLockSharedAndAcquire(a1 + 36, v9);
  }
  v4 = *(_DWORD *)(a1 + 148);
  v5 = 0;
  while ( v4 )
  {
    v5 = v4;
    v4 = *(_DWORD *)(v4 + 4);
  }
  if ( v3 != 17 )
  {
    v10 = (unsigned int *)(a1 + 36);
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v10);
    }
    else
    {
      __dmb(0xBu);
      do
        v11 = __ldrex(v10);
      while ( __strex(v11 & 0xBFFFFFFF, v10) );
      __dmb(0xBu);
      do
        v12 = __ldrex(v10);
      while ( __strex(v12 - 1, v10) );
    }
    KfLowerIrql(v3);
  }
  return v5 - 40;
}
