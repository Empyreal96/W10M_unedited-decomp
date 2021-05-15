// ExpRemoveCurrentThreadFromThreadHistory 
 
unsigned int __fastcall ExpRemoveCurrentThreadFromThreadHistory(unsigned int result)
{
  unsigned int v1; // r5
  unsigned int v2; // r4

  v1 = result;
  if ( (*(_DWORD *)(result + 88) & 7) != 4 )
  {
    result = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v2 = 0;
    while ( *(_DWORD *)(v1 + 4 * v2 + 32) != result )
    {
      v2 = (unsigned __int8)(v2 + 1);
      if ( v2 >= 4 )
        return result;
    }
    result = ObfDereferenceObjectWithTag(result);
    *(_DWORD *)(v1 + 4 * v2 + 32) = 0;
  }
  return result;
}
