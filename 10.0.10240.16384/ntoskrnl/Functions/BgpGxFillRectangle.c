// BgpGxFillRectangle 
 
_DWORD *__fastcall BgpGxFillRectangle(_DWORD *result, int a2)
{
  int v2; // r1
  int i; // r2

  v2 = result[5];
  for ( i = result[1] * *result; i; v2 += result[2] >> 3 )
  {
    *(_WORD *)(v2 + 1) = *(_WORD *)((char *)&a2 + 1);
    *(_BYTE *)v2 = a2;
    if ( result[2] == 32 )
      *(_BYTE *)(v2 + 3) = HIBYTE(a2);
    --i;
  }
  result[4] &= 0xFFFFFFEF;
  return result;
}
