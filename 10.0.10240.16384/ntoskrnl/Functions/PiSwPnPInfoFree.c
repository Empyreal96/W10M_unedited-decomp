// PiSwPnPInfoFree 
 
unsigned int __fastcall PiSwPnPInfoFree(unsigned int *a1)
{
  unsigned int v2; // r0
  unsigned int v3; // r0
  unsigned int v4; // r0
  unsigned int v5; // r0
  unsigned int result; // r0

  v2 = *a1;
  if ( v2 )
  {
    ExFreePoolWithTag(v2);
    *a1 = 0;
  }
  v3 = a1[1];
  if ( v3 )
  {
    ExFreePoolWithTag(v3);
    a1[1] = 0;
  }
  v4 = a1[2];
  if ( v4 )
  {
    ExFreePoolWithTag(v4);
    a1[2] = 0;
  }
  v5 = a1[3];
  if ( v5 )
  {
    ExFreePoolWithTag(v5);
    a1[3] = 0;
  }
  result = a1[4];
  if ( result )
  {
    result = ExFreePoolWithTag(result);
    a1[4] = 0;
  }
  return result;
}
