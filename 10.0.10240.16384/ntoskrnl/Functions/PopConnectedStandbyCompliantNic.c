// PopConnectedStandbyCompliantNic 
 
int PopConnectedStandbyCompliantNic()
{
  int *v0; // r1
  int result; // r0
  unsigned int v2; // r2

  v0 = &PopCsDeviceCompliance;
  result = 0;
  v2 = 0;
  while ( v2 != 1 && v2 != 2 && v2 != 4 || *v0 != 1 )
  {
    ++v2;
    ++v0;
    if ( v2 >= 5 )
      return result;
  }
  return 1;
}
