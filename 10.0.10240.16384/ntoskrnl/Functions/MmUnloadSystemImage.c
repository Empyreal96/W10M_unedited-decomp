// MmUnloadSystemImage 
 
int __fastcall MmUnloadSystemImage(unsigned int a1)
{
  int v2; // r5

  v2 = MmAcquireLoadLock();
  MiUnloadSystemImage(a1, -1);
  MmReleaseLoadLock(v2);
  return 0;
}
