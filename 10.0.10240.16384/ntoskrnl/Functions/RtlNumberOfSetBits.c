// RtlNumberOfSetBits 
 
int __fastcall RtlNumberOfSetBits(unsigned int *a1)
{
  unsigned int v1; // r1
  int v2; // lr
  BOOL v3; // r3
  char *v4; // r6
  int v5; // r9
  unsigned int v6; // r2
  int v7; // r7
  int v8; // r10
  unsigned int v9; // r4
  int v10; // r8
  char v11; // t1
  char v12; // r1
  unsigned int v14; // lr
  int v15; // t1
  char v16; // t1
  char v17; // r2

  v1 = *a1;
  v2 = *a1 & 7;
  v3 = v2 != 0;
  v4 = (char *)a1[1];
  v5 = v3 + (*a1 >> 3);
  v6 = 4 - ((unsigned __int8)v4 & 3);
  v7 = 0;
  if ( v6 > *a1 >> 3 )
  {
    v6 = v3 + (v1 >> 3);
    v8 = 0;
    v9 = 0;
  }
  else
  {
    v8 = ((v1 >> 3) - v6) & 3;
    if ( v2 )
      ++v8;
    v9 = v5 - v8 - v6;
  }
  v10 = 0;
  if ( v6 )
  {
    do
    {
      v11 = *v4++;
      v12 = v11;
      if ( v10 == v5 - 1 && v2 )
        v12 &= *((_BYTE *)dword_409D88 + v2);
      ++v10;
      v7 += *((unsigned __int8 *)RtlpBitsClearTotal + (unsigned __int8)~v12);
      --v6;
    }
    while ( v6 );
    v5 = v3 + (*a1 >> 3);
  }
  if ( v9 )
  {
    v14 = ((v9 - 1) >> 2) + 1;
    v10 += 4 * v14;
    do
    {
      v15 = *(_DWORD *)v4;
      v4 += 4;
      v7 += (unsigned __int8)(*((_BYTE *)RtlpBitsClearTotal + ((unsigned int)~v15 >> 24))
                            + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)((unsigned int)~v15 >> 16))
                            + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)((unsigned __int16)~(_WORD)v15 >> 8))
                            + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)~(_BYTE)v15));
      --v14;
    }
    while ( v14 );
    v2 = *a1 & 7;
  }
  for ( ; v8; --v8 )
  {
    v16 = *v4++;
    v17 = v16;
    if ( v10 == v5 - 1 && v2 )
      v17 &= *((_BYTE *)dword_409D88 + v2);
    ++v10;
    v7 += *((unsigned __int8 *)RtlpBitsClearTotal + (unsigned __int8)~v17);
  }
  return v7;
}
