// VerifierExEnterCriticalRegionAndAcquireResourceExclusive 
 
int __fastcall VerifierExEnterCriticalRegionAndAcquireResourceExclusive(int a1)
{
  int v2; // r4

  v2 = pXdvExEnterCriticalRegionAndAcquireResourceExclusive(a1);
  VfDeadlockAcquireResource(a1, 8, __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, 0);
  return v2;
}
