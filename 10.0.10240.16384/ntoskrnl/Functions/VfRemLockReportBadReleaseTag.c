// VfRemLockReportBadReleaseTag 
 
int __fastcall VfRemLockReportBadReleaseTag(int a1, int a2)
{
  VerifierBugCheckIfAppropriate(196, 213, a1, a2, 0);
  return 1;
}
