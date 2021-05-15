// MiClearImports 
 
unsigned int __fastcall MiClearImports(int a1)
{
  unsigned int result; // r0

  result = *(_DWORD *)(a1 + 76);
  if ( result != 1 )
  {
    if ( result != -2 && (result & 1) == 0 )
      result = ExFreePoolWithTag(result);
    *(_DWORD *)(a1 + 76) = 1;
  }
  return result;
}
