// RtlDecompressChunks 
 
int __fastcall RtlDecompressChunks(_BYTE *a1, unsigned int a2, int a3, unsigned int a4, int a5, int a6, int a7)
{
  int v8; // lr
  int v9; // r10
  unsigned int v10; // r7
  _BYTE *v11; // r6
  unsigned int v12; // r2
  unsigned int v13; // r1
  int result; // r0
  int v15; // r9
  int *v16; // r8
  unsigned int v17; // r4
  unsigned int v18; // r3
  unsigned int v19; // r9
  unsigned int v20; // lr
  int v21; // t1
  unsigned int v22; // [sp+8h] [bp-38h]
  int v23; // [sp+Ch] [bp-34h]
  int v24; // [sp+10h] [bp-30h]
  unsigned int v25; // [sp+14h] [bp-2Ch] BYREF
  unsigned int v26; // [sp+18h] [bp-28h]
  unsigned int v27; // [sp+1Ch] [bp-24h]

  v8 = a3;
  v22 = a3;
  v9 = *(unsigned __int16 *)(a7 + 6);
  v10 = a2;
  v11 = a1;
  v12 = 1 << *(_BYTE *)(a7 + 3);
  v13 = (unsigned int)&a1[a2];
  v26 = v13;
  v27 = v12;
  v24 = v9;
  if ( v13 < (unsigned int)a1 )
    return -1073741811;
  v15 = a6;
  v16 = (int *)(a7 + 8);
  v23 = a6;
  while ( 1 )
  {
    v17 = v10;
    if ( v10 >= v12 )
      v17 = v12;
    if ( !v9 || (v18 = *v16) == 0 )
    {
      if ( (unsigned int)&v11[v17] > v13 )
        return -1073741246;
      memset(v11, 0, v17);
      if ( !v9 )
      {
        v9 = 1;
        --v16;
      }
      goto LABEL_28;
    }
    if ( v18 == v12 )
    {
      if ( v17 >= a4 )
      {
        if ( !v15 && v17 > a4 )
          return -1073741246;
        memmove((int)v11, v8, a4);
        memmove((int)&v11[a4], a5, v17 - a4);
        goto LABEL_24;
      }
      memmove((int)v11, v8, v17);
LABEL_28:
      v20 = v22;
      goto LABEL_29;
    }
    if ( v18 > a4 )
      break;
LABEL_20:
    result = RtlDecompressBuffer(*(_WORD *)a7, (int)v11, v17, v8, *v16, (int)&v25);
    if ( result < 0 )
      return result;
    if ( v17 > v25 )
      memset(&v11[v25], 0, v17 - v25);
    if ( *v16 < a4 )
      goto LABEL_28;
LABEL_24:
    v20 = a5 - a4;
    a4 += v15;
    v15 = 0;
    v23 = 0;
LABEL_29:
    v13 = v26;
    v11 += v17;
    if ( (unsigned int)v11 > v26 || v17 > v10 )
      return -1073741246;
    v21 = *v16++;
    v10 -= v17;
    --v9;
    v8 = v20 + v21;
    a4 -= v21;
    v22 = v8;
    v24 = v9;
    if ( !v10 )
      return 0;
    v12 = v27;
  }
  if ( v15 )
  {
    v19 = (unsigned int)&v11[v10 - v12];
    if ( v19 + a4 < v19 )
      return -1073741811;
    if ( v19 >= (unsigned int)v11 && v19 + a4 <= v13 )
    {
      memmove(v19, v8, a4);
      memmove(v19 + a4, a5, *v16 - a4);
      v9 = v24;
      v8 = v19;
      v22 = v19;
      v15 = v23;
      goto LABEL_20;
    }
  }
  return -1073741246;
}
