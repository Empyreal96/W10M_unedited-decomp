// EtwpInitializeBufferHeader 
 
_BYTE *__fastcall EtwpInitializeBufferHeader(_DWORD *a1, int a2)
{
  _BYTE *result; // r0
  int v5; // r3
  int v6; // r3

  result = memset((_BYTE *)a2, 0, 72);
  __dmb(0xBu);
  *(_DWORD *)(a2 + 8) = 72;
  v5 = *(_DWORD *)(a2 + 8);
  __dmb(0xBu);
  *(_DWORD *)(a2 + 48) = v5;
  *(_DWORD *)a2 = a1[1];
  v6 = (unsigned __int16)*a1;
  *(_WORD *)(a2 + 42) = v6;
  if ( !v6 )
    result = (_BYTE *)sub_54CB3C(result);
  return result;
}
