// CmpDeleteKcbCache 
 
unsigned int __fastcall CmpDeleteKcbCache(_DWORD *a1)
{
  unsigned int result; // r0
  unsigned int v3; // r5

  result = a1[461];
  v3 = a1[463];
  if ( result )
  {
    a1[461] = 0;
    a1[462] = 0;
    result = ExFreePoolWithTag(result);
  }
  if ( v3 )
  {
    a1[463] = 0;
    a1[464] = 0;
    result = ExFreePoolWithTag(v3);
  }
  return result;
}
