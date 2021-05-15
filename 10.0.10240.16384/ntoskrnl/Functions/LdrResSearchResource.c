// LdrResSearchResource 
 
int __fastcall LdrResSearchResource(int a1, int a2, unsigned int a3, int a4, _DWORD *a5, int *a6, int a7, int a8)
{
  int v8; // r5
  unsigned int v9; // r8
  int v10; // r10
  int v11; // r4
  bool v12; // zf
  int v13; // r9
  int v14; // r0
  int v16; // [sp+18h] [bp-70h] BYREF
  unsigned int v17; // [sp+1Ch] [bp-6Ch]
  int v18; // [sp+20h] [bp-68h]
  int *v19; // [sp+24h] [bp-64h]
  _DWORD *v20; // [sp+28h] [bp-60h]
  int v21; // [sp+2Ch] [bp-5Ch]
  int v22; // [sp+30h] [bp-58h]
  int v23; // [sp+34h] [bp-54h]
  int v24; // [sp+38h] [bp-50h]
  int v25; // [sp+3Ch] [bp-4Ch]
  _DWORD *v26; // [sp+40h] [bp-48h]
  int v27; // [sp+44h] [bp-44h]
  int v28; // [sp+48h] [bp-40h]
  int *v29; // [sp+4Ch] [bp-3Ch]
  int v30; // [sp+50h] [bp-38h]
  _DWORD v31[2]; // [sp+58h] [bp-30h] BYREF
  unsigned int v32; // [sp+60h] [bp-28h]
  int varg_r0; // [sp+90h] [bp+8h]
  int varg_r1; // [sp+94h] [bp+Ch]
  unsigned int varg_r2; // [sp+98h] [bp+10h]
  int varg_r3; // [sp+9Ch] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  v8 = a4;
  varg_r3 = a4;
  v9 = a3;
  varg_r2 = a3;
  v21 = a1;
  v28 = a1;
  v17 = a2;
  v20 = a5;
  v26 = a5;
  v19 = a6;
  v29 = a6;
  v18 = a7;
  v24 = a7;
  v22 = a8;
  v25 = a8;
  v10 = 0;
  v23 = 0;
  if ( !a1 || !a2 || a7 && !a8 )
    return -1073741811;
  if ( (a4 & 0xC00) != 0 )
    return -1073741582;
  if ( (a4 & 0xF00) == 0 )
  {
    v8 = a4 | 0x100;
    varg_r3 = a4 | 0x100;
  }
  if ( (v8 & 0x2000) == 0 )
  {
    v8 |= 0x1000u;
    varg_r3 = v8;
  }
  if ( (v8 & 0xFFF80000) != 0 )
    return -1073741582;
  if ( a3 < 3 && (v8 & 2) == 0 || a3 > 4 )
    return -1073741583;
  if ( (v8 & 0x41) != 0 )
  {
    if ( a3 != 4 )
      return -1073741583;
  }
  else if ( a3 != 4 )
  {
    goto LABEL_21;
  }
  if ( (v8 & 0x41) == 0 )
    return -1073741582;
LABEL_21:
  if ( (v8 & 0x100) != 0 )
  {
    v12 = (v8 & 0xE00) == 0;
    goto LABEL_23;
  }
  if ( (v8 & 0x200) == 0 )
  {
    if ( (v8 & 0xC00) != 3072 )
      goto LABEL_28;
    return -1073741582;
  }
  v12 = (v8 & 0xC00) == 0;
LABEL_23:
  if ( !v12 )
    return -1073741582;
LABEL_28:
  if ( (v8 & 0x8000) != 0 && (~v8 & 0x810) != 0 || (v8 & 0x3000) == 12288 || (v8 & 0x18) == 24 )
    return -1073741582;
  v13 = 0;
  v16 = 0;
  if ( (v8 & 0x20000) != 0 )
  {
    if ( (v8 & 0x400) == 0 || !a6 || !*a6 )
    {
      v11 = -1073741811;
      v27 = -1073741811;
      return v11;
    }
    v13 = *a6;
    v16 = *a6;
  }
  memmove((int)v31, a2, 4 * a3);
  if ( v9 <= 3 )
  {
    v17 = v9;
    if ( v9 != 3 )
      goto LABEL_51;
  }
  else
  {
    v9 = 3;
    v17 = 3;
  }
  if ( v32 < 0x10000 )
  {
    if ( v32 && ((v32 & 0x3FF) == 0 || v32 == 127 || !DownLevelLangIDToLanguageName((unsigned __int16)v32, 0, 0, 2)) )
      return -1073741811;
  }
  else
  {
    if ( *(_WORD *)v32 )
      v14 = DownLevelLanguageNameToLangID(v32, 2);
    else
      v14 = 0;
    v30 = v14;
    v32 = (unsigned __int16)v14;
  }
LABEL_51:
  if ( (v8 & 0x300) == 0 )
    return LdrpResSearchResourceMappedFile(v10, v13, v8, v31, v9, v20, v19, v18, v22);
  v10 = v21;
  if ( (v8 & 0x200) != 0 && (v21 & 1) == 0 )
    v10 = v21 | 1;
  v11 = LdrpResGetMappingSize(v10, &v16, v8);
  if ( v11 >= 0 || (v8 & 0x1000) == 0 )
  {
    v13 = v16;
    return LdrpResSearchResourceMappedFile(v10, v13, v8, v31, v9, v20, v19, v18, v22);
  }
  return v11;
}
