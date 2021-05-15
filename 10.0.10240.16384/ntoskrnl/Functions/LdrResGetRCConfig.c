// LdrResGetRCConfig 
 
int __fastcall LdrResGetRCConfig(int a1, int a2, int *a3, int a4, unsigned __int8 a5)
{
  int v7; // r6
  int v8; // r8
  BOOL v9; // r4
  int v10; // r5
  int v11; // r3
  _DWORD *v12; // r0
  int v13; // r2
  int v14; // r8
  int v15; // r0
  bool v16; // zf
  int v17; // r4
  unsigned int v18; // r1
  int v19; // r3
  unsigned int v20; // r2
  unsigned int v21; // r3
  unsigned int v22; // r2
  unsigned int v23; // r3
  unsigned int v24; // r2
  unsigned int v25; // r3
  unsigned int v26; // r2
  unsigned int v27; // r3
  unsigned int v28; // r2
  unsigned int v29; // r3
  unsigned int v30; // r2
  unsigned int v31; // r3
  unsigned int v32; // r2
  unsigned int v33; // r3
  unsigned int v34; // r2
  unsigned int v35; // r3
  int v36; // r0
  int v37; // r6
  int v38; // r1
  int v39; // r0
  int v41; // [sp+0h] [bp-68h]
  _DWORD *v42; // [sp+1Ch] [bp-4Ch] BYREF
  int v43; // [sp+20h] [bp-48h] BYREF
  int v44; // [sp+24h] [bp-44h]
  int v45; // [sp+28h] [bp-40h]
  int *v46; // [sp+2Ch] [bp-3Ch]
  int v47; // [sp+30h] [bp-38h]
  _DWORD v48[12]; // [sp+38h] [bp-30h] BYREF

  v7 = a2;
  v45 = a1;
  v47 = a1;
  v46 = a3;
  v48[0] = L"MUI";
  v48[1] = 1;
  v48[2] = 0;
  v43 = a2;
  v42 = 0;
  v8 = 0x2000;
  v9 = (a4 & 0x2000) == 0;
  if ( (a4 & 0x2000) == 0 )
    v8 = 4096;
  if ( !a1 )
    return -1073741811;
  v11 = a5;
  if ( a5 )
  {
    v12 = (_DWORD *)LdrpGetFromMUIMemCache(a1, 0, 0, 8);
    v42 = v12;
    if ( v12 == (_DWORD *)-1 )
      return -1073741686;
    if ( v12 )
    {
      v10 = 0;
      if ( a3 )
        *a3 = (int)v12;
      return v10;
    }
    a1 = v45;
  }
  if ( !v7 && v9 )
  {
    v10 = LdrpResGetMappingSize(a1, (unsigned int *)&v43, a4, v11);
    if ( v10 < 0 )
      return v10;
    v7 = v43;
  }
  v13 = v8 | 0x30;
  v14 = v45;
  v15 = LdrpResSearchResourceMappedFile(v45, v7, v13, v48, 3, &v42, &v43, 0, 0);
  v10 = v15;
  if ( v15 < 0 )
  {
    v17 = (int)v42;
    v19 = a5;
    if ( v15 != -1073741701 )
      v10 = -1073741686;
    goto LABEL_60;
  }
  v16 = !v9;
  v17 = (int)v42;
  if ( v16 )
  {
LABEL_55:
    v19 = a5;
    if ( a3 )
      *a3 = v17;
    v10 = 0;
    goto LABEL_62;
  }
  v18 = v42[1];
  if ( (unsigned int)v42 + v18 > (v14 & 0xFFFFFFFC) + v7 )
  {
    v10 = -1073741701;
    v44 = -1073741701;
    v19 = a5;
    goto LABEL_60;
  }
  v10 = -1073020925;
  v44 = -1073020925;
  v20 = v42[17];
  v21 = v42[18] + v20;
  if ( v21 > v18 )
    goto LABEL_36;
  if ( v21 < v20 )
    goto LABEL_36;
  v22 = v42[19];
  v23 = v42[20] + v22;
  if ( v23 > v18 )
    goto LABEL_36;
  if ( v23 < v22 )
    goto LABEL_36;
  v24 = v42[21];
  v25 = v42[22] + v24;
  if ( v25 > v18 )
    goto LABEL_36;
  if ( v25 < v24 )
    goto LABEL_36;
  v26 = v42[23];
  v27 = v42[24] + v26;
  if ( v27 > v18 )
    goto LABEL_36;
  if ( v27 < v26 )
    goto LABEL_36;
  v28 = v42[25];
  v29 = v42[26] + v28;
  if ( v29 > v18
    || v29 < v28
    || (v30 = v42[27], v31 = v42[28] + v30, v31 > v18)
    || v31 < v30
    || (v32 = v42[29], v33 = v42[30] + v32, v33 > v18)
    || v33 < v32
    || (v34 = v42[31], v35 = v42[32] + v34, v35 > v18)
    || v35 < v34 )
  {
LABEL_36:
    v19 = a5;
    goto LABEL_60;
  }
  if ( *v42 != -20054323 || v18 != v43 )
  {
    v19 = a5;
    goto LABEL_60;
  }
  if ( v42[2] != 0x10000 )
  {
    v19 = a5;
    goto LABEL_60;
  }
  v36 = v42[3];
  if ( v36 && !CheckOneBitValidFlag(v36, 7) )
  {
    v19 = a5;
    goto LABEL_60;
  }
  v37 = *(_DWORD *)(v17 + 16);
  if ( !CheckOneBitValidFlag(v37 & 0xFFFFFFCF, 3) || !CheckOneBitValidFlag(v37 & ~v38, 48) )
  {
    v19 = a5;
    goto LABEL_60;
  }
  if ( (v37 & 1) == 0 )
    goto LABEL_54;
  if ( !CheckOneBitValidFlag(*(_DWORD *)(v17 + 24), 3) )
  {
    v19 = a5;
    goto LABEL_60;
  }
  v39 = *(_DWORD *)(v17 + 20);
  if ( !v39 || CheckOneBitValidFlag(v39, 256) )
  {
LABEL_54:
    v44 = 0;
    goto LABEL_55;
  }
  v19 = a5;
LABEL_60:
  if ( v10 < 0 )
    v17 = 0;
LABEL_62:
  if ( v19 )
  {
    if ( !v17 )
      v17 = -1;
    LdrpSetAlternateResourceModuleHandle(v14, 0, 0, v17, v41, 0, 2, v10, 0);
  }
  return v10;
}
