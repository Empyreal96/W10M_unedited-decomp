// MiDereferencePageRuns 
 
int __fastcall MiDereferencePageRuns(int a1)
{
  unsigned int *v2; // r4
  int v3; // r6
  int v4; // r9
  int result; // r0
  unsigned __int8 *v6; // r3
  unsigned int v7; // r1
  unsigned int v8; // r0
  int v9; // r3
  unsigned int v10; // r1

  v2 = (unsigned int *)(*(_DWORD *)(a1 - 8) + 168);
  v3 = 0;
  v4 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_513B24();
  v6 = (unsigned __int8 *)v2 + 3;
  do
    v7 = __ldrex(v6);
  while ( __strex(v7 | 0x80, v6) );
  __dmb(0xBu);
  if ( v7 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire(v2);
  while ( 1 )
  {
    v8 = *v2;
    if ( (*v2 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (v8 & 0x40000000) == 0 )
    {
      do
        v10 = __ldrex(v2);
      while ( v10 == v8 && __strex(v8 | 0x40000000, v2) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  v9 = *(_DWORD *)(a1 - 4) - 1;
  *(_DWORD *)(a1 - 4) = v9;
  if ( !v9 )
    v3 = a1 - 8;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v2);
  }
  else
  {
    __dmb(0xBu);
    *v2 = 0;
  }
  result = KfLowerIrql(v4);
  if ( v3 )
    result = ExFreePoolWithTag(v3, 0);
  return result;
}
