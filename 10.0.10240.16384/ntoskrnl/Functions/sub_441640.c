// sub_441640 
 
int sub_441640()
{
  int result; // r0

  result = MmProbeAndLockPages();
  if ( (MmTrackLockedPages & 1) != 0 )
    result = sub_51AB24(result);
  return result;
}
