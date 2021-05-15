// MiSetControlAreaSystemVa 
 
int __fastcall MiSetControlAreaSystemVa(_DWORD *a1, int a2)
{
  unsigned int *v3; // r4
  int v5; // r9
  unsigned __int8 *v7; // r3
  unsigned int v8; // r1
  unsigned int v9; // r0
  int v10; // r3
  unsigned int v11; // r3
  unsigned int v12; // r1

  v3 = a1 + 9;
  v5 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_528368();
  v7 = (unsigned __int8 *)v3 + 3;
  do
    v8 = __ldrex(v7);
  while ( __strex(v8 | 0x80, v7) );
  __dmb(0xBu);
  if ( v8 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire(v3);
  while ( 1 )
  {
    v9 = *v3;
    if ( (*v3 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (v9 & 0x40000000) == 0 )
    {
      do
        v12 = __ldrex(v3);
      while ( v12 == v9 && __strex(v9 | 0x40000000, v3) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  a1[7] |= 0x10000000u;
  v10 = a1[13];
  if ( a2 == 1 )
    v11 = v10 | 0x2000000;
  else
    v11 = v10 & 0xFDFFFFFF;
  a1[13] = v11;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v3);
  }
  else
  {
    __dmb(0xBu);
    *v3 = 0;
  }
  return KfLowerIrql(v5);
}
