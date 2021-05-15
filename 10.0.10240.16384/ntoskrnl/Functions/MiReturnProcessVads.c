// MiReturnProcessVads 
 
unsigned int __fastcall MiReturnProcessVads(unsigned int result)
{
  _DWORD *v1; // r4
  unsigned int v2; // r5
  unsigned int v3; // r0

  v1 = (_DWORD *)result;
  while ( v1 )
  {
    v2 = (unsigned int)v1;
    v3 = v1[9];
    v1 = (_DWORD *)*v1;
    if ( v3 )
      ExFreePoolWithTag(v3);
    result = ExFreePoolWithTag(v2);
  }
  return result;
}
