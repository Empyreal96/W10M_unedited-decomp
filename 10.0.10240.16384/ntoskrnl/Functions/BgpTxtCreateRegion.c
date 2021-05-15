// BgpTxtCreateRegion 
 
int __fastcall BgpTxtCreateRegion(_DWORD *a1, unsigned int *a2, _DWORD *a3, _DWORD *a4, char a5)
{
  int v7; // r5
  _DWORD *v8; // r9
  int v9; // r8
  unsigned int *v10; // r1
  _BYTE *v11; // r0
  _DWORD *v12; // r6
  int v14; // r1
  int v15; // r2
  int v16; // r3
  _DWORD *v17; // r10
  unsigned int v18; // r2
  unsigned int v19; // r3
  unsigned int v20; // r3
  _DWORD *v21; // [sp+0h] [bp-40h] BYREF
  int v22; // [sp+4h] [bp-3Ch] BYREF
  unsigned int v23; // [sp+8h] [bp-38h] BYREF
  unsigned int v24; // [sp+Ch] [bp-34h]
  _DWORD *v25; // [sp+10h] [bp-30h]
  _DWORD *v26; // [sp+14h] [bp-2Ch]
  unsigned int v27; // [sp+18h] [bp-28h] BYREF
  unsigned int v28; // [sp+1Ch] [bp-24h]

  v7 = 0;
  v25 = a1;
  v26 = a4;
  *a4 = 0;
  v8 = 0;
  v21 = 0;
  v22 = 0;
  v9 = 0;
  if ( !a1 )
    return -1073741811;
  if ( !a2 )
    return -1073741811;
  BgpGetResolution(&v27);
  if ( *v10 > v27 || v10[1] > v28 )
    return -1073741811;
  v11 = (_BYTE *)BgpFwAllocateMemory(0x38u);
  v12 = v11;
  if ( !v11 )
    return sub_8DFB48();
  memset(v11, 0, 56);
  if ( a3 )
  {
    v14 = a3[1];
    v15 = a3[2];
    v16 = a3[3];
    v12[7] = *a3;
    v12[8] = v14;
    v12[9] = v15;
    v12[10] = v16;
    v12[11] = a3[4];
  }
  else
  {
    v7 = BgpFoGetFontHandle(0, &v23);
    if ( v7 < 0 )
      goto LABEL_35;
    *(_QWORD *)(v12 + 7) = 0xFFFFFFFF00000000ui64;
    v20 = v23;
    v12[11] = 0;
    v12[9] = v20;
    v12[10] = 18;
  }
  if ( (a5 & 1) != 0 )
    goto LABEL_15;
  v7 = BgpFoGetTextMetrics((int)(v12 + 7), (int)&v23);
  if ( v7 < 0 )
  {
LABEL_35:
    BgpFwFreeMemory((int)v12);
    goto LABEL_24;
  }
  if ( a2[1] < v24 )
    a2[1] = v24;
  if ( *a2 < v23 )
    *a2 = v23;
LABEL_15:
  v17 = v25;
  if ( *a2 + *v25 > v27 || a2[1] + v25[1] > v28 )
  {
    v7 = -1073741811;
  }
  else
  {
    if ( (a5 & 2) == 0 )
    {
      v7 = BgpGxRectangleCreate(a2, 32, &v21);
      v8 = v21;
      if ( v7 < 0 )
        goto LABEL_31;
      BgpGxFillRectangle(v21, v12[7]);
    }
    if ( (a5 & 9) != 0 )
    {
      v7 = BgpGxRectangleCreate(a2, 32, &v22);
      v9 = v22;
      if ( v7 < 0 )
      {
LABEL_31:
        if ( v8 )
          BgpGxRectangleDestroy(v8);
        if ( v9 )
          BgpGxRectangleDestroy(v9);
        goto LABEL_35;
      }
      v12[6] = v22;
    }
    *v12 = *v17;
    v12[1] = v17[1];
    v18 = a2[1];
    v19 = a2[2];
    v12[2] = *a2;
    v12[3] = v18;
    v12[4] = v19;
    v12[12] = 1;
    v12[13] = 0;
    v12[5] = v8;
    if ( (a5 & 4) != 0 )
      v12[12] = 5;
  }
  if ( v7 < 0 )
    goto LABEL_31;
LABEL_24:
  *v26 = v12;
  return v7;
}
