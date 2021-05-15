// BgpTxtDisplayString 
 
int __fastcall BgpTxtDisplayString(int a1, unsigned __int16 *a2)
{
  unsigned __int16 *v3; // r7
  int v4; // r4
  unsigned int v5; // r6
  unsigned int v6; // r8
  unsigned int v7; // r10
  unsigned __int16 *v8; // r9
  unsigned int v9; // t1
  unsigned int v10; // r2
  _DWORD *v11; // r8
  unsigned int v12; // r3
  int v13; // r1
  unsigned int v14; // r9
  int v15; // r0
  int v16; // r0
  char *v17; // r6
  __int64 v18; // r2
  _DWORD *v20[2]; // [sp+18h] [bp-48h] BYREF
  unsigned int v21; // [sp+20h] [bp-40h] BYREF
  int v22; // [sp+24h] [bp-3Ch]
  int v23[2]; // [sp+28h] [bp-38h] BYREF
  unsigned int v24; // [sp+30h] [bp-30h] BYREF
  unsigned int v25; // [sp+34h] [bp-2Ch]
  unsigned int v26; // [sp+38h] [bp-28h]

  v20[0] = 0;
  v3 = a2;
  if ( !a1 || (*(_DWORD *)(a1 + 48) & 1) == 0 )
    return -1073741811;
  if ( !a2 )
    return BgpTxtClearRegion(a1);
  if ( *(_DWORD *)(a1 + 52) )
    return -1073741811;
  v5 = 0;
  v6 = 0;
  v7 = wcslen(a2);
  if ( v7 )
  {
    v8 = v3;
    while ( 1 )
    {
      v9 = *v8++;
      v4 = BgpFoGetAdvanceWidth(a1 + 28, v9, v23, 0, 0);
      if ( v4 < 0 )
        break;
      ++v6;
      v5 += v23[0];
      if ( v6 >= v7 )
        goto LABEL_10;
    }
  }
  else
  {
LABEL_10:
    v4 = BgpFoGetTextMetrics(a1 + 28, (int)&v24);
    if ( v4 >= 0 )
    {
      v10 = *(_DWORD *)(a1 + 12);
      v24 = v5;
      v26 = v5;
      if ( v25 > v10 )
        v25 = v10;
      if ( v5 > *(_DWORD *)(a1 + 8) )
      {
        v5 = *(_DWORD *)(a1 + 8);
        v24 = v5;
      }
      v4 = BgpGxRectangleCreate(&v24, 32, v20);
      v11 = v20[0];
      if ( v4 >= 0 )
      {
        BgpGxFillRectangle(v20[0], *(_DWORD *)(a1 + 28));
        v12 = 0;
        v13 = 0;
        v21 = 0;
        v22 = 0;
        v14 = 0;
        if ( v7 )
        {
          while ( 1 )
          {
            v15 = BgpRasPrintGlyph(v11, (_DWORD *)(a1 + 28), *v3, v12, v13, 0, v23, 0, 0);
            v4 = v15;
            if ( v15 == -2147483643 )
              break;
            if ( v15 < 0 )
              goto LABEL_27;
            v12 = v23[0] + v21;
            v21 = v12;
            if ( v12 > v5 )
              break;
            ++v14;
            ++v3;
            if ( v14 >= v7 )
              break;
            v13 = v22;
          }
        }
        TxtpJustifyRectangle(a1, &v24, &v21);
        v16 = *(_DWORD *)(a1 + 20);
        v20[0] = 0;
        v4 = BgpGxBlendRectangle(v16, v11, &v21, v20);
        v17 = (char *)v20[0];
        if ( v4 >= 0 )
        {
          v4 = BgpTxtClearRegion(a1);
          if ( v4 >= 0 )
          {
            v18 = *(_QWORD *)a1;
            v22 = *(_DWORD *)(a1 + 4);
            v21 += v18;
            v4 = BgpGxDrawRectangle(v17, (int)&v21);
          }
        }
        if ( v17 )
          BgpGxRectangleDestroy((int)v17);
      }
LABEL_27:
      if ( v11 )
        BgpGxRectangleDestroy((int)v11);
    }
  }
  return v4;
}
