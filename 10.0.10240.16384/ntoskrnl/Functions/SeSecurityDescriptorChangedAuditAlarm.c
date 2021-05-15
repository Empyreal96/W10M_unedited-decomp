// SeSecurityDescriptorChangedAuditAlarm 
 
int __fastcall SeSecurityDescriptorChangedAuditAlarm(int a1, int a2, _WORD *a3, int a4, int a5, int a6, int a7, char a8, int a9, int a10, int a11, int a12, int a13)
{
  int v14; // r6
  int v15; // r8
  int v16; // r10
  int v17; // r9
  int v18; // r0
  int v20; // r7
  int v21; // r1
  int v22; // r4
  _DWORD *v23; // r4
  int v24; // lr
  int v25; // r3
  int v26; // r2
  int v27; // r3
  int v28; // r7
  int v29; // r1
  int v30; // r0
  int v31; // r3
  unsigned int v32; // r0
  int v33; // r3
  int v34; // r0
  int v35; // r3
  int v36; // r3
  unsigned __int8 *v37; // r5
  int v38; // r3
  int v39; // r4
  int v40; // lr
  int v41; // r1
  unsigned int v42; // r10
  unsigned __int8 *v43; // r7
  int v44; // r3
  int v45; // r2
  int v46; // r4
  int v47; // r0
  int v48; // r2
  int v49; // r4
  int v50; // r4
  int v51; // r4
  bool v52; // zf
  int v53; // r3
  int v54; // r9
  int v55; // r3
  int v56; // r1
  int v57; // r3
  int v58; // r0
  __int16 v59; // r8
  int v60; // r3
  int v61; // r1
  int v62; // r3
  int v63; // r0
  int v64; // r3
  char *v65; // r1
  int v66; // r3
  int v67; // r0
  int v68; // r0
  unsigned int v69; // r9
  int v70; // r2
  int v71; // r10
  int v72; // r4
  int v73; // [sp+18h] [bp-80h]
  int v74; // [sp+1Ch] [bp-7Ch]
  int v75; // [sp+20h] [bp-78h]
  int v76; // [sp+24h] [bp-74h]
  int v77; // [sp+28h] [bp-70h]
  int v78; // [sp+2Ch] [bp-6Ch]
  int v79; // [sp+30h] [bp-68h] BYREF
  _WORD *v80; // [sp+34h] [bp-64h]
  int v81; // [sp+38h] [bp-60h]
  int v82; // [sp+3Ch] [bp-5Ch]
  int v83; // [sp+40h] [bp-58h]
  int v84; // [sp+44h] [bp-54h]
  unsigned int v85; // [sp+48h] [bp-50h]
  int v86; // [sp+4Ch] [bp-4Ch] BYREF
  int v87; // [sp+50h] [bp-48h] BYREF
  int v88; // [sp+54h] [bp-44h]
  unsigned __int8 *v89; // [sp+58h] [bp-40h]
  int v90; // [sp+5Ch] [bp-3Ch]
  int v91; // [sp+60h] [bp-38h]
  int v92[2]; // [sp+68h] [bp-30h] BYREF
  int v93; // [sp+70h] [bp-28h]

  v90 = a2;
  v14 = 0;
  v91 = 0;
  v86 = 0;
  v87 = 0;
  v84 = 0;
  v85 = 0;
  v79 = 0;
  v80 = 0;
  v88 = 0;
  v89 = 0;
  v15 = 0;
  v77 = 0;
  v78 = 0;
  v16 = 0;
  v81 = 0;
  v73 = 0;
  v74 = 0;
  v17 = 0;
  v75 = 0;
  v76 = 0;
  v83 = 0;
  v18 = SeCaptureSubjectContext(v92);
  v82 = v92[0];
  if ( !v92[0] )
  {
    v82 = v93;
    if ( !v93 )
      return sub_7DC6CC(v18);
  }
  v20 = SepAdtAuditThisEventWithContext(0x8Cu, 1, 0, v92);
  if ( v20 && a11 )
    v15 = a8 & 0x20;
  if ( (a7 & 0x1000000) != 0 )
  {
    if ( SepAdtAuditThisEventWithContext(0x8Au, 1, 0, v92) )
      v15 |= a8 & 8;
    if ( v20 && a12 )
      v15 |= a8 & 0x40;
  }
  if ( a3 && *a3 )
  {
    v80 = a3;
  }
  else if ( v90 )
  {
    v88 = SepQueryTypeString(v90, &v79);
    if ( v88 < 0 )
    {
      v32 = v79;
LABEL_221:
      if ( v32 )
        ExFreePoolWithTag(v32);
      goto LABEL_32;
    }
    v85 = v79;
    if ( v79 )
      v80 = (_WORD *)v79;
  }
  v21 = a10;
  v22 = a7 & 0xFEFFFFFF;
  if ( (a7 & 0xFEFFFFFF) != 0 )
  {
    if ( (*(_WORD *)(a10 + 2) & 0x10) == 0 )
      goto LABEL_62;
    if ( (*(_WORD *)(a10 + 2) & 0x8000) == 0 )
    {
      v34 = *(_DWORD *)(a10 + 12);
      goto LABEL_64;
    }
    v33 = *(_DWORD *)(a10 + 12);
    if ( v33 )
      v34 = v33 + a10;
    else
LABEL_62:
      v34 = 0;
LABEL_64:
    SeMaximumAuditMask(v34, v22, v82, &v86);
    SeMaximumAuditMaskFromGlobalSacl(v80, v22, v82, &v86);
    v21 = a10;
    v91 = v86;
    if ( (v86 & 0x80000) != 0 && v20 )
      v15 |= a8 & 0x10;
  }
  v23 = (_DWORD *)a13;
  v24 = *(unsigned __int16 *)(a13 + 2);
  v79 = v24;
  if ( (v24 & 0x10) == 0 )
  {
LABEL_39:
    v26 = 0;
    goto LABEL_17;
  }
  if ( (v24 & 0x8000) != 0 )
  {
    v25 = *(_DWORD *)(a13 + 12);
    if ( v25 )
    {
      v26 = v25 + a13;
      goto LABEL_17;
    }
    goto LABEL_39;
  }
  v26 = *(_DWORD *)(a13 + 12);
LABEL_17:
  if ( !v21 )
    goto LABEL_22;
  if ( (*(_WORD *)(v21 + 2) & 0x10) == 0 )
    goto LABEL_21;
  if ( (*(_WORD *)(v21 + 2) & 0x8000) != 0 )
  {
    v27 = *(_DWORD *)(v21 + 12);
    if ( !v27 )
    {
LABEL_21:
      v17 = 0;
      goto LABEL_22;
    }
    v17 = v27 + v21;
  }
  else
  {
    v17 = *(_DWORD *)(v21 + 12);
  }
LABEL_22:
  v28 = a9;
  if ( a9 )
  {
    if ( (*(_WORD *)(a9 + 2) & 0x10) == 0 )
      goto LABEL_72;
    if ( (*(_WORD *)(a9 + 2) & 0x8000) == 0 )
    {
      v16 = *(_DWORD *)(a9 + 12);
      goto LABEL_23;
    }
    v35 = *(_DWORD *)(a9 + 12);
    if ( v35 )
      v16 = v35 + a9;
    else
LABEL_72:
      v16 = 0;
  }
LABEL_23:
  if ( !a11 || (*(_WORD *)(a11 + 2) & 0x10) == 0 )
    goto LABEL_24;
  if ( (*(_WORD *)(a11 + 2) & 0x8000) != 0 )
  {
    v31 = *(_DWORD *)(a11 + 12);
    if ( v31 )
    {
      v29 = a11 + v31;
      goto LABEL_25;
    }
LABEL_24:
    v29 = 0;
    goto LABEL_25;
  }
  v29 = *(_DWORD *)(a11 + 12);
  if ( !a12 || (*(_WORD *)(a12 + 2) & 0x10) == 0 )
    goto LABEL_26;
LABEL_25:
  if ( (*(_WORD *)(a12 + 2) & 0x8000) == 0 )
  {
    v30 = *(_DWORD *)(a12 + 12);
    goto LABEL_27;
  }
  v36 = *(_DWORD *)(a12 + 12);
  if ( v36 )
    v30 = a12 + v36;
  else
LABEL_26:
    v30 = 0;
LABEL_27:
  if ( v26 && *(_WORD *)(v26 + 4) )
  {
    if ( !v15 )
      goto LABEL_30;
    v37 = (unsigned __int8 *)(v26 + 8);
    if ( v17 )
    {
      v38 = *(unsigned __int16 *)(v17 + 4);
      if ( *(_WORD *)(v17 + 4) )
      {
        v89 = (unsigned __int8 *)(v17 + 8);
        v73 = v38;
      }
    }
    if ( v16 && *(_WORD *)(v16 + 4) )
    {
      v39 = v16 + 8;
      v74 = v16 + 8;
      v81 = *(unsigned __int16 *)(v16 + 4);
    }
    else
    {
      v39 = 0;
    }
    if ( v29 && *(_WORD *)(v29 + 4) )
    {
      v40 = v29 + 8;
      v78 = v29 + 8;
      v75 = *(unsigned __int16 *)(v29 + 4);
    }
    else
    {
      v40 = 0;
    }
    if ( v30 && *(_WORD *)(v30 + 4) )
    {
      v41 = v30 + 8;
      v76 = v30 + 8;
      v83 = *(unsigned __int16 *)(v30 + 4);
    }
    else
    {
      v41 = 0;
    }
    v42 = *(unsigned __int16 *)(v26 + 4);
    v43 = v89;
    v44 = 0;
    while ( 1 )
    {
      v45 = *v37;
      switch ( v45 )
      {
        case 17:
          if ( (v15 & 0x10) != 0 )
          {
            if ( v39 )
            {
              v51 = *(unsigned __int16 *)(v39 + 2);
              if ( *((unsigned __int16 *)v37 + 1) == v51 && RtlCompareMemory(v37, v74, v51) == v51 )
              {
                v47 = v75;
                v41 = v76;
                v40 = v78;
                v52 = v81 == 1;
                v48 = v73;
                --v81;
                if ( v52 )
                {
                  v39 = 0;
                  v74 = 0;
                }
                else
                {
                  v74 += v51;
                  v39 = v74;
                }
                v44 = v77;
                goto LABEL_142;
              }
              v39 = v74;
            }
            v41 = v76;
            v40 = v78;
            v14 |= 0x10u;
            v15 &= 0xFFFFFFEF;
            goto LABEL_140;
          }
          break;
        case 18:
          if ( (v15 & 0x20) != 0 )
          {
            if ( v40 )
            {
              v50 = *(unsigned __int16 *)(v40 + 2);
              if ( *((unsigned __int16 *)v37 + 1) == v50 )
              {
                if ( RtlCompareMemory(v37, v40, *(unsigned __int16 *)(v40 + 2)) == v50 )
                {
                  v41 = v76;
                  v48 = v73;
                  v47 = (unsigned __int16)(v75 - 1);
                  v44 = v77;
                  v75 = v47;
                  if ( v47 )
                    v40 = v78 + v50;
                  else
                    v40 = 0;
                  v78 = v40;
                  goto LABEL_108;
                }
                v40 = v78;
              }
            }
            v41 = v76;
            v14 |= 0x20u;
            v15 &= 0xFFFFFFDF;
            goto LABEL_115;
          }
          break;
        case 19:
          if ( (v15 & 0x40) != 0 )
          {
            if ( v41 )
            {
              v49 = *(unsigned __int16 *)(v41 + 2);
              if ( *((unsigned __int16 *)v37 + 1) == v49 )
              {
                if ( RtlCompareMemory(v37, v41, *(unsigned __int16 *)(v41 + 2)) == v49 )
                {
                  v40 = v78;
                  v48 = v73;
                  v47 = v75;
                  v83 = (unsigned __int16)(v83 - 1);
                  v44 = v77;
                  if ( v83 )
                    v41 = v76 + v49;
                  else
                    v41 = 0;
                  v76 = v41;
                  goto LABEL_108;
                }
                v41 = v76;
              }
            }
            v14 |= 0x40u;
            v15 &= 0xFFFFFFBF;
            goto LABEL_112;
          }
          break;
        default:
          if ( (v15 & 8) != 0 )
          {
            if ( v43 )
            {
              if ( *v43 == v45 )
              {
                v46 = *((unsigned __int16 *)v43 + 1);
                if ( *((unsigned __int16 *)v37 + 1) == v46
                  && RtlCompareMemory(v37, (int)v43, *((unsigned __int16 *)v43 + 1)) == v46 )
                {
                  v47 = v75;
                  v41 = v76;
                  v40 = v78;
                  v48 = (unsigned __int16)(v73 - 1);
                  v44 = v77;
                  v73 = v48;
                  if ( v48 )
                    v43 += v46;
                  else
                    v43 = 0;
LABEL_108:
                  v39 = v74;
                  goto LABEL_142;
                }
              }
            }
            v41 = v76;
            v14 |= 8u;
            v15 &= 0xFFFFFFF7;
LABEL_112:
            v40 = v78;
LABEL_115:
            v39 = v74;
LABEL_140:
            v44 = v77;
            break;
          }
          break;
      }
      v47 = v75;
      v48 = v73;
LABEL_142:
      v77 = v44 + 1;
      v37 += *((unsigned __int16 *)v37 + 1);
      if ( ++v44 >= v42 || !v15 )
      {
        v28 = a9;
        if ( v48 )
          v14 |= v15 & 8;
        if ( v47 )
          v14 |= v15 & 0x20;
        if ( v83 )
          v14 |= v15 & 0x40;
        v23 = (_DWORD *)a13;
        LOWORD(v24) = v79;
        if ( v81 )
        {
          v53 = v15 & 0x10;
          goto LABEL_160;
        }
        goto LABEL_30;
      }
    }
  }
  if ( v17 && *(_WORD *)(v17 + 4) )
    v14 = v15 & 8;
  if ( v16 && *(_WORD *)(v16 + 4) )
    v14 |= v15 & 0x10;
  if ( v29 && *(_WORD *)(v29 + 4) )
    v14 |= v15 & 0x20;
  if ( v30 && *(_WORD *)(v30 + 4) )
  {
    v53 = v15 & 0x40;
LABEL_160:
    v14 |= v53;
  }
LABEL_30:
  if ( v28 )
  {
    v54 = v91;
    if ( (v91 & 0x80000) != 0 )
    {
      if ( (a8 & 1) != 0 )
      {
        if ( (v24 & 0x8000) != 0 )
        {
          v55 = v23[1];
          v56 = (int)(v55 ? (_DWORD *)((char *)v23 + v55) : 0);
        }
        else
        {
          v56 = v23[1];
        }
        if ( (*(_WORD *)(v28 + 2) & 0x8000) != 0 )
        {
          v57 = *(_DWORD *)(v28 + 4);
          v58 = v57 ? v57 + v28 : 0;
        }
        else
        {
          v58 = *(_DWORD *)(v28 + 4);
        }
        if ( !SepIsSidEqual(v58, v56) )
          v14 |= 1u;
      }
      v59 = v79;
      if ( (a8 & 2) != 0 )
      {
        if ( (v79 & 0x8000) != 0 )
        {
          v60 = v23[2];
          v61 = (int)(v60 ? (_DWORD *)((char *)v23 + v60) : 0);
        }
        else
        {
          v61 = v23[2];
        }
        if ( (*(_WORD *)(v28 + 2) & 0x8000) != 0 )
        {
          v62 = *(_DWORD *)(v28 + 8);
          v63 = v62 ? v62 + v28 : 0;
        }
        else
        {
          v63 = *(_DWORD *)(v28 + 8);
        }
        if ( !SepIsSidEqual(v63, v61) )
          v14 |= 2u;
      }
    }
    else
    {
      v59 = v79;
    }
    if ( (v54 & 0x40000) != 0 )
    {
      if ( (v59 & 4) != 0 )
      {
        if ( (v59 & 0x8000) == 0 )
        {
          v65 = (char *)v23[4];
LABEL_196:
          if ( (*(_WORD *)(v28 + 2) & 4) != 0 )
          {
            if ( (*(_WORD *)(v28 + 2) & 0x8000) == 0 )
            {
              v67 = *(_DWORD *)(v28 + 16);
LABEL_202:
              if ( !SepIsAclEqual(v67, v65) )
                v14 |= 4u;
              goto LABEL_31;
            }
            v66 = *(_DWORD *)(v28 + 16);
            if ( v66 )
            {
              v67 = v66 + v28;
              goto LABEL_202;
            }
          }
          v67 = 0;
          goto LABEL_202;
        }
        v64 = v23[4];
        if ( v64 )
        {
          v65 = (char *)v23 + v64;
          goto LABEL_196;
        }
      }
      v65 = 0;
      goto LABEL_196;
    }
  }
LABEL_31:
  if ( v14 )
  {
    if ( v90 )
    {
      v68 = SepQueryNameString(v90, &v87);
      v69 = v87;
      v88 = v68;
      if ( v68 < 0 )
      {
LABEL_218:
        if ( v69 )
          ExFreePoolWithTag(v69);
        v32 = v85;
        goto LABEL_221;
      }
      if ( v87 )
      {
        v70 = v87;
        v84 = v87;
LABEL_210:
        v71 = (int)v80;
        v72 = **(_DWORD **)(v82 + 148);
        if ( (v14 & 8) != 0 )
          SepAdtSecurityDescriptorChangedAuditAlarm(v92, &SeSubsystemName, v80, v70, a5, v72, a10, 8, a13);
        if ( (v14 & 0x20) != 0 )
          SepAdtSecurityDescriptorChangedAuditAlarm(v92, &SeSubsystemName, v71, v84, a5, v72, a11, 32, a13);
        if ( (v14 & 0x40) != 0 )
          SepAdtSecurityDescriptorChangedAuditAlarm(v92, &SeSubsystemName, v71, v84, a5, v72, a12, 64, a13);
        if ( (v14 & 0xFFFFFF97) != 0 )
          SepAdtSecurityDescriptorChangedAuditAlarm(
            v92,
            &SeSubsystemName,
            v71,
            v84,
            a5,
            v72,
            v28,
            v14 & 0xFFFFFF97,
            a13);
        goto LABEL_218;
      }
    }
    else
    {
      v69 = 0;
    }
    v70 = 0;
    goto LABEL_210;
  }
LABEL_32:
  if ( v88 < 0 )
    SepAuditFailed(v88);
  return SeReleaseSubjectContext((int)v92);
}
