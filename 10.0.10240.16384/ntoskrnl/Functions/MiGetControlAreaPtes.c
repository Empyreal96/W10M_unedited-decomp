// MiGetControlAreaPtes 
 
int __fastcall MiGetControlAreaPtes(unsigned int *a1)
{
  unsigned int v2; // r2
  unsigned int *v3; // r6
  int v4; // r9
  int v6; // r0
  unsigned int v7; // r1
  unsigned int v8; // r3
  unsigned int i; // r5
  int v10; // r5
  unsigned int v11; // r4
  unsigned int v12; // r2

  v2 = a1[7];
  if ( (v2 & 0x20) != 0 || !a1[8] || (v2 & 0x400) != 0 )
    return *(_DWORD *)(*a1 + 4);
  v3 = a1 + 9;
  v4 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_545FE4();
  v6 = *v3 & 0x7FFFFFFF;
  do
    v7 = __ldrex(v3);
  while ( v7 == v6 && __strex(v6 + 1, v3) );
  __dmb(0xBu);
  if ( v7 != v6 )
    ExpWaitForSpinLockSharedAndAcquire(v3);
  v8 = a1[37];
  for ( i = 0; v8; v8 = *(_DWORD *)(v8 + 4) )
    i = v8;
  v10 = *(_DWORD *)(i - 20) + *(_DWORD *)(i - 12);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v3);
  }
  else
  {
    __dmb(0xBu);
    do
      v11 = __ldrex(v3);
    while ( __strex(v11 & 0xBFFFFFFF, v3) );
    __dmb(0xBu);
    do
      v12 = __ldrex(v3);
    while ( __strex(v12 - 1, v3) );
  }
  KfLowerIrql(v4);
  return v10;
}
