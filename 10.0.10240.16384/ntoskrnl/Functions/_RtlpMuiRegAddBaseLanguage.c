// _RtlpMuiRegAddBaseLanguage 
 
int __fastcall RtlpMuiRegAddBaseLanguage(_DWORD *a1, _WORD *a2, unsigned int a3, int a4, unsigned __int16 *a5)
{
  char v5; // r7
  unsigned __int16 *v7; // r8
  BOOL v8; // r4
  int v9; // r10
  int v10; // r3
  __int16 v11; // r6
  _DWORD *v12; // r0
  int v13; // r4
  int v14; // r0
  int v15; // r5
  int v16; // r9
  int v17; // r2
  _DWORD *v18; // r4
  int v19; // r10
  int v20; // r0
  _DWORD *v21; // r5
  _WORD *v22; // r0
  int v23; // r1
  char v25[2]; // [sp+8h] [bp-70h] BYREF
  __int16 v26; // [sp+Ah] [bp-6Eh] BYREF
  char v27[2]; // [sp+Ch] [bp-6Ch] BYREF
  __int16 v28; // [sp+Eh] [bp-6Ah] BYREF
  _DWORD *v29; // [sp+10h] [bp-68h]
  int v30; // [sp+14h] [bp-64h]
  int v31; // [sp+18h] [bp-60h]
  _WORD *v32; // [sp+1Ch] [bp-5Ch]
  BOOL v33; // [sp+20h] [bp-58h]
  int v34; // [sp+28h] [bp-50h] BYREF
  unsigned __int16 *v35; // [sp+2Ch] [bp-4Ch]
  int v36; // [sp+30h] [bp-48h]
  __int16 v37; // [sp+38h] [bp-40h] BYREF
  __int16 v38; // [sp+3Ch] [bp-3Ch]
  __int16 v39; // [sp+3Eh] [bp-3Ah]
  __int16 v40; // [sp+40h] [bp-38h]
  __int16 v41[26]; // [sp+44h] [bp-34h]

  v5 = 0;
  v32 = a2;
  v36 = a3;
  v29 = a1;
  v25[0] = 0;
  if ( !a1 || !a2 || !a4 || a3 > 3 )
    return -1073741811;
  v7 = (unsigned __int16 *)(*(_DWORD *)(a4 + 8) + a4);
  v8 = *(_DWORD *)(a4 + 12) && v7 && *v7;
  v9 = (*(_DWORD *)(a4 + 16) >> 1) + 10;
  v10 = *(unsigned __int16 *)(a4 + 2 * v9);
  v33 = v8;
  v31 = v10;
  *(_WORD *)(a4 + 2 * v9) = 0;
  RtlInitUnicodeString((unsigned int)&v34, (unsigned __int16 *)(a4 + 20));
  v11 = 0;
  v26 = 0;
  if ( !v8 )
  {
    v21 = v29;
    v13 = RtlpMuiRegGetLanguageSpec(v29, v35, v25, (int)&v26, &v26);
    if ( v13 < 0 )
      return v13;
    v5 = v25[0];
    v11 = v26;
    goto LABEL_39;
  }
  v12 = v29;
  v7[*(_DWORD *)(a4 + 12) >> 1] = 0;
  v13 = RtlpMuiRegInitAnyLanguage((int)v12, &v37, v35, 1026);
  v34 = v13;
  if ( v13 < 0 )
    return v13;
  v37 ^= ((unsigned __int8)*v32 ^ (unsigned __int8)v37) & 0x18;
  *(_WORD *)(a4 + 2 * v9) = v31;
  v30 = 0;
  v31 = 0;
  if ( a5 && *a5 && RtlpLangNameInMultiSzString(v7, a5) )
  {
    v14 = RtlpMuiRegGetLanguageSpec(v29, a5, v27, (int)&v28, &v28);
    v15 = (unsigned __int8)v27[0];
    v16 = v28;
    if ( v14 >= 0 )
    {
      v41[0] = v28;
      v40 ^= ((unsigned __int8)v40 ^ v27[0]) & 3;
      v17 = 1;
      v30 = 1;
      v31 = 1;
      goto LABEL_19;
    }
  }
  else
  {
    v16 = 0;
    v15 = 0;
  }
  v17 = 0;
LABEL_19:
  if ( v7 )
  {
    v18 = v29;
    v19 = v17;
    do
    {
      if ( !*v7 || v19 >= 4 )
        break;
      v20 = RtlpMuiRegGetLanguageSpec(v18, v7, v25, (int)&v26, &v26);
      v5 = v25[0];
      v11 = v26;
      if ( v20 >= 0 && (!v31 || v15 != (unsigned __int8)v25[0] || v16 != v26) )
      {
        v40 = ((v25[0] & 3) << (v19 * 2)) | v40 & ~(3 << (v19 * 2));
        v41[v19++] = v26;
        ++v30;
      }
      v7 += wcslen(v7) + 1;
    }
    while ( v7 );
    v13 = v34;
    v17 = v30;
  }
  if ( v17 >= 0 )
  {
    v21 = v29;
LABEL_39:
    if ( !v33 )
      goto LABEL_42;
    v37 &= 0xFFDFu;
    v13 = RtlpMuiRegGetOrAddLangInfo(v21 + 5, (int)&v37, &v26);
    if ( v13 >= 0 )
    {
      v11 = v26;
      v5 = 2;
      goto LABEL_42;
    }
    return v13;
  }
  if ( v38 )
  {
    v5 = 1;
    v11 = v38;
LABEL_42:
    v22 = v32;
    v23 = v36;
    v32[4] = ((v5 & 3) << (2 * v36)) | v32[4] & ~(3 << (2 * v36));
    v22[v23 + 6] = v11;
    return v13;
  }
  v11 = v39;
  if ( v39 > 0 )
  {
    v5 = 3;
    goto LABEL_42;
  }
  return -1073741823;
}
