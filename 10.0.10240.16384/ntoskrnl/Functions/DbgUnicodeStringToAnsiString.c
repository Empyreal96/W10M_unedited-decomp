// DbgUnicodeStringToAnsiString 
 
int __fastcall DbgUnicodeStringToAnsiString(int a1, unsigned __int16 *a2)
{
  unsigned int v5; // r0
  int v6; // r0

  if ( NlsMbCodePageTag )
    return sub_50A640();
  v5 = ((unsigned int)*a2 + 2) >> 1;
  if ( v5 <= 0xFFFF )
  {
    *(_WORD *)(a1 + 2) = v5;
    *(_WORD *)a1 = v5 - 1;
    v6 = ExAllocatePoolWithTag(512, v5, 1682730317);
    *(_DWORD *)(a1 + 4) = v6;
    if ( v6 )
    {
      if ( RtlUnicodeStringToAnsiString(a1, a2, 0) >= 0 )
        return 1;
      ExFreePoolWithTag(*(_DWORD *)(a1 + 4), 0);
    }
  }
  return 0;
}
