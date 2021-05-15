// SepAdjustPrivileges 
 
int __fastcall SepAdjustPrivileges(_DWORD *a1, int a2, int a3, unsigned int a4, int *a5, int a6, _DWORD *a7, _DWORD *a8, _BYTE *a9)
{
  int v9; // r8
  int v10; // r4
  int v12; // r7
  int v13; // r9
  int v14; // r0
  int v15; // r6
  int v18; // r9
  int v19; // r0
  int v20; // r4
  int v21; // r3
  int v22; // r3
  int v23; // r0
  int v24; // r1
  int v25; // r3
  unsigned int v26; // r2
  _DWORD *v27; // r4
  int v28; // r2
  int v29; // r3
  int v30; // r2
  int v31; // r3
  int v32; // r4
  int v33; // r6
  int v34; // lr
  int v35; // r2
  int v36; // r0
  int v37; // r3
  __int64 v38; // r2
  __int64 v39; // r2
  _DWORD *v40; // r4
  int v41; // r2
  int v42; // r3
  int v43; // r2
  int v44; // r3
  int v45; // r6
  int v46; // r6
  int v47; // r7
  int *v48; // r9
  int v49; // lr
  int v50; // r8
  BOOL v51; // r3
  _DWORD *v52; // r4
  int v53; // r2
  int v54; // r3
  int v55; // r3
  int v56; // r2
  __int64 v57; // kr00_8
  int v58; // r3
  int v59; // r1
  char v60; // [sp+8h] [bp-3E8h] BYREF
  char v61[3]; // [sp+9h] [bp-3E7h] BYREF
  int v62; // [sp+Ch] [bp-3E4h]
  int v63; // [sp+10h] [bp-3E0h]
  int v64; // [sp+14h] [bp-3DCh]
  int v65; // [sp+18h] [bp-3D8h]
  int v66; // [sp+1Ch] [bp-3D4h]
  int v67; // [sp+20h] [bp-3D0h]
  int v68; // [sp+24h] [bp-3CCh]
  int v69; // [sp+28h] [bp-3C8h]
  int v70; // [sp+2Ch] [bp-3C4h]
  int v71; // [sp+30h] [bp-3C0h]
  int v72; // [sp+34h] [bp-3BCh]
  unsigned int v73; // [sp+38h] [bp-3B8h]
  int v74; // [sp+40h] [bp-3B0h]
  int v75; // [sp+44h] [bp-3ACh]
  int v76; // [sp+48h] [bp-3A8h]
  int v77; // [sp+4Ch] [bp-3A4h]
  unsigned int v78; // [sp+50h] [bp-3A0h]
  int *v79; // [sp+54h] [bp-39Ch]
  unsigned int v80; // [sp+58h] [bp-398h]
  int *v81; // [sp+5Ch] [bp-394h]
  int v82; // [sp+60h] [bp-390h]
  int v83; // [sp+64h] [bp-38Ch]
  unsigned int v84; // [sp+68h] [bp-388h] BYREF
  _BYTE *v85; // [sp+70h] [bp-380h]
  _DWORD *v86; // [sp+74h] [bp-37Ch]
  int v87; // [sp+78h] [bp-378h]
  int v88; // [sp+7Ch] [bp-374h]
  int v89; // [sp+80h] [bp-370h] BYREF
  char v90[416]; // [sp+84h] [bp-36Ch] BYREF
  int v91; // [sp+228h] [bp-1C8h] BYREF
  char v92[416]; // [sp+22Ch] [bp-1C4h] BYREF

  v9 = a6;
  v77 = a3;
  v78 = a4;
  v65 = a6;
  v85 = a9;
  v86 = a7;
  v10 = a2;
  v12 = 0;
  v66 = a2;
  v73 = 0;
  v63 = 0;
  v64 = 0;
  v69 = 0;
  v70 = 0;
  v71 = 0;
  v60 = 0;
  v82 = 0;
  v61[0] = 0;
  v13 = 0;
  v75 = 0;
  v76 = 0;
  v74 = 0;
  v87 = 0;
  v88 = 0;
  v68 = 0;
  v89 = 0;
  memset(v90, 0, sizeof(v90));
  v91 = 0;
  memset(v92, 0, sizeof(v92));
  *a8 = 0;
  *a9 = 0;
  SepCopyTokenIntegrity((int)a1, &v84);
  v14 = AppContainerPrivilegesEnabledExt_0();
  v15 = v14;
  if ( v14 == -1073741637 )
    return sub_7F4D74();
  if ( v14 >= 0 )
  {
    v83 = 1;
    v15 = RtlSidDominates((unsigned __int16 *)v84, (unsigned __int16 *)SeHighMandatorySid, &v60);
    v72 = v15;
    if ( v15 >= 0 )
    {
      if ( !v60 )
      {
        v15 = RtlSidDominates((unsigned __int16 *)v84, (unsigned __int16 *)SeMediumMandatorySid, v61);
        v72 = v15;
        if ( v15 < 0 )
          return v15;
        v82 = (unsigned __int8)v61[0];
        if ( !v61[0] )
          v76 = 1;
      }
      if ( v77 )
      {
        v46 = v65;
        v47 = 0;
        v48 = &v89;
        do
        {
          v49 = 1 << (v47 - 32);
          v50 = 1 << v47;
          if ( a1[19] & v49 | a1[18] & (1 << v47) )
          {
            if ( v10 )
            {
              v51 = (a1[21] & v49 | a1[20] & v50) != 0;
              v71 = v51 | 2;
              v69 = v47;
              v70 = v47 >> 31;
              *(_QWORD *)v48 = v47;
              v48[2] = v51 | 2;
              v48 += 3;
              ++v64;
              if ( v46 )
              {
                v52 = (_DWORD *)(v46 + 12 * *a8 + 4);
                v53 = v70;
                v54 = v71;
                *v52 = v69;
                v52[1] = v53;
                v52[2] = v54;
                v10 = v66;
              }
              v55 = a1[19];
              a1[18] &= ~v50;
              a1[19] = v55 & ~v49;
            }
            ++*a8;
          }
          ++v47;
        }
        while ( (unsigned int)v47 <= 0x23 );
LABEL_11:
        v15 = v72;
        if ( !v77 && (v73 < v78 || v63) )
          v15 = 262;
        v12 = v64;
        v9 = v65;
        v13 = v68;
      }
      else if ( v78 )
      {
        v79 = &v89;
        v80 = v78;
        v81 = &v91;
        while ( 1 )
        {
          v18 = a1[16];
          v19 = 1 << (*a5 - 32);
          v20 = 1 << *a5;
          v84 = a1[17];
          if ( v84 & v19 | v20 & v18 )
            break;
LABEL_10:
          a5 += 3;
          if ( !--v80 )
            goto LABEL_11;
        }
        v56 = *a5;
        v57 = *((_QWORD *)a1 + 9);
        ++v73;
        v58 = a5[1];
        v69 = v56;
        v70 = v58;
        v62 = 1 << (v56 - 32);
        v67 = 1 << v56;
        if ( v62 & HIDWORD(v57) | (1 << v56) & (unsigned int)v57 )
          v59 = 2;
        else
          v59 = 0;
        v71 = ((a1[21] & v62 | a1[20] & (1 << v56)) != 0) | v59;
        v22 = a5[2];
        if ( (v22 & 4) != 0 )
        {
          if ( v66 )
          {
            v23 = v67;
            v24 = v62;
            a1[18] = v57 & ~v67;
            a1[16] = v18 & ~v23;
            v25 = a1[44];
            a1[19] = HIDWORD(v57) & ~v24;
            v26 = v84;
            a1[44] = v25 | 0x800;
            a1[17] = v26 & ~v24;
          }
          goto LABEL_10;
        }
        if ( (v22 & 2) == 0 || v19 & HIDWORD(v57) | v20 & (unsigned int)v57 )
        {
          if ( (v22 & 2) != 0 || !(v19 & HIDWORD(v57) | v20 & (unsigned int)v57) )
            goto LABEL_10;
          if ( !v66 )
            goto LABEL_66;
          if ( v65 )
          {
            v40 = (_DWORD *)(v65 + 12 * *a8 + 4);
            v41 = v70;
            v42 = v71;
            *v40 = v69;
            v40[1] = v41;
            v40[2] = v42;
          }
          v43 = v70;
          v44 = v71;
          v45 = (int)v79;
          *v79 = v69;
          *(_DWORD *)(v45 + 4) = v43;
          *(_DWORD *)(v45 + 8) = v44;
          v79 = (int *)(v45 + 12);
          ++v64;
          LODWORD(v39) = a1[18] & ~v67;
          HIDWORD(v39) = a1[19] & ~v62;
          goto LABEL_51;
        }
        if ( v66 )
        {
          if ( v65 )
          {
            v27 = (_DWORD *)(v65 + 12 * *a8 + 4);
            v28 = v70;
            v29 = v71;
            *v27 = v69;
            v27[1] = v28;
            v27[2] = v29;
          }
          v30 = v70;
          v31 = v71;
          v33 = v74;
          v32 = v75;
          v34 = (int)v81;
          *v81 = v69;
          *(_DWORD *)(v34 + 4) = v30;
          *(_DWORD *)(v34 + 8) = v31;
          v81 = (int *)(v34 + 12);
          ++v68;
          if ( v60 )
            goto LABEL_44;
          if ( v82 )
          {
            if ( !((1 << (*a5 - 32)) & 1 | (1 << *a5) & 0x20160684) )
            {
LABEL_44:
              LODWORD(v39) = a1[18] | v67;
              HIDWORD(v39) = a1[19] | v62;
LABEL_51:
              *((_QWORD *)a1 + 9) = v39;
              goto LABEL_66;
            }
LABEL_65:
            ++v63;
            goto LABEL_66;
          }
          if ( v76 )
          {
            if ( v83 )
            {
              v35 = v33;
              v36 = v32;
            }
            else
            {
              v35 = 0x800000;
              v36 = 2;
            }
            v37 = *a5;
            if ( (a1[44] & 0x4000) != 0 )
            {
              LODWORD(v38) = v35 & (1 << *a5);
              HIDWORD(v38) = (1 << (v37 - 32)) & v36;
            }
            else
            {
              LODWORD(v38) = (1 << *a5) & 0x2800000;
              HIDWORD(v38) = (1 << (v37 - 32)) & 2;
            }
            if ( v38 )
              goto LABEL_44;
            goto LABEL_65;
          }
        }
LABEL_66:
        ++*a8;
        goto LABEL_10;
      }
      if ( *a8 && v66 )
      {
        *v85 = 1;
        SepAdtUserRightAdjusted(a1, &v89, v12, &v91, v13, v15 >= 0);
      }
      if ( v9 )
      {
        if ( *a8 > 1u )
          v21 = 12 * (*a8 - 1);
        else
          v21 = 0;
        *v86 = v21 + 16;
      }
    }
  }
  return v15;
}
