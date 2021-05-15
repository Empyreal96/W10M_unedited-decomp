// RtlSparseBitmapCtxInitializeRange 
 
_BYTE *__fastcall RtlSparseBitmapCtxInitializeRange(_DWORD *a1, _DWORD *a2)
{
  _BYTE *result; // r0
  int v5; // r1

  *a2 = 0;
  a2[1] = 0;
  a2[2] = 0;
  a2[1] = a1[8];
  a2[2] = a2 + 3;
  if ( (a1[12] & 1) != 0 )
    result = (_BYTE *)RtlSetAllBits(a2 + 1);
  else
    result = RtlClearAllBits((int)(a2 + 1));
  v5 = a1[11];
  if ( v5 )
    result = memset((_BYTE *)a2 + a1[10], 0, a1[8] * v5);
  __dmb(0xBu);
  *a2 = 0;
  return result;
}
