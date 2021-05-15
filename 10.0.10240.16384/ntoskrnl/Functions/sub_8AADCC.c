// sub_8AADCC 
 
_WORD *__fastcall sub_8AADCC(int a1)
{
  _WORD *result; // r0

  *(_DWORD *)a1 = 0;
  *(_DWORD *)(a1 + 4) = 0;
  *(_DWORD *)(a1 + 8) = 0;
  result = (_WORD *)ExAllocatePoolWithTag(1, 128, 542329939);
  if ( result )
  {
    *(_WORD *)(a1 + 2) = 128;
    *(_WORD *)a1 = 0;
    *(_DWORD *)(a1 + 4) = 0;
    *(_DWORD *)(a1 + 8) = result;
    *result = 0;
  }
  return result;
}
