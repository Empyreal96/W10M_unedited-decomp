// SmFpInitialize 
 
_BYTE *__fastcall SmFpInitialize(int a1)
{
  _BYTE *result; // r0

  result = memset((_BYTE *)a1, 0, 64);
  *(_BYTE *)(a1 + 4) = 1;
  *(_BYTE *)(a1 + 6) = 4;
  *(_BYTE *)(a1 + 5) = 0;
  *(_DWORD *)(a1 + 8) = 0;
  *(_DWORD *)(a1 + 12) = a1 + 12;
  *(_DWORD *)(a1 + 16) = a1 + 12;
  return result;
}
