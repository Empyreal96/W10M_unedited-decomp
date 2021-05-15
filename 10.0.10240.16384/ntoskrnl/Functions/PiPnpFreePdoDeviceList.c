// PiPnpFreePdoDeviceList 
 
unsigned int *__fastcall PiPnpFreePdoDeviceList(unsigned int *result)
{
  unsigned int *v1; // r4
  unsigned int v2; // r6
  unsigned int *v3; // r5
  int v4; // t1

  v1 = result;
  if ( result )
  {
    v2 = 0;
    if ( *result )
    {
      v3 = result;
      do
      {
        v4 = v3[1];
        ++v3;
        ObfDereferenceObject(v4);
        ++v2;
      }
      while ( v2 < *v1 );
    }
    result = (unsigned int *)ExFreePoolWithTag((unsigned int)v1);
  }
  return result;
}
