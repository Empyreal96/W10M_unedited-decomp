// PfTLbInitialize 
 
_BYTE *__fastcall PfTLbInitialize(int a1, int a2, int a3)
{
  _BYTE *result; // r0

  if ( a3 )
  {
    result = memset((_BYTE *)(a1 + 16), 0, a2 - 16);
  }
  else
  {
    result = memset((_BYTE *)a1, 0, a2);
    *(_DWORD *)a1 = a1;
    *(_DWORD *)(a1 + 4) = a1;
  }
  *(_DWORD *)(a1 + 8) = 0;
  *(_DWORD *)(a1 + 12) = (unsigned int)(a2 - 16) >> 3;
  return result;
}
