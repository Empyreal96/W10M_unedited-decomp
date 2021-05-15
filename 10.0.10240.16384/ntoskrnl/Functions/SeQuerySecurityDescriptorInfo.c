// SeQuerySecurityDescriptorInfo 
 
int __fastcall SeQuerySecurityDescriptorInfo(int *a1, int a2, unsigned int *a3, int *a4)
{
  _BYTE *v5; // lr
  unsigned int v6; // r2
  int v7; // r4
  int result; // r0
  __int16 v9; // r1
  int v10; // r3
  int v11; // r10
  int v12; // r3
  int v13; // r0
  int v14; // r8
  int v15; // r3
  int v16; // r9
  int v17; // r3
  __int16 v18; // r5
  unsigned int v19; // r4
  unsigned int *v20; // r1
  int v21; // r3
  unsigned int v22; // r2
  int v23; // r4
  int *v24; // r10
  int v25; // [sp+0h] [bp-60h]
  int v27; // [sp+8h] [bp-58h] BYREF
  int v28; // [sp+Ch] [bp-54h]
  unsigned int v29; // [sp+10h] [bp-50h]
  int *v30; // [sp+14h] [bp-4Ch]
  int v31; // [sp+18h] [bp-48h]
  unsigned int v32; // [sp+1Ch] [bp-44h]
  unsigned int v33; // [sp+20h] [bp-40h]
  unsigned int *v34; // [sp+24h] [bp-3Ch]
  unsigned int v35; // [sp+28h] [bp-38h]
  int v36; // [sp+30h] [bp-30h]
  int v37; // [sp+34h] [bp-2Ch]
  int v38; // [sp+38h] [bp-28h]
  int v39; // [sp+3Ch] [bp-24h]
  int v40; // [sp+40h] [bp-20h]

  v34 = a3;
  v5 = (_BYTE *)a2;
  v30 = a1;
  v29 = 0;
  v32 = 0;
  v33 = 0;
  v27 = 0;
  v6 = *a3;
  v35 = v6;
  v7 = *a4;
  if ( *a4 )
  {
    v36 = *(_DWORD *)v7;
    v37 = *(_DWORD *)(v7 + 4);
    v38 = *(_DWORD *)(v7 + 8);
    v39 = *(_DWORD *)(v7 + 12);
    v40 = *(_DWORD *)(v7 + 16);
    v9 = *(_WORD *)(v7 + 2);
    if ( (v9 & 0x8000) != 0 )
    {
      v10 = *(_DWORD *)(v7 + 4);
      if ( v10 )
        v11 = v10 + v7;
      else
        v11 = 0;
    }
    else
    {
      v11 = *(_DWORD *)(v7 + 4);
    }
    v37 = v11;
    if ( (v9 & 0x8000) != 0 )
    {
      v12 = *(_DWORD *)(v7 + 8);
      if ( v12 )
        v13 = v12 + v7;
      else
        v13 = 0;
    }
    else
    {
      v13 = *(_DWORD *)(v7 + 8);
    }
    v31 = v13;
    v38 = v13;
    if ( (v9 & 4) != 0 )
    {
      if ( (v9 & 0x8000) != 0 )
      {
        v15 = *(_DWORD *)(v7 + 16);
        if ( v15 )
          v14 = v15 + v7;
        else
          v14 = 0;
      }
      else
      {
        v14 = *(_DWORD *)(v7 + 16);
      }
    }
    else
    {
      v14 = 0;
    }
    v40 = v14;
    if ( (v9 & 0x10) != 0 )
    {
      if ( (v9 & 0x8000) != 0 )
      {
        v17 = *(_DWORD *)(v7 + 12);
        if ( v17 )
          v16 = v17 + v7;
        else
          v16 = 0;
      }
      else
      {
        v16 = *(_DWORD *)(v7 + 12);
      }
    }
    else
    {
      v16 = 0;
    }
    v39 = v16;
    v18 = HIWORD(v36) & 0x7FFF;
    HIWORD(v36) &= 0x7FFFu;
    v19 = 20;
    v25 = 20;
    v20 = (unsigned int *)v30;
    v21 = *v30;
    if ( (*v30 & 0x10000) != 0 )
    {
      *v30 = v21 | 0xFF;
      if ( (v21 & 0x80) == 0 )
        *v20 = (v21 | 0xFF) & 0xFFFFFF7F;
    }
    v22 = *v20;
    if ( (*v20 & 1) != 0 && v11 )
    {
      v29 = 4 * (*(unsigned __int8 *)(v11 + 1) + 2);
      v19 = ((v29 + 3) & 0xFFFFFFFC) + 20;
      v25 = v19;
    }
    if ( (v22 & 2) != 0 && v13 )
    {
      v32 = 4 * (*(unsigned __int8 *)(v13 + 1) + 2);
      v19 += (v32 + 3) & 0xFFFFFFFC;
      v25 = v19;
    }
    if ( (v22 & 4) != 0 && (v18 & 4) != 0 && v14 )
    {
      v33 = (*(unsigned __int16 *)(v14 + 2) + 3) & 0xFFFFFFFC;
      v19 += v33;
      v25 = v19;
    }
    if ( (v22 & 0xF8) != 0 && (v18 & 0x10) != 0 && v16 )
    {
      RtlpFilterSacl(v16, 0, &v27, v22 & 0xF8, v25);
      v19 += v27;
      v25 = v19;
      v5 = (_BYTE *)a2;
    }
    *v34 = v19;
    if ( v19 <= v35 )
    {
      memset(v5, 0, 20);
      *(_BYTE *)a2 = 1;
      *(_WORD *)(a2 + 2) |= 0x8000u;
      v23 = (a2 + 23) & 0xFFFFFFFC;
      v28 = v23;
      if ( (*v30 & 1) != 0 && v11 )
      {
        memmove((a2 + 23) & 0xFFFFFFFC, v11, v29);
        *(_DWORD *)(a2 + 4) = v23 - a2;
        *(_WORD *)(a2 + 2) |= v18 & 1;
        v23 += (v29 + 3) & 0xFFFFFFFC;
        v28 = v23;
      }
      v24 = v30;
      if ( (*v30 & 2) != 0 && v31 )
      {
        memmove(v23, v31, v32);
        *(_DWORD *)(a2 + 8) = v23 - a2;
        *(_WORD *)(a2 + 2) |= v18 & 2;
        v23 += (v32 + 3) & 0xFFFFFFFC;
        v28 = v23;
      }
      if ( (*v24 & 4) != 0 )
      {
        *(_WORD *)(a2 + 2) |= v18 & 0x140C;
        if ( (v18 & 4) != 0 )
        {
          if ( v14 )
          {
            memmove(v23, v14, *(unsigned __int16 *)(v14 + 2));
            *(_DWORD *)(a2 + 16) = v23 - a2;
            v23 += v33;
            v28 = v23;
          }
        }
      }
      if ( (*v24 & 0xF8) != 0 )
      {
        *(_WORD *)(a2 + 2) |= v18 & 0x2830;
        if ( (v18 & 0x10) != 0 )
        {
          if ( v16 )
          {
            RtlpFilterSacl(v16, v23, &v27, *v24 & 0xF8, v25);
            *(_DWORD *)(a2 + 12) = v23 - a2;
            v28 = v27 + v23;
          }
        }
      }
      result = 0;
    }
    else
    {
      result = -1073741789;
      v27 = -1073741789;
    }
  }
  else
  {
    *a3 = 20;
    if ( v6 >= 0x14 )
    {
      RtlCreateSecurityDescriptorRelative((_BYTE *)a2);
      *(_WORD *)(a2 + 2) |= 0x8000u;
      result = 0;
      v27 = 0;
    }
    else
    {
      result = -1073741789;
      v27 = -1073741789;
    }
  }
  return result;
}
