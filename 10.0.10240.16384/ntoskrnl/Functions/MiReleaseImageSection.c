// MiReleaseImageSection 
 
int __fastcall MiReleaseImageSection(int a1, _DWORD *a2)
{
  int v2; // r7
  unsigned int *v4; // r4
  int v5; // r8
  unsigned __int8 *v7; // r3
  unsigned int v8; // r1
  unsigned int v9; // r0
  int v10; // r5
  unsigned int v11; // r1

  v2 = *(_DWORD *)(a1 + 20);
  v4 = a2 + 9;
  v5 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_51A85C();
  v7 = (unsigned __int8 *)v4 + 3;
  do
    v8 = __ldrex(v7);
  while ( __strex(v8 | 0x80, v7) );
  __dmb(0xBu);
  if ( v8 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire(v4);
  while ( 1 )
  {
    v9 = *v4;
    if ( (*v4 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (v9 & 0x40000000) == 0 )
    {
      do
        v11 = __ldrex(v4);
      while ( v11 == v9 && __strex(v9 | 0x40000000, v4) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  v10 = a2[11];
  a2[7] &= 0xFFFFFFFD;
  a2[11] = 0;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v4);
  }
  else
  {
    __dmb(0xBu);
    *v4 = 0;
  }
  KfLowerIrql(v5);
  KeAbPostRelease(v2 + 8);
  return v10;
}
