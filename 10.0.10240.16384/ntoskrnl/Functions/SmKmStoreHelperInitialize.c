// SmKmStoreHelperInitialize 
 
_BYTE *__fastcall SmKmStoreHelperInitialize(int a1)
{
  _BYTE *result; // r0

  result = memset((_BYTE *)a1, 0, 72);
  *(_BYTE *)(a1 + 6) = 4;
  *(_BYTE *)(a1 + 4) = 0;
  *(_BYTE *)(a1 + 5) = 0;
  *(_DWORD *)(a1 + 8) = 0;
  *(_DWORD *)(a1 + 12) = a1 + 12;
  *(_DWORD *)(a1 + 16) = a1 + 12;
  *(_BYTE *)(a1 + 20) = 0;
  *(_BYTE *)(a1 + 21) = 0;
  *(_BYTE *)(a1 + 22) = 4;
  *(_DWORD *)(a1 + 24) = 0;
  *(_DWORD *)(a1 + 28) = a1 + 28;
  *(_DWORD *)(a1 + 32) = a1 + 28;
  return result;
}
