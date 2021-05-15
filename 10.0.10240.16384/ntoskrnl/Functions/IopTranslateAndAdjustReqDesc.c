// IopTranslateAndAdjustReqDesc 
 
int __fastcall IopTranslateAndAdjustReqDesc(_DWORD *a1, int a2, _DWORD *a3)
{
  int v3; // r7
  int v4; // r3
  int v5; // r6
  int v6; // r4
  _BYTE *v8; // r0
  unsigned int v9; // r10
  _BYTE *v10; // r0
  unsigned int v11; // r9
  unsigned int v12; // r3
  _DWORD *v13; // r5
  int v14; // r9
  unsigned int v15; // r10
  int v16; // r0
  int v17; // r2
  int v18; // r6
  int v19; // r0
  _DWORD *v20; // r9
  _DWORD *v21; // lr
  _DWORD *v22; // r4
  unsigned int v23; // r10
  int v24; // r1
  int v25; // r2
  int v26; // r3
  int v27; // r1
  int v28; // r2
  int v29; // r3
  int v30; // r3
  unsigned int v31; // r5
  unsigned int *v32; // r4
  _DWORD *v34; // [sp+8h] [bp-40h]
  int v35; // [sp+Ch] [bp-3Ch]
  unsigned int v36; // [sp+Ch] [bp-3Ch]
  _DWORD *v37; // [sp+Ch] [bp-3Ch]
  int v38; // [sp+10h] [bp-38h]
  int v39; // [sp+10h] [bp-38h]
  int v40; // [sp+14h] [bp-34h]
  unsigned int v41; // [sp+14h] [bp-34h]
  _DWORD *v42; // [sp+18h] [bp-30h]
  _BYTE *v43; // [sp+1Ch] [bp-2Ch]
  _DWORD *v45; // [sp+24h] [bp-24h]

  v3 = 0;
  v40 = *(_DWORD *)(a2 + 12);
  v38 = 0;
  v4 = a1[8];
  v5 = 0;
  v6 = -1073741823;
  v35 = 0;
  if ( !v4 )
    return -1073741811;
  *a3 = 0;
  v8 = (_BYTE *)ExAllocatePoolWithTag(257, 4 * v4, 538996816);
  v9 = (unsigned int)v8;
  v43 = v8;
  if ( !v8 )
    return -1073741670;
  memset(v8, 0, 4 * a1[8]);
  v10 = (_BYTE *)ExAllocatePoolWithTag(257, 4 * a1[8], 538996816);
  v11 = (unsigned int)v10;
  v34 = v10;
  if ( !v10 )
  {
    ExFreePoolWithTag(v9);
    return -1073741670;
  }
  memset(v10, 0, 4 * a1[8]);
  if ( !a1[8] )
    goto LABEL_18;
  v12 = v9 - v11;
  v13 = (_DWORD *)v11;
  v14 = a1[9];
  v36 = v12;
  v15 = 0;
  do
  {
    v16 = (*(int (__fastcall **)(_DWORD, int, _DWORD, _DWORD *, unsigned int))(v40 + 20))(
            *(_DWORD *)(v40 + 4),
            v14,
            a1[10],
            v13,
            (unsigned int)v13 + v12);
    v6 = v16;
    if ( v16 >= 0 && *v13 )
    {
      v5 += *v13;
      v17 = 1;
      v38 = 1;
    }
    else
    {
      v17 = v38;
      *(_DWORD *)((char *)v13 + v36) = v14;
      *v13 = 0;
      ++v5;
    }
    v14 += 32;
    if ( v16 >= 0 && v3 != 288 )
      v3 = v16;
    ++v15;
    ++v13;
    v12 = v36;
  }
  while ( v15 < a1[8] );
  v9 = (unsigned int)v43;
  v11 = (unsigned int)v34;
  v39 = v3;
  v35 = v5;
  if ( !v17 )
  {
LABEL_18:
    v3 = v6;
    v39 = v6;
  }
  v18 = ExAllocatePoolWithTag(257, 32 * v5, 538996816);
  if ( !v18 )
  {
    v3 = -1073741670;
    goto LABEL_39;
  }
  v19 = ExAllocatePoolWithTag(257, 180, 538996816);
  v20 = (_DWORD *)v19;
  v45 = (_DWORD *)v19;
  if ( !v19 )
  {
    ExFreePoolWithTag(v18);
    v3 = -1073741670;
    goto LABEL_38;
  }
  memmove(v19, (int)a1, 0xB4u);
  v20[44] = a2;
  v20[3] = 0;
  v20[5] = 0;
  v20[6] = v20 + 6;
  v20[7] = v20 + 6;
  v20[8] = v35;
  v20[9] = v18;
  v20[17] = v20 + 20;
  v21 = (_DWORD *)a1[9];
  v41 = 0;
  v37 = v21;
  if ( !a1[8] )
    goto LABEL_37;
  v22 = v34;
  v23 = v9 - (_DWORD)v34;
  v42 = v34;
  do
  {
    if ( *v22 )
    {
      memmove(v18, *(_DWORD *)((char *)v22 + v23), 32 * *v22);
      v21 = v37;
      v18 += 32 * *v22;
      goto LABEL_35;
    }
    v24 = v21[1];
    v25 = v21[2];
    v26 = v21[3];
    *(_DWORD *)v18 = *v21;
    *(_DWORD *)(v18 + 4) = v24;
    *(_DWORD *)(v18 + 8) = v25;
    *(_DWORD *)(v18 + 12) = v26;
    v27 = v21[5];
    v28 = v21[6];
    v29 = v21[7];
    *(_DWORD *)(v18 + 16) = v21[4];
    *(_DWORD *)(v18 + 20) = v27;
    *(_DWORD *)(v18 + 24) = v28;
    *(_DWORD *)(v18 + 28) = v29;
    v30 = *(unsigned __int8 *)(v18 + 1);
    switch ( v30 )
    {
      case 1:
        goto LABEL_33;
      case 2:
        goto LABEL_47;
      case 3:
        goto LABEL_33;
      case 4:
LABEL_47:
        *(_DWORD *)(v18 + 8) = 2;
        *(_DWORD *)(v18 + 12) = 1;
        break;
      case 6:
        *(_DWORD *)(v18 + 12) = 2;
        *(_DWORD *)(v18 + 16) = 1;
        break;
      case 7:
LABEL_33:
        *(_DWORD *)(v18 + 16) = 2;
        *(_DWORD *)(v18 + 20) = 0;
        *(_DWORD *)(v18 + 24) = 1;
        *(_DWORD *)(v18 + 28) = 0;
        break;
    }
    v22 = v42;
    v18 += 32;
LABEL_35:
    v21 += 8;
    ++v22;
    ++v41;
    v42 = v22;
    v37 = v21;
  }
  while ( v41 < a1[8] );
  v3 = v39;
  v20 = v45;
  v9 = (unsigned int)v43;
LABEL_37:
  *a3 = v20;
LABEL_38:
  v11 = (unsigned int)v34;
LABEL_39:
  v31 = 0;
  if ( a1[8] )
  {
    v32 = (unsigned int *)v9;
    do
    {
      if ( *(unsigned int *)((char *)v32 + v11 - v9) )
        ExFreePoolWithTag(*v32);
      ++v31;
      ++v32;
    }
    while ( v31 < a1[8] );
  }
  ExFreePoolWithTag(v9);
  ExFreePoolWithTag(v11);
  return v3;
}
