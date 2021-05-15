// KeQueryMaximumGroupCount 
 
int KeQueryMaximumGroupCount()
{
  unsigned __int16 v0; // r3

  if ( KeDynamicPartitioningSupported )
    v0 = KiMaximumGroups;
  else
    v0 = KiActiveGroups;
  return v0;
}
