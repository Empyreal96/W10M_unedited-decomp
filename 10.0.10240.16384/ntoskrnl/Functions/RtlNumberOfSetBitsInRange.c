// RtlNumberOfSetBitsInRange 
 
int __fastcall RtlNumberOfSetBitsInRange(unsigned int *a1, unsigned int a2, unsigned int a3)
{
  unsigned int v3; // r7
  unsigned int v4; // r4
  int v5; // r5
  char *v6; // r6
  int v7; // r8
  int v8; // r9
  unsigned int v9; // r7
  int v10; // t1
  char v11; // r2
  int v12; // r2
  char v13; // r3
  unsigned int i; // r8
  int v15; // t1
  unsigned int v16; // r2
  char v17; // t1

  if ( a2 >= *a1 || *a1 - a2 < a3 || !a3 )
    return -1;
  v3 = a2 + a3 - 1;
  v4 = a2 >> 3;
  v5 = 0;
  v6 = (char *)(a1[1] + (a2 >> 3));
  v7 = a2 & 7;
  v8 = v3 & 7;
  if ( a2 >> 3 == v3 >> 3 )
    return *((unsigned __int8 *)RtlpBitsClearTotal
           + (unsigned __int8)~(*((_BYTE *)dword_409D94 + v7) & *((_BYTE *)dword_409D88 + v8 + 1) & *v6));
  if ( (a2 & 0x1F) != 0 || (a3 & 0x1F) != 0 )
  {
    if ( (a2 & 7) != 0 )
    {
      v11 = *v6++;
      v5 = *((unsigned __int8 *)RtlpBitsClearTotal + (unsigned __int8)~(*((_BYTE *)dword_409D94 + v7) & v11));
      ++v4;
    }
    v12 = 4 - (v4 & 3);
    if ( v12 != 4 && v12 )
    {
      do
      {
        if ( v4 >= v3 >> 3 )
          break;
        v13 = *v6++;
        ++v4;
        v5 += *((unsigned __int8 *)RtlpBitsClearTotal + (unsigned __int8)~v13);
        --v12;
      }
      while ( v12 );
    }
    for ( i = v4 + 4; i <= v3 >> 3; i += 4 )
    {
      v15 = *(_DWORD *)v6;
      v6 += 4;
      v5 += (unsigned __int8)(*((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)((unsigned int)~v15 >> 16))
                            + *((_BYTE *)RtlpBitsClearTotal + ((unsigned int)~v15 >> 24))
                            + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)((unsigned __int16)~(_WORD)v15 >> 8))
                            + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)~(_BYTE)v15));
      v4 += 4;
    }
    if ( v4 < v3 >> 3 )
    {
      v16 = (v3 >> 3) - v4;
      do
      {
        v17 = *v6++;
        v5 += *((unsigned __int8 *)RtlpBitsClearTotal + (unsigned __int8)~v17);
        --v16;
      }
      while ( v16 );
    }
    v5 += *((unsigned __int8 *)RtlpBitsClearTotal + (unsigned __int8)~(*((_BYTE *)dword_409D88 + v8 + 1) & *v6));
  }
  else
  {
    v9 = ((a3 - 1) >> 5) + 1;
    do
    {
      v10 = *(_DWORD *)v6;
      v6 += 4;
      v5 += (unsigned __int8)(*((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)((unsigned int)~v10 >> 16))
                            + *((_BYTE *)RtlpBitsClearTotal + ((unsigned int)~v10 >> 24))
                            + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)((unsigned __int16)~(_WORD)v10 >> 8))
                            + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)~(_BYTE)v10));
      --v9;
    }
    while ( v9 );
  }
  return v5;
}
