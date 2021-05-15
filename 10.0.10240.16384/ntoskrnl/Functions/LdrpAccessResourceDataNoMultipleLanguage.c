// LdrpAccessResourceDataNoMultipleLanguage 
 
int __fastcall LdrpAccessResourceDataNoMultipleLanguage(int a1, unsigned int *a2, _DWORD *a3, int a4)
{
  _DWORD *v4; // r6
  unsigned int v6; // r4
  int result; // r0
  int v8; // r8
  unsigned int v9; // r1
  int v10; // r10
  int v11; // r3
  int v12; // r0
  unsigned int v13; // r6
  int v14; // r2
  unsigned int v15; // r2
  int v16; // r0
  unsigned int v17; // r2
  int v18; // r0
  int v19; // r0
  int v20; // r2
  unsigned int *v21; // r0
  unsigned int v22; // r2
  int v23; // [sp+0h] [bp-40h]
  int v24; // [sp+4h] [bp-3Ch] BYREF
  unsigned int v25; // [sp+8h] [bp-38h]
  _DWORD *v26; // [sp+Ch] [bp-34h]
  int v27; // [sp+10h] [bp-30h]
  int v28; // [sp+14h] [bp-2Ch]
  int v29; // [sp+18h] [bp-28h] BYREF
  unsigned int *v30; // [sp+1Ch] [bp-24h]
  int v31; // [sp+20h] [bp-20h]
  int varg_r0; // [sp+48h] [bp+8h]
  unsigned int *varg_r1; // [sp+4Ch] [bp+Ch]
  _DWORD *varg_r2; // [sp+50h] [bp+10h]
  int varg_r3; // [sp+54h] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v4 = (_DWORD *)a4;
  v26 = (_DWORD *)a4;
  v30 = a3;
  v6 = a1;
  v23 = RtlImageDirectoryEntryToData(a1, 1, 2, (int)&v29);
  if ( !v23 )
    return -1073741687;
  v24 = 0;
  v8 = LdrpGetImageSize(v6, &v24);
  v31 = v8;
  if ( v8 == -1073741701 )
    return -1073741701;
  v9 = v6 & 0xFFFFFFFC;
  v25 = v6 & 0xFFFFFFFC;
  if ( (unsigned int)a2 <= (v6 & 0xFFFFFFFC) )
    return -1073741701;
  v10 = v24;
  if ( v24 )
  {
    if ( (unsigned int)a2 >= v9 + v24 )
      return -1073741701;
  }
  v11 = 0;
  v27 = 0;
  if ( (v6 & 3) != 0 )
  {
    if ( (v6 & 1) != 0 )
    {
      v11 = 1;
      v27 = 1;
    }
    v6 &= 0xFFFFFFFC;
  }
  if ( v11 == 1 )
  {
    v12 = RtlImageNtHeader(v6);
    v13 = v12;
    if ( !v12 )
      return -1073741687;
    v14 = *(unsigned __int16 *)(v12 + 24);
    if ( v14 == 267 )
    {
      v15 = *(_DWORD *)(v12 + 136);
    }
    else if ( v14 == 523 )
    {
      v15 = *(_DWORD *)(v12 + 152);
    }
    else
    {
      v15 = 0;
    }
    if ( !v15 )
      return -1073741687;
    v24 = v15 - v23 + v6;
    v16 = RtlSectionTableFromVirtualAddress(v12, v6, v15);
    if ( !v16 )
      return -1073741687;
    v17 = *a2;
    if ( *a2 <= *(_DWORD *)(v16 + 8) )
    {
      v20 = v24;
    }
    else
    {
      v29 = *(_DWORD *)(v16 + 12);
      v18 = RtlSectionTableFromVirtualAddress(v13, v6, v17);
      v28 = v18;
      if ( !v18 )
        return -1073741687;
      v19 = RtlAddressInSectionTable(v13, v6, *(_DWORD *)(v18 + 12));
      v20 = v23 + *(_DWORD *)(v28 + 12) - v19 - v29 + v24;
    }
    v4 = v26;
    v9 = v25;
  }
  else
  {
    v20 = 0;
  }
  v21 = v30;
  if ( v30 && ((v22 = *a2 - v20 + v6, *v30 = v22, v22 <= v9) || v10 && v22 >= v9 + v10) )
  {
    *v21 = 0;
    result = -1073741701;
  }
  else
  {
    if ( v4 )
      *v4 = a2[1];
    result = v8;
  }
  return result;
}
