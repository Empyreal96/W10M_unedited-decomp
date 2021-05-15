// ExSizeOfRundownProtectionCacheAware 
 
int ExSizeOfRundownProtectionCacheAware()
{
  int v0; // r4
  int v1; // r3

  v0 = KeNumberProcessors_0;
  if ( (unsigned int)KeNumberProcessors_0 <= 1 )
    v1 = 4;
  else
    v1 = (v0 + 1) * KeGetRecommendedSharedDataAlignment();
  return v1 + 16;
}
