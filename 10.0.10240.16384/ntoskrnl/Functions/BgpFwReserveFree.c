// BgpFwReserveFree 
 
_BYTE *__fastcall BgpFwReserveFree(int a1)
{
  unsigned int v1; // r4
  _BYTE *result; // r0

  v1 = a1 - dword_6416B8 - 4;
  result = RtlClearBits(&dword_6416BC, v1, *(_DWORD *)(a1 + 4));
  if ( v1 < dword_6416C8 )
    dword_6416C8 = v1;
  return result;
}
