// SepAccessCheck 
 
int __fastcall SepAccessCheck(int a1, int a2, int *a3, int *a4, unsigned int a5, _DWORD *a6, int a7, _DWORD *a8, unsigned int a9, char a10, unsigned int *a11, _DWORD *a12, int *a13, unsigned __int8 a14, unsigned __int8 a15, int a16, int *a17, _BYTE *a18, char *a19)
{
  int *v19; // r6
  _DWORD *v20; // r1
  int v22; // lr
  int v24; // r0
  int v25; // r8
  unsigned int v26; // r5
  __int16 v27; // r3
  int v28; // r2
  int v29; // r8
  int v30; // r2
  unsigned int v31; // r10
  unsigned int v32; // r10
  unsigned int v33; // r9
  unsigned int v34; // r10
  int v35; // r3
  int v36; // r8
  int v37; // r6
  int v38; // r4
  unsigned int v39; // r0
  int result; // r0
  int v41; // r2
  int v42; // r1
  int v43; // r3
  int v44; // r3
  int v45; // r1
  int v46; // r3
  int v47; // r2
  int v48; // r3
  int v49; // r3
  int v50; // r2
  int v51; // r3
  bool v52; // zf
  int v53; // r2
  int v54; // r6
  char v55; // r8
  unsigned int v56; // lr
  int v57; // r1
  unsigned int v58; // r4
  int *v59; // r2
  int v60; // r3
  unsigned int *v61; // r1
  unsigned int *v62; // r2
  unsigned int v63; // [sp+Ch] [bp-BCh]
  unsigned int v64; // [sp+28h] [bp-A0h]
  int v65; // [sp+2Ch] [bp-9Ch]
  int v66; // [sp+34h] [bp-94h]
  int v67; // [sp+38h] [bp-90h]
  int v69; // [sp+58h] [bp-70h]
  int v70; // [sp+5Ch] [bp-6Ch]
  __int64 v71; // [sp+68h] [bp-60h] BYREF
  int v72; // [sp+70h] [bp-58h]
  _DWORD v73[20]; // [sp+78h] [bp-50h] BYREF

  v19 = a4;
  v20 = (_DWORD *)a16;
  v67 = (int)a3;
  v22 = (int)a3;
  v65 = 0;
  v69 = 0;
  v70 = 0;
  if ( !a4 )
    v19 = a3;
  v24 = a14;
  v25 = a7;
  v64 = a5;
  if ( (a5 & 0x1000000) != 0 )
  {
    v71 = SeSecurityPrivilege;
    v72 = 0;
    if ( SepPrivilegeCheck((int)v19, (int *)&v71, 1, 1, a10) )
      return sub_52DEF8();
    v38 = -1073741727;
    v37 = a14;
    v26 = 0;
    goto LABEL_30;
  }
  v26 = a9;
  v27 = *(_WORD *)(a1 + 2);
  if ( (v27 & 4) != 0 )
  {
    if ( (*(_WORD *)(a1 + 2) & 0x8000) != 0 )
    {
      v28 = *(_DWORD *)(a1 + 16);
      if ( v28 )
        v29 = a1 + v28;
      else
        v29 = 0;
    }
    else
    {
      v29 = *(_DWORD *)(a1 + 16);
    }
  }
  else
  {
    v29 = 0;
  }
  if ( (v27 & 0x10) != 0 )
  {
    if ( (*(_WORD *)(a1 + 2) & 0x8000) != 0 )
    {
      v41 = *(_DWORD *)(a1 + 12);
      if ( v41 )
        v30 = v41 + a1;
      else
        v30 = 0;
    }
    else
    {
      v30 = *(_DWORD *)(a1 + 12);
    }
  }
  else
  {
    v30 = 0;
  }
  v66 = v30;
  if ( (v27 & 4) == 0 || !v29 )
  {
    if ( (a5 & 0x2000000) != 0 )
      v26 = (a5 | a9) & 0xFDFFFFFF | a8[3];
    else
      v26 = a9 | a5;
    if ( (v19[44] & 0x4000) != 0 )
    {
      v26 = 0;
      v38 = -1073741790;
      v37 = a14;
      v25 = a7;
      *(_BYTE *)(a16 + 17) = 0;
      *(_DWORD *)(a16 + 4) = 0;
      goto LABEL_30;
    }
    goto LABEL_26;
  }
  if ( (a5 & 0x80000) == 0 )
  {
    v31 = a5;
    goto LABEL_14;
  }
  v72 = 0;
  v71 = *(_QWORD *)&SeTakeOwnershipPrivilege;
  v24 = SepPrivilegeCheck((int)v19, (int *)&v71, 1, 1, a10);
  if ( v24 )
  {
    v26 = a9 | 0x80000;
    v31 = a5 & 0xFFF7FFFF;
    v52 = (a5 & 0xFFF7FFFF) == 0;
    v64 = a5 & 0xFFF7FFFF;
    v65 = 1;
    v70 = 1;
    goto LABEL_87;
  }
  v72 = 0;
  v71 = *(_QWORD *)&SeRelabelPrivilege;
  v24 = SepPrivilegeCheck((int)v19, (int *)&v71, 1, 1, a10);
  v31 = a5;
  if ( v24 )
  {
    v31 = a5 & 0xFFF7FFFF;
    v52 = (a5 & 0xFFF7FFFF) == 0;
    v64 = a5 & 0xFFF7FFFF;
    v65 = 1;
    v69 = 1;
    v26 = a9 | 0x80000;
LABEL_87:
    if ( v52 )
      goto LABEL_26;
  }
  v20 = (_DWORD *)a16;
  v22 = v67;
  v24 = a14;
LABEL_14:
  if ( !*(_WORD *)(v29 + 4) )
  {
    v20[3] = v31;
    v53 = v19[44];
    if ( (v53 & 0x4000) != 0 )
      v26 &= ~*v20;
    if ( v31 == 0x2000000 )
    {
      if ( v26 )
        goto LABEL_26;
    }
    else if ( !v31 && *v20 && v26 && (v53 & 0x6000) == 0 )
    {
      goto LABEL_26;
    }
    v38 = -1073741790;
    v37 = a14;
    v26 = 0;
    goto LABEL_29;
  }
  if ( a7 )
  {
    v32 = a7;
  }
  else
  {
    v73[0] = 0;
    v73[1] = 0;
    v73[2] = 0;
    v73[3] = 0;
    v73[4] = 0;
    v73[6] = 0;
    v73[7] = 0;
    v73[8] = 0;
    v73[9] = 0;
    v73[10] = 0;
    a6 = v73;
    v73[5] = -1;
    v32 = 1;
  }
  if ( (a5 & 0x2000000) == 0 && !v24 )
  {
    v24 = SepNormalAccessCheck(v64, v19, v22, v29, v66, a17, a2, v32, a6, a7, 0, a15, v20);
    *(_DWORD *)(a16 + 12) = a6[6];
    if ( a6[6] )
      goto LABEL_44;
    if ( (v19[44] & 0x10) != 0 )
    {
      v24 = SeTokenIsWriteRestricted((int)v19);
      if ( v24 )
      {
        v47 = a8[1] & ~(a8[2] | *a8);
        v48 = 17629184;
      }
      else
      {
        v47 = a8[3];
        v48 = 0x1FFFFF;
      }
      v33 = a5;
      v49 = v48 | v47;
      if ( (v49 & a5) != 0 )
      {
        v63 = v32;
        v34 = v64;
        v24 = SepNormalAccessCheck(v49 & v64, v19, v67, v29, v66, a17, a2, v63, a6, a7, 1, a15, a16);
        goto LABEL_23;
      }
    }
    else
    {
      v33 = a5;
    }
    v34 = v64;
LABEL_23:
    *(_DWORD *)(a16 + 12) = a6[6];
    if ( !a6[6] )
    {
      v35 = v19[44];
      if ( (v35 & 0x2000) != 0 )
        goto LABEL_25;
      v42 = v34 | v33;
      if ( (v35 & 0x4000) != 0 )
      {
        v43 = (*(_DWORD *)a16 | v42) & ~(*(_DWORD *)(a16 + 8) | *(_DWORD *)(a16 + 4));
      }
      else
      {
        if ( !*(_BYTE *)(a16 + 16) )
        {
          a6[6] = 0;
          goto LABEL_25;
        }
        v43 = (*(_DWORD *)a16 | v42) & ~*(_DWORD *)(a16 + 4);
      }
      a6[6] = v43;
      if ( !v43 )
      {
LABEL_25:
        v26 |= v33;
LABEL_26:
        v36 = v65;
        v37 = a14;
        goto LABEL_27;
      }
    }
LABEL_44:
    v38 = -1073741790;
    v26 = 0;
    result = 1;
    goto LABEL_32;
  }
  SepMaximumAccessCheck(v19, v22, v29, v66, a17, a2, v32, (int)a6, a7, 0, 0, a15, (int)v20);
  if ( (v19[44] & 0x10) != 0 )
  {
    if ( SeTokenIsWriteRestricted((int)v19) )
    {
      v50 = a8[1] & ~(a8[2] | *a8);
      v51 = 17629184;
    }
    else
    {
      v50 = a8[3];
      v51 = 0x1FFFFF;
    }
    SepMaximumAccessCheck(v19, v67, v29, v66, a17, a2, v32, (int)a6, a7, v51 | v50, 1u, a15, a16);
  }
  v44 = v19[44];
  v45 = a6[7];
  if ( (v44 & 0x2000) == 0 )
  {
    if ( (v44 & 0x4000) != 0 )
    {
      v45 &= *(_DWORD *)(a16 + 4) | *(_DWORD *)(a16 + 8);
      v46 = *(_DWORD *)a16;
    }
    else
    {
      if ( !*(_BYTE *)(a16 + 16) )
        goto LABEL_47;
      v45 &= *(_DWORD *)(a16 + 4);
      v46 = *(_DWORD *)a16;
    }
    v26 &= ~v46;
  }
LABEL_47:
  v37 = a14;
  if ( !a14 )
  {
    v24 = v64;
    if ( (v64 & ~(v45 | 0x2000000)) == 0 )
    {
      v36 = v65;
      v26 |= v45;
LABEL_27:
      v38 = 0;
      if ( v26 )
      {
        v39 = KeGetCurrentIrql(v24);
        if ( v36 )
        {
          if ( v39 < 2 )
          {
            SepAssemblePrivileges(v36, 0, v70, v69, a12);
            if ( a12 )
            {
              v25 = a7;
              if ( !*a12 )
              {
                v38 = -1073741801;
                result = 0;
                v26 = 0;
LABEL_31:
                if ( v37 )
                {
                  if ( v25 )
                  {
                    v62 = a11;
                    do
                    {
                      *(unsigned int *)((char *)v62 + (char *)a13 - (char *)a11) = v38;
                      *v62++ = v26;
                      --v25;
                    }
                    while ( v25 );
                  }
                  goto LABEL_33;
                }
LABEL_32:
                *a13 = v38;
                *a11 = v26;
LABEL_33:
                if ( v38 < 0 )
                {
                  if ( a18 )
                    *a18 = 0;
                  if ( a19 )
                    *a19 = 1;
                }
                else
                {
                  if ( a18 )
                    *a18 = 1;
                  if ( a19 )
                    *a19 = 0;
                }
                return result;
              }
LABEL_30:
              result = 1;
              goto LABEL_31;
            }
          }
        }
      }
      else
      {
        v38 = -1073741790;
      }
LABEL_29:
      v25 = a7;
      goto LABEL_30;
    }
    goto LABEL_44;
  }
  v54 = 0;
  v55 = 0;
  if ( (a5 & 0x2000000) != 0 )
  {
    v56 = (a5 | v26) & 0xFDFFFFFF;
    v57 = -33554433;
  }
  else
  {
    v57 = a5 | v26;
    v56 = a5 | v26;
  }
  v58 = v32;
  v59 = a13;
  do
  {
    v60 = (a6[7] | v26) & v57;
    *(int *)((char *)v59 + (char *)a11 - (char *)a13) = v60;
    if ( v60 )
    {
      if ( (v56 & ~v60) != 0 )
      {
        *v59 = -1073741790;
        v55 = 1;
      }
      else
      {
        *v59 = 0;
        v54 = 1;
      }
    }
    else
    {
      *v59 = -1073741790;
      v55 = 1;
    }
    a6 += 11;
    ++v59;
    --v58;
  }
  while ( v58 );
  if ( (unsigned int)KeGetCurrentIrql(-1073741790) < 2
    && v54
    && v65
    && (SepAssemblePrivileges(v65, 0, v70, v69, a12), a12)
    && !*a12 )
  {
    result = 0;
    LOBYTE(v54) = 0;
    v55 = 1;
    v61 = a11;
    do
    {
      *(unsigned int *)((char *)v61 + (char *)a13 - (char *)a11) = -1073741801;
      *v61++ = 0;
      --v32;
    }
    while ( v32 );
  }
  else
  {
    result = 1;
  }
  if ( a18 )
    *a18 = v54;
  if ( a19 )
    *a19 = v55;
  return result;
}
