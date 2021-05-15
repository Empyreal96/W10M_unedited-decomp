// RtlFillMemoryUlong 
 
_DWORD *__fastcall RtlFillMemoryUlong(_DWORD *result, unsigned int a2, int a3)
{
  _DWORD *v3; // r3

  if ( a2 >> 2 )
  {
    v3 = &result[a2 >> 2];
    do
      *result++ = a3;
    while ( result != v3 );
  }
  return result;
}
