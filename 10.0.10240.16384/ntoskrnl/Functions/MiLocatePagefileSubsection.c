// MiLocatePagefileSubsection 
 
unsigned int *__fastcall MiLocatePagefileSubsection(unsigned int *result, int a2)
{
  __int64 v2; // kr00_8
  unsigned int v3; // r5
  unsigned int v4; // r2
  unsigned int v5; // r4

  v2 = *(_QWORD *)a2;
  if ( (*(_DWORD *)(*result + 28) & 0x1000) != 0 )
  {
    v3 = v2 >> 11;
    v4 = v2 & 0x7FF;
    v5 = v3;
    if ( (v2 & 0x7FF) != 0 )
      v5 = v3 + 1;
    if ( v5 <= *(_DWORD *)(*result + 56) )
    {
      result += 14 * v3;
      if ( v4 < result[7] )
      {
        *(_DWORD *)a2 = v4;
        *(_DWORD *)(a2 + 4) = 0;
        return result;
      }
    }
    return 0;
  }
  if ( v2 >= (unsigned __int64)result[7] )
    return 0;
  return result;
}
