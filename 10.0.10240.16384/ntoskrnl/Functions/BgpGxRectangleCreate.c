// BgpGxRectangleCreate 
 
int __fastcall BgpGxRectangleCreate(_DWORD *a1, int a2, _DWORD *a3)
{
  int v6; // r5
  unsigned int v7; // r4
  _DWORD *v8; // r0
  int v9; // r3

  v6 = 0;
  v7 = GxpBitsToBytes(a1[1] * *a1 * a2);
  v8 = (_DWORD *)BgpFwAllocateMemory(v7 + 64);
  if ( !v8 )
    return -1073741801;
  v9 = a1[1];
  *a3 = v8;
  *v8 = v9;
  v8[1] = *a1;
  v8[2] = a2;
  v8[3] = v7;
  v8[4] = 0;
  v8[5] = v8 + 16;
  return v6;
}
