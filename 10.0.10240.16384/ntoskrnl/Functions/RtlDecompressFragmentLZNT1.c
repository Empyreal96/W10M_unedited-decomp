// RtlDecompressFragmentLZNT1 
 
int __fastcall RtlDecompressFragmentLZNT1(int a1, int a2, unsigned __int8 *a3, int a4, unsigned int a5, signed int a6, _DWORD *a7, unsigned int a8)
{
  unsigned __int8 *v8; // r5
  unsigned int v9; // r9
  unsigned int v10; // r7
  int v11; // r6
  int v12; // r4
  unsigned int v13; // r8
  int v14; // r3
  unsigned int v15; // r2
  unsigned int v16; // r10
  unsigned int v17; // r2
  char *v18; // lr
  unsigned int v19; // r7
  char *v20; // r4
  int v21; // r0
  int v22; // r1
  int v23; // r2
  unsigned int v24; // r1
  unsigned int v25; // r1
  char *v27; // r3
  int v28; // [sp+4h] [bp-5Ch]
  int v29; // [sp+8h] [bp-58h]
  int v30; // [sp+Ch] [bp-54h] BYREF
  char *v31; // [sp+10h] [bp-50h] BYREF
  char *v32; // [sp+14h] [bp-4Ch]
  unsigned int v33; // [sp+18h] [bp-48h]
  unsigned int v34; // [sp+1Ch] [bp-44h]
  int v35; // [sp+20h] [bp-40h]
  char v36[16]; // [sp+28h] [bp-38h] BYREF
  unsigned int v37; // [sp+38h] [bp-28h] BYREF
  int v38; // [sp+3Ch] [bp-24h]

  v8 = a3;
  v32 = (char *)a2;
  v33 = a1 + a2;
  v9 = a1;
  v35 = a1;
  v10 = (unsigned int)&a3[a4];
  v11 = 0;
  v34 = (unsigned int)&a3[a4];
  KeInitializeEvent((int)v36, 1, 0);
  v37 = 1;
  v38 = 0;
  if ( ((unsigned __int8)v8 & 1) != 0 )
  {
    LOWORD(v29) = *(_WORD *)v8;
    v12 = *(unsigned __int16 *)v8;
  }
  else
  {
    v12 = *(unsigned __int16 *)v8;
    LOWORD(v29) = *(_WORD *)v8;
  }
  v13 = a5;
  v14 = (v12 & 0xFFF) + 3;
  v30 = 4096;
  if ( a5 >= 0x1000 )
  {
    v30 = 4096;
    while ( 1 )
    {
      v15 = (unsigned int)&v8[v14];
      if ( (unsigned int)&v8[v14] > v10 )
        break;
      v13 -= 4096;
      v8 += v14;
      if ( v15 > v10 - 2
        || ((v15 & 1) == 0 ? (v12 = *(unsigned __int16 *)v15, LOWORD(v29) = *(_WORD *)v15) : (LOWORD(v29) = *(_WORD *)v15,
                                                                                              v12 = *(unsigned __int16 *)v15),
            !v12) )
      {
        v11 = 0;
        *a7 = 0;
        goto LABEL_42;
      }
      v14 = (v12 & 0xFFF) + 3;
      if ( v13 < 0x1000 )
        goto LABEL_13;
    }
LABEL_41:
    v11 = -1073741246;
    *a7 = v8;
    goto LABEL_42;
  }
LABEL_13:
  v16 = (unsigned int)&v8[v14];
  if ( (unsigned int)&v8[v14] > v10 )
    goto LABEL_41;
  v17 = v34;
  v18 = v32;
  while ( 1 )
  {
    v19 = 4096 - v13;
    if ( 4096 - v13 >= (unsigned int)v18 )
    {
      v19 = (unsigned int)v18;
      v31 = v18;
    }
    else
    {
      v31 = (char *)(4096 - v13);
    }
    if ( (v12 & 0xFFFF8000) == 0 )
    {
      if ( (unsigned int)&v8[v19 + 2 + v13] > v17 )
        goto LABEL_41;
      v22 = (int)&v8[v13 + 2];
      v21 = v9;
LABEL_33:
      memmove(v21, v22, v19);
      goto LABEL_34;
    }
    if ( v13 || v19 != 4096 )
      break;
    if ( a6 )
    {
      v11 = LZNT1DecompressChunkNewThread((int)v36, v9, v33, (unsigned int)(v8 + 2), v16, a6);
      if ( v11 < 0 )
      {
        v23 = 4096;
        goto LABEL_51;
      }
      v19 = a6;
    }
    else
    {
      v11 = LZNT1DecompressChunk(v9, v33, v8 + 2, v16, &v31, v28, v29);
      if ( v11 < 0 )
      {
        v27 = v31;
        goto LABEL_54;
      }
      v19 = (unsigned int)v31;
    }
LABEL_34:
    v13 = 0;
    v9 += v19;
    v18 = &v32[-v19];
    v32 -= v19;
    if ( !v32 )
      goto LABEL_30;
    v17 = v34;
    v8 = (unsigned __int8 *)v16;
    if ( v16 > v34 - 2 )
      goto LABEL_30;
    if ( (v16 & 1) != 0 )
    {
      LOWORD(v29) = *(_WORD *)v16;
      v12 = *(unsigned __int16 *)v16;
    }
    else
    {
      v12 = *(unsigned __int16 *)v16;
      LOWORD(v29) = *(_WORD *)v16;
    }
    if ( !v12 )
      goto LABEL_30;
    v16 += (v12 & 0xFFF) + 3;
    v30 = 4096;
    if ( v16 > v34 )
      goto LABEL_41;
  }
  v11 = LZNT1DecompressChunk(a8, a8 + 4096, v8 + 2, v16, (char **)&v30, v28, v29);
  if ( v11 >= 0 )
  {
    v20 = (char *)v30;
    v21 = v9;
    v22 = v13 + a8;
    if ( v30 - v13 < v19 )
    {
      memmove(v9, v22, v30 - v13);
      v9 = (unsigned int)&v20[v9 - v13];
LABEL_30:
      v23 = v9 - v35;
LABEL_51:
      *a7 = v23;
      goto LABEL_42;
    }
    goto LABEL_33;
  }
  v27 = (char *)v30;
LABEL_54:
  *a7 = v27;
LABEL_42:
  __dmb(0xBu);
  do
  {
    v24 = __ldrex(&v37);
    v25 = v24 - 1;
  }
  while ( __strex(v25, &v37) );
  __dmb(0xBu);
  if ( !v25 )
    KeSetEvent((int)v36, 0, 0);
  KeWaitForSingleObject((unsigned int)v36, 0, 0, 0, 0);
  if ( v11 >= 0 && v38 < 0 )
    v11 = v38;
  return v11;
}
