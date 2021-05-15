// BgpFwFlushFrameBufferRectangle 
 
int __fastcall BgpFwFlushFrameBufferRectangle(int result, _DWORD *a2)
{
  int v2; // r3
  int v3; // r4
  int i; // r5
  unsigned int j; // r3

  v2 = __mrc(15, 0, 0, 0, 1);
  v3 = a2[1];
  for ( i = 1 << ((BYTE2(v2) & 0xF) + 2); v3; --v3 )
  {
    for ( j = result & ~(i - 1); j < *a2 + result; j += i )
      __mcr(15, 0, j, 7, 10, 1);
    result += a2[2];
  }
  __dsb(0xFu);
  return result;
}
