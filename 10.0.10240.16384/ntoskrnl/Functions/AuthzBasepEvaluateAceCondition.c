// AuthzBasepEvaluateAceCondition 
 
int __fastcall AuthzBasepEvaluateAceCondition(int a1, int a2, int a3, int a4, int a5, int a6, int a7, _DWORD *a8, unsigned int a9, unsigned __int8 a10, unsigned __int8 a11, int *a12)
{
  int v12; // r6
  int *v13; // r8
  int v15; // r7
  int v16; // r9
  int v17; // r10
  unsigned int v19; // r5
  unsigned int v20; // r10
  int v21; // r8
  int v22; // r4
  unsigned int v23; // r5
  unsigned int v24; // r2
  unsigned int v25; // r5
  int *v26; // r6
  int v27; // r3
  int *v28; // r8
  int v29; // r7
  int *v30; // r8
  int v31; // r3
  int v32; // r3
  unsigned int v33; // r4
  int *v34; // r5
  int v35; // r4
  int v36; // r2
  bool v37; // zf
  int v38; // r0
  int v39; // r0
  int v40; // r2
  int v41; // r0
  int v42; // r0
  int v43; // r0
  int v44; // r4
  int v45; // r2
  BOOL v46; // r2
  int v47; // r0
  int v48; // r3
  BOOL v49; // r2
  int v50; // r0
  int v51; // r3
  int v52; // r0
  int v53; // r8
  int v54; // r0
  int v55; // r2
  int v56; // r8
  int v57; // r3
  int v58; // r3
  int v59; // r0
  char v60[4]; // [sp+8h] [bp-518h] BYREF
  unsigned __int8 v61; // [sp+Ch] [bp-514h] BYREF
  unsigned __int8 v62; // [sp+Dh] [bp-513h]
  int v63; // [sp+10h] [bp-510h]
  int v64; // [sp+14h] [bp-50Ch]
  int v65; // [sp+18h] [bp-508h] BYREF
  int *v66; // [sp+1Ch] [bp-504h]
  char v67[4]; // [sp+20h] [bp-500h] BYREF
  int v68; // [sp+24h] [bp-4FCh] BYREF
  int v69; // [sp+28h] [bp-4F8h]
  int v70; // [sp+2Ch] [bp-4F4h]
  int v71; // [sp+30h] [bp-4F0h] BYREF
  int v72; // [sp+34h] [bp-4ECh]
  int v73; // [sp+38h] [bp-4E8h] BYREF
  int v74; // [sp+3Ch] [bp-4E4h]
  int v75; // [sp+40h] [bp-4E0h] BYREF
  int v76; // [sp+44h] [bp-4DCh]
  int v77[12]; // [sp+48h] [bp-4D8h] BYREF
  int v78; // [sp+78h] [bp-4A8h] BYREF
  int v79; // [sp+7Ch] [bp-4A4h]
  int v80; // [sp+80h] [bp-4A0h] BYREF
  int v81; // [sp+84h] [bp-49Ch]
  int v82; // [sp+88h] [bp-498h]
  _DWORD *v83; // [sp+8Ch] [bp-494h]
  int v84; // [sp+90h] [bp-490h]
  int v85; // [sp+94h] [bp-48Ch]
  __int16 v86; // [sp+98h] [bp-488h] BYREF
  int v87[6]; // [sp+9Ch] [bp-484h] BYREF
  int v88; // [sp+B8h] [bp-468h] BYREF
  int v89; // [sp+BCh] [bp-464h] BYREF
  int v90; // [sp+C0h] [bp-460h]
  int v91; // [sp+C4h] [bp-45Ch]
  int v92; // [sp+C8h] [bp-458h]
  int v93; // [sp+CCh] [bp-454h]
  int v94; // [sp+D0h] [bp-450h]
  int v95; // [sp+D4h] [bp-44Ch]
  int v96; // [sp+D8h] [bp-448h]
  int v97[9]; // [sp+DCh] [bp-444h] BYREF
  int v98[264]; // [sp+100h] [bp-420h] BYREF

  v12 = (int)a8;
  v13 = a12;
  v84 = a3;
  v85 = a4;
  v72 = a2;
  v88 = 0;
  v81 = a1;
  v83 = a8;
  v66 = a12;
  v15 = 0;
  v68 = 0;
  LOWORD(v89) = 0;
  memset((_BYTE *)&v89 + 2, 0, 66);
  v76 = 0;
  LOWORD(v75) = 0;
  memset(v77, 0, sizeof(v77));
  v86 = 0;
  memset(v87, 0, sizeof(v87));
  v80 = 0;
  v16 = 0;
  v63 = 0;
  v64 = 0;
  v17 = 0;
  v71 = 0;
  v87[2] = 1;
  v65 = -1;
  v73 = 0;
  v74 = 0;
  v78 = 0;
  v61 = 0;
  v62 = 0;
  v67[0] = 0;
  v60[0] = 0;
  v82 = 0;
  *a12 = -1;
  v90 = 0;
  v97[2] = 0;
  if ( !a1 || !a8 )
  {
    v15 = -1073741811;
    goto LABEL_37;
  }
  if ( (unsigned int)KeGetCurrentIrql() >= 2 )
    return sub_517578();
  v79 = 0;
  if ( a9 < 4 )
  {
    *a12 = 1;
    v15 = -2147483601;
LABEL_210:
    v16 = 0;
    goto LABEL_37;
  }
  if ( *a8 != 2020897377 )
  {
    *a12 = 1;
    v15 = -2147483601;
    goto LABEL_210;
  }
  AuthzBasepResetOperands(&v75, &v61);
  v19 = 4;
  v20 = 0;
  if ( a9 <= 4 )
  {
    v17 = 0;
    goto LABEL_210;
  }
  v21 = v61;
  v69 = v61;
  v70 = v62;
  while ( 1 )
  {
    v22 = *(unsigned __int8 *)(v12 + v19);
    if ( v22 == 248 )
      goto LABEL_10;
    if ( v22 == 162 )
    {
      ++v19;
      if ( !AuthzBasepIsValidExpression(162, (int)&v75, v20, v60) )
        goto LABEL_62;
      if ( v20 == 1 )
      {
        v35 = AuthzBasepEvaluateAttribute(v77[2]);
        v65 = v35;
        AuthzBasepResetOperands(&v75, &v61);
      }
      else
      {
        v15 = AuthzBasepPopResult(v98, &v68, &v65);
        if ( v15 < 0 )
          goto LABEL_100;
        v35 = v65;
      }
      if ( v35 == -1 )
        v36 = -1;
      else
        v36 = v35 == 0;
      v15 = AuthzBasepPushResult((int)v98, &v68, v36);
      if ( v15 < 0 )
        goto LABEL_100;
      goto LABEL_52;
    }
    if ( *(unsigned __int8 *)(v12 + v19) > 0x8Bu )
      break;
    if ( v22 == 139 )
    {
LABEL_74:
      v42 = *(unsigned __int8 *)(v12 + v19++);
      if ( AuthzBasepIsValidExpression(v42, (int)&v75, v20, v60) )
      {
        if ( v60[0] )
        {
          v48 = v74;
        }
        else
        {
          v46 = v22 == 137 || v22 == 144;
          v47 = AuthzBasepMemberOf(&v75, v81, a10, a11, v46, v67);
          v48 = (unsigned __int8)v67[0];
          v15 = v47;
          v74 = (unsigned __int8)v67[0];
        }
        if ( v15 >= 0 )
        {
          v40 = v48 != 0;
          v65 = v40;
LABEL_123:
          if ( (v22 == 144 || v22 == 146) && v40 != -1 )
          {
            if ( v40 )
LABEL_128:
              v40 = 0;
            else
              v40 = 1;
            goto LABEL_129;
          }
          goto LABEL_69;
        }
      }
      else
      {
        v15 = -1073741406;
        if ( !v60[0] )
          goto LABEL_100;
      }
      v40 = -1;
      v65 = -1;
      goto LABEL_123;
    }
    if ( *(unsigned __int8 *)(v12 + v19) > 0x86u )
    {
      switch ( *(_BYTE *)(v12 + v19) )
      {
        case 0x87:
          goto LABEL_67;
        case 0x88:
          goto LABEL_72;
        case 0x89:
          goto LABEL_74;
        case 0x8A:
          goto LABEL_76;
        default:
          goto LABEL_62;
      }
    }
    if ( *(unsigned __int8 *)(v12 + v19) >= 0x80u )
    {
LABEL_72:
      v41 = *(unsigned __int8 *)(v12 + v19++);
      if ( AuthzBasepIsValidExpression(v41, (int)&v75, v20, v60) )
      {
        if ( !v60[0] )
        {
          AuthzBasepEvaluateExpression(v22, &v75, &v65);
          if ( v22 == 143 || v22 == 142 )
          {
            v45 = v65;
            if ( v65 != -1 )
            {
              if ( v65 )
              {
                v45 = 0;
                v65 = 0;
              }
              else
              {
                v45 = 1;
                v65 = 1;
              }
            }
          }
          else
          {
            v45 = v65;
          }
          goto LABEL_110;
        }
      }
      else
      {
        v15 = -1073741406;
        if ( !v60[0] )
          goto LABEL_100;
      }
      v45 = -1;
      v65 = -1;
LABEL_110:
      v15 = AuthzBasepPushResult((int)v98, &v68, v45);
      if ( v15 < 0 )
        goto LABEL_100;
LABEL_52:
      AuthzBasepResetOperands(&v75, &v61);
      v21 = v61;
      v20 = 0;
      v69 = v61;
      v70 = v62;
      goto LABEL_34;
    }
    if ( *(unsigned __int8 *)(v12 + v19) > 0x10u )
    {
      if ( v22 != 24 && (*(unsigned __int8 *)(v12 + v19) <= 0x4Fu || *(unsigned __int8 *)(v12 + v19) > 0x51u) )
        goto LABEL_62;
LABEL_88:
      if ( v20 == 2 )
      {
        if ( v77[1] == 1 )
          goto LABEL_62;
        v44 = v77[2];
        v65 = AuthzBasepEvaluateAttribute(v77[2]);
        v15 = AuthzBasepPushResult((int)v98, &v68, v65);
        if ( v15 < 0 )
          goto LABEL_100;
        if ( v21 )
          ExFreePoolWithTag(*(_DWORD *)(v44 + 8), 0);
        v88 = v97[0];
        v89 = v97[1];
        v90 = v97[2];
        v91 = v97[3];
        v92 = v97[4];
        v93 = v97[5];
        v94 = v97[6];
        v95 = v97[7];
        v96 = v97[8];
        v75 = v77[5];
        v76 = v77[6];
        v77[0] = v77[7];
        v77[1] = v77[8];
        v77[3] = v77[10];
        v77[4] = v77[11];
        v77[2] = (int)&v88;
        v21 = v70;
        v69 = v70;
        v61 = v70;
        v70 = 0;
        v62 = 0;
        memset(&v77[5], 0, 28);
        memset(v97, 0, sizeof(v97));
        v20 = 1;
      }
      v15 = AuthzBasepGetConstantOperand(v12 + v19, a9 - v19, &v75 + 7 * v20, &v80);
      if ( v15 < 0 )
        goto LABEL_100;
      v19 += v80;
LABEL_33:
      ++v20;
      goto LABEL_34;
    }
    if ( v22 == 16 )
      goto LABEL_88;
    if ( *(_BYTE *)(v12 + v19) )
    {
      if ( *(unsigned __int8 *)(v12 + v19) > 4u )
        goto LABEL_62;
      goto LABEL_88;
    }
    while ( 1 )
    {
      v37 = ++v19 == a9;
      if ( v19 >= a9 )
        break;
      if ( *(_BYTE *)(v12 + v19) )
      {
        v37 = v19 == a9;
        break;
      }
    }
    if ( !v37 )
    {
LABEL_62:
      v15 = -1073741406;
LABEL_100:
      v13 = v66;
      v17 = v63;
      v16 = v64;
      goto LABEL_37;
    }
LABEL_34:
    if ( v19 >= a9 )
    {
      if ( v68 == 1 )
      {
        v13 = v66;
        v17 = v63;
        v16 = v64;
        *v66 = v98[0];
        goto LABEL_37;
      }
      if ( !v68 && v20 == 1 )
      {
        v38 = AuthzBasepEvaluateAttribute(v77[2]);
        v13 = v66;
        v17 = v63;
        v16 = v64;
        *v66 = v38;
        goto LABEL_37;
      }
      goto LABEL_100;
    }
  }
  if ( *(unsigned __int8 *)(v12 + v19) <= 0xA1u )
  {
    if ( *(unsigned __int8 *)(v12 + v19) < 0xA0u )
    {
      switch ( *(_BYTE *)(v12 + v19) )
      {
        case 0x8C:
        case 0x91:
        case 0x93:
LABEL_76:
          v43 = *(unsigned __int8 *)(v12 + v19++);
          if ( !AuthzBasepIsValidExpression(v43, (int)&v75, v20, v60) )
          {
            v15 = -1073741406;
            if ( !v60[0] )
              goto LABEL_100;
LABEL_131:
            v40 = -1;
            v65 = -1;
            goto LABEL_141;
          }
          if ( v60[0] )
          {
            v51 = v74;
          }
          else
          {
            v49 = v22 == 138 || v22 == 145;
            v50 = AuthzBasepDeviceMemberOf(&v75, v81, a10, a11, v49, v67);
            v51 = (unsigned __int8)v67[0];
            v15 = v50;
            v74 = (unsigned __int8)v67[0];
          }
          if ( v15 < 0 )
            goto LABEL_131;
          v40 = v51 != 0;
          v65 = v40;
LABEL_141:
          if ( v22 != 145 && v22 != 147 || v40 == -1 )
            goto LABEL_69;
          if ( v40 )
            goto LABEL_128;
          v40 = 1;
          break;
        case 0x8D:
LABEL_67:
          v39 = *(unsigned __int8 *)(v12 + v19++);
          if ( !AuthzBasepIsValidExpression(v39, (int)&v75, v20, v60) )
            goto LABEL_62;
          v40 = v77[2] != 0;
          v65 = v40;
          if ( v22 != 141 )
            goto LABEL_69;
          if ( v77[2] )
            goto LABEL_128;
          v40 = 1;
          break;
        case 0x8E:
        case 0x8F:
          goto LABEL_72;
        case 0x90:
        case 0x92:
          goto LABEL_74;
        default:
          goto LABEL_62;
      }
LABEL_129:
      v65 = v40;
LABEL_69:
      v15 = AuthzBasepPushResult((int)v98, &v68, v40);
      if ( v15 < 0 )
        goto LABEL_100;
      goto LABEL_52;
    }
    v52 = *(unsigned __int8 *)(v12 + v19++);
    if ( !AuthzBasepIsValidExpression(v52, (int)&v75, v20, v60) )
      goto LABEL_62;
    if ( v20 == 2 )
    {
      v53 = AuthzBasepEvaluateAttribute(v77[2]);
      v73 = v53;
      v54 = AuthzBasepEvaluateAttribute(v77[9]);
      v78 = v54;
    }
    else
    {
      if ( v20 == 1 )
      {
        v53 = AuthzBasepEvaluateAttribute(v77[2]);
        v73 = v53;
      }
      else
      {
        v15 = AuthzBasepPopResult(v98, &v68, &v73);
        if ( v15 < 0 )
          goto LABEL_100;
        v53 = v73;
      }
      v15 = AuthzBasepPopResult(v98, &v68, &v78);
      if ( v15 < 0 )
        goto LABEL_100;
      v54 = v78;
    }
    if ( v22 == 160 )
    {
      if ( v53 && v54 )
      {
        if ( v53 == -1 || v54 == -1 )
        {
LABEL_162:
          v55 = -1;
          v65 = -1;
          goto LABEL_170;
        }
        goto LABEL_168;
      }
    }
    else
    {
      if ( v53 == 1 || v54 == 1 )
      {
LABEL_168:
        v55 = 1;
        goto LABEL_169;
      }
      if ( v53 == -1 || v54 == -1 )
        goto LABEL_162;
    }
    v55 = 0;
LABEL_169:
    v65 = v55;
LABEL_170:
    v15 = AuthzBasepPushResult((int)v98, &v68, v55);
    if ( v15 < 0 )
      goto LABEL_100;
    goto LABEL_52;
  }
  if ( (unsigned int)(v22 - 249) > 2 )
    goto LABEL_62;
LABEL_10:
  v23 = v19 + 1;
  if ( v20 == 2 )
  {
    if ( v77[1] == 1 )
      goto LABEL_62;
    v56 = v77[2];
    v65 = AuthzBasepEvaluateAttribute(v77[2]);
    v15 = AuthzBasepPushResult((int)v98, &v68, v65);
    if ( v15 < 0 )
      goto LABEL_100;
    if ( v69 )
      ExFreePoolWithTag(*(_DWORD *)(v56 + 8), 0);
    v88 = v97[0];
    v89 = v97[1];
    v90 = v97[2];
    v91 = v97[3];
    v92 = v97[4];
    v93 = v97[5];
    v94 = v97[6];
    v95 = v97[7];
    v96 = v97[8];
    v75 = v77[5];
    v76 = v77[6];
    v77[0] = v77[7];
    v77[1] = v77[8];
    v77[3] = v77[10];
    v77[4] = v77[11];
    v77[2] = (int)&v88;
    v61 = v70;
    v62 = 0;
    memset(&v77[5], 0, 28);
    memset(v97, 0, sizeof(v97));
    v20 = 1;
  }
  if ( a9 - v23 < 4 )
    goto LABEL_62;
  v24 = *(_DWORD *)(v12 + v23);
  v25 = v23 + 4;
  v69 = v24;
  if ( a9 - v25 < v24 )
    goto LABEL_62;
  if ( v24 <= 0xFFFE )
  {
    v87[4] = v24;
    v87[5] = v12 + v25;
    v15 = AuthzBasepUnicodeStringFromOperandValue(&v86, 0, &v89 + 9 * v20, &v61 + v20);
    if ( v15 < 0 )
      goto LABEL_100;
    if ( v22 == 249 )
    {
      v26 = &v88 + 9 * v20;
      if ( a11 )
        v27 = a5;
      else
        v27 = v85;
    }
    else if ( v22 == 251 )
    {
      v26 = &v88 + 9 * v20;
      if ( a11 )
        v27 = a7;
      else
        v27 = a6;
    }
    else
    {
      v26 = &v88 + 9 * v20;
      if ( v22 == 250 )
        v27 = v84;
      else
        v27 = v72;
    }
    *v26 = v27;
    v28 = &v88 + 9 * v20;
    v28[7] = 0;
    v28[8] = 0;
    v15 = AuthzBasepQuerySecurityAttributeAndValues(v26);
    if ( v15 != -1073741275 )
      goto LABEL_25;
    v29 = v72;
    if ( *v26 == v72 && (SepSingletonGlobal[3] & 1) != 0 && SepPotentialGlobalTableAttribute(&v89 + 9 * v20) && !v82 )
    {
      if ( v64 )
      {
        v57 = v63;
        goto LABEL_197;
      }
      v15 = SepValidateAndCopyGlobalEntry(v29, &v71);
      if ( v15 >= 0 )
      {
        v64 = 1;
        v57 = v71;
        v63 = v71;
LABEL_197:
        *v26 = v57;
        v15 = AuthzBasepQuerySecurityAttributeAndValues(v26);
        if ( v15 != -1073741275 )
          goto LABEL_25;
        v29 = v72;
        *v26 = v72;
        goto LABEL_22;
      }
      v82 = 1;
      if ( v15 != -1073741275 )
      {
        v63 = v71;
        goto LABEL_25;
      }
      v29 = v72;
      v63 = v71;
    }
LABEL_22:
    if ( v79 || *v26 != v29 )
      goto LABEL_200;
    *v26 = 0;
    v15 = AuthzBasepQuerySystemSecurityAttributeAndValues(v26);
LABEL_25:
    if ( v15 >= 0 )
    {
      *((_WORD *)&v75 + 14 * v20) = *((_WORD *)v28 + 6);
      v30 = &v75 + 7 * v20;
      v31 = *(&v93 + 9 * v20);
      v30[4] = (int)v26;
      v30[1] = v31;
LABEL_27:
      v30[5] = 0;
      v30[6] = 0;
      v30[2] = 0;
      switch ( v22 )
      {
        case 249:
          v32 = 3;
          break;
        case 250:
          v32 = 4;
          break;
        case 251:
          v32 = 5;
          break;
        default:
          if ( *v26 )
            v32 = 2;
          else
            v32 = 6;
          break;
      }
      v30[3] = v32;
      v21 = v61;
      v12 = (int)v83;
      v19 = v25 + v69;
      v69 = v61;
      v70 = v62;
      goto LABEL_33;
    }
    if ( v15 != -1073741275 )
      goto LABEL_100;
LABEL_200:
    *((_WORD *)&v75 + 14 * v20) = 0;
    v30 = &v75 + 7 * v20;
    v58 = *(&v61 + v20);
    v15 = 0;
    v30[1] = 0;
    v30[4] = 0;
    if ( v58 )
    {
      v59 = ExFreePoolWithTag(*(&v90 + 9 * v20), 0);
      if ( v20 >= 2 )
        _report_rangecheckfailure(v59);
      *(&v61 + v20) = 0;
    }
    goto LABEL_27;
  }
  v15 = -1073741562;
  v13 = v66;
  v17 = v63;
  v16 = v64;
LABEL_37:
  v33 = 0;
  v34 = &v88;
  do
  {
    if ( *(&v61 + v33) )
      ExFreePoolWithTag(v34[2], 0);
    ++v33;
    v34 += 9;
  }
  while ( v33 < 2 );
  if ( v16 && v17 )
  {
    AuthzBasepFreeSecurityAttributesList(v17);
    ExFreePoolWithTag(v17, 1950442835);
  }
  if ( v15 < 0 )
    *v13 = -1;
  return v15;
}
