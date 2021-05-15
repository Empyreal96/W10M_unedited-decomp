// SmCrEncInitialize 
 
_BYTE *__fastcall SmCrEncInitialize(int a1)
{
  _BYTE *result; // r0

  memset((_BYTE *)a1, 0, 96);
  *(_DWORD *)(a1 + 4) = 1;
  result = memset((_BYTE *)(a1 + 32), 0, 64);
  *(_DWORD *)(a1 + 32) = 64;
  *(_DWORD *)(a1 + 36) = 1;
  return result;
}
