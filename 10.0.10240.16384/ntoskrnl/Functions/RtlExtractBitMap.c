// RtlExtractBitMap 
 
int __fastcall RtlExtractBitMap(int result, unsigned int *a2, unsigned int a3, unsigned int a4)
{
  int v4; // r7
  unsigned int v6; // r4
  unsigned int v7; // r8
  bool v8; // zf
  unsigned int v9; // r6
  int v10; // r4
  char v11; // r2
  unsigned int *v12; // r5
  int *v13; // r6
  int v14; // r1
  unsigned int v15; // r7
  int v16; // t1
  unsigned int v17; // r3

  v4 = result;
  v6 = *(_DWORD *)result - a3;
  if ( a4 <= v6 )
    v6 = a4;
  if ( v6 > *a2 )
    v6 = *a2;
  if ( v6 )
  {
    v7 = a3 >> 3;
    if ( (a3 & 7) != 0 )
    {
      result = a3 & 0x1F;
      v12 = (unsigned int *)a2[1];
      v13 = (int *)(*(_DWORD *)(v4 + 4) + 4 * (a3 >> 5));
      if ( v6 >= 0x20 )
      {
        v14 = (1 << result) - 1;
        v15 = v6 >> 5;
        do
        {
          v16 = *v13++;
          v6 -= 32;
          *v12 = (v16 & (unsigned int)~v14) >> result;
          *v12++ |= (*v13 & v14) << (32 - result);
          --v15;
        }
        while ( v15 );
      }
      if ( v6 )
      {
        if ( v6 > 32 - result )
          v17 = ((*v13 & (unsigned int)~((1 << result) - 1)) >> result) | ((v13[1] & ((1 << (result + v6 - 32)) - 1)) << (32 - result));
        else
          v17 = (*v13 & (unsigned int)(((1 << v6) - 1) << result)) >> result;
        *v12 = v17;
      }
    }
    else
    {
      v9 = v6 >> 3;
      v8 = v6 >> 3 == 0;
      v10 = v6 & 7;
      if ( !v8 )
        result = memmove(a2[1], *(_DWORD *)(result + 4) + v7, v9);
      if ( v10 )
      {
        result = a2[1];
        v11 = *(_BYTE *)(result + v9) & ~((1 << v10) - 1);
        *(_BYTE *)(result + v9) = v11;
        *(_BYTE *)(result + v9) = *(_BYTE *)(*(_DWORD *)(v4 + 4) + v9 + v7) & ((1 << v10) - 1) | v11;
      }
    }
  }
  return result;
}
