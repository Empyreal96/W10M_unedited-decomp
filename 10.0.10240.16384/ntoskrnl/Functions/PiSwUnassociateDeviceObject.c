// PiSwUnassociateDeviceObject 
 
unsigned int *__fastcall PiSwUnassociateDeviceObject(unsigned int *result)
{
  int *v1; // r5
  unsigned int *v2; // r4

  v1 = (int *)result[10];
  v2 = (unsigned int *)*v1;
  if ( *v1 )
  {
    PiSwRemovePdoAssociation(*v1, (int)result);
    result = PiSwDeviceDereference(v2);
    *v1 = 0;
  }
  return result;
}
