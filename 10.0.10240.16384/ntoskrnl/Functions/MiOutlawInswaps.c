// MiOutlawInswaps 
 
int __fastcall MiOutlawInswaps(int a1)
{
  int v2; // r9
  unsigned int v4; // r1
  int v5; // r7
  int v6; // r6
  int v7; // r1
  unsigned int v8; // r0

  v2 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_524B58();
  do
    v4 = __ldrex((unsigned __int8 *)&dword_63F990 + 3);
  while ( __strex(v4 | 0x80, (unsigned __int8 *)&dword_63F990 + 3) );
  __dmb(0xBu);
  if ( v4 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_63F990);
  while ( 1 )
  {
    v5 = dword_63F990;
    if ( (dword_63F990 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (dword_63F990 & 0x40000000) == 0 )
    {
      v7 = dword_63F990 | 0x40000000;
      do
        v8 = __ldrex((unsigned int *)&dword_63F990);
      while ( v8 == v5 && __strex(v7, (unsigned int *)&dword_63F990) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  v6 = *(_DWORD *)(a1 + 612);
  *(_DWORD *)(a1 + 612) = 2;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&dword_63F990);
  }
  else
  {
    __dmb(0xBu);
    dword_63F990 = 0;
  }
  KfLowerIrql(v2);
  return v6;
}
