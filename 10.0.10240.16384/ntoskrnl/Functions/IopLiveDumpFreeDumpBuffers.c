// IopLiveDumpFreeDumpBuffers 
 
unsigned int __fastcall IopLiveDumpFreeDumpBuffers(unsigned int result)
{
  _DWORD *v1; // r4
  unsigned int v2; // r5
  unsigned int v3; // r0

  v1 = (_DWORD *)result;
  if ( result )
  {
    v2 = 0;
    if ( *(_DWORD *)(result + 28) )
    {
      do
      {
        v3 = *(_DWORD *)(v1[8] + 4 * v2);
        if ( v3 )
        {
          ExFreePoolWithTag(v3);
          *(_DWORD *)(v1[8] + 4 * v2) = 0;
        }
        ++v2;
      }
      while ( v2 < v1[7] );
    }
    result = v1[8];
    if ( result )
    {
      result = ExFreePoolWithTag(result);
      v1[8] = 0;
    }
    v1[7] = 0;
    v1[4] = 0;
    *v1 = 0;
    v1[1] = 0;
    v1[2] = 0;
  }
  return result;
}
