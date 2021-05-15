// WmipDoFindRegEntryByDevice 
 
void **__fastcall WmipDoFindRegEntryByDevice(void *a1)
{
  void **result; // r0

  for ( result = (void **)WmipInUseRegEntryHead; result != &WmipInUseRegEntryHead; result = (void **)*result )
  {
    if ( result[2] == a1 && (int)result[6] >= 0 )
      return result;
  }
  return 0;
}
