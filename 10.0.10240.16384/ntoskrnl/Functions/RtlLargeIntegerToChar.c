// RtlLargeIntegerToChar 
 
int __fastcall RtlLargeIntegerToChar(unsigned int *a1, unsigned int a2, int a3, int a4)
{
  int v4; // r6
  int v5; // r4
  unsigned int v6; // r5
  int v9; // r0
  int v10; // lr
  int v11; // r8
  unsigned int v12; // r9
  unsigned int v13; // r5
  int v14; // r1
  unsigned int v15; // r1
  unsigned int v16; // r2
  _BYTE *v17; // r5
  bool v18; // cc
  int v19; // r3
  _BYTE *v20; // r2
  int v21; // [sp+8h] [bp-78h] BYREF
  __int64 v22; // [sp+10h] [bp-70h] BYREF
  _BYTE v23[39]; // [sp+59h] [bp-27h] BYREF

  v4 = a4;
  v21 = a4;
  v5 = a3;
  LODWORD(v22) = a3;
  v6 = a2;
  switch ( a2 )
  {
    case 0u:
      v6 = 10;
      goto LABEL_12;
    case 2u:
      v9 = 1;
      goto LABEL_10;
    case 8u:
      v9 = 3;
LABEL_10:
      v10 = (1 << v9) - 1;
      goto LABEL_13;
  }
  if ( a2 != 10 )
  {
    if ( a2 != 16 )
      return -1073741811;
    v9 = 4;
    goto LABEL_10;
  }
LABEL_12:
  v9 = 0;
  v10 = 0;
LABEL_13:
  v11 = (int)v23;
  if ( v9 )
  {
    v12 = *a1;
    v13 = a1[1];
    do
    {
      v14 = v12 & v10;
      v12 = __PAIR64__(v13, v12) >> v9;
      v13 >>= v9;
      *(_BYTE *)--v11 = *((_BYTE *)RtlpIntegerChars + v14);
    }
    while ( __PAIR64__(v13, v12) );
    v5 = v22;
    v4 = v21;
  }
  else
  {
    v15 = *a1;
    v16 = a1[1];
    do
    {
      RtlExtendedLargeIntegerDivide(&v22, __PAIR64__(v16, v15), v6, &v21);
      v16 = HIDWORD(v22);
      v15 = v22;
      *(_BYTE *)--v11 = *((_BYTE *)RtlpIntegerChars + v21);
    }
    while ( __PAIR64__(v16, v15) );
  }
  v17 = &v23[-v11];
  if ( v5 < 0 )
  {
    v5 = -v5;
    v18 = (int)v17 <= v5;
    if ( (int)v17 >= v5 )
      goto LABEL_25;
    v19 = v5 - (_DWORD)v17;
    v20 = (_BYTE *)v4;
    if ( (_BYTE *)v5 != v17 )
    {
      do
        *v20++ = 48;
      while ( v20 != (_BYTE *)(v4 + v19) );
    }
    v5 = (int)&v23[-v11];
    v4 += v19;
  }
  v18 = (int)v17 <= v5;
LABEL_25:
  if ( !v18 )
    return -2147483643;
  memmove(v4, v11, (unsigned int)&v23[-v11]);
  if ( (int)v17 < v5 )
    v17[v4] = 0;
  return 0;
}
