// BgpGxFindSubRectangle 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall BgpGxFindSubRectangle(int a1, int a2, _DWORD *a3, _QWORD *a4, _BYTE *a5)
{
  int v5; // r5
  unsigned int v6; // r6
  unsigned int v7; // r0
  unsigned int v8; // r8
  __int64 v9; // kr00_8
  _DWORD *v10; // r7
  int v11; // r4
  unsigned int v12; // r10 OVERLAPPED
  unsigned int v13; // lr
  unsigned int v14; // r9 OVERLAPPED
  unsigned int v15; // r1
  unsigned int v16; // r5
  unsigned int v17; // r2
  unsigned int v19; // r1
  unsigned __int8 *v20; // r6
  unsigned int v21; // r2
  unsigned int v22; // r8
  int v23; // r7
  int v24; // r4
  int result; // r0
  int v26; // r8
  int v27; // r5
  int v28; // r6
  unsigned int v29; // [sp+0h] [bp-58h]
  unsigned int v30; // [sp+4h] [bp-54h]
  unsigned int v31; // [sp+8h] [bp-50h]
  _DWORD *v32; // [sp+Ch] [bp-4Ch]
  unsigned int v34; // [sp+18h] [bp-40h]
  unsigned int v35; // [sp+24h] [bp-34h]
  int var28[13]; // [sp+30h] [bp-28h] BYREF
  int varg_r1; // [sp+64h] [bp+Ch]
  _DWORD *varg_r2; // [sp+68h] [bp+10h]
  _QWORD *varg_r3; // [sp+6Ch] [bp+14h]

  var28[12] = a1;
  varg_r2 = a3;
  varg_r3 = a4;
  v5 = a1;
  v32 = a3;
  varg_r1 = a2;
  if ( !a4 )
    return -1073741811;
  if ( !a1 )
    return -1073741811;
  v6 = *(_DWORD *)(a1 + 8);
  v35 = v6;
  if ( v6 != 24 && v6 != 32 )
    return -1073741811;
  v9 = *(_QWORD *)a1;
  v7 = *(_DWORD *)(a1 + 4);
  v8 = v9;
  v10 = *(_DWORD **)(v5 + 20);
  v29 = 0;
  v11 = 0;
  v34 = v6 >> 3;
  v12 = v9;
  v30 = 0;
  v31 = v9;
  v13 = 0;
  v14 = v7;
  if ( a2 == -16777216 && v6 >> 3 == 4 )
  {
    v15 = 0;
    if ( (_DWORD)v9 )
    {
      v16 = 0;
      do
      {
        v17 = 0;
        if ( v7 )
        {
          do
          {
            if ( *v10++ )
            {
              if ( v17 < v14 )
                v14 = v17;
              if ( v17 > v16 )
                v16 = v17;
              if ( v15 < v12 )
                v12 = v15;
              if ( v15 > v13 )
                v13 = v15;
              v11 = 1;
            }
            ++v17;
          }
          while ( v17 < v7 );
          v29 = v16;
          v30 = v13;
          v31 = v12;
        }
        ++v15;
      }
      while ( v15 < (unsigned int)v9 );
      goto LABEL_43;
    }
LABEL_55:
    *a5 = 1;
    *a3 = 0;
    return 0;
  }
  v19 = 0;
  if ( !(_DWORD)v9 )
    goto LABEL_55;
  v20 = *(unsigned __int8 **)(v5 + 20);
  do
  {
    v21 = 0;
    if ( v7 )
    {
      v22 = v30;
      do
      {
        if ( __PAIR64__(v20[2], v20[1]) != __PAIR64__(BYTE2(varg_r1), BYTE1(varg_r1))
          || *v20 != (unsigned __int8)varg_r1 )
        {
          if ( v21 < v14 )
            v14 = v21;
          if ( v21 > v29 )
            v29 = v21;
          if ( v19 < v12 )
            v12 = v19;
          if ( v19 > v22 )
            v22 = v19;
          v11 = 1;
        }
        ++v21;
        v20 += v34;
      }
      while ( v21 < v7 );
      v30 = v22;
      v31 = v12;
      v8 = v9;
    }
    ++v19;
  }
  while ( v19 < v8 );
  v6 = v35;
LABEL_43:
  if ( !v11 )
  {
    a3 = v32;
    goto LABEL_55;
  }
  v23 = v29 - v14 + 1;
  var28[0] = v23;
  v24 = v30 - v12 + 1;
  var28[1] = v24;
  if ( !v12 && !v14 && v23 == v7 && v24 == v8 )
    return -1073741275;
  result = BgpGxRectangleCreate(var28, v6, v32);
  if ( result >= 0 )
  {
    v26 = *(_DWORD *)(a1 + 4) * (v6 >> 3);
    v27 = (v6 >> 3) * v14 + v26 * v12 + *(_DWORD *)(a1 + 20);
    v28 = *(_DWORD *)(*v32 + 20);
    if ( v30 - v12 != -1 )
    {
      do
      {
        memmove(v28, v27, v23 * v34);
        v28 += v23 * v34;
        v27 += v26;
        --v24;
      }
      while ( v24 );
      v12 = v31;
    }
    *a4 = *(_QWORD *)&v14;
    *a5 = 0;
    return 0;
  }
  return result;
}
