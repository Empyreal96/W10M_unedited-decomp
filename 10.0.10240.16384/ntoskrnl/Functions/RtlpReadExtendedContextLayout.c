// RtlpReadExtendedContextLayout 
 
int __fastcall RtlpReadExtendedContextLayout(int a1, int a2, int a3, int a4, int *a5)
{
  unsigned int v6; // r6
  int v7; // r2
  int *v8; // r8
  unsigned int v9; // r1
  unsigned int v10; // r1
  int v11; // r0
  int v12; // r1
  int v13; // r3
  int v14; // r2
  unsigned int v15; // r1
  int v16; // r3
  int v17; // r2
  int v19; // [sp+8h] [bp-30h]
  int v20; // [sp+Ch] [bp-2Ch]
  int v21; // [sp+10h] [bp-28h]
  unsigned int v22; // [sp+14h] [bp-24h]
  int v23; // [sp+18h] [bp-20h]
  int v24; // [sp+1Ch] [bp-1Ch]
  int varg_r2; // [sp+48h] [bp+10h]

  varg_r2 = a3;
  v6 = 0;
  if ( (a2 & 0x10000) != 0 )
  {
    v7 = 716;
    v6 = a3 + 716;
    v8 = a5;
    a5[2] = -716;
    a5[3] = 204;
    if ( (a2 & 0x10020) != 65568 )
      goto LABEL_13;
    goto LABEL_12;
  }
  if ( (a2 & 0x100000) != 0 )
  {
    v7 = 1232;
  }
  else
  {
    if ( (a2 & 0x200000) == 0 )
    {
      v8 = a5;
      if ( (a2 & 0x400000) == 0 )
        goto LABEL_13;
      v7 = 912;
      goto LABEL_11;
    }
    v7 = 416;
  }
  v8 = a5;
LABEL_11:
  v6 = a3 + v7;
  v8[2] = -v7;
LABEL_12:
  v8[3] = v7;
LABEL_13:
  *v8 = v8[2];
  v8[1] = v6 - a3 + 24;
  if ( (a4 & 0xFFFFFFFE) == 0 )
    return 0;
  if ( (_BYTE)a1 && (v6 & 3) != 0 )
    ExRaiseDatatypeMisalignment((char)a1);
  v19 = *(_DWORD *)v6;
  v20 = *(_DWORD *)(v6 + 4);
  v21 = *(_DWORD *)(v6 + 8);
  v22 = *(_DWORD *)(v6 + 12);
  v23 = *(_DWORD *)(v6 + 16);
  v24 = *(_DWORD *)(v6 + 20);
  v9 = v21 + v6;
  if ( v21 > (int)(v22 + v21) )
    return -1073741811;
  if ( v21 >= 0 )
  {
    if ( v9 < v6 )
      return -1073741811;
  }
  else if ( v9 >= v6 )
  {
    return -1073741811;
  }
  if ( v22 + v21 + v6 < v9 || v8[2] != v21 || v8[3] > v22 )
    return -1073741811;
  if ( (a4 & 2) != 0 )
  {
    v10 = v23 + v6;
    if ( v23 > v24 + v23 )
      return -1073741811;
    if ( v23 >= 0 )
    {
      if ( v10 < v6 )
        return -1073741811;
    }
    else if ( v10 >= v6 )
    {
      return -1073741811;
    }
    if ( v24 + v23 + v6 < v10 )
      return -1073741811;
    v8[4] = v23;
    v8[5] = v24;
    v11 = v8[1];
    v12 = *v8;
    if ( *v8 + v11 > v23 )
    {
      if ( v8[5] + v23 > v12 )
        return -1073741811;
      v13 = v12 - v23 + v11;
      *v8 = v23;
    }
    else
    {
      v13 = v8[5] + v23 - v12;
    }
    v8[1] = v13;
  }
  v14 = *v8;
  v15 = *v8 + v6;
  v16 = v8[1] + *v8;
  if ( *v8 > v16 )
    return -1073741811;
  if ( v14 < 0 )
  {
    if ( v15 < v6 )
      goto LABEL_42;
    return -1073741811;
  }
  if ( v15 < v6 )
    return -1073741811;
LABEL_42:
  if ( v16 + v6 < v15 )
    return -1073741811;
  if ( v14 < v19 )
    return -1073741811;
  v17 = v14 + v8[1];
  if ( v20 + v19 < v17 || v15 > v6 || v17 + v6 < v6 )
    return -1073741811;
  return 0;
}
