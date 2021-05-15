// RtlpLookupLowBox 
 
_DWORD *__fastcall RtlpLookupLowBox(int a1, int a2)
{
  int v3; // r4
  _DWORD *result; // r0

  if ( (*(_DWORD *)(a1 + 16) & 1) != 0 )
    v3 = 0;
  else
    v3 = RtlpQueryLowBoxId();
  if ( !v3 )
    return (_DWORD *)(a2 + 8);
  for ( result = *(_DWORD **)(a2 + 8); result != (_DWORD *)(a2 + 8); result = (_DWORD *)*result )
  {
    if ( result[2] == v3 )
      return result;
  }
  return (_DWORD *)sub_553738();
}
