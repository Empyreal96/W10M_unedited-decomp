// RtlIntegerToUnicode 
 
int __fastcall RtlIntegerToUnicode(unsigned int a1, unsigned int a2, int a3, _WORD *a4)
{
  int v4; // r9
  unsigned int v5; // r8
  int v6; // r5
  int v7; // r3
  int v9; // r4
  int v10; // r1
  int v11; // r5
  int v12; // r10
  bool v13; // cc
  int v14; // r3
  _WORD *v15; // r2
  _BYTE v17[38]; // [sp+4Ah] [bp-26h] BYREF

  v4 = a3;
  v5 = a2;
  if ( a2 != 10 )
  {
    switch ( a2 )
    {
      case 0u:
        v5 = 10;
        break;
      case 2u:
        v6 = 1;
        goto LABEL_6;
      case 8u:
        v6 = 3;
        goto LABEL_6;
      case 0x10u:
        v6 = 4;
LABEL_6:
        v7 = (1 << v6) - 1;
        goto LABEL_10;
      default:
        return -1073741811;
    }
  }
  v6 = 0;
  v7 = 0;
LABEL_10:
  v9 = (int)v17;
  do
  {
    if ( v6 )
    {
      v10 = v7 & a1;
      a1 >>= v6;
    }
    else
    {
      if ( !v5 )
        __brkdiv0();
      v10 = a1 % v5;
      a1 /= v5;
    }
    *(_WORD *)(v9 - 2) = RtlpIntegerWChars[v10];
    v9 -= 2;
  }
  while ( a1 );
  v11 = (int)&v17[-v9] >> 1;
  v12 = (int)a4;
  if ( a3 < 0 )
  {
    v4 = -a3;
    v13 = v11 <= -a3;
    if ( v11 >= -a3 )
      goto LABEL_23;
    v14 = v4 - v11;
    v15 = a4;
    if ( v4 != v11 )
    {
      do
        *v15++ = 48;
      while ( v15 != &a4[v14] );
    }
    v4 = (int)&v17[-v9] >> 1;
    v12 = (int)&a4[v14];
  }
  v13 = v11 <= v4;
LABEL_23:
  if ( !v13 )
    return -2147483643;
  memmove(v12, v9, 2 * v11);
  if ( v11 < v4 )
    *(_WORD *)(v12 + 2 * v11) = 0;
  return 0;
}
