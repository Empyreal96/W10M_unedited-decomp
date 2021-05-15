// ExpParseEfiPath 
 
int __fastcall ExpParseEfiPath(_BYTE *a1, int *a2, int *a3, _BYTE *a4)
{
  int v5; // r5
  int *v6; // r8
  unsigned int v8; // r7
  int v9; // r0
  unsigned int v11; // r9
  _BYTE *v12; // r2
  int v13; // r3
  int v14; // r4
  int v15; // r0
  int v16; // r0
  int v17; // r4
  int v18; // r1
  _BYTE *v19; // r1
  unsigned int v20; // r8
  unsigned int v21; // r10
  int v22; // r3
  int v23; // r7
  unsigned int v24; // r3
  _BYTE *v25; // [sp+0h] [bp-28h]
  int *v26; // [sp+4h] [bp-24h]

  v5 = -1073741811;
  v25 = 0;
  v26 = a3;
  v6 = a3;
  v8 = 0;
  v9 = *a1 & 0x7F;
  if ( v9 != 127 )
  {
    if ( v9 != 4 || a1[1] != 1 )
      return sub_8154F0();
    v5 = 0;
    v11 = (unsigned __int8)a1[2] | ((unsigned __int8)a1[3] << 8);
    v12 = &a1[v11];
    if ( (a1[v11] & 0x7F) == 4 && v12[1] == 4 )
    {
      v25 = &a1[v11];
      while ( 1 )
      {
        v16 = (unsigned __int8)v12[3];
        v17 = (unsigned __int8)v12[2];
        v18 = v17 | (v16 << 8);
        if ( v18 - 4 + v8 < v8 )
          break;
        v8 += v18 - 4;
        if ( v18 + v11 < v11 )
        {
          v11 = -1;
          goto LABEL_25;
        }
        v11 += v18;
        v12 += v17 | (v16 << 8);
        v5 = 0;
        if ( (*v12 & 0x7F) != 4 || v12[1] != 4 )
          goto LABEL_6;
      }
      v8 = -1;
LABEL_25:
      v5 = -1073741675;
    }
LABEL_6:
    if ( (*v12 & 0x7F) != 127 )
      v5 = -1073741811;
    if ( v5 >= 0 )
    {
      v13 = (unsigned __int8)a1[41];
      if ( v13 == 2 )
      {
        *a4 = 1;
      }
      else
      {
        if ( v13 != 1 )
          return -1073741811;
        *a4 = 0;
      }
      if ( v8 )
      {
        v14 = ExAllocatePoolWithTag(512, v8 + 2, 1920364101);
        if ( !v14 )
          return -1073741670;
        v19 = v25;
        v20 = 0;
        v21 = v8 + 2;
        while ( (*v19 & 0x7F) != 127 )
        {
          v22 = (unsigned __int8)v19[2] | ((unsigned __int8)v19[3] << 8);
          v23 = v22 - 4;
          if ( v22 - 4 >= v21 )
            goto LABEL_33;
          memmove(v20 + v14, (int)(v19 + 4), v22 - 4);
          v21 -= v23;
          v20 += v23;
          v19 = &v25[(unsigned __int8)v25[2] | ((unsigned __int8)v25[3] << 8)];
          v25 = v19;
        }
        v24 = v20 >> 1;
        v6 = v26;
        *(_WORD *)(v14 + 2 * v24) = 0;
      }
      else
      {
        v14 = 0;
      }
      v15 = ExAllocatePoolWithTag(512, v11, 1920364101);
      *a2 = v15;
      if ( v15 )
      {
        memmove(v15, (int)a1, v11);
        *v6 = v14;
        return v5;
      }
      if ( v14 )
LABEL_33:
        ExFreePoolWithTag(v14);
      return -1073741670;
    }
  }
  return v5;
}
