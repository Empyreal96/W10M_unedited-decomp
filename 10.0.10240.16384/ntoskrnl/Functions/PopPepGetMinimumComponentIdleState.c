// PopPepGetMinimumComponentIdleState 
 
int __fastcall PopPepGetMinimumComponentIdleState(int a1, int a2, char a3, unsigned int *a4)
{
  unsigned int *v6; // r4
  int v7; // r5
  int v8; // r10
  int v10; // r0
  unsigned int v11; // r1
  BOOL v12; // r6
  unsigned int v13; // r1
  unsigned int v14; // r2
  int v15; // r3
  unsigned int v16; // r2
  unsigned int v17; // r0
  int v18; // r1
  int v20; // [sp+4h] [bp-24h]

  v6 = (unsigned int *)(a1 + 44);
  v20 = 1 << a3;
  v7 = 0;
  v8 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_550F38();
  v10 = *v6 & 0x7FFFFFFF;
  do
    v11 = __ldrex(v6);
  while ( v11 == v10 && __strex(v10 + 1, v6) );
  __dmb(0xBu);
  if ( v11 != v10 )
    ExpWaitForSpinLockSharedAndAcquire(v6);
  v12 = *(_DWORD *)(a1 + 112) == 2;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v6);
  }
  else
  {
    __dmb(0xBu);
    do
      v13 = __ldrex(v6);
    while ( __strex(v13 & 0xBFFFFFFF, v6) );
    __dmb(0xBu);
    do
      v14 = __ldrex(v6);
    while ( __strex(v14 - 1, v6) );
  }
  KfLowerIrql(v8);
  if ( v12 )
  {
    v15 = a1 + 168 * a2;
    v16 = 0;
    v17 = *(_DWORD *)(v15 + 284);
    if ( v17 )
    {
      v18 = *(_DWORD *)(v15 + 288);
      do
      {
        if ( (v20 & *(_DWORD *)(v18 + 16)) == 0 )
          break;
        ++v16;
        v18 += 24;
      }
      while ( v16 < v17 );
    }
    if ( v16 >= v17 )
    {
      v7 = 0;
    }
    else
    {
      *a4 = v16;
      v7 = 1;
    }
  }
  return v7;
}
