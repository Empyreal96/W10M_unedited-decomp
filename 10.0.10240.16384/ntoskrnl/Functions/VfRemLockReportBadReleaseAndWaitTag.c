// VfRemLockReportBadReleaseAndWaitTag 
 
int __fastcall VfRemLockReportBadReleaseAndWaitTag(int a1, int a2, int a3)
{
  VerifierBugCheckIfAppropriate(196, 214, a1, a2, a3);
  return 1;
}
