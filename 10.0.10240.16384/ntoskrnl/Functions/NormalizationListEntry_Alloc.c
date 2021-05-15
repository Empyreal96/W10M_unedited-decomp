// NormalizationListEntry_Alloc 
 
int NormalizationListEntry_Alloc()
{
  return ExAllocatePoolWithTag(1, 80);
}
