// HvFreeUnreconciledData 
 
unsigned int __fastcall HvFreeUnreconciledData(int a1)
{
  unsigned int result; // r0
  unsigned int v3; // r6
  int v4; // r5
  unsigned int v5; // r0

  result = *(_DWORD *)(a1 + 1924);
  if ( result )
  {
    result = ExFreePoolWithTag(result);
    *(_DWORD *)(a1 + 1924) = 0;
    *(_BYTE *)(a1 + 1900) = 0;
  }
  if ( *(_DWORD *)(a1 + 1908) )
  {
    v3 = 0;
    if ( *(_DWORD *)(a1 + 1920) )
    {
      v4 = 0;
      do
      {
        v5 = *(_DWORD *)(*(_DWORD *)(a1 + 1916) + v4 + 4);
        if ( v5 )
          ExFreePoolWithTag(v5);
        ++v3;
        v4 += 12;
      }
      while ( v3 < *(_DWORD *)(a1 + 1920) );
    }
    ExFreePoolWithTag(*(_DWORD *)(a1 + 1916));
    result = ExFreePoolWithTag(*(_DWORD *)(a1 + 1908));
    *(_DWORD *)(a1 + 1916) = 0;
    *(_DWORD *)(a1 + 1920) = 0;
    *(_DWORD *)(a1 + 1904) = 0;
    *(_DWORD *)(a1 + 1908) = 0;
  }
  return result;
}
