// RtlCompressChunks 
 
int __fastcall RtlCompressChunks(int a1, unsigned int a2, int a3, int a4, int a5, int a6, int a7)
{
  unsigned int v8; // r6
  unsigned int v10; // r5
  unsigned int v11; // r8
  unsigned int v12; // r4
  int v13; // r0
  int v14; // r2
  int *v15; // r1
  int result; // r0
  __int16 v17; // r3
  int v18; // [sp+10h] [bp-28h] BYREF
  int *v19; // [sp+14h] [bp-24h]

  v8 = a2;
  v10 = 1 << *(_BYTE *)(a5 + 3);
  *(_WORD *)(a5 + 6) = 0;
  v19 = (int *)(a5 + 8);
  v11 = a2 - (a2 >> 4);
  while ( 1 )
  {
    v12 = v8;
    if ( v8 >= v10 )
      v12 = v10;
    v13 = RtlCompressBuffer(*(_WORD *)a5, a1, v12, a3, v11, v10, (int)&v18, a7);
    if ( v13 == 279 )
    {
      v14 = 0;
      v18 = 0;
    }
    else if ( v13 >= 0 )
    {
      v14 = v18;
    }
    else
    {
      if ( v11 < v10 )
        return -1073741789;
      memmove(a3, a1, v12);
      if ( v10 > v12 )
        memset((_BYTE *)(v12 + a3), 0, v10 - v12);
      v14 = v10;
      v18 = v10;
    }
    v15 = v19;
    result = 0;
    a1 += v12;
    *v19 = v14;
    v17 = *(_WORD *)(a5 + 6);
    v19 = v15 + 1;
    *(_WORD *)(a5 + 6) = v17 + 1;
    if ( v12 > v8 )
      break;
    v8 -= v12;
    a3 += v14;
    v11 -= v14;
    if ( !v8 )
      return result;
  }
  return -1073741246;
}
