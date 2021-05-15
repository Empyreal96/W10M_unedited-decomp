// PiPnpRtlFreeContainerRemoveInfo 
 
int *__fastcall PiPnpRtlFreeContainerRemoveInfo(int *result)
{
  int *v1; // r4
  int v2; // r0
  int v3; // r0

  v1 = result;
  if ( result )
  {
    v2 = *result;
    if ( *v1 )
      PiDmObjectRelease(v2);
    v3 = v1[1];
    if ( v3 )
      PiDmObjectRelease(v3);
    result = (int *)ExFreePoolWithTag((unsigned int)v1);
  }
  return result;
}
