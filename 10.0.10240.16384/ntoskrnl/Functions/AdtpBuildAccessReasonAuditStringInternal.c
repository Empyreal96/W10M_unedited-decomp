// AdtpBuildAccessReasonAuditStringInternal 
 
int __fastcall AdtpBuildAccessReasonAuditStringInternal(int a1, int a2, int a3, int a4, int a5, int a6, int a7, _WORD *a8, int a9, int a10, int a11, _BYTE *a12)
{
  int v13; // r6
  unsigned int v14; // r5
  int v15; // r3
  int v17; // r4
  int v18; // r2
  int v19; // r8
  int v20; // r3
  int v21; // r10
  unsigned int v22; // r5
  int *v23; // r2
  unsigned __int8 *v24; // r7
  int v25; // r8
  int v26; // r4
  int v27; // r0
  int v28; // r5
  int v30; // r1
  int v31; // r7
  int v32; // r1
  int v33; // r0
  unsigned __int8 *v34; // r8
  unsigned __int16 *v35; // r4
  unsigned int v36; // r2
  __int16 v37; // r7
  __int16 *v38; // r1
  int v39; // r2
  int v40; // r3
  int v41; // r4
  int v42; // r2
  unsigned int v43; // r3
  int *v44; // r2
  int v45; // r4
  __int16 *v46; // r1
  unsigned __int16 *v47; // r1
  int v48; // r4
  unsigned __int16 *v49; // r1
  int v50; // r4
  int v51; // r2
  int v52; // r0
  unsigned int v53; // r8
  int v54; // r9
  int v55; // r0
  int v56; // r7
  int v57; // r3
  _WORD *v58; // r2
  unsigned __int16 v59; // [sp+18h] [bp-1F8h] BYREF
  __int16 v60; // [sp+1Ah] [bp-1F6h]
  int v61; // [sp+1Ch] [bp-1F4h]
  char v62[8]; // [sp+20h] [bp-1F0h] BYREF
  int v63; // [sp+28h] [bp-1E8h] BYREF
  int v64; // [sp+2Ch] [bp-1E4h]
  int v65; // [sp+30h] [bp-1E0h] BYREF
  int v66; // [sp+38h] [bp-1D8h] BYREF
  const __int16 *v67; // [sp+3Ch] [bp-1D4h]
  unsigned __int8 *v68; // [sp+40h] [bp-1D0h] BYREF
  int v69; // [sp+48h] [bp-1C8h]
  int v70; // [sp+4Ch] [bp-1C4h]
  int *v71; // [sp+50h] [bp-1C0h] BYREF
  bool v72; // [sp+54h] [bp-1BCh] BYREF
  _WORD *v73; // [sp+58h] [bp-1B8h]
  unsigned __int8 *v74; // [sp+5Ch] [bp-1B4h] BYREF
  int *v75; // [sp+60h] [bp-1B0h]
  __int16 v76[2]; // [sp+68h] [bp-1A8h] BYREF
  char *v77; // [sp+6Ch] [bp-1A4h]
  __int16 v78[2]; // [sp+70h] [bp-1A0h] BYREF
  char *v79; // [sp+74h] [bp-19Ch]
  __int16 v80[2]; // [sp+78h] [bp-198h] BYREF
  char *v81; // [sp+7Ch] [bp-194h]
  __int16 v82[2]; // [sp+80h] [bp-190h] BYREF
  char *v83; // [sp+84h] [bp-18Ch]
  __int16 v84[2]; // [sp+88h] [bp-188h] BYREF
  char *v85; // [sp+8Ch] [bp-184h]
  __int16 v86[2]; // [sp+90h] [bp-180h] BYREF
  char *v87; // [sp+94h] [bp-17Ch]
  _BYTE *v88; // [sp+98h] [bp-178h]
  char v89; // [sp+A0h] [bp-170h] BYREF
  char v90[19]; // [sp+A1h] [bp-16Fh] BYREF
  _DWORD v91[6]; // [sp+B8h] [bp-158h] BYREF
  unsigned __int16 v92[20]; // [sp+D0h] [bp-140h] BYREF
  char v93; // [sp+F8h] [bp-118h] BYREF
  char v94; // [sp+110h] [bp-100h] BYREF
  char v95; // [sp+130h] [bp-E0h] BYREF
  char v96; // [sp+150h] [bp-C0h] BYREF
  char v97; // [sp+170h] [bp-A0h] BYREF
  char v98; // [sp+190h] [bp-80h] BYREF
  char v99; // [sp+1B0h] [bp-60h] BYREF
  char v100; // [sp+1D0h] [bp-40h] BYREF

  v71 = (int *)a4;
  v73 = a8;
  v13 = 0;
  v88 = a12;
  v68 = 0;
  v74 = 0;
  v75 = (int *)a3;
  v69 = 0;
  v70 = 0;
  v59 = 0;
  v60 = 0;
  v63 = 0;
  v64 = 0;
  v14 = 0;
  v15 = 1;
  v65 = 0;
  v61 = 0;
  while ( (v15 & a5) == 0 )
  {
    ++v14;
    v15 *= 2;
    if ( v14 >= 0x20 )
    {
      v14 = (unsigned int)v73;
      break;
    }
  }
  v87 = &v93;
  v86[1] = 20;
  v86[0] = 0;
  v77 = &v100;
  v76[1] = 30;
  v76[0] = 0;
  v17 = AdtpFormatPrefix(v76, 1801, 1);
  if ( v17 < 0 )
    goto LABEL_30;
  v79 = &v95;
  v78[1] = 30;
  v78[0] = 0;
  v17 = AdtpFormatPrefix(v78, 1802, 1);
  if ( v17 < 0 )
    goto LABEL_30;
  v85 = &v99;
  v84[1] = 30;
  v84[0] = 0;
  v17 = AdtpFormatPrefix(v84, 1811, 1);
  if ( v17 < 0 )
    goto LABEL_30;
  v91[1] = &v97;
  v91[0] = 1966080;
  v17 = AdtpFormatPrefix(v91, 1812, 1);
  if ( v17 < 0 )
    goto LABEL_30;
  v67 = (const __int16 *)&v94;
  v66 = 1966080;
  v17 = AdtpFormatPrefix(&v66, 1810, 1);
  if ( v17 < 0 )
    goto LABEL_30;
  v81 = &v96;
  v80[1] = 30;
  v80[0] = 0;
  v17 = AdtpFormatPrefix(v80, 1814, 0);
  if ( v17 < 0 )
    goto LABEL_30;
  v83 = &v98;
  v82[1] = 30;
  v82[0] = 0;
  v17 = AdtpFormatPrefix(v82, 1816, 0);
  if ( v17 < 0 )
    goto LABEL_30;
  v17 = AdtpBuildAccessesString(a1, a2, a5);
  if ( v17 < 0 )
    goto LABEL_30;
  v19 = *(_DWORD *)(a7 + 4 * v14);
  v20 = 6291456;
  v21 = v70;
  v22 = v19 & 0xFF0000;
  if ( (v19 & 0xFF0000u) > 0x100000 )
  {
    if ( v22 > 0x600000 )
    {
      if ( v22 != 7340032 && v22 != 0x800000 && v22 != 9437184 )
        goto LABEL_126;
      goto LABEL_104;
    }
    if ( v22 == 6291456 )
    {
LABEL_104:
      v50 = (int)v73;
      goto LABEL_106;
    }
    if ( v22 != 0x200000 )
    {
      if ( v22 != 3145728 && v22 != 0x400000 && v22 != 5242880 )
        goto LABEL_126;
      goto LABEL_104;
    }
LABEL_92:
    v91[0] = 1;
    v91[1] = 1;
    v91[2] = (unsigned __int16)v19;
    v91[4] = 0;
    v91[3] = 0;
    v17 = AdtpBuildPrivilegeAuditString(v91, &v63);
    if ( v17 < 0 )
      goto LABEL_31;
    v48 = 2 * (((unsigned __int16)v63 >> 1) + 27);
    v13 = ExAllocatePoolWithTag(1, v48);
    v61 = v13;
    if ( !v13 )
      goto LABEL_29;
    v59 = 0;
    v60 = v48;
    if ( v22 == 0x200000 )
    {
      v49 = (unsigned __int16 *)v76;
    }
    else
    {
      if ( v22 != 0x100000 )
        goto LABEL_99;
      v49 = (unsigned __int16 *)&v66;
    }
    RtlAppendUnicodeStringToString(&v59, v49);
LABEL_99:
    RtlAppendUnicodeStringToString(&v59, (unsigned __int16 *)&v63);
    v28 = v64;
    if ( v64 )
    {
      ExFreePoolWithTag(v64);
      v28 = 0;
    }
    goto LABEL_127;
  }
  if ( (v19 & 0xFF0000) == 0x100000 )
    goto LABEL_92;
  v18 = 0x40000;
  if ( v22 > 0x40000 )
  {
    if ( v22 == 327680 || v22 == 393216 )
    {
      v41 = 2;
      qmemcpy(v91, "# %d", 8);
      v66 = 131074;
      v67 = L"-";
      if ( v22 == 393216 )
        v42 = (int)v71;
      else
        v42 = (int)v75;
      v43 = *(_DWORD *)(v42 + 4);
      if ( !v43 )
        goto LABEL_78;
      if ( (unsigned __int16)v19 >= v43 )
      {
        v17 = -1073741811;
        goto LABEL_30;
      }
      v44 = (int *)(*(_DWORD *)(v42 + 8) + 8 * (unsigned __int16)v19);
      v66 = *v44;
      v41 = (unsigned __int16)v66;
      v67 = (const __int16 *)v44[1];
      if ( (unsigned __int16)v66 <= 2u )
      {
LABEL_78:
        v71 = 0;
        if ( StringCchPrintfExW(v92, 20, 0, &v71, 0, v91, (unsigned __int16)v19, 0, v62) >= 0 )
        {
          HIWORD(v66) = 40;
          v41 = (unsigned __int16)(2 * (20 - (_WORD)v71));
          v67 = (const __int16 *)v92;
          LOWORD(v66) = 2 * (20 - (_WORD)v71);
        }
      }
      v45 = v41 + 54;
      v13 = ExAllocatePoolWithTag(1, v45);
      v61 = v13;
      if ( v13 )
      {
        v59 = 0;
        v60 = 2 * v45;
        if ( v22 == 327680 )
          v46 = v80;
        else
          v46 = v82;
        RtlAppendUnicodeStringToString(&v59, (unsigned __int16 *)v46);
        v47 = (unsigned __int16 *)&v66;
LABEL_125:
        RtlAppendUnicodeStringToString(&v59, v47);
LABEL_126:
        v28 = v64;
LABEL_127:
        v52 = RtlAppendUnicodeToString(&v59, (int)L"\r\n\t\t\t\t", v18, v20);
        v53 = v59;
        v17 = v52;
        v54 = (v59 >> 1) + ((unsigned __int16)v69 >> 1) + 1;
        v55 = ExAllocatePoolWithTag(1, 2 * v54);
        v56 = v55;
        if ( v55 )
        {
          *v88 = 1;
          v57 = (unsigned __int16)v69;
          if ( (_WORD)v69 )
          {
            memmove(v55, v21, (unsigned __int16)v69);
            v57 = (unsigned __int16)v69;
          }
          v13 = v61;
          if ( v53 )
            memmove(v57 + v56, v61, v53);
          *(_WORD *)(v56 + 2 * v54 - 2) = 0;
          v58 = v73;
          *v73 = 2 * (v54 - 1);
          v58[1] = 2 * (v54 - 1) + 2;
          *((_DWORD *)v58 + 1) = v56;
        }
        else
        {
          v13 = v61;
          v17 = -1073741801;
        }
        v34 = v68;
        goto LABEL_135;
      }
LABEL_29:
      v17 = -1073741801;
LABEL_30:
      v21 = v70;
LABEL_31:
      v28 = v64;
      goto LABEL_32;
    }
    if ( v22 != 458752 )
      goto LABEL_126;
    v50 = 1830;
LABEL_106:
    if ( v22 == 3145728 )
      v50 = 1803;
    if ( v22 == 0x400000 )
      v50 = 1804;
    if ( v22 == 5242880 )
      v50 = 1806;
    if ( v22 == 6291456 )
      v50 = 1807;
    if ( v22 == 7340032 )
      v50 = 1808;
    if ( !v22 )
      v50 = 1809;
    if ( v22 == 0x800000 )
      v50 = 1805;
    if ( v22 == 9437184 )
      v50 = 1841;
    v13 = ExAllocatePoolWithTag(1, 78);
    v61 = v13;
    if ( v13 )
    {
      v59 = 0;
      v60 = 78;
      RtlAppendUnicodeToString(&v59, (int)L"%%", v51, 78);
      v17 = RtlIntegerToUnicodeString(v50, 10, v86);
      if ( v17 < 0 )
      {
        v13 = v61;
        goto LABEL_31;
      }
      v47 = (unsigned __int16 *)v86;
      goto LABEL_125;
    }
    goto LABEL_29;
  }
  if ( v22 == 0x40000 )
    goto LABEL_21;
  if ( !v22 )
    goto LABEL_104;
  if ( v22 != 0x10000 && v22 != 0x20000 && v22 != 196608 )
    goto LABEL_126;
LABEL_21:
  v68 = 0;
  v65 = 0;
  v89 = 0;
  memset(v90, 0, sizeof(v90));
  v66 = 0;
  if ( v22 == 0x10000 || v22 == 0x20000 )
    v23 = v75;
  else
    v23 = v71;
  v17 = RtlGetDaclSecurityDescriptor(*v23, v62, &v68, &v72);
  if ( v17 < 0 )
    goto LABEL_31;
  if ( !v62[0] )
    goto LABEL_31;
  v24 = v68;
  v17 = RtlGetAce(v68, (unsigned __int16)v19, (int)&v65);
  if ( v17 < 0 )
    goto LABEL_31;
  v25 = v65;
  v26 = *(unsigned __int16 *)(v65 + 2);
  v27 = ExAllocatePoolWithTag(1, v26 + 8);
  v65 = v27;
  if ( !v27 )
    goto LABEL_29;
  v17 = RtlCreateAcl(v27, v26 + 8, *v24);
  if ( v17 < 0 )
  {
    v31 = v65;
  }
  else
  {
    v30 = *v24;
    v31 = v65;
    v17 = RtlAddAce(v65, v30, 0, v25, *(unsigned __int16 *)(v25 + 2));
    if ( v17 >= 0 )
    {
      v17 = RtlCreateSecurityDescriptor(&v89, 1);
      if ( v17 >= 0 )
      {
        v17 = RtlSetDaclSecurityDescriptor(&v89, 1, v31, 0);
        if ( v17 >= 0 )
        {
          v33 = SeConvertSecurityDescriptorToStringSecurityDescriptor((int)&v89, v32, 4, &v74, &v66);
          v34 = v74;
          v17 = v33;
          v68 = v74;
          if ( v33 < 0 )
          {
            if ( v33 == -1073741801 )
              goto LABEL_64;
            if ( StringCchPrintfW(v92, 0x10u, (int)L"<0x%08X>", v33) < 0 )
              v35 = L"-";
            else
              v35 = v92;
          }
          else
          {
            v35 = (unsigned __int16 *)v74;
          }
          v36 = wcslen(v35) + 1;
          if ( 2 * v36 <= 0xFFFF )
          {
LABEL_52:
            v37 = 2 * (v36 + 27);
            v13 = ExAllocatePoolWithTag(1, 2 * (v36 + 27));
            v61 = v13;
            if ( !v13 )
            {
              v28 = v64;
              v17 = -1073741801;
LABEL_135:
              v31 = v65;
LABEL_136:
              if ( v34 )
                ExFreePoolWithTag(v34);
              goto LABEL_138;
            }
            v59 = 0;
            v60 = v37;
            switch ( v22 )
            {
              case 0x10000u:
                v38 = v76;
                break;
              case 0x20000u:
                v38 = v78;
                break;
              case 0x30000u:
                v38 = v84;
                break;
              default:
                v38 = (__int16 *)v91;
                break;
            }
            RtlAppendUnicodeStringToString(&v59, (unsigned __int16 *)v38);
            RtlAppendUnicodeToString(&v59, (int)v35, v39, v40);
            if ( v34 )
            {
              ExFreePoolWithTag(v34);
              v68 = 0;
            }
            ExFreePoolWithTag(v65);
            v65 = 0;
            goto LABEL_126;
          }
          v17 = RtlStringCbPrintfW(v92, 0x10u, (int)L"%%%%%u", 1828);
          if ( v17 >= 0 )
          {
            v35 = v92;
            v36 = wcslen(v92) + 1;
            goto LABEL_52;
          }
LABEL_64:
          v28 = v64;
          goto LABEL_136;
        }
      }
    }
  }
  v28 = v64;
LABEL_138:
  if ( v31 )
    ExFreePoolWithTag(v31);
LABEL_32:
  if ( v28 )
    ExFreePoolWithTag(v28);
  if ( v21 )
    ExFreePoolWithTag(v21);
  if ( v13 )
    ExFreePoolWithTag(v13);
  return v17;
}
