// NtFilterToken 
 
int __fastcall NtFilterToken(int a1, int a2, unsigned int *a3, int *a4, unsigned int *a5, _DWORD *a6)
{
  int v8; // r4
  int v9; // r8
  int v10; // r0
  _DWORD *v11; // r2
  unsigned int v12; // r1
  unsigned int v13; // r2
  int v14; // r5
  int v15; // r9
  int v16; // r10
  unsigned int v17; // r2
  int v18; // r1
  int v20; // [sp+0h] [bp-98h]
  int v21; // [sp+4h] [bp-94h]
  int v22; // [sp+24h] [bp-74h] BYREF
  int v23; // [sp+28h] [bp-70h]
  int v24; // [sp+2Ch] [bp-6Ch] BYREF
  int v25; // [sp+30h] [bp-68h]
  int v26; // [sp+34h] [bp-64h]
  int v27; // [sp+38h] [bp-60h]
  int v28; // [sp+3Ch] [bp-5Ch]
  unsigned int v29; // [sp+40h] [bp-58h]
  int v30; // [sp+44h] [bp-54h]
  int v31; // [sp+48h] [bp-50h]
  unsigned int v32; // [sp+4Ch] [bp-4Ch]
  _DWORD *v33; // [sp+50h] [bp-48h]
  int v34; // [sp+54h] [bp-44h]
  unsigned int v35; // [sp+58h] [bp-40h]
  int v36; // [sp+5Ch] [bp-3Ch]
  int v37; // [sp+60h] [bp-38h] BYREF
  int v38; // [sp+64h] [bp-34h]
  unsigned int v39; // [sp+68h] [bp-30h]
  int v40; // [sp+70h] [bp-28h]
  int v41; // [sp+74h] [bp-24h]
  unsigned int v42; // [sp+78h] [bp-20h]
  int varg_r0; // [sp+A0h] [bp+8h]
  int varg_r1; // [sp+A4h] [bp+Ch]
  unsigned int *varg_r2; // [sp+A8h] [bp+10h]
  int *varg_r3; // [sp+ACh] [bp+14h]

  varg_r2 = a3;
  varg_r3 = a4;
  v36 = a2;
  varg_r1 = a2;
  v22 = a1;
  varg_r0 = a1;
  v8 = 0;
  v29 = 0;
  v39 = 0;
  v24 = 0;
  v25 = 0;
  v30 = 0;
  v40 = 0;
  v32 = 0;
  v35 = 0;
  v23 = 0;
  v28 = 0;
  v31 = 0;
  v38 = 0;
  v27 = 0;
  v26 = 0;
  v37 = 0;
  v9 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v10 = (int)a6;
  v33 = a6;
  v11 = a6;
  if ( (unsigned int)a6 >= MmUserProbeAddress )
    v11 = (_DWORD *)MmUserProbeAddress;
  *v11 = *v11;
  if ( a3 )
  {
    if ( ((unsigned __int8)a3 & 3) != 0 )
      ExRaiseDatatypeMisalignment(a6);
    v32 = *a3;
    v12 = v32;
    v35 = v32;
    v13 = 0;
    v42 = 0;
    while ( v13 < v12 )
    {
      a3[2 * ++v13] = 0;
      v42 = v13;
    }
    v10 = SeCaptureSidAndAttributesArray(a3 + 1, v12, v9, 0, 0);
    v8 = v10;
    v34 = v10;
    v23 = v28;
  }
  if ( v8 >= 0 )
  {
    if ( a4 )
    {
      if ( ((unsigned __int8)a4 & 3) != 0 )
        ExRaiseDatatypeMisalignment(v10);
      v31 = *a4;
      v38 = v31;
      v10 = SeCaptureLuidAndAttributesArray(a4 + 1);
      v8 = v10;
      v34 = v10;
      v27 = v26;
    }
    if ( v8 >= 0 && a5 )
    {
      if ( ((unsigned __int8)a5 & 3) != 0 )
        ExRaiseDatatypeMisalignment(v10);
      v29 = *a5;
      v39 = v29;
      v8 = SeCaptureSidAndAttributesArray(a5 + 1, v29, v9, 0, 0);
      v34 = v8;
      v24 = v25;
      v30 = v40;
    }
  }
  v14 = v24;
  v15 = v23;
  v16 = v27;
  if ( v8 >= 0 )
  {
    v17 = 0;
    v18 = v24;
    while ( v17 < v29 )
    {
      if ( *(_DWORD *)(v18 + 4) )
      {
        v8 = -1073741811;
        goto LABEL_32;
      }
      ++v17;
      v18 += 8;
    }
    v8 = ObReferenceObjectByHandle(v22, 2, SeTokenObjectType, v9, &v24);
    if ( v8 >= 0 )
    {
      v22 = 0;
      v8 = SepFilterToken(v24, v9, v36, v32, v23, v31, v16, v29, v14, v30, &v22);
      if ( v8 >= 0 )
      {
        v8 = ObInsertObject(v22, 0, v41, 1, 0, &v37);
        if ( v8 >= 0 )
        {
          SepAppendAceToTokenObjectAcl(v22, 8, (unsigned __int16 *)SeAliasAdminsSid, (int)&SeAliasAdminsSid, v20, v21);
          ObfDereferenceObject(v22);
        }
      }
      ObfDereferenceObject(v24);
      if ( v8 >= 0 )
        *v33 = v37;
    }
  }
LABEL_32:
  if ( v15 )
    SeReleaseLuidAndAttributesArray(v15, v9);
  if ( v16 )
    SeReleaseLuidAndAttributesArray(v16, v9);
  if ( v14 )
    SeReleaseLuidAndAttributesArray(v14, v9);
  return v8;
}
