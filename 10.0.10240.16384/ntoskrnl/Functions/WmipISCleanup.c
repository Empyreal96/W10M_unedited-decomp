// WmipISCleanup 
 
unsigned int __fastcall WmipISCleanup(int a1)
{
  unsigned int result; // r0

  result = *(_DWORD *)(a1 + 48);
  if ( result )
  {
    result = ExFreePoolWithTag(result);
    *(_DWORD *)(a1 + 48) = 0;
  }
  return result;
}
