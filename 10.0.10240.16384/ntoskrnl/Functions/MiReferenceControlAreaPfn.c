// MiReferenceControlAreaPfn 
 
int __fastcall MiReferenceControlAreaPfn(_DWORD *a1, int a2, int a3)
{
  unsigned int *v6; // r5
  int v7; // r10
  unsigned __int8 *v9; // r3
  unsigned int v10; // r1
  unsigned int v11; // r7
  unsigned int v12; // r1

  if ( (a1[7] & 0x20) != 0 || !a1[8] )
    a2 = 0;
  v6 = a1 + 9;
  v7 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_544C68();
  v9 = (unsigned __int8 *)a1 + 39;
  do
    v10 = __ldrex(v9);
  while ( __strex(v10 | 0x80, v9) );
  __dmb(0xBu);
  if ( v10 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire(a1 + 9);
  while ( 1 )
  {
    v11 = *v6;
    if ( (*v6 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (v11 & 0x40000000) == 0 )
    {
      do
        v12 = __ldrex(v6);
      while ( v12 == v11 && __strex(v11 | 0x40000000, v6) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  a1[4] += a3;
  if ( a2 )
    *(_DWORD *)(a2 + 64) += a3;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(a1 + 9);
  }
  else
  {
    __dmb(0xBu);
    *v6 = 0;
  }
  return KfLowerIrql(v7);
}
