// RtlLargeIntegerToUnicode 
 
int __fastcall RtlLargeIntegerToUnicode(_DWORD *a1, int a2, int a3, int a4)
{
  int v6; // lr
  __int64 v7; // r2
  int v8; // r0
  int v9; // r5
  bool v10; // cc
  int v11; // r3
  _WORD *v12; // r2
  _BYTE v14[22]; // [sp+86h] [bp-16h] BYREF

  v6 = (int)v14;
  HIDWORD(v7) = *a1;
  LODWORD(v7) = a1[1];
  do
  {
    v8 = BYTE4(v7) & 0xF;
    HIDWORD(v7) = ((_DWORD)v7 << 28) | (HIDWORD(v7) >> 4);
    LODWORD(v7) = (unsigned int)v7 >> 4;
    *(_WORD *)(v6 - 2) = RtlpIntegerWChars[v8];
    v6 -= 2;
  }
  while ( v7 );
  v9 = (int)&v14[-v6] >> 1;
  if ( a3 < 0 )
  {
    a3 = -a3;
    v10 = v9 <= a3;
    if ( v9 >= a3 )
      goto LABEL_9;
    v11 = a3 - v9;
    v12 = (_WORD *)a4;
    if ( a3 != v9 )
    {
      do
        *v12++ = 48;
      while ( v12 != (_WORD *)(a4 + 2 * v11) );
    }
    a3 = (int)&v14[-v6] >> 1;
    a4 += 2 * v11;
  }
  v10 = v9 <= a3;
LABEL_9:
  if ( !v10 )
    return -2147483643;
  memmove(a4, v6, 2 * v9);
  if ( v9 < a3 )
    *(_WORD *)(a4 + 2 * v9) = 0;
  return 0;
}
