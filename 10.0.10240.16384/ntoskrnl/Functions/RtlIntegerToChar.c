// RtlIntegerToChar 
 
int __fastcall RtlIntegerToChar(unsigned int a1, unsigned int a2, int a3, int a4)
{
  int v4; // r4
  unsigned int v5; // r5
  int v7; // r6
  int v8; // r10
  int v9; // r9
  int v10; // r1
  int v11; // r5
  int v12; // r8
  bool v13; // cc
  int v14; // r3
  _BYTE *v15; // r2
  _BYTE *v16; // [sp+0h] [bp-50h]
  _BYTE v17[39]; // [sp+29h] [bp-27h] BYREF

  v16 = (_BYTE *)a4;
  v4 = a3;
  v5 = a2;
  switch ( a2 )
  {
    case 0u:
      v5 = 10;
      goto LABEL_12;
    case 2u:
      v7 = 1;
      break;
    case 8u:
      v7 = 3;
      break;
    case 0xAu:
LABEL_12:
      v7 = 0;
      v8 = 0;
      goto LABEL_13;
    case 0x10u:
      v7 = 4;
      break;
    default:
      return -1073741811;
  }
  v8 = (1 << v7) - 1;
LABEL_13:
  v9 = (int)v17;
  do
  {
    if ( v7 )
    {
      v10 = v8 & a1;
      a1 >>= v7;
    }
    else
    {
      if ( !v5 )
        __brkdiv0();
      v10 = a1 % v5;
      a1 /= v5;
    }
    *(_BYTE *)--v9 = *((_BYTE *)RtlpIntegerChars + v10);
  }
  while ( a1 );
  v11 = (int)&v17[-v9];
  v12 = a4;
  if ( a3 < 0 )
  {
    v4 = -a3;
    v13 = v11 <= -a3;
    if ( v11 >= -a3 )
      goto LABEL_26;
    v14 = v4 - v11;
    v15 = v16;
    if ( v4 != v11 )
    {
      do
        *v15++ = 48;
      while ( v15 != &v16[v14] );
    }
    v4 = (int)&v17[-v9];
    v12 = (int)&v16[v14];
  }
  v13 = v11 <= v4;
LABEL_26:
  if ( !v13 )
    return -2147483643;
  memmove(v12, v9, (unsigned int)&v17[-v9]);
  if ( v11 < v4 )
    *(_BYTE *)(v12 + v11) = 0;
  return 0;
}
