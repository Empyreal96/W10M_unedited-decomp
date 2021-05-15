// EtwpPsProvTraceProcess 
 
int __fastcall EtwpPsProvTraceProcess(_DWORD *a1, int a2, int *a3, int a4, __int16 a5)
{
  int *v8; // r7
  int v9; // r0
  char v10; // r1
  int v11; // r3
  char *v12; // r1
  int v13; // r3
  int v14; // r2
  int result; // r0
  int v16; // r5
  unsigned int v17; // r6
  int v18; // r0
  unsigned int v19; // r4
  int v20; // r3
  int v21; // r0
  unsigned int v22; // r2
  unsigned int v23; // r2
  bool v24; // zf
  __int64 v25; // r2
  __int64 v26; // r2
  char *v27; // r0
  int v28; // r4
  __int64 v29; // r8
  int v30; // [sp+8h] [bp-1D0h] BYREF
  int v31; // [sp+Ch] [bp-1CCh] BYREF
  _DWORD *v32; // [sp+10h] [bp-1C8h] BYREF
  int v33; // [sp+14h] [bp-1C4h] BYREF
  int *v34; // [sp+18h] [bp-1C0h] BYREF
  int v35; // [sp+1Ch] [bp-1BCh] BYREF
  int v36; // [sp+20h] [bp-1B8h] BYREF
  int v37; // [sp+24h] [bp-1B4h] BYREF
  int v38; // [sp+28h] [bp-1B0h] BYREF
  int v39; // [sp+2Ch] [bp-1ACh] BYREF
  int v40; // [sp+30h] [bp-1A8h] BYREF
  int v41; // [sp+34h] [bp-1A4h] BYREF
  int v42; // [sp+38h] [bp-1A0h] BYREF
  unsigned __int64 v43; // [sp+40h] [bp-198h] BYREF
  unsigned __int64 v44; // [sp+48h] [bp-190h] BYREF
  char v45[8]; // [sp+50h] [bp-188h] BYREF
  char v46[16]; // [sp+58h] [bp-180h] BYREF
  char v47; // [sp+68h] [bp-170h] BYREF
  int v48; // [sp+78h] [bp-160h]
  int v49; // [sp+7Ch] [bp-15Ch]
  int v50; // [sp+80h] [bp-158h]
  int v51; // [sp+84h] [bp-154h]
  __int64 v52; // [sp+90h] [bp-148h]
  __int64 v53; // [sp+98h] [bp-140h]
  int *v54; // [sp+A8h] [bp-130h]
  int v55; // [sp+ACh] [bp-12Ch]
  int v56; // [sp+B0h] [bp-128h]
  int v57; // [sp+B4h] [bp-124h]
  _DWORD *v58; // [sp+B8h] [bp-120h]
  int v59; // [sp+BCh] [bp-11Ch]
  int v60; // [sp+C0h] [bp-118h]
  int v61; // [sp+C4h] [bp-114h]
  int *v62; // [sp+C8h] [bp-110h]
  int v63; // [sp+CCh] [bp-10Ch]
  int v64; // [sp+D0h] [bp-108h]
  int v65; // [sp+D4h] [bp-104h]
  int *v66; // [sp+D8h] [bp-100h]
  int v67; // [sp+DCh] [bp-FCh]
  int v68; // [sp+E0h] [bp-F8h]
  int v69; // [sp+E4h] [bp-F4h]
  int *v70; // [sp+E8h] [bp-F0h]
  int v71; // [sp+ECh] [bp-ECh]
  int v72; // [sp+F0h] [bp-E8h]
  int v73; // [sp+F4h] [bp-E4h]
  int *v74; // [sp+F8h] [bp-E0h]
  int v75; // [sp+FCh] [bp-DCh]
  int v76; // [sp+100h] [bp-D8h]
  int v77; // [sp+104h] [bp-D4h]
  int *v78; // [sp+108h] [bp-D0h]
  int v79; // [sp+10Ch] [bp-CCh]
  int v80; // [sp+110h] [bp-C8h]
  int v81; // [sp+114h] [bp-C4h]
  unsigned __int64 *v82; // [sp+118h] [bp-C0h]
  int v83; // [sp+11Ch] [bp-BCh]
  int v84; // [sp+120h] [bp-B8h]
  int v85; // [sp+124h] [bp-B4h]
  char *v86; // [sp+128h] [bp-B0h]
  int v87; // [sp+12Ch] [bp-ACh]
  int v88; // [sp+130h] [bp-A8h]
  int v89; // [sp+134h] [bp-A4h]
  int *v90; // [sp+138h] [bp-A0h]
  int v91; // [sp+13Ch] [bp-9Ch]
  int v92; // [sp+140h] [bp-98h]
  int v93; // [sp+144h] [bp-94h]
  int *v94; // [sp+148h] [bp-90h]
  int v95; // [sp+14Ch] [bp-8Ch]
  int v96; // [sp+150h] [bp-88h]
  int v97; // [sp+154h] [bp-84h]
  int *v98; // [sp+158h] [bp-80h]
  int v99; // [sp+15Ch] [bp-7Ch]
  int v100; // [sp+160h] [bp-78h]
  int v101; // [sp+164h] [bp-74h]
  int *v102; // [sp+168h] [bp-70h]
  int v103; // [sp+16Ch] [bp-6Ch]
  int v104; // [sp+170h] [bp-68h]
  int v105; // [sp+174h] [bp-64h]
  _DWORD *v106; // [sp+178h] [bp-60h]
  int v107; // [sp+17Ch] [bp-5Ch]
  int v108; // [sp+180h] [bp-58h]
  int v109; // [sp+184h] [bp-54h]
  _DWORD *v110; // [sp+188h] [bp-50h]
  int v111; // [sp+18Ch] [bp-4Ch]
  char *v112; // [sp+190h] [bp-48h]
  int v113; // [sp+194h] [bp-44h]
  unsigned __int16 v114[32]; // [sp+198h] [bp-40h] BYREF

  v30 = 0;
  if ( a5 == 769 )
  {
    v8 = ProcessStart;
  }
  else
  {
    if ( a5 != 770 )
      return sub_7C3744();
    v8 = ProcessStop;
  }
  v41 = a1[44];
  v54 = &v41;
  v55 = 0;
  v56 = 4;
  v57 = 0;
  v58 = a1 + 50;
  v59 = 0;
  v60 = 8;
  v61 = 0;
  if ( a5 == 769 || a5 == 771 )
  {
    v39 = a1[78];
    v62 = &v39;
    v63 = 0;
    v64 = 4;
    v65 = 0;
    v9 = MmGetSessionId((int)a1);
    v66 = &v40;
    v67 = 0;
    v68 = 4;
    v11 = 0;
    v69 = 0;
    v31 = 0;
    v40 = v9;
    if ( (v10 & 1) != 0 )
    {
      v11 = 1;
      v31 = 1;
    }
    if ( (v10 & 8) != 0 )
      v31 = v11 | 2;
    v70 = &v31;
    v71 = 0;
    v12 = (char *)a1[95];
    v72 = 4;
    v73 = 0;
    if ( !v12 || !*(_WORD *)v12 )
    {
      RtlStringCchPrintfW(v114, 0xFu, (int)L"%S", (int)(a1 + 90));
      RtlInitUnicodeString((unsigned int)v45, v114);
      v12 = v45;
    }
    v13 = *((_DWORD *)v12 + 1);
    v14 = *(unsigned __int16 *)v12;
    v82 = (unsigned __int64 *)a4;
    v74 = (int *)v13;
    v75 = 0;
    v76 = v14;
    v77 = 0;
    v78 = &EtwpNull;
    v79 = 0;
    v80 = 2;
    v81 = 0;
    v83 = 0;
    v84 = 4;
    v85 = 0;
    v86 = (char *)(a4 + 4);
    v87 = 0;
    v88 = 4;
    v89 = 0;
    v90 = a3 + 2;
    v91 = 0;
    v92 = *a3;
    v93 = 0;
    v94 = a3 + 66;
    v95 = 0;
    v96 = a3[1];
    v97 = 0;
  }
  else if ( a5 == 770 )
  {
    v34 = 0;
    PsQueryStatisticsProcess((int)a1, (int)v46);
    v62 = a1 + 174;
    v63 = 0;
    v64 = 8;
    v65 = 0;
    v66 = a1 + 158;
    v67 = 0;
    v68 = 4;
    v69 = 0;
    v17 = PsReferencePrimaryToken(a1);
    v18 = SeQueryInformationToken(v17, 18, &v34);
    v19 = (unsigned int)v34;
    if ( v18 >= 0 )
    {
      if ( *v34 == 1 )
      {
        v32 = 0;
        if ( SeQueryInformationToken(v17, 20, &v32) >= 0 )
        {
          if ( *v32 )
            v20 = 1;
          else
            v20 = 4;
          v30 = v20;
        }
        if ( v32 )
          ExFreePoolWithTag((unsigned int)v32);
      }
      else
      {
        v30 = *v34;
      }
    }
    ObFastDereferenceObject(a1 + 61, v17);
    if ( v19 )
      ExFreePoolWithTag(v19);
    v70 = &v30;
    v71 = 0;
    v72 = 4;
    v73 = 0;
    v21 = ObGetProcessHandleCount(a1, 0);
    v74 = &v38;
    v75 = 0;
    v76 = 4;
    v77 = 0;
    v38 = v21;
    v22 = a1[121];
    __dmb(0xBu);
    v43 = (unsigned __int64)v22 << 12;
    v78 = (int *)&v43;
    v79 = 0;
    v80 = 8;
    v81 = 0;
    v23 = a1[122];
    __dmb(0xBu);
    v44 = (unsigned __int64)v23 << 12;
    v82 = &v44;
    v83 = 0;
    v84 = 8;
    v85 = 0;
    v86 = &v47;
    v87 = 0;
    v88 = 8;
    v89 = 0;
    if ( v49 )
      v36 = -1;
    else
      v36 = v48;
    v90 = &v36;
    v91 = 0;
    v92 = 4;
    v93 = 0;
    if ( v51 )
      v33 = -1;
    else
      v33 = v50;
    v94 = &v33;
    v95 = 0;
    v96 = 4;
    v97 = 0;
    v25 = v52 >> 10;
    v24 = SHIDWORD(v52) >> 10 == 0;
    v52 >>= 10;
    if ( v24 )
      v35 = v25;
    else
      v35 = -1;
    v98 = &v35;
    v99 = 0;
    v100 = 4;
    v101 = 0;
    v26 = v53 >> 10;
    v24 = SHIDWORD(v53) >> 10 == 0;
    v53 >>= 10;
    if ( v24 )
      v37 = v26;
    else
      v37 = -1;
    v102 = &v37;
    v103 = 0;
    v104 = 4;
    v105 = 0;
    v106 = a1 + 145;
    v107 = 0;
    v108 = 4;
    v109 = 0;
    v27 = strlen((unsigned int)(a1 + 90));
    v110 = a1 + 90;
    v111 = 0;
    v112 = v27 + 1;
    v113 = 0;
  }
  EtwWrite(EtwpPsProvRegHandle, dword_61A934, (int)v8, 0);
  result = PsGetProcessServerSilo(a1);
  v16 = result;
  if ( result )
  {
    PsGetMonitorContextServerSilo(EtwSiloMonitor, result, &v42);
    v28 = v42;
    if ( v42 )
    {
      v29 = *(_QWORD *)(v42 + 368);
      if ( EtwProviderEnabled(*(_DWORD *)(v42 + 368), *(_DWORD *)(v42 + 372), 0, 0, 16i64) )
        EtwWrite(v29, SHIDWORD(v29), (int)v8, 0);
      PsDereferenceMonitorContextServerSilo(v28);
    }
    result = PspDereferenceSiloObject(v16);
  }
  return result;
}
