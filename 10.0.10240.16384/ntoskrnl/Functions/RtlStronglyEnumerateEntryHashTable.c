// RtlStronglyEnumerateEntryHashTable 
 
_DWORD *__fastcall RtlStronglyEnumerateEntryHashTable(int a1, int a2, int a3)
{
  unsigned int v5; // r1
  unsigned int v6; // r5
  unsigned int v7; // r6
  _DWORD *result; // r0

  v5 = *(_DWORD *)(a2 + 16);
  v6 = *(_DWORD *)(a1 + 8);
  if ( v5 < v6 )
  {
    v7 = v5;
    while ( 2 )
    {
      if ( v5 == v7 )
      {
        result = *(_DWORD **)a2;
        a3 = *(_DWORD *)(a2 + 12);
      }
      else
      {
        result = (_DWORD *)RtlpGetChainHead(a1, v5, a3);
        a3 = (int)result;
      }
      while ( *result != a3 )
      {
        result = (_DWORD *)*result;
        if ( result[2] )
        {
          *(_DWORD *)(a2 + 12) = a3;
          *(_DWORD *)(a2 + 16) = v5;
          *(_DWORD *)a2 = result;
          return result;
        }
      }
      if ( ++v5 < v6 )
        continue;
      break;
    }
  }
  return 0;
}
