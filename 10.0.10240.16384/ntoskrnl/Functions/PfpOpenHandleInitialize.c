// PfpOpenHandleInitialize 
 
_BYTE *__fastcall PfpOpenHandleInitialize(int a1)
{
  _BYTE *result; // r0

  result = memset((_BYTE *)a1, 0, 20);
  *(_DWORD *)(a1 + 16) |= 2u;
  return result;
}
