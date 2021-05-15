// RawScanDeletedList 
 
int RawScanDeletedList()
{
  int result; // r0

  if ( (int *)RawDismountedQueue != &RawDismountedQueue )
    result = sub_7CFDEC();
  return result;
}
