// PiSwInstanceInfoFree 
 
unsigned int __fastcall PiSwInstanceInfoFree(unsigned int *a1)
{
  unsigned int v2; // r0
  unsigned int result; // r0

  v2 = *a1;
  if ( v2 )
  {
    ExFreePoolWithTag(v2);
    *a1 = 0;
  }
  result = a1[1];
  if ( result )
  {
    result = ExFreePoolWithTag(result);
    a1[1] = 0;
  }
  return result;
}
