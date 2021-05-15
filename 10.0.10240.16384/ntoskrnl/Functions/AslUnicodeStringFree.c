// AslUnicodeStringFree 
 
unsigned int __fastcall AslUnicodeStringFree(unsigned int result)
{
  unsigned int v1; // r4

  v1 = result;
  if ( result )
  {
    result = *(_DWORD *)(result + 4);
    if ( result )
    {
      memset((_BYTE *)result, 66, *(unsigned __int16 *)(v1 + 2));
      result = *(_DWORD *)(v1 + 4);
      if ( result )
        result = ExFreePoolWithTag(result);
    }
    *(_DWORD *)v1 = 0;
    *(_DWORD *)(v1 + 4) = 0;
  }
  return result;
}
