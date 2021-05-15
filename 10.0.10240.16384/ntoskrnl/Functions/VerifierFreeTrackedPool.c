// VerifierFreeTrackedPool 
 
int __fastcall VerifierFreeTrackedPool(int a1, int a2, int a3, int a4)
{
  if ( !VerifierIsTrackingPool )
    VerifierBugCheckIfAppropriate(194, 153, a1);
  return ViFreeTrackedPool(a1, a2, a3, a4);
}
