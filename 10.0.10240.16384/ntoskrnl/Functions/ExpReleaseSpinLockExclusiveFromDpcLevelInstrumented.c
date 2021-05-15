// ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented 
 
int __fastcall ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(_DWORD *a1, int a2)
{
  int v4; // r0
  int v5; // r1

  v4 = ReadTimeStampCounter();
  __dmb(0xBu);
  *a1 = 0;
  return PerfLogSpinLockRelease(a1, a2, v4, v5);
}
