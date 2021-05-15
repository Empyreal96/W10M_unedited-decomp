// KiReleaseSpinLockInstrumented 
 
int __fastcall KiReleaseSpinLockInstrumented(_DWORD *a1, int a2)
{
  int v4; // r0
  int v5; // r1

  __dmb(0xBu);
  *a1 = 0;
  v4 = ReadTimeStampCounter();
  return PerfLogSpinLockRelease(a1, a2, v4, v5);
}
