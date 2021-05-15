// EtwTraceProcess 
 
unsigned int __fastcall EtwTraceProcess(int a1, int *a2)
{
  int v4; // r9
  int v5; // r8
  BOOL v6; // r0
  unsigned int v7; // r8
  int *v8; // r7
  int v9; // r9
  int v10; // r3
  int *v11; // r10
  unsigned __int64 v12; // kr00_8
  int v13; // r9
  int v14; // r10
  __int64 v15; // kr10_8
  __int64 v16; // kr18_8
  unsigned __int16 *v17; // r2
  int v18; // r5
  unsigned int v19; // r3
  int *v20; // r5
  unsigned int v21; // r2
  unsigned int result; // r0
  unsigned int *v23; // r0
  unsigned int v24; // r4
  unsigned int v25; // r1
  unsigned int *v26; // r0
  unsigned int v27; // r4
  unsigned int v28; // r1
  char v29; // [sp+20h] [bp-480h] BYREF
  char v30; // [sp+21h] [bp-47Fh] BYREF
  char v31; // [sp+22h] [bp-47Eh] BYREF
  char v32; // [sp+23h] [bp-47Dh] BYREF
  char v33; // [sp+24h] [bp-47Ch] BYREF
  char v34; // [sp+25h] [bp-47Bh] BYREF
  int *v35[2]; // [sp+28h] [bp-478h] BYREF
  int *v36; // [sp+30h] [bp-470h] BYREF
  int v37; // [sp+34h] [bp-46Ch]
  int v38; // [sp+38h] [bp-468h] BYREF
  __int64 v39; // [sp+40h] [bp-460h] BYREF
  __int64 v40; // [sp+48h] [bp-458h] BYREF
  __int64 v41; // [sp+50h] [bp-450h] BYREF
  int v42[2]; // [sp+58h] [bp-448h] BYREF
  int v43[2]; // [sp+60h] [bp-440h] BYREF
  __int64 v44; // [sp+68h] [bp-438h] BYREF
  int v45[2]; // [sp+70h] [bp-430h] BYREF
  __int64 v46; // [sp+78h] [bp-428h] BYREF
  int v47[2]; // [sp+80h] [bp-420h] BYREF
  int v48; // [sp+88h] [bp-418h] BYREF
  unsigned __int16 v49[4]; // [sp+90h] [bp-410h] BYREF
  _QWORD v50[12]; // [sp+98h] [bp-408h] BYREF
  char v51[24]; // [sp+F8h] [bp-3A8h] BYREF
  char v52[24]; // [sp+110h] [bp-390h] BYREF
  int v53; // [sp+128h] [bp-378h]
  int v54[2]; // [sp+130h] [bp-370h] BYREF
  unsigned __int16 v55[128]; // [sp+138h] [bp-368h] BYREF
  unsigned __int16 v56[68]; // [sp+238h] [bp-268h] BYREF
  _DWORD v57[8]; // [sp+2C0h] [bp-1E0h] BYREF
  char *v58; // [sp+2E0h] [bp-1C0h]
  int v59; // [sp+2E4h] [bp-1BCh]
  int v60; // [sp+2E8h] [bp-1B8h]
  int v61; // [sp+2ECh] [bp-1B4h]
  char *v62; // [sp+2F0h] [bp-1B0h]
  int v63; // [sp+2F4h] [bp-1ACh]
  int v64; // [sp+2F8h] [bp-1A8h]
  int v65; // [sp+2FCh] [bp-1A4h]
  __int64 *v66; // [sp+300h] [bp-1A0h]
  int v67; // [sp+304h] [bp-19Ch]
  int v68; // [sp+308h] [bp-198h]
  int v69; // [sp+30Ch] [bp-194h]
  int *v70; // [sp+310h] [bp-190h]
  int v71; // [sp+314h] [bp-18Ch]
  int v72; // [sp+318h] [bp-188h]
  int v73; // [sp+31Ch] [bp-184h]
  int *v74; // [sp+320h] [bp-180h]
  int v75; // [sp+324h] [bp-17Ch]
  int v76; // [sp+328h] [bp-178h]
  int v77; // [sp+32Ch] [bp-174h]
  char *v78; // [sp+330h] [bp-170h]
  int v79; // [sp+334h] [bp-16Ch]
  int v80; // [sp+338h] [bp-168h] BYREF
  int v81; // [sp+33Ch] [bp-164h]
  int *v82; // [sp+340h] [bp-160h]
  int v83; // [sp+344h] [bp-15Ch]
  int v84; // [sp+348h] [bp-158h]
  int v85; // [sp+34Ch] [bp-154h]
  int **v86; // [sp+350h] [bp-150h]
  int v87; // [sp+354h] [bp-14Ch]
  int v88; // [sp+358h] [bp-148h]
  int v89; // [sp+35Ch] [bp-144h]
  int **v90; // [sp+360h] [bp-140h]
  int v91; // [sp+364h] [bp-13Ch]
  int v92; // [sp+368h] [bp-138h]
  int v93; // [sp+36Ch] [bp-134h]
  int *v94; // [sp+370h] [bp-130h]
  int v95; // [sp+374h] [bp-12Ch]
  int v96; // [sp+378h] [bp-128h]
  int v97; // [sp+37Ch] [bp-124h]
  __int64 *v98; // [sp+380h] [bp-120h]
  int v99; // [sp+384h] [bp-11Ch]
  int v100; // [sp+388h] [bp-118h]
  int v101; // [sp+38Ch] [bp-114h]
  int *v102; // [sp+390h] [bp-110h]
  int v103; // [sp+394h] [bp-10Ch]
  int v104; // [sp+398h] [bp-108h]
  int v105; // [sp+39Ch] [bp-104h]
  int v106[4]; // [sp+3A0h] [bp-100h] BYREF
  int v107[4]; // [sp+3B0h] [bp-F0h] BYREF
  int **v108; // [sp+3C0h] [bp-E0h]
  int v109; // [sp+3C4h] [bp-DCh]
  unsigned int v110; // [sp+3C8h] [bp-D8h]
  int v111; // [sp+3CCh] [bp-D4h]
  int *v112; // [sp+3D0h] [bp-D0h]
  int v113; // [sp+3D4h] [bp-CCh]
  int v114; // [sp+3D8h] [bp-C8h]
  int v115; // [sp+3DCh] [bp-C4h]
  unsigned int v116; // [sp+3E0h] [bp-C0h]
  int v117; // [sp+3E4h] [bp-BCh]
  int v118[2]; // [sp+3E8h] [bp-B8h] BYREF
  int v119[44]; // [sp+3F0h] [bp-B0h] BYREF

  v4 = 0;
  v5 = 1;
  if ( a2 == (int *)770 )
    return sub_7C37E8();
  if ( *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) != a1 )
  {
    v26 = (unsigned int *)(a1 + 172);
    __pld((void *)(a1 + 172));
    v27 = *(_DWORD *)(a1 + 172) & 0xFFFFFFFE;
    do
      v28 = __ldrex(v26);
    while ( v28 == v27 && __strex(v27 + 2, v26) );
    __dmb(0xBu);
    if ( v28 == v27 || ExfAcquireRundownProtection(v26) )
    {
      KiStackAttachProcess(a1, 0, (int)v51);
      v4 = 1;
    }
    else
    {
      v5 = 0;
    }
  }
  v39 = 0i64;
  EtwpBuildProcessEvent(a1, a2, v5, (int)v52, v47, v119, &v48, v54, v49, (unsigned __int16 *)&v39, v35);
  if ( v4 )
  {
    KiUnstackDetachProcess((unsigned int)v51, 0);
    v23 = (unsigned int *)(a1 + 172);
    __pld((void *)(a1 + 172));
    v24 = *(_DWORD *)(a1 + 172) & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v25 = __ldrex(v23);
    while ( v25 == v24 && __strex(v24 - 2, v23) );
    if ( v25 != v24 )
      ExfReleaseRundownProtection((unsigned __int8 *)v23);
  }
  if ( (dword_61AD40 & 1) != 0 )
    EtwpPsProvTraceProcess((_DWORD *)a1, v53, v54, (int)v47, (__int16)a2);
  v6 = TraceLoggingProviderEnabled(&dword_616438);
  v7 = HIDWORD(v39);
  v8 = v35[0];
  if ( v6 )
  {
    if ( a2 == (int *)769 )
    {
      memset(v50, 0, sizeof(v50));
      v10 = *(_DWORD *)(a1 + 820);
      v45[0] = *(_DWORD *)(a1 + 816);
      v9 = v45[0];
      v11 = (int *)(v10 | (MEMORY[0xFFFF92C4] << 16));
      v36 = v11;
      EtwpGetProcessAppSessionGuid((_DWORD *)a1, (int)&v50[3]);
      v50[1] = v50[3];
      v50[2] = __PAIR64__((unsigned int)v11, v9);
      v50[0] = 0i64;
      __dmb(0xBu);
      do
      {
        v12 = __ldrexd(EtwpAppStateChangeSequenceNumber);
        v14 = (v12 + 1) >> 32;
        v13 = v12 + 1;
      }
      while ( __strexd(v12 + 1, EtwpAppStateChangeSequenceNumber) );
      __dmb(0xBu);
      v15 = *(_QWORD *)(a1 + 816);
      v50[10] = __PAIR64__(v14, v13);
      v43[0] = HIDWORD(v15);
      v35[0] = (int *)v15;
      v50[11] = v15;
      v16 = MmGetSessionCreateTime(a1);
      LODWORD(v40) = HIDWORD(v16);
      v42[0] = v16;
      v38 = PsGetProcessSessionId(a1);
      LODWORD(v41) = dword_616438;
      if ( (unsigned int)dword_616438 > 5 )
      {
        if ( TlgKeywordOn((int)&dword_616438, 3i64) )
        {
          v17 = *(unsigned __int16 **)(a1 + 380);
          v44 = *(_QWORD *)(a1 + 200);
          LODWORD(v46) = *(_DWORD *)(a1 + 176);
          LODWORD(v41) = *(_DWORD *)(a1 + 312);
          v45[1] = (int)v36;
          v36 = v35[0];
          v37 = v43[0];
          v35[0] = *(int **)(a1 + 824);
          v35[1] = *(int **)(a1 + 828);
          v43[0] = v42[0];
          v43[1] = v40;
          LODWORD(v40) = v47[0];
          v42[0] = v47[1];
          if ( v8 )
            v18 = *v8;
          else
            v18 = SeNullSid;
          v58 = (char *)&v44;
          v59 = 0;
          v60 = 8;
          v61 = 0;
          v62 = (char *)&v46;
          v63 = 0;
          v64 = 4;
          v65 = 0;
          v66 = &v41;
          v67 = 0;
          v68 = 4;
          v69 = 0;
          v70 = &v38;
          v71 = 0;
          v72 = 4;
          v73 = 0;
          v74 = &v80;
          v75 = 0;
          v76 = 2;
          v77 = 0;
          v78 = (char *)*((_DWORD *)v17 + 1);
          v79 = 0;
          v80 = *v17;
          v81 = 0;
          v82 = v45;
          v83 = 0;
          v84 = 8;
          v85 = 0;
          v86 = &v36;
          v87 = 0;
          v88 = 8;
          v89 = 0;
          v90 = v35;
          v91 = 0;
          v92 = 8;
          v93 = 0;
          v94 = v43;
          v95 = 0;
          v96 = 8;
          v97 = 0;
          v98 = &v40;
          v99 = 0;
          v100 = 4;
          v101 = 0;
          v102 = v42;
          v103 = 0;
          v104 = 4;
          v105 = 0;
          TlgCreateWsz((int)v106, v55);
          TlgCreateWsz((int)v107, v56);
          v19 = *(unsigned __int8 *)(v18 + 1);
          if ( v19 > 0xF )
            v19 = 15;
          v110 = 4 * (v19 + 2);
          v111 = 0;
          v112 = v118;
          v113 = 0;
          v114 = 2;
          v115 = 0;
          v116 = v7;
          v117 = 0;
          v108 = (int **)v18;
          v109 = 0;
          v118[0] = (unsigned __int16)v39;
          v118[1] = 0;
          TlgWrite(&dword_616438, &dword_414AA8[1], 0, 0, 19, v57);
          v20 = (int *)v50[11];
          v14 = HIDWORD(v50[10]);
          v13 = v50[10];
          v21 = dword_616438;
          v43[0] = HIDWORD(v50[11]);
        }
        else
        {
          v21 = v41;
          v20 = v35[0];
        }
        if ( v21 > 5 && TlgKeywordOn((int)&dword_616438, 0x400000000001i64) )
        {
          v42[0] = v13;
          v42[1] = v14;
          v36 = v20;
          v33 = v50[0];
          v31 = BYTE4(v50[0]);
          v32 = 1;
          v34 = 1;
          v29 = 1;
          v44 = v50[5];
          v39 = v50[6];
          v41 = v50[7];
          v46 = v50[8];
          v40 = v50[9];
          v30 = 1;
          v37 = v43[0];
          v58 = &v33;
          v59 = 0;
          v60 = 1;
          v61 = 0;
          v62 = &v31;
          v63 = 0;
          v64 = 1;
          v65 = 0;
          v66 = &v50[1];
          v67 = 0;
          v68 = 16;
          v69 = 0;
          v70 = (int *)&v32;
          v71 = 0;
          v72 = 1;
          v73 = 0;
          v74 = (int *)&v34;
          v75 = 0;
          v76 = 1;
          v77 = 0;
          v78 = &v29;
          v79 = 0;
          v80 = 1;
          v81 = 0;
          v82 = (int *)&v50[3];
          v83 = 0;
          v84 = 16;
          v85 = 0;
          v86 = (int **)&v44;
          v87 = 0;
          v88 = 8;
          v89 = 0;
          v90 = (int **)&v39;
          v91 = 0;
          v92 = 8;
          v93 = 0;
          v94 = (int *)&v41;
          v95 = 0;
          v96 = 8;
          v97 = 0;
          v98 = &v46;
          v99 = 0;
          v100 = 8;
          v101 = 0;
          v102 = (int *)&v40;
          v103 = 0;
          v104 = 8;
          v105 = 0;
          v106[0] = (int)&v30;
          v106[1] = 0;
          v106[2] = 1;
          v106[3] = 0;
          v107[0] = (int)v42;
          v107[1] = 0;
          v107[2] = 8;
          v107[3] = 0;
          v108 = &v36;
          v109 = 0;
          v110 = 8;
          v111 = 0;
          TlgWrite(&dword_616438, (unsigned __int8 *)&byte_4148A9[1], 0, 0, 17, v57);
        }
      }
    }
  }
  EtwTraceKernelEvent(v119, v48, 1u, (int)a2, (int)off_501904);
  result = RtlFreeAnsiString(v49);
  if ( v7 )
    result = ExFreePoolWithTag(v7);
  if ( v8 )
    result = ExFreePoolWithTag((unsigned int)v8);
  return result;
}
