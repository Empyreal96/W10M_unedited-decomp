// ExpReleaseSpinLockSharedFromDpcLevelInstrumented 
 
unsigned int __fastcall ExpReleaseSpinLockSharedFromDpcLevelInstrumented(unsigned int *a1, int a2)
{
  int v4; // r0
  int v5; // r1
  unsigned int v6; // r6
  unsigned int v7; // r5

  v4 = ReadTimeStampCounter();
  __dmb(0xBu);
  do
    v6 = __ldrex(a1);
  while ( __strex(v6 & 0xBFFFFFFF, a1) );
  __dmb(0xBu);
  do
    v7 = __ldrex(a1);
  while ( __strex(v7 - 1, a1) );
  return PerfLogSpinLockRelease((unsigned int)a1, a2, v4, v5);
}
