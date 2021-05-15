// NtCreateTokenEx 
 
int __fastcall NtCreateTokenEx(_DWORD *a1, int a2, int a3, int a4, int a5, _DWORD *a6, int a7, unsigned int *a8, unsigned int *a9, int a10, int a11, int *a12, unsigned int a13, _DWORD *a14, int a15, int a16, _DWORD *a17)
{
  int v18; // r8
  int v19; // r0
  _DWORD *v21; // r1
  _DWORD *v22; // r5
  int v23; // r0
  int v24; // r10
  int v25; // r9
  int v26; // r0
  int v27; // r5
  int v28; // r1
  int v29; // r2
  int v30; // r3
  int v31; // r9
  unsigned __int16 **v32; // r4
  int v33; // r10
  int *v34; // r3
  int *v36; // [sp+5Ch] [bp-124h]
  char v37[4]; // [sp+60h] [bp-120h] BYREF
  _DWORD *v38; // [sp+64h] [bp-11Ch]
  int v39; // [sp+68h] [bp-118h]
  int v40; // [sp+6Ch] [bp-114h]
  unsigned __int16 *v41; // [sp+70h] [bp-110h]
  int v42; // [sp+74h] [bp-10Ch]
  int v43; // [sp+78h] [bp-108h]
  unsigned __int16 *v44; // [sp+7Ch] [bp-104h]
  int v45; // [sp+80h] [bp-100h]
  int v46; // [sp+84h] [bp-FCh]
  int v47; // [sp+88h] [bp-F8h]
  unsigned __int16 *v48; // [sp+8Ch] [bp-F4h]
  int v49; // [sp+90h] [bp-F0h] BYREF
  int v50; // [sp+94h] [bp-ECh]
  int v51; // [sp+98h] [bp-E8h] BYREF
  unsigned __int16 *v52; // [sp+9Ch] [bp-E4h]
  int v53; // [sp+A0h] [bp-E0h]
  int v54; // [sp+A4h] [bp-DCh]
  int v55; // [sp+A8h] [bp-D8h]
  int v56; // [sp+ACh] [bp-D4h]
  int v57; // [sp+B0h] [bp-D0h]
  unsigned int v58; // [sp+B4h] [bp-CCh]
  int v59; // [sp+B8h] [bp-C8h]
  unsigned int *v60; // [sp+BCh] [bp-C4h]
  unsigned __int16 **v61; // [sp+C0h] [bp-C0h]
  unsigned int *v62; // [sp+C4h] [bp-BCh]
  unsigned int v63; // [sp+C8h] [bp-B8h]
  int v64; // [sp+CCh] [bp-B4h]
  unsigned int v65; // [sp+D0h] [bp-B0h]
  int v66; // [sp+D4h] [bp-ACh]
  int v67; // [sp+D8h] [bp-A8h]
  int v68; // [sp+DCh] [bp-A4h]
  int v69; // [sp+E0h] [bp-A0h]
  unsigned int v70; // [sp+E4h] [bp-9Ch]
  _DWORD *v71; // [sp+E8h] [bp-98h]
  int v72; // [sp+ECh] [bp-94h]
  int v73; // [sp+F0h] [bp-90h]
  _DWORD *v74; // [sp+F4h] [bp-8Ch]
  int v75; // [sp+F8h] [bp-88h] BYREF
  _DWORD *v76; // [sp+FCh] [bp-84h]
  int v77[2]; // [sp+100h] [bp-80h] BYREF
  int v78; // [sp+108h] [bp-78h]
  int *v79; // [sp+10Ch] [bp-74h]
  int v80; // [sp+110h] [bp-70h]
  _DWORD v81[2]; // [sp+118h] [bp-68h] BYREF
  _DWORD v82[8]; // [sp+120h] [bp-60h] BYREF
  _DWORD v83[4]; // [sp+140h] [bp-40h] BYREF
  int _150[18]; // [sp+150h] [bp-30h] BYREF

  _150[14] = (int)a1;
  _150[16] = a3;
  v42 = a4;
  _150[17] = a4;
  v57 = a3;
  v69 = a2;
  _150[15] = a2;
  v71 = a1;
  v77[1] = (int)a1;
  v80 = a3;
  v73 = a5;
  v82[5] = a5;
  v78 = a7;
  v82[2] = a7;
  v62 = a8;
  v82[3] = a8;
  v60 = a9;
  v82[4] = a9;
  v79 = a12;
  v82[6] = a12;
  v76 = a14;
  v81[0] = a14;
  v68 = a15;
  v82[0] = a15;
  v74 = (_DWORD *)a16;
  v43 = a16;
  v77[0] = 0;
  v37[0] = 0;
  v61 = 0;
  v58 = 0;
  v63 = 0;
  v47 = 0;
  v59 = 0;
  v55 = 0;
  v39 = 0;
  v70 = 0;
  v65 = 0;
  v46 = 0;
  v50 = 0;
  v44 = 0;
  v48 = 0;
  v41 = 0;
  v52 = 0;
  v40 = 0;
  v56 = 0;
  v75 = 0;
  v53 = 0;
  v72 = 0;
  v49 = 0;
  v64 = 0;
  v51 = 0;
  v66 = 0;
  v67 = 0;
  v45 = 0;
  v54 = 0;
  v18 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v19 = SeSinglePrivilegeCheck(SeCreateTokenPrivilege, dword_922A04, v18, (int)&SeCreateTokenPrivilege);
  if ( !v19 )
    return -1073741727;
  if ( v18 )
  {
    v21 = a1;
    if ( (unsigned int)a1 >= MmUserProbeAddress )
      v21 = (_DWORD *)MmUserProbeAddress;
    *v21 = *v21;
    v22 = a6;
    if ( ((unsigned __int8)a6 & 3) != 0 )
      ExRaiseDatatypeMisalignment(v19);
    if ( ((unsigned __int8)v62 & 3) != 0 )
      ExRaiseDatatypeMisalignment(v62);
    if ( ((unsigned __int8)v60 & 3) != 0 )
      ExRaiseDatatypeMisalignment(v62);
    v38 = a17;
    if ( ((unsigned __int8)a17 & 3) != 0 )
      ExRaiseDatatypeMisalignment(a17);
    if ( a14 && ((unsigned __int8)a14 & 3) != 0 )
      ExRaiseDatatypeMisalignment(a17);
    v23 = v68;
    if ( (v68 & 3) != 0 )
      ExRaiseDatatypeMisalignment(v68);
    if ( a16 && (a16 & 3) != 0 )
      ExRaiseDatatypeMisalignment(v68);
    if ( (v73 & 3) != 0 )
      ExRaiseDatatypeMisalignment(v68);
    v36 = (int *)a13;
    if ( a13 )
    {
      v23 = a13;
      if ( (a13 & 3) != 0 )
        ExRaiseDatatypeMisalignment(a13);
      if ( a13 >= MmUserProbeAddress )
        v23 = MmUserProbeAddress;
    }
    if ( a12 && ((unsigned __int8)a12 & 3) != 0 )
      ExRaiseDatatypeMisalignment(v23);
    v24 = a11;
    if ( a11 && (a11 & 3) != 0 )
      ExRaiseDatatypeMisalignment(v23);
    v25 = a10;
    if ( a10 && (a10 & 3) != 0 )
      ExRaiseDatatypeMisalignment(v23);
  }
  else
  {
    v38 = a17;
    v36 = (int *)a13;
    v24 = a11;
    v25 = a10;
    v22 = a6;
  }
  if ( (unsigned int)(v42 - 1) > 1 )
    return -1073741656;
  v26 = SeCaptureSecurityQos(v57, v18, v37, _150);
  if ( v26 < 0 )
    return v26;
  if ( v42 == 2 && !v37[0] )
    return -1073741659;
  v81[0] = *(_DWORD *)v73;
  v81[1] = *(_DWORD *)(v73 + 4);
  v82[0] = *v22;
  v82[1] = v22[1];
  v27 = SeCaptureSidAndAttributesArray(v78, 1, v18, 0, 0);
  if ( v27 >= 0 )
  {
    v58 = *v62;
    v63 = v58;
    v27 = SeCaptureSidAndAttributesArray(v62 + 1, v58, v18, 0, 0);
    v55 = (v39 - 8 * v58 + 3) & 0xFFFFFFFC;
    v39 = v55;
    v47 = v59;
    if ( v27 >= 0 )
    {
      v70 = *v60;
      v65 = v70;
      v27 = SeCaptureLuidAndAttributesArray(v60 + 1);
      v46 = v50;
    }
  }
  if ( v76 && v27 >= 0 )
  {
    v27 = SeCaptureSid(*v76, v18);
    v44 = v48;
  }
  if ( v27 >= 0 )
  {
    v27 = SeCaptureSid(*(_DWORD *)v68, v18);
    v41 = v52;
  }
  if ( v74 && v27 >= 0 && *v74 )
  {
    v27 = SeCaptureAcl(*v74, v18);
    v40 = v56;
  }
  v28 = v38[1];
  v29 = v38[2];
  v30 = v38[3];
  v83[0] = *v38;
  v83[1] = v28;
  v83[2] = v29;
  v83[3] = v30;
  if ( v79 && v27 >= 0 )
  {
    v66 = *v79;
    v67 = v66;
    v27 = SeCaptureSidAndAttributesArray(v79 + 1, v66, v18, 0, 0);
    v45 = v54;
  }
  if ( v25 && v27 >= 0 )
  {
    v27 = SepCaptureTokenSecurityAttributesInformation(v25, v18, 0, &v49);
    v72 = v49;
  }
  if ( v24 && v27 >= 0 )
  {
    v27 = SepCaptureTokenSecurityAttributesInformation(v24, v18, 0, &v51);
    v31 = v51;
  }
  else
  {
    v31 = v64;
  }
  if ( v36 && v27 >= 0 )
  {
    v75 = *v36;
    v53 = 1;
  }
  v32 = v61;
  v33 = v72;
  if ( v27 >= 0 )
  {
    if ( v53 )
      v34 = &v75;
    else
      v34 = 0;
    v27 = SepCreateTokenEx(
            v77,
            v18,
            v69,
            v57,
            v42,
            _150[1],
            (int)v81,
            v82,
            v61,
            v58,
            v47,
            v55,
            v70,
            v46,
            v44,
            v41,
            v40,
            v83,
            v72,
            v31,
            v66,
            v45,
            v34,
            0);
  }
  if ( v32 )
    SeReleaseLuidAndAttributesArray(v32, v18);
  if ( v47 )
    SeReleaseLuidAndAttributesArray(v47, v18);
  if ( v46 )
    SeReleaseLuidAndAttributesArray(v46, v18);
  if ( v44 )
    SeReleaseSid(v44, v18, 1);
  if ( v41 )
    SeReleaseSid(v41, v18, 1);
  if ( v40 )
    SeReleaseAcl(v40, v18);
  if ( v45 )
    SeReleaseLuidAndAttributesArray(v45, v18);
  if ( v33 )
    SepFreeCapturedTokenSecurityAttributesInformation(v33);
  if ( v31 )
    SepFreeCapturedTokenSecurityAttributesInformation(v31);
  if ( v27 >= 0 )
    *v71 = v77[0];
  return v27;
}
