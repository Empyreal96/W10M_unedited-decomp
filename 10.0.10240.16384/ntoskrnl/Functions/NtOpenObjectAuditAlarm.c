// NtOpenObjectAuditAlarm 
 
int __fastcall NtOpenObjectAuditAlarm(_DWORD *a1, int a2, _DWORD *a3, _DWORD *a4, unsigned int a5, int a6, int a7, int a8, unsigned int a9, int a10, unsigned __int8 a11, unsigned int a12)
{
  int *v12; // r10
  int v13; // r3
  int v14; // r5
  int v15; // r4
  int v16; // r9
  int v17; // r0
  int v18; // r6
  unsigned int v19; // r8
  unsigned int v20; // r4
  _BYTE *v21; // r10
  int v22; // r3
  unsigned int v23; // r10
  unsigned int *v24; // r0
  _BYTE *v25; // r2
  __int16 v26; // r3
  int v27; // r1
  int v28; // r2
  int v29; // r0
  int v30; // r3
  int v31; // r6
  int v32; // r1
  int v33; // r3
  int *v34; // r2
  int v35; // r5
  unsigned __int8 v36; // r3
  int v37; // r2
  unsigned __int16 *v38; // r6
  unsigned __int16 *v39; // r5
  int v41; // [sp+4h] [bp-D4h]
  int v42; // [sp+Ch] [bp-CCh]
  unsigned __int8 v43; // [sp+40h] [bp-98h] BYREF
  char v44[3]; // [sp+41h] [bp-97h] BYREF
  unsigned __int16 *v45; // [sp+44h] [bp-94h]
  unsigned __int16 *v46; // [sp+48h] [bp-90h]
  int v47; // [sp+4Ch] [bp-8Ch]
  __int16 *v48; // [sp+50h] [bp-88h]
  unsigned int *v49; // [sp+54h] [bp-84h]
  unsigned __int16 v50; // [sp+58h] [bp-80h] BYREF
  int v51; // [sp+5Ch] [bp-7Ch]
  char v52; // [sp+60h] [bp-78h]
  int v53; // [sp+64h] [bp-74h]
  int v54; // [sp+68h] [bp-70h]
  __int16 *v55; // [sp+6Ch] [bp-6Ch] BYREF
  unsigned __int16 *v56; // [sp+70h] [bp-68h] BYREF
  int v57; // [sp+74h] [bp-64h]
  int v58; // [sp+78h] [bp-60h]
  int v59; // [sp+7Ch] [bp-5Ch]
  int v60; // [sp+80h] [bp-58h]
  unsigned int v61; // [sp+84h] [bp-54h] BYREF
  unsigned __int16 *v62; // [sp+88h] [bp-50h] BYREF
  unsigned int v63; // [sp+8Ch] [bp-4Ch]
  int v64; // [sp+90h] [bp-48h] BYREF
  int *v65; // [sp+94h] [bp-44h]
  unsigned int *v66; // [sp+98h] [bp-40h]
  int v67[2]; // [sp+A0h] [bp-38h] BYREF
  int v68; // [sp+A8h] [bp-30h]
  int v69; // [sp+B0h] [bp-28h] BYREF
  _DWORD *v70; // [sp+B4h] [bp-24h]
  _DWORD *v71; // [sp+B8h] [bp-20h]
  _DWORD *varg_r0; // [sp+E0h] [bp+8h]
  int varg_r1; // [sp+E4h] [bp+Ch]
  _DWORD *varg_r2; // [sp+E8h] [bp+10h]
  _DWORD *varg_r3; // [sp+ECh] [bp+14h]

  varg_r0 = a1;
  varg_r2 = a3;
  varg_r3 = a4;
  v71 = a4;
  v70 = a3;
  v12 = (int *)a2;
  v65 = (int *)a2;
  varg_r1 = a2;
  v51 = (int)a1;
  v48 = 0;
  v55 = 0;
  v45 = 0;
  v56 = 0;
  v46 = 0;
  v62 = 0;
  v61 = 0;
  v49 = 0;
  v66 = 0;
  v58 = 0;
  v52 = 0;
  v59 = 0;
  v44[0] = 0;
  v54 = 0;
  v43 = 0;
  v60 = 0;
  v64 = 0;
  v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v14 = *(char *)(v13 + 346);
  v57 = v14;
  LOBYTE(v50) = v14;
  SeCaptureSubjectContext(v67, a2, (int)a3, v13);
  if ( !SeCheckAuditPrivilege(v67, v14) )
  {
    v15 = -1073741727;
LABEL_11:
    SeReleaseSubjectContext((int)v67);
    return v15;
  }
  v15 = ObReferenceObjectByHandle(a6, 8, SeTokenObjectType, v14, (int)&v69, 0);
  if ( v15 < 0 )
  {
    SeReleaseSubjectContext((int)v67);
    if ( v15 != -1073741816 )
      SepAuditFailed();
    return v15;
  }
  v16 = v69;
  if ( *(_DWORD *)(v69 + 168) == 2 && *(int *)(v69 + 172) < 1 )
  {
    ObfDereferenceObject(v69);
    v15 = -1073741659;
    goto LABEL_11;
  }
  if ( !a5 )
  {
    ObfDereferenceObject(v69);
    v15 = -1073741703;
    goto LABEL_11;
  }
  v17 = SeCaptureSecurityDescriptor(a5, v14, 1, 0, &v61);
  v18 = v17;
  if ( v17 < 0 || (v19 = v61) == 0 )
  {
    ObfDereferenceObject(v16);
    SeReleaseSubjectContext((int)v67);
LABEL_89:
    if ( v18 == -1073741670 )
      SepAuditFailed();
    return v18;
  }
  v47 = a11;
  if ( a11 )
  {
    v63 = a9;
    if ( a9 )
    {
      if ( (a9 & 3) != 0 )
        ExRaiseDatatypeMisalignment(v17);
      v20 = *(_DWORD *)a9;
      if ( *(_DWORD *)a9 && v20 > 0x41 )
      {
        v18 = -1073741811;
        v53 = -1073741811;
        v21 = (_BYTE *)a12;
        goto LABEL_40;
      }
      v22 = 12 * (v20 - 1);
      v23 = v22 + 20;
      if ( v22 != -20 && (v23 + a9 > MmUserProbeAddress || v23 + a9 < a9) )
        *(_BYTE *)MmUserProbeAddress = 0;
      v24 = (unsigned int *)ExAllocatePoolWithTag(1, v23, 1917871443);
      v49 = v24;
      v66 = v24;
      if ( !v24 )
      {
        SeReleaseSecurityDescriptor(v19, v57, 0);
        ObfDereferenceObject(v16);
        SeReleaseSubjectContext((int)v67);
        v53 = -1073741670;
        SepAuditFailed();
        v15 = -1073741670;
        v51 = -1073741670;
        return v15;
      }
      v17 = memmove((int)v24, a9, v23);
      *v49 = v20;
      v12 = v65;
    }
  }
  else
  {
    v63 = a9;
  }
  if ( v12 )
  {
    if ( ((unsigned __int8)v12 & 3) != 0 )
      ExRaiseDatatypeMisalignment(v17);
    v60 = *v12;
    v64 = v60;
  }
  v21 = (_BYTE *)a12;
  v25 = (_BYTE *)a12;
  if ( a12 >= MmUserProbeAddress )
    v25 = (_BYTE *)MmUserProbeAddress;
  *v25 = *v25;
  v18 = SepProbeAndCaptureString_U((_DWORD *)v51, &v55);
  v53 = v18;
  if ( v18 >= 0 )
  {
    v18 = SepProbeAndCaptureString_U(v70, &v56);
    v53 = v18;
    if ( v18 >= 0 )
    {
      v18 = SepProbeAndCaptureString_U(v71, &v62);
      v53 = v18;
      v48 = v55;
      v45 = v56;
      v46 = v62;
      goto LABEL_40;
    }
    v45 = v56;
  }
  v48 = v55;
LABEL_40:
  if ( v18 < 0 )
  {
    if ( v48 )
      ExFreePoolWithTag((unsigned int)v48);
    if ( v45 )
      ExFreePoolWithTag((unsigned int)v45);
    if ( v46 )
      ExFreePoolWithTag((unsigned int)v46);
    if ( v49 )
      ExFreePoolWithTag((unsigned int)v49);
    SeReleaseSecurityDescriptor(v19, v57, 0);
    ObfDereferenceObject(v16);
    SeReleaseSubjectContext((int)v67);
    goto LABEL_89;
  }
  if ( !SepAdtAuditObjectAccessWithContext(0, (int)v45, v47, v47 == 0, (int)v67, 0, &v50) )
  {
    v31 = a7;
    v32 = v54;
LABEL_72:
    v35 = v68;
    goto LABEL_73;
  }
  v26 = *(_WORD *)(v19 + 2);
  if ( (v26 & 0x10) == 0 )
    goto LABEL_52;
  if ( (*(_WORD *)(v19 + 2) & 0x8000) != 0 )
  {
    v28 = *(_DWORD *)(v19 + 12);
    if ( !v28 )
    {
LABEL_52:
      v27 = 0;
      goto LABEL_57;
    }
    v27 = v28 + v19;
  }
  else
  {
    v27 = *(_DWORD *)(v19 + 12);
  }
LABEL_57:
  if ( (v26 & 0x10) == 0 )
  {
LABEL_58:
    v29 = 0;
    goto LABEL_63;
  }
  if ( (*(_WORD *)(v19 + 2) & 0x8000) != 0 )
  {
    v30 = *(_DWORD *)(v19 + 12);
    if ( !v30 )
      goto LABEL_58;
    v29 = v30 + v19;
  }
  else
  {
    v29 = *(_DWORD *)(v19 + 12);
  }
LABEL_63:
  v31 = a7;
  SeExamineSacl(v29, v27, v16, a7 | a8, v47, v44, &v43);
  v59 = (unsigned __int8)v44[0];
  if ( v44[0] )
  {
    v54 = v43;
  }
  else
  {
    v32 = v43;
    v54 = v43;
    if ( !v43 )
      goto LABEL_72;
  }
  v33 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  if ( v65 )
    v34 = &v64;
  else
    v34 = 0;
  v35 = v68;
  v58 = SepAdtOpenObjectAuditAlarm(
          v50,
          v48,
          v34,
          v45,
          v46,
          v19,
          v16,
          v68,
          a7,
          a8,
          v49,
          v47,
          *(_DWORD *)(v33 + 176),
          2,
          0,
          0,
          0,
          0,
          0);
  v32 = v54;
LABEL_73:
  if ( v59 || v32 || !v63 || (v36 = v47, !v47) )
  {
    v38 = v46;
    v39 = v45;
  }
  else
  {
    v37 = __mrc(15, 0, 13, 0, 3);
    v42 = v31;
    v41 = v35;
    v38 = v46;
    v39 = v45;
    SepAdtPrivilegeObjectAuditAlarm(
      (int)v48,
      (int)v45,
      (int)v46,
      v60,
      v16,
      v41,
      *(_DWORD *)(*(_DWORD *)((v37 & 0xFFFFFFC0) + 0x74) + 176),
      v42,
      (int)v49,
      v36);
    v58 = 0;
  }
  SeReleaseSecurityDescriptor(v19, v57, 0);
  if ( v48 )
    ExFreePoolWithTag((unsigned int)v48);
  if ( v39 )
    ExFreePoolWithTag((unsigned int)v39);
  if ( v38 )
    ExFreePoolWithTag((unsigned int)v38);
  if ( v49 )
    ExFreePoolWithTag((unsigned int)v49);
  ObfDereferenceObject(v16);
  SeReleaseSubjectContext((int)v67);
  *v21 = v58;
  return 0;
}
