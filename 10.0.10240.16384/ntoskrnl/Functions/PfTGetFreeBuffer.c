// PfTGetFreeBuffer 
 
_DWORD *__fastcall PfTGetFreeBuffer(int a1)
{
  _DWORD *v2; // r2
  _DWORD *result; // r0

  v2 = *(_DWORD **)(a1 + 12);
  result = 0;
  if ( v2 )
  {
    result = v2;
    *(_DWORD *)(a1 + 12) = *v2;
    --*(_WORD *)(a1 + 10);
  }
  return result;
}
