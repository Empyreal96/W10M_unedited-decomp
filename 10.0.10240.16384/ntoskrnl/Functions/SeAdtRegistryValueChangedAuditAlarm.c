// SeAdtRegistryValueChangedAuditAlarm 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall SeAdtRegistryValueChangedAuditAlarm(int a1, int a2, int a3, unsigned __int16 *a4, int a5, int a6, int a7, int a8)
{
  unsigned int v9; // r7
  unsigned __int16 *v10; // r9
  unsigned int v11; // r10
  int v12; // r1
  int v13; // r2
  int v14; // r4
  int v15; // r0
  int v16; // lr
  __int16 v17; // r3
  int v18; // r1
  int v19; // r2
  int v20; // r0
  int v21; // r3
  int v22; // r2
  int v23; // r1
  int v24; // r3
  int v25; // r0
  unsigned int v26; // r1 OVERLAPPED
  int v27; // r2 OVERLAPPED
  int v28; // r5
  unsigned int v29; // r1 OVERLAPPED
  int v30; // r2 OVERLAPPED
  int v31; // r0
  int v32; // r6
  int v33; // r3
  int v34; // r3
  int v35; // r3
  int v36; // r3
  unsigned int v37; // r0
  unsigned __int8 v39; // [sp+10h] [bp-378h] BYREF
  unsigned __int8 v40; // [sp+11h] [bp-377h] BYREF
  char v41; // [sp+12h] [bp-376h] BYREF
  char v42[5]; // [sp+13h] [bp-375h] BYREF
  unsigned __int16 v43; // [sp+18h] [bp-370h] BYREF
  __int16 v44; // [sp+1Ah] [bp-36Eh]
  char *v45; // [sp+1Ch] [bp-36Ch]
  unsigned __int16 v46; // [sp+20h] [bp-368h] BYREF
  __int16 v47; // [sp+22h] [bp-366h]
  char *v48; // [sp+24h] [bp-364h]
  unsigned __int16 v49; // [sp+28h] [bp-360h] BYREF
  __int16 v50; // [sp+2Ah] [bp-35Eh]
  char *v51; // [sp+2Ch] [bp-35Ch]
  unsigned __int16 v52; // [sp+30h] [bp-358h] BYREF
  _BYTE v53[6]; // [sp+32h] [bp-356h]
  unsigned __int16 v54; // [sp+38h] [bp-350h] BYREF
  _BYTE v55[6]; // [sp+3Ah] [bp-34Eh]
  int v56; // [sp+40h] [bp-348h]
  unsigned __int16 *v57; // [sp+44h] [bp-344h]
  unsigned __int16 *v58; // [sp+48h] [bp-340h] BYREF
  int v59[2]; // [sp+50h] [bp-338h] BYREF
  int v60; // [sp+58h] [bp-330h]
  int v61; // [sp+60h] [bp-328h]
  unsigned __int16 *v62; // [sp+64h] [bp-324h]
  char v63[8]; // [sp+68h] [bp-320h] BYREF
  int v64; // [sp+70h] [bp-318h] BYREF
  int v65[165]; // [sp+74h] [bp-314h] BYREF
  char v66; // [sp+308h] [bp-80h] BYREF
  char v67; // [sp+328h] [bp-60h] BYREF
  char v68; // [sp+348h] [bp-40h] BYREF

  v61 = a5;
  v62 = a4;
  v64 = 0;
  memset(v65, 0, sizeof(v65));
  v9 = 0;
  v57 = 0;
  v58 = 0;
  v10 = 0;
  v52 = 0;
  *(_DWORD *)v53 = 0;
  *(_WORD *)&v53[4] = 0;
  v54 = 0;
  *(_DWORD *)v55 = 0;
  *(_WORD *)&v55[4] = 0;
  v43 = 0;
  v44 = 0;
  v45 = 0;
  v46 = 0;
  v47 = 0;
  v48 = 0;
  v49 = 0;
  v50 = 0;
  v51 = 0;
  v56 = 0;
  v39 = 0;
  v40 = 0;
  v11 = 0;
  SeCaptureSubjectContext(v59, v12, v13, 0);
  v14 = v59[0];
  v15 = SeAuditingWithTokenForSubcategory(117);
  v41 = v15;
  if ( !v15 )
    return SeReleaseSubjectContext((int)v59);
  if ( v14 )
    v16 = v14;
  else
    v16 = v60;
  v17 = *(_WORD *)(a2 + 2);
  if ( (v17 & 0x10) == 0 )
    goto LABEL_6;
  if ( (*(_WORD *)(a2 + 2) & 0x8000) != 0 )
  {
    v19 = *(_DWORD *)(a2 + 12);
    if ( !v19 )
    {
LABEL_6:
      v18 = 0;
      goto LABEL_11;
    }
    v18 = v19 + a2;
  }
  else
  {
    v18 = *(_DWORD *)(a2 + 12);
  }
LABEL_11:
  if ( (v17 & 0x10) == 0 )
  {
LABEL_12:
    v20 = 0;
    goto LABEL_17;
  }
  if ( (*(_WORD *)(a2 + 2) & 0x8000) != 0 )
  {
    v21 = *(_DWORD *)(a2 + 12);
    if ( !v21 )
      goto LABEL_12;
    v20 = v21 + a2;
  }
  else
  {
    v20 = *(_DWORD *)(a2 + 12);
  }
LABEL_17:
  SeExamineSacl(v20, v18, v16, 2, 1, &v41, v42);
  RtlInitUnicodeString((unsigned int)v63, L"Key");
  if ( v14 )
    v22 = v14;
  else
    v22 = v60;
  if ( (*(_WORD *)(a2 + 2) & 0x10) == 0 )
    goto LABEL_21;
  if ( (*(_WORD *)(a2 + 2) & 0x8000) != 0 )
  {
    v24 = *(_DWORD *)(a2 + 12);
    if ( !v24 )
    {
LABEL_21:
      v23 = 0;
      goto LABEL_26;
    }
    v23 = v24 + a2;
  }
  else
  {
    v23 = *(_DWORD *)(a2 + 12);
  }
LABEL_26:
  SeExamineGlobalSacl(v63, v23, v22, 2, 1, &v41, v42);
  if ( !v41 )
    return SeReleaseSubjectContext((int)v59);
  if ( v61 )
  {
    v25 = SepQueryNameString(v61, &v58);
    v9 = (unsigned int)v58;
    if ( v25 < 0 )
    {
LABEL_38:
      v28 = 0;
      goto LABEL_62;
    }
    if ( v58 )
      v10 = v58;
  }
  if ( !a8 )
  {
    RtlInitUnicodeString((unsigned int)&v52, L"-");
    RtlInitUnicodeString((unsigned int)&v43, L"-");
    goto LABEL_40;
  }
  *(_QWORD *)&v26 = *(_QWORD *)(a7 + 4);
  if ( v26 >= 0x1000 )
    v26 = 4096;
  if ( AdtpBuildRegistryValueString(*(_DWORD *)a7, v26, v27, &v52, &v39) < 0
    || (v43 = 0, v44 = 26, v45 = &v68, AdtpBuildReplacementString(*(_DWORD *)a7 + 1872, &v43) < 0) )
  {
    v56 = v39;
    goto LABEL_38;
  }
  v56 = v39;
LABEL_40:
  if ( a8 == 2 )
  {
    RtlInitUnicodeString((unsigned int)&v54, L"-");
    RtlInitUnicodeString((unsigned int)&v46, L"-");
    v28 = 0;
  }
  else
  {
    *(_QWORD *)&v29 = *(_QWORD *)(a7 + 16);
    if ( v29 >= 0x1000 )
      v29 = 4096;
    if ( AdtpBuildRegistryValueString(*(_DWORD *)(a7 + 12), v29, v30, &v54, &v40) < 0
      || (v46 = 0, v47 = 26, v48 = &v66, AdtpBuildReplacementString(*(_DWORD *)(a7 + 12) + 1872, &v46) < 0) )
    {
      v28 = v40;
      goto LABEL_62;
    }
    v28 = v40;
  }
  v49 = 0;
  v50 = 26;
  v51 = &v67;
  if ( AdtpBuildReplacementString(a8 + 1904, &v49) >= 0 )
  {
    v31 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
    v32 = *(_DWORD *)(v31 + 176);
    if ( SeLocateProcessImageName(v31) >= 0 )
    {
      v64 = 3;
      v65[3] = 524405;
      v65[0] = 4657;
      v65[5] = 4;
      if ( v14 )
        v33 = v14;
      else
        v33 = v60;
      v65[6] = 4 * (*(unsigned __int8 *)(**(_DWORD **)(v33 + 148) + 1) + 2);
      if ( v14 )
        v34 = v14;
      else
        v34 = v60;
      v65[9] = **(_DWORD **)(v34 + 148);
      v65[10] = 1;
      v65[11] = 24;
      v65[14] = (int)&SeSubsystemName;
      v65[15] = 5;
      v65[16] = 8;
      if ( !v14 )
        v14 = v60;
      v65[17] = *(_DWORD *)(v14 + 24);
      v65[18] = *(_DWORD *)(v14 + 28);
      if ( v10 )
      {
        v65[20] = 1;
        v35 = *v10;
        v65[24] = (int)v10;
        v65[21] = v35 + 8;
      }
      v65[25] = 1;
      v36 = *v62;
      v65[29] = (int)v62;
      v65[26] = v36 + 8;
      v65[30] = 11;
      v65[31] = 4;
      v37 = ObNormalizeHandleValue(a6);
      v65[35] = 1;
      v11 = (unsigned int)v57;
      v65[32] = v37;
      v65[36] = v49 + 8;
      v65[39] = (int)&v49;
      v65[40] = 1;
      v65[62] = v32;
      v65[69] = (int)v57;
      v65[41] = v43 + 8;
      v65[44] = (int)&v43;
      v65[45] = 1;
      v65[46] = v52 + 8;
      v65[49] = (int)&v52;
      v65[50] = 1;
      v65[51] = v46 + 8;
      v65[54] = (int)&v46;
      v65[55] = 1;
      v65[56] = v54 + 8;
      v65[59] = (int)&v54;
      v65[60] = 11;
      v65[61] = 4;
      v65[65] = 2;
      v65[66] = *v57 + 8;
      v65[1] = 13;
      SepAdtLogAuditRecord((int)&v64);
      goto LABEL_63;
    }
    v11 = (unsigned int)v57;
  }
LABEL_62:
  SepAuditFailed();
LABEL_63:
  if ( v56 )
    ExFreePoolWithTag(*(unsigned int *)&v53[2]);
  if ( v28 )
    ExFreePoolWithTag(*(unsigned int *)&v55[2]);
  if ( v11 )
    ExFreePoolWithTag(v11);
  if ( v9 )
    ExFreePoolWithTag(v9);
  return SeReleaseSubjectContext((int)v59);
}
