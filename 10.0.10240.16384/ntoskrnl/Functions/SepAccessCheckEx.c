// SepAccessCheckEx 
 
int __fastcall SepAccessCheckEx(int a1, int a2, int a3, int a4, unsigned int a5, int *a6, int a7, _DWORD *a8, unsigned int a9, char a10, unsigned int *a11, _DWORD *a12, int *a13, int a14, int a15, unsigned __int8 a16, unsigned __int8 a17, int a18, int a19, _BYTE *a20)
{
  int v20; // r5
  int v23; // r0
  unsigned int v24; // r10
  int v25; // r9
  int *v26; // r3
  int v27; // r2
  unsigned int v28; // r6
  int v29; // r5
  int v30; // r2
  __int16 v31; // r2
  int v32; // lr
  int v33; // r1
  int v34; // r3
  int v35; // r1
  int v36; // r2
  int v37; // r2
  int v38; // r3
  int v39; // r3
  unsigned int v40; // r2
  int v41; // r3
  int v42; // r1
  int v43; // r3
  int v44; // r2
  int v45; // r3
  int v46; // r3
  int v47; // r1
  int v48; // r3
  int v49; // r1
  int v50; // r2
  int v51; // r2
  int v53; // [sp+4h] [bp-B4h]
  int v54; // [sp+4h] [bp-B4h]
  int v56; // [sp+28h] [bp-90h]
  int v57; // [sp+30h] [bp-88h]
  int v59; // [sp+3Ch] [bp-7Ch]
  int v60; // [sp+40h] [bp-78h]
  int v61; // [sp+44h] [bp-74h]
  __int64 v62; // [sp+58h] [bp-60h] BYREF
  int v63; // [sp+60h] [bp-58h]
  int v64[20]; // [sp+68h] [bp-50h] BYREF

  v20 = a4;
  v57 = 0;
  v59 = 0;
  v60 = 0;
  v61 = 0;
  if ( !a4 )
    v20 = a3;
  v23 = a5;
  v24 = a5;
  if ( a7 )
  {
    v25 = a7;
  }
  else
  {
    a6 = v64;
    v25 = 1;
    memset(v64, 0, 44);
    v64[5] = -1;
    v23 = a5;
  }
  v26 = a6;
  v27 = v25;
  do
  {
    v26[10] = a14;
    a14 += 128;
    v26 += 11;
    --v27;
  }
  while ( v27 );
  if ( (v23 & 0x1000000) != 0 )
  {
    v62 = SeSecurityPrivilege;
    v63 = 0;
    if ( !SepPrivilegeCheck(v20, (int *)&v62, 1, 1, a10) )
    {
      v28 = 0;
      v29 = -1073741727;
      AuthzBasepSetTypeListAccessReasons(0x1000000, 0x100000, 8, a6, v25, 0);
LABEL_11:
      v30 = 1;
      goto LABEL_12;
    }
    v24 = a5 & 0xFEFFFFFF;
    v28 = a9 | 0x1000000;
    v23 = AuthzBasepSetTypeListAccessReasons(0x1000000, 0x200000, 8, a6, v25, 0);
    v57 = 1;
    v60 = 1;
    if ( (a5 & 0xFEFFFFFF) == 0 )
      goto LABEL_16;
    v23 = a5;
  }
  else
  {
    v28 = a9;
  }
  v31 = *(_WORD *)(a1 + 2);
  if ( (v31 & 4) == 0 )
    goto LABEL_26;
  if ( (*(_WORD *)(a1 + 2) & 0x8000) == 0 )
  {
    v32 = *(_DWORD *)(a1 + 16);
    goto LABEL_31;
  }
  v33 = *(_DWORD *)(a1 + 16);
  if ( v33 )
    v32 = v33 + a1;
  else
LABEL_26:
    v32 = 0;
  if ( (v31 & 0x10) == 0 )
    goto LABEL_32;
LABEL_31:
  if ( (*(_WORD *)(a1 + 2) & 0x8000) == 0 )
  {
    v34 = *(_DWORD *)(a1 + 12);
    goto LABEL_37;
  }
  v35 = *(_DWORD *)(a1 + 12);
  if ( v35 )
    v34 = a1 + v35;
  else
LABEL_32:
    v34 = 0;
LABEL_37:
  v56 = v34;
  if ( (v31 & 4) == 0 || !v32 )
  {
    if ( (v23 & 0x2000000) != 0 )
    {
      v28 = (v23 | v28) & 0xFDFFFFFF | a8[3];
      v23 = AuthzBasepSetTypeListAccessReasons(v28, 5242880, 0, a6, v25, 0);
      if ( (*(_DWORD *)(v20 + 176) & 0x4000) != 0 )
      {
        v28 = 0;
        AuthzBasepSetTypeListAccessReasons(0, v49, v50, a6, v25, 1);
        v29 = -1073741790;
        *(_BYTE *)(a18 + 17) = 0;
        *(_DWORD *)(a18 + 4) = 0;
        goto LABEL_11;
      }
    }
    else
    {
      v28 |= v23;
      v23 = AuthzBasepSetTypeListAccessReasons(v23, 5242880, 0, a6, v25, 0);
      if ( (*(_DWORD *)(v20 + 176) & 0x4000) != 0 )
      {
        v28 = 0;
        AuthzBasepSetTypeListAccessReasons(0, 5242880, v51, a6, v25, 0);
        *(_BYTE *)(a18 + 17) = 0;
        *(_DWORD *)(a18 + 4) = 0;
        goto LABEL_94;
      }
    }
    goto LABEL_16;
  }
  if ( (v24 & 0x80000) != 0 )
  {
    v62 = SeTakeOwnershipPrivilege;
    v63 = 0;
    if ( SepPrivilegeCheck(v20, (int *)&v62, 1, 1, a10) )
    {
      v24 &= 0xFFF7FFFF;
      v28 |= 0x80000u;
      v23 = AuthzBasepSetTypeListAccessReasons(0x80000, 0x200000, 9, a6, v25, 0);
      ++v57;
      v59 = 1;
    }
    else
    {
      v62 = SeRelabelPrivilege;
      v63 = 0;
      v23 = SepPrivilegeCheck(v20, (int *)&v62, 1, 1, a10);
      if ( !v23 )
        goto LABEL_43;
      v24 &= 0xFFF7FFFF;
      v28 |= 0x80000u;
      v23 = AuthzBasepSetTypeListAccessReasons(0x80000, 0x200000, 32, a6, v25, 0);
      ++v57;
      v61 = 1;
    }
    if ( !v24 )
      goto LABEL_16;
  }
LABEL_43:
  if ( !*(_WORD *)(v32 + 4) )
  {
    *(_DWORD *)(a18 + 12) = v24;
    v36 = *(_DWORD *)(v20 + 176);
    if ( (v36 & 0x4000) != 0 )
      v28 &= ~*(_DWORD *)a18;
    if ( v24 == 0x2000000 )
    {
      if ( v28 )
        goto LABEL_16;
    }
    else if ( !v24 && *(_DWORD *)a18 && v28 && (v36 & 0x6000) == 0 )
    {
      goto LABEL_16;
    }
    v29 = -1073741790;
    v28 = 0;
    AuthzBasepSetTypeListAccessReasons(-33554433, 6291456, 0, a6, v25, 0);
    goto LABEL_11;
  }
  if ( (a5 & 0x2000000) != 0 )
  {
    SepMaximumAccessCheckEx(v20, a3, v32, v56, a19, v53, v25, a6, a7, 0, 0, a16, a17, a18);
    AuthzBasepSetTypeListAccessReasons(-1, 0x800000, 0, a6, v25, 0);
    v23 = SeTokenIsRestricted(v20);
    if ( v23 )
    {
      if ( SeTokenIsWriteRestricted(v20) )
      {
        v44 = a8[1] & ~(a8[2] | *a8);
        v45 = 17629184;
      }
      else
      {
        v44 = a8[3];
        v45 = 0x1FFFFF;
      }
      v23 = SepMaximumAccessCheckEx(v20, a3, v32, v56, a19, v54, v25, a6, a7, v45 | v44, 1, a16, a17, a18);
    }
    v46 = *(_DWORD *)(v20 + 176);
    v47 = a6[7];
    if ( (v46 & 0x2000) != 0 )
      goto LABEL_87;
    if ( (v46 & 0x4000) != 0 )
    {
      v48 = *(_DWORD *)(a18 + 4) | *(_DWORD *)(a18 + 8);
    }
    else
    {
      if ( !*(_BYTE *)(a18 + 16) )
      {
LABEL_87:
        if ( (v24 & ~(v47 | 0x2000000)) != 0 )
          goto LABEL_58;
        v28 |= v47;
LABEL_16:
        v29 = 0;
        goto LABEL_17;
      }
      v48 = *(_DWORD *)(a18 + 4);
    }
    v47 &= v48;
    v28 &= ~*(_DWORD *)a18;
    goto LABEL_87;
  }
  SepNormalAccessCheckEx(v24, v20, a3, v32, v56, a19);
  *(_DWORD *)(a18 + 12) = a6[6];
  if ( a6[6] )
  {
LABEL_58:
    v29 = -1073741790;
    v28 = 0;
    goto LABEL_11;
  }
  v23 = SeTokenIsRestricted(v20);
  if ( !v23 )
    goto LABEL_65;
  v23 = SeTokenIsWriteRestricted(v20);
  if ( v23 )
  {
    v37 = a8[1] & ~(a8[2] | *a8);
    v38 = 17629184;
  }
  else
  {
    v37 = a8[3];
    v38 = 0x1FFFFF;
  }
  v39 = v38 | v37;
  v40 = a5;
  if ( (v39 & a5) != 0 )
  {
    v23 = SepNormalAccessCheckEx(v39 & v24, v20, a3, v32, v56, a19);
LABEL_65:
    v40 = a5;
  }
  *(_DWORD *)(a18 + 12) = a6[6];
  if ( a6[6] )
    goto LABEL_58;
  v41 = *(_DWORD *)(v20 + 176);
  if ( (v41 & 0x2000) == 0 )
  {
    v42 = v24 | v40;
    if ( (v41 & 0x4000) != 0 )
    {
      v43 = (*(_DWORD *)a18 | v42) & ~(*(_DWORD *)(a18 + 8) | *(_DWORD *)(a18 + 4));
    }
    else
    {
      if ( !*(_BYTE *)(a18 + 16) )
      {
        v43 = 0;
        goto LABEL_74;
      }
      v43 = (*(_DWORD *)a18 | v42) & ~*(_DWORD *)(a18 + 4);
    }
    v40 = a5;
LABEL_74:
    a6[6] = v43;
    if ( v43 )
      goto LABEL_58;
  }
  v29 = 0;
  v28 |= v40;
LABEL_17:
  if ( !v28 )
  {
LABEL_94:
    v29 = -1073741790;
    goto LABEL_11;
  }
  if ( (unsigned int)KeGetCurrentIrql(v23) >= 2 )
    goto LABEL_11;
  if ( !v57 )
    goto LABEL_11;
  SepAssemblePrivileges(v57, v60, v59, v61, a12);
  if ( !a12 || *a12 )
    goto LABEL_11;
  v29 = -1073741801;
  v30 = 0;
  v28 = 0;
LABEL_12:
  *a13 = v29;
  *a11 = v28;
  if ( v29 < 0 )
  {
    if ( a20 )
      *a20 = 0;
  }
  else if ( a20 )
  {
    *a20 = 1;
  }
  return v30;
}
