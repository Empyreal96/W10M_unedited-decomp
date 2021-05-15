// ExpGetSystemProcessorFeaturesInformation 
 
int __fastcall ExpGetSystemProcessorFeaturesInformation(_DWORD *a1)
{
  int result; // r0

  result = 0;
  *a1 = KeFeatureBits;
  a1[1] = 0;
  a1[2] = 0;
  a1[3] = 0;
  a1[4] = 0;
  a1[5] = 0;
  a1[6] = 0;
  a1[7] = 0;
  return result;
}
