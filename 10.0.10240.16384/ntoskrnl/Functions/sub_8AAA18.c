// sub_8AAA18 
 
unsigned int __fastcall sub_8AAA18(_DWORD *a1)
{
  unsigned int result; // r0

  result = a1[2];
  if ( result )
  {
    result = ExFreePoolWithTag(result);
    *a1 = 0;
    a1[1] = 0;
    a1[2] = 0;
  }
  return result;
}
