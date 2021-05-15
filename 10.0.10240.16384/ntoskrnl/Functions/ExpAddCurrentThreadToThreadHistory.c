// ExpAddCurrentThreadToThreadHistory 
 
unsigned int __fastcall ExpAddCurrentThreadToThreadHistory(unsigned int result)
{
  unsigned int v1; // r7
  unsigned int v2; // r6
  int v3; // r1
  unsigned int i; // r2
  unsigned int v5; // r2
  int v6; // r5
  unsigned int v7; // r4

  v1 = result;
  if ( (*(_DWORD *)(result + 88) & 7) != 4 )
  {
    v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v3 = 0;
    for ( i = result; *(_DWORD *)(i + 32) != v2; i += 4 )
    {
      if ( (unsigned int)++v3 >= 4 )
      {
        ObfReferenceObjectWithTag(v2, 1953261124);
        v5 = 0;
        result = v1;
        while ( *(_DWORD *)(result + 32) )
        {
          ++v5;
          result += 4;
          if ( v5 >= 4 )
          {
            v6 = *(_DWORD *)(v1 + 88) & 7;
            v7 = v1 + 4 * v6;
            ObfDereferenceObjectWithTag(*(_DWORD *)(v7 + 32));
            *(_DWORD *)(v7 + 32) = v2;
            result = (v6 + 1) & 3 | *(_DWORD *)(v1 + 88) & 0xFFFFFFF8;
            *(_DWORD *)(v1 + 88) = result;
            return result;
          }
        }
        *(_DWORD *)(v1 + 4 * v5 + 32) = v2;
        return result;
      }
    }
  }
  return result;
}
