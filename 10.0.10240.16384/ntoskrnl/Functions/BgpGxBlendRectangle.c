// BgpGxBlendRectangle 
 
int __fastcall BgpGxBlendRectangle(_DWORD *a1, _DWORD *a2, _DWORD *a3, int **a4)
{
  int **v4; // r7
  int *v5; // r5
  int v6; // r6
  _DWORD *v7; // r9
  _DWORD *v8; // r8
  unsigned int v9; // r0
  int v10; // r4
  unsigned int v11; // r1
  int v12; // lr
  int v13; // r1
  int v14; // r2
  int v15; // r10
  int v16; // r4
  int v17; // r3
  int v18; // r2
  int v19; // r3
  _DWORD *v20; // r2
  int v21; // r0
  int v22; // r3
  int v23; // r7
  unsigned int v24; // r3
  int v25; // r6
  int v26; // r9
  char *v27; // r10
  unsigned int v28; // r8
  int v29; // r3
  int v30; // r3
  int *v32; // [sp+0h] [bp-58h] BYREF
  _DWORD *v33; // [sp+4h] [bp-54h]
  int v34; // [sp+8h] [bp-50h]
  int v35; // [sp+Ch] [bp-4Ch]
  int v36; // [sp+10h] [bp-48h]
  int v37; // [sp+14h] [bp-44h]
  int v38; // [sp+18h] [bp-40h]
  int v39; // [sp+1Ch] [bp-3Ch]
  int v40; // [sp+20h] [bp-38h]
  _DWORD *v41; // [sp+24h] [bp-34h]
  _DWORD *v42; // [sp+28h] [bp-30h]
  int **v43; // [sp+2Ch] [bp-2Ch]
  _DWORD v44[10]; // [sp+30h] [bp-28h] BYREF

  v4 = a4;
  v5 = 0;
  v6 = 0;
  v42 = a2;
  v43 = a4;
  v32 = 0;
  v33 = a3;
  v36 = 0;
  v7 = a2;
  v8 = a1;
  v41 = a1;
  if ( !a4
    || (v9 = *a1) == 0
    || (v10 = *a2) == 0
    || (v11 = v8[1]) == 0
    || (v12 = v7[1]) == 0
    || v8[2] != 32
    || v7[2] != 32
    || v11 < *a3 + v12
    || v9 < a3[1] + v10 )
  {
    v6 = -1073741811;
    goto LABEL_25;
  }
  v5 = *a4;
  if ( *a4 )
  {
    if ( v5[1] == v12 && *v5 == v10 )
    {
LABEL_15:
      v13 = v8[1];
      v14 = a3[1];
      v15 = v7[5];
      v16 = v5[5];
      v17 = *v33;
      v37 = (unsigned int)v5[2] >> 3;
      v32 = (int *)v15;
      v18 = v17 + v13 * v14;
      v19 = v8[5];
      v34 = v16;
      v20 = (_DWORD *)(v19 + v18 * v37);
      v21 = *v5;
      v33 = v20;
      v35 = v21;
      if ( v21 )
      {
        v22 = v5[1];
        v23 = v37;
        do
        {
          v37 = v15;
          v38 = 0;
          if ( v22 )
          {
            v39 = v16 - (_DWORD)v20;
            v24 = (unsigned int)v20 - v15;
            v25 = v16 - (_DWORD)v20;
            v26 = v15;
            v40 = (int)v20 - v15;
            v27 = (char *)v20 - v15;
            v28 = 0;
            do
            {
              *(_DWORD *)&v27[v26 + v25] = BgpGxBlendColor(
                                             *(_DWORD *)&v27[v26],
                                             *(_DWORD *)v26,
                                             *(unsigned __int8 *)(v26 + 3),
                                             v24);
              v24 = v5[1];
              ++v28;
              v26 += v23;
            }
            while ( v28 < v24 );
            v8 = v41;
            v7 = v42;
            v15 = (int)v32;
            v20 = v33;
            v16 = v34;
            v21 = v35;
          }
          v29 = v7[1];
          v35 = --v21;
          v15 += v29 * v23;
          v30 = v8[1];
          v32 = (int *)v15;
          v20 = (_DWORD *)((char *)v20 + v30 * v23);
          v22 = v5[1];
          v33 = v20;
          v16 += v22 * v23;
          v34 = v16;
        }
        while ( v21 );
        v6 = v36;
        v4 = v43;
      }
LABEL_25:
      if ( v6 >= 0 )
        goto LABEL_29;
      goto LABEL_26;
    }
    v6 = -1073741670;
  }
  else
  {
    v44[0] = v7[1];
    v44[1] = v10;
    v6 = BgpGxRectangleCreate(v44, 32, &v32);
    v5 = v32;
    v36 = v6;
    if ( v6 >= 0 )
    {
      a3 = v33;
      goto LABEL_15;
    }
  }
LABEL_26:
  if ( *v4 )
    return v6;
  if ( v5 )
  {
    BgpGxRectangleDestroy((int)v5);
    v5 = 0;
  }
LABEL_29:
  if ( !*v4 )
    *v4 = v5;
  return v6;
}
