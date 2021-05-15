// RtlpFindUCREntry 
 
_DWORD *__fastcall RtlpFindUCREntry(int a1, unsigned int a2)
{
  _DWORD *result; // r0
  _DWORD *v3; // r2

  if ( RtlpHeapErrorHandlerThreshold >= 1 )
    return (_DWORD *)sub_55410C();
  if ( *(_DWORD *)(a1 + 184) )
    JUMPOUT(0x554124);
  v3 = (_DWORD *)(a1 + 140);
  for ( result = *(_DWORD **)(a1 + 140); v3 != result; result = (_DWORD *)*result )
  {
    if ( result[5] >= a2 )
      return result;
  }
  return v3;
}
