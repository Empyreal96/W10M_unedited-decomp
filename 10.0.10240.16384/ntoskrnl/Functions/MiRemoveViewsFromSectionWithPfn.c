// MiRemoveViewsFromSectionWithPfn 
 
int __fastcall MiRemoveViewsFromSectionWithPfn(_DWORD *a1, int a2, int a3, int a4)
{
  unsigned int *v6; // r4
  int v8; // r6
  unsigned __int8 *v10; // r3
  unsigned int v11; // r1
  unsigned int v12; // r0

  v6 = (unsigned int *)(*a1 + 36);
  v8 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_54A878();
  v10 = (unsigned __int8 *)v6 + 3;
  do
    v11 = __ldrex(v10);
  while ( __strex(v11 | 0x80, v10) );
  __dmb(0xBu);
  if ( v11 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire(v6);
  while ( 1 )
  {
    v12 = *v6;
    if ( (*v6 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (v12 & 0x40000000) == 0 )
    {
      do
        v11 = __ldrex(v6);
      while ( v11 == v12 && __strex(v12 | 0x40000000, v6) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  MiRemoveViewsFromSection(a1, v11, a3, a4);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v6);
  }
  else
  {
    __dmb(0xBu);
    *v6 = 0;
  }
  return KfLowerIrql(v8);
}
