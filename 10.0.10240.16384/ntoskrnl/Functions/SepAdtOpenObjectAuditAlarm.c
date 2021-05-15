// SepAdtOpenObjectAuditAlarm 
 
int __fastcall SepAdtOpenObjectAuditAlarm(unsigned int a1, __int16 *a2, int *a3, unsigned __int16 *a4, unsigned __int16 *a5, int a6, int a7, int a8, int a9, int a10, _DWORD *a11, unsigned __int8 a12, int a13, int a14, int a15, unsigned int a16, int a17, int a18, int a19)
{
  int v21; // r5
  int v22; // r2
  int v23; // r10
  unsigned int v24; // r8
  int v25; // r6
  unsigned int v26; // r3
  int v27; // r3
  __int16 v28; // r3
  int v29; // r3
  int v30; // r3
  int v31; // r2
  int v32; // r4
  int v33; // r7
  int v34; // r9
  int v36; // r3
  int v37; // r3
  int v38; // r3
  int v39; // r0
  int v40; // r0
  int v41; // r2
  int v42; // r1
  int v43; // r3
  int v44; // r7
  unsigned int *v45; // r0
  unsigned int *v46; // r8
  int v47; // r3
  int v48; // r3
  unsigned int v49; // r4
  int v50; // r3
  int v51; // r3
  int v52; // r4
  int *v53; // r3
  int v54; // r2
  unsigned int v55; // r1
  unsigned __int16 *v56; // r0
  unsigned int v57; // r2
  unsigned __int16 v58; // r10
  unsigned int v59; // lr
  unsigned __int16 *v60; // r7
  int v61; // r5
  int v62; // r1
  int v63; // r2
  int v64; // r3
  unsigned int v65; // r3
  unsigned int v66; // r7
  unsigned __int16 *v67; // r0
  int v68; // r4
  int v69; // r0
  int v70; // r0
  unsigned __int8 v71; // [sp+0h] [bp-348h] BYREF
  unsigned __int8 v72; // [sp+1h] [bp-347h] BYREF
  char v73[2]; // [sp+2h] [bp-346h] BYREF
  unsigned __int16 *v74; // [sp+4h] [bp-344h]
  unsigned int v75; // [sp+8h] [bp-340h]
  unsigned int v76; // [sp+Ch] [bp-33Ch]
  int v77; // [sp+10h] [bp-338h]
  unsigned int v78; // [sp+14h] [bp-334h] BYREF
  int v79; // [sp+18h] [bp-330h]
  unsigned int v80; // [sp+1Ch] [bp-32Ch]
  int v81; // [sp+20h] [bp-328h] BYREF
  int v82; // [sp+24h] [bp-324h] BYREF
  unsigned int v83; // [sp+28h] [bp-320h] BYREF
  unsigned int v84; // [sp+2Ch] [bp-31Ch] BYREF
  int v85; // [sp+30h] [bp-318h]
  unsigned int *v86; // [sp+38h] [bp-310h]
  int v87; // [sp+3Ch] [bp-30Ch]
  int *v88; // [sp+40h] [bp-308h]
  unsigned __int16 *v89; // [sp+44h] [bp-304h]
  int v90; // [sp+48h] [bp-300h]
  unsigned int *v91; // [sp+4Ch] [bp-2FCh]
  int v92; // [sp+50h] [bp-2F8h]
  int v93; // [sp+54h] [bp-2F4h]
  int v94; // [sp+58h] [bp-2F0h]
  _DWORD *v95; // [sp+5Ch] [bp-2ECh]
  int v96; // [sp+60h] [bp-2E8h]
  unsigned int v97; // [sp+64h] [bp-2E4h]
  int v98; // [sp+68h] [bp-2E0h]
  int v99[2]; // [sp+70h] [bp-2D8h] BYREF
  int v100; // [sp+78h] [bp-2D0h]
  int v101; // [sp+7Ch] [bp-2CCh]
  int v102[166]; // [sp+80h] [bp-2C8h] BYREF
  _DWORD v103[12]; // [sp+318h] [bp-30h] BYREF

  v88 = a3;
  v89 = a4;
  v21 = a6;
  v22 = 0;
  v74 = 0;
  v75 = 0;
  v83 = 0;
  v84 = 0;
  v23 = 0;
  v90 = 0;
  v80 = 0;
  v81 = 0;
  v24 = 0;
  if ( !a12 )
    v22 = 1;
  v99[1] = 0;
  v100 = 0;
  if ( a12 )
    v22 = 0;
  v85 = a8;
  v86 = 0;
  v87 = 0;
  v100 = a8;
  v101 = 0;
  v103[0] = 0;
  v103[1] = 0;
  v103[2] = 0;
  v103[3] = 0;
  v76 = 0;
  v77 = 0;
  v78 = 0;
  v79 = 0;
  v71 = 0;
  v72 = 0;
  v73[0] = 0;
  v97 = a1;
  v94 = a6;
  v82 = a6;
  v99[0] = a7;
  if ( !SepAdtAuditThisEventWithContext(0x7Bu, a12, v22, v99)
    && !SepAdtAuditThisEventWithContext(a1, a12, a12 == 0, v99) )
  {
    return 1;
  }
  v95 = (_DWORD *)a18;
  if ( !a18 )
    v95 = v103;
  v25 = SeLocateProcessImageName(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74));
  v26 = (unsigned int)v74;
  v92 = v25;
  if ( v25 < 0 )
    goto LABEL_26;
  if ( a7 )
  {
    v96 = **(_DWORD **)(a7 + 148);
    v91 = *(unsigned int **)(a7 + 24);
    v93 = *(_DWORD *)(a7 + 28);
  }
  else
  {
    v96 = **(_DWORD **)(v85 + 148);
    v93 = v87;
    v91 = v86;
  }
  v98 = *(_DWORD *)(v85 + 24);
  v86 = *(unsigned int **)(v85 + 28);
  memset(v102, 0, sizeof(v102));
  if ( a14 == 2 )
    v27 = 3;
  else
    v27 = 8;
  v102[0] = v27;
  v102[1] = 4656;
  if ( a12 )
    v28 = 8;
  else
    v28 = 16;
  HIWORD(v102[4]) = v28;
  LOWORD(v102[4]) = v97;
  if ( !a2 )
    a2 = &SeSubsystemName;
  v102[6] = 4;
  v29 = *(unsigned __int8 *)(v96 + 1);
  v102[10] = v96;
  v102[15] = (int)a2;
  v102[7] = 4 * (v29 + 2);
  v102[11] = 1;
  v30 = (unsigned __int16)*a2 + 8;
  v102[12] = v30;
  v102[16] = 5;
  v102[17] = 8;
  if ( a7 )
  {
    v102[18] = (int)v91;
    v31 = v93;
  }
  else
  {
    v102[18] = v98;
    v31 = (int)v86;
  }
  v102[19] = v31;
  v102[21] = 1;
  v102[22] = v30;
  v102[25] = (int)a2;
  v102[2] = 4;
  if ( !v89 )
  {
    v25 = -1073741811;
    v26 = (unsigned int)v74;
LABEL_26:
    v32 = 0;
LABEL_27:
    v33 = 0;
LABEL_28:
    v34 = 0;
    goto LABEL_29;
  }
  v102[26] = 1;
  v36 = *v89;
  v102[30] = (int)v89;
  v102[27] = v36 + 8;
  if ( a5 )
  {
    if ( v97 == 116 || v97 == 128 )
      v37 = 2;
    else
      v37 = 1;
    v102[31] = v37;
    v38 = *a5;
    v102[35] = (int)a5;
    v102[32] = v38 + 8;
  }
  if ( v88 )
  {
    v39 = *v88;
    v102[36] = 11;
    v102[37] = 4;
    v102[38] = ObNormalizeHandleValue(v39);
  }
  else
  {
    v102[36] = 11;
    v102[37] = 4;
    v102[38] = 0;
  }
  v102[41] = 13;
  v102[42] = 16;
  v102[45] = (int)v95;
  if ( a12 )
  {
    v102[46] = 7;
    v102[47] = 4;
    v102[48] = a10;
  }
  else
  {
    v102[46] = 7;
    v102[47] = 4;
    v102[48] = a9;
  }
  v102[49] = 4;
  v102[2] = 9;
  if ( a19 && (v40 = *(_DWORD *)(a19 + 48)) != 0 )
  {
    v25 = SepCheckAndCopySelfRelativeSD(*(_DWORD *)(v40 + 48), &v81, &v78, &v71);
    if ( v25 < 0 )
    {
      v23 = v81;
      v32 = v71;
      v26 = (unsigned int)v74;
      goto LABEL_27;
    }
    v25 = SepCheckAndCopySelfRelativeSD(*(_DWORD *)(*(_DWORD *)(a19 + 48) + 52), (int *)&v83, &v84, &v72);
    v24 = v83;
    v23 = v81;
    v92 = v25;
    if ( v25 < 0 )
    {
      v32 = v71;
      v33 = v72;
LABEL_63:
      v26 = (unsigned int)v74;
      goto LABEL_28;
    }
    v80 = v83;
    v90 = v81;
    if ( v81 || v83 )
    {
      v41 = v78;
      v42 = v84;
      v76 = v78;
      v77 = v71;
      v43 = 4;
      v75 = v84;
      v79 = v72;
      goto LABEL_67;
    }
    v41 = v78;
    v42 = v84;
    v76 = v78;
    v77 = v71;
    v75 = v84;
    v79 = v72;
  }
  else
  {
    v41 = 0;
    v42 = 0;
  }
  v43 = 0;
LABEL_67:
  v44 = v42 - v43 + v41 + 144;
  v45 = (unsigned int *)ExAllocatePoolWithTag(1, v44, 1883333971);
  v46 = v45;
  v86 = v45;
  if ( !v45 )
  {
    v25 = -1073741670;
    v33 = v79;
    v24 = v80;
    v32 = v77;
    goto LABEL_63;
  }
  memset(v45, 0, v44);
  v46[33] = 4;
  v46[34] = a12;
  if ( a12 )
    v47 = a10;
  else
    v47 = a9;
  *v46 = v47 & 0xFDFFFFFF;
  if ( a19 )
  {
    v48 = *(_DWORD *)(a19 + 48);
    if ( v48 )
      memmove((int)(v46 + 1), v48 + 64, 0x80u);
  }
  v49 = v76;
  if ( v23 )
    memmove((int)(v46 + 35), v23, v76);
  if ( v80 )
    memmove((int)v46 + v49 + 140, v80, v75);
  v102[51] = 29;
  v102[52] = v44;
  v102[55] = (int)v46;
  v102[56] = 10;
  v102[57] = 4;
  if ( a12 )
    v50 = a10;
  else
    v50 = a9;
  v102[58] = v50;
  if ( a11 && *a11 )
  {
    v51 = 12 * (*a11 - 1) + 20;
    v102[61] = 8;
    v102[62] = v51;
    v102[65] = (int)a11;
  }
  v52 = 12;
  v102[2] = 12;
  if ( !a16 )
    goto LABEL_109;
  v53 = (int *)(a12 ? 1 : 2);
  v54 = 0;
  v55 = 0;
  v88 = v53;
  do
  {
    if ( !v55 || (*(_WORD *)(a15 + 44 * v55 + 2) & (unsigned __int16)v53) != 0 )
      ++v54;
    ++v55;
  }
  while ( v55 < a16 );
  v21 = v94;
  if ( !v54 )
  {
LABEL_109:
    v66 = 0;
    goto LABEL_110;
  }
  v56 = (unsigned __int16 *)ExAllocatePoolWithTag(1, 24 * v54, 1883333971);
  v89 = v56;
  if ( v56 )
  {
    v57 = a16;
    v58 = (unsigned __int16)v88;
    v75 = 0;
    v59 = 0;
    v60 = v56;
    do
    {
      if ( v59 && (*(_WORD *)(a15 + 44 * v59 + 2) & v58) == 0 )
      {
        v65 = v75;
      }
      else
      {
        v61 = a15 + 44 * v59;
        v62 = *(_DWORD *)(v61 + 8);
        v63 = *(_DWORD *)(v61 + 12);
        v64 = *(_DWORD *)(v61 + 16);
        *(_DWORD *)v60 = *(_DWORD *)(v61 + 4);
        *((_DWORD *)v60 + 1) = v62;
        *((_DWORD *)v60 + 2) = v63;
        *((_DWORD *)v60 + 3) = v64;
        v60[9] = *(_WORD *)v61;
        if ( v59 )
        {
          v60[8] = 0;
          if ( a17 && a12 )
            *((_DWORD *)v60 + 5) = *(_DWORD *)(a17 + 4 * v59);
        }
        else
        {
          v60[8] = 1;
          *((_DWORD *)v60 + 5) = 0;
        }
        v57 = a16;
        v65 = ++v75;
        v60 += 12;
      }
      ++v59;
    }
    while ( v59 < v57 );
    v102[67] = 24 * v65;
    v66 = (unsigned int)v89;
    v23 = v90;
    v102[69] = 4;
    v102[70] = (int)v89;
    v52 = 13;
    v25 = v92;
    v46 = v86;
    v21 = v94;
    v102[1] = 4661;
    v102[2] = 13;
    v102[66] = 9;
LABEL_110:
    v102[5 * v52 + 6] = 27;
    v67 = v74;
    v102[5 * v102[2] + 7] = 4;
    v102[5 * v102[2]++ + 8] = *(_DWORD *)(v85 + 128);
    v102[5 * v102[2] + 6] = 11;
    v102[5 * v102[2] + 7] = 4;
    v102[5 * v102[2]++ + 8] = a13;
    v102[5 * v102[2] + 6] = 2;
    v102[5 * v102[2] + 7] = *v67 + 8;
    v102[5 * v102[2] + 10] = (int)v67;
    v68 = ++v102[2];
    if ( (v97 == 116 || v97 == 128) && v21 && v102[1] == 4656 && SepSDContainsAttributeACE(v21) )
    {
      v25 = SepCheckAndCopySelfRelativeSD(v21, &v82, &v78, v73);
      v21 = v82;
      if ( v25 < 0 )
      {
        v34 = (unsigned __int8)v73[0];
        goto LABEL_120;
      }
      v69 = v82;
      v102[5 * v68 + 6] = 31;
      v70 = SepSecurityDescriptorStrictLength(v69);
      v34 = (unsigned __int8)v73[0];
      v102[5 * v102[2] + 7] = v70;
      v102[5 * v102[2] + 10] = v21;
      v102[5 * v102[2] + 8] = 32;
      v102[5 * v102[2] + 9] = 0;
      v68 = v102[2];
    }
    else
    {
      v34 = 0;
    }
    v102[2] = v68 + 1;
    SepAdtLogAuditRecord((int)v102);
LABEL_120:
    if ( v66 )
      ExFreePoolWithTag(v66);
    goto LABEL_122;
  }
  v25 = -1073741670;
  v34 = 0;
LABEL_122:
  ExFreePoolWithTag((unsigned int)v46);
  v33 = v79;
  v24 = v80;
  v32 = v77;
  v26 = (unsigned int)v74;
LABEL_29:
  if ( v26 )
    ExFreePoolWithTag(v26);
  if ( v34 && v21 )
    ExFreePoolWithTag(v21);
  if ( v32 && v23 )
    ExFreePoolWithTag(v23);
  if ( v33 )
  {
    if ( v24 )
      ExFreePoolWithTag(v24);
  }
  if ( v25 < 0 )
  {
    SepAuditFailed();
    return 0;
  }
  return 1;
}
