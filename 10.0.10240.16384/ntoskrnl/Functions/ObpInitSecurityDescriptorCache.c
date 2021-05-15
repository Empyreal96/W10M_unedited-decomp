// ObpInitSecurityDescriptorCache 
 
int ObpInitSecurityDescriptorCache()
{
  int *v0; // r2
  int v1; // r1
  int *v2; // r3

  v0 = ObsSecurityDescriptorCache;
  v1 = 257;
  do
  {
    *v0 = 0;
    v0 += 3;
    --v1;
    v2 = v0 - 2;
    *v2 = (int)v2;
    v2[1] = (int)v2;
  }
  while ( v1 );
  return 0;
}
