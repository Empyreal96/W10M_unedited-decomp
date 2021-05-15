// PiPnpRtlFreeInterfaceDeleteInfo 
 
int *__fastcall PiPnpRtlFreeInterfaceDeleteInfo(int *result)
{
  int *v1; // r4
  int v2; // r0
  int v3; // r0
  int v4; // r0
  int v5; // r0

  v1 = result;
  if ( result )
  {
    v2 = *result;
    if ( *v1 )
      PiDmObjectRelease(v2);
    v3 = v1[1];
    if ( v3 )
      PiDmObjectRelease(v3);
    v4 = v1[2];
    if ( v4 )
      PiDmObjectRelease(v4);
    v5 = v1[3];
    if ( v5 )
      PiDmObjectRelease(v5);
    result = (int *)ExFreePoolWithTag((unsigned int)v1);
  }
  return result;
}
