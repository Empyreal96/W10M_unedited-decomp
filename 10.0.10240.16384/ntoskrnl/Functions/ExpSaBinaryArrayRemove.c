// ExpSaBinaryArrayRemove 
 
_DWORD *__fastcall ExpSaBinaryArrayRemove(int a1, unsigned int a2)
{
  unsigned int v2; // r3
  _DWORD *result; // r0

  v2 = __clz(a2);
  result = *(_DWORD **)(a1 + 4 * (29 - v2));
  result[((1 << (31 - v2)) ^ a2) + 1] = 0;
  if ( (*result)-- == 1 )
  {
    *(_DWORD *)(a1 + 4 * (29 - v2)) = 0;
    result = (_DWORD *)ExFreePoolWithTag(result);
  }
  return result;
}
