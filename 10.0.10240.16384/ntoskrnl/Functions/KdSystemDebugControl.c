// KdSystemDebugControl 
 
int __fastcall KdSystemDebugControl(int a1, int *a2, int a3, int a4, int a5, int *a6, char a7)
{
  int v8; // r10
  int v9; // r8
  int v10; // r9
  int result; // r0
  int v12; // r5
  int v13; // r2
  int v14; // r3
  int v15; // r4
  int v16; // r0
  int v17; // r1
  int v18; // r0
  int v19; // r2
  int v20; // r3
  int v21; // r1
  int v22; // r2
  int v23; // r3
  int v24; // r1
  int v25; // r2
  int v26; // r3
  int v27; // r0
  int v28; // r1
  int v29; // r2
  int v30; // r3
  int *v31; // r6
  int v32; // r3
  int v33; // r4
  int v34; // r1
  int v35; // r0
  int v36; // r1
  int v37; // r2
  int v38; // r3
  int *v39; // r6
  int v40; // r3
  int v41; // r4
  int v42; // r1
  int v43; // r0
  int v44; // r1
  int v45; // r2
  int v46; // r3
  int *v47; // r6
  int v48; // r1
  int v49; // r2
  int v50; // r3
  int v51; // r0
  int v52; // r1
  int v53; // r2
  int v54; // r3
  int *v55; // r6
  int v56; // r1
  int v57; // r2
  int v58; // r3
  int v59; // r0
  int v60; // r0
  int v61; // r1
  int v62; // r2
  int v63; // r3
  int *v64; // r6
  int v65; // r3
  int v66; // r4
  int v67; // r0
  int v68; // r1
  int v69; // r2
  int v70; // r3
  int *v71; // r6
  int v72; // r3
  int v73; // r4
  int v74; // [sp+4h] [bp-124h]
  int v75; // [sp+1Ch] [bp-10Ch] BYREF
  int v76; // [sp+20h] [bp-108h] BYREF
  int v77; // [sp+24h] [bp-104h] BYREF
  int v78; // [sp+28h] [bp-100h]
  int v79; // [sp+2Ch] [bp-FCh]
  int v80; // [sp+30h] [bp-F8h]
  int v81; // [sp+38h] [bp-F0h]
  int v82; // [sp+3Ch] [bp-ECh]
  int v83; // [sp+40h] [bp-E8h]
  int v84; // [sp+48h] [bp-E0h]
  int v85; // [sp+4Ch] [bp-DCh]
  int v86; // [sp+50h] [bp-D8h]
  int v87; // [sp+54h] [bp-D4h]
  int v88; // [sp+58h] [bp-D0h]
  int v89; // [sp+5Ch] [bp-CCh]
  int v90; // [sp+60h] [bp-C8h]
  int v91; // [sp+64h] [bp-C4h]
  int v92; // [sp+68h] [bp-C0h]
  int v93; // [sp+6Ch] [bp-BCh]
  int v94; // [sp+70h] [bp-B8h]
  int v95; // [sp+74h] [bp-B4h]
  int v96; // [sp+78h] [bp-B0h]
  int v97; // [sp+7Ch] [bp-ACh]
  int v98; // [sp+80h] [bp-A8h]
  int v99; // [sp+84h] [bp-A4h]
  int v100; // [sp+88h] [bp-A0h]
  int v101; // [sp+8Ch] [bp-9Ch]
  int v102; // [sp+90h] [bp-98h]
  int v103; // [sp+94h] [bp-94h]
  int v104; // [sp+98h] [bp-90h]
  int v105; // [sp+9Ch] [bp-8Ch]
  int v106; // [sp+A0h] [bp-88h]
  int v107; // [sp+A4h] [bp-84h]
  int v108; // [sp+A8h] [bp-80h]
  int v109; // [sp+ACh] [bp-7Ch]
  int v110; // [sp+B0h] [bp-78h]
  int v111; // [sp+B4h] [bp-74h]
  int v112; // [sp+B8h] [bp-70h]
  int v113; // [sp+BCh] [bp-6Ch]
  int v114; // [sp+C0h] [bp-68h]
  int v115; // [sp+C4h] [bp-64h]
  int v116; // [sp+C8h] [bp-60h]
  int v117; // [sp+CCh] [bp-5Ch]
  int v118; // [sp+D0h] [bp-58h]
  int v119; // [sp+D4h] [bp-54h]
  int v120; // [sp+D8h] [bp-50h]
  int v121; // [sp+DCh] [bp-4Ch]
  int v122; // [sp+E0h] [bp-48h]
  int v123; // [sp+E4h] [bp-44h]
  int v124; // [sp+E8h] [bp-40h]
  int v125; // [sp+ECh] [bp-3Ch]
  int v126; // [sp+F0h] [bp-38h]
  int v127; // [sp+F4h] [bp-34h]
  int v128; // [sp+F8h] [bp-30h]
  int v129; // [sp+FCh] [bp-2Ch]
  int v130; // [sp+100h] [bp-28h]
  int v131; // [sp+104h] [bp-24h]

  v8 = 0;
  v75 = 0;
  v9 = 0;
  v77 = 0;
  v10 = 0;
  v76 = 0;
  if ( (KdpBootedNodebug || KdPitchDebugger || !KdDebuggerEnabled) && !KdLocalDebugEnabled )
    return -1073741790;
  switch ( a1 )
  {
    case 7:
      if ( a5 == 40 )
      {
        KdpSysGetVersion(a4);
        v12 = 0;
        goto LABEL_75;
      }
      result = -1073741820;
      v75 = -1073741820;
      break;
    case 8:
      if ( a3 == 12 )
      {
        v13 = a2[1];
        v14 = a2[2];
        v78 = *a2;
        v79 = v13;
        v80 = v14;
        v15 = v14;
        if ( !v14 )
          goto LABEL_13;
        v12 = ExLockUserBuffer(v79, v14, a7, 1, &v77, &v76);
        if ( v12 >= 0 )
        {
          v74 = 0;
          v16 = v78;
          goto LABEL_16;
        }
        goto LABEL_50;
      }
      result = -1073741820;
      v75 = -1073741820;
      break;
    case 9:
      if ( a3 == 12 )
      {
        v19 = a2[1];
        v20 = a2[2];
        v81 = *a2;
        v82 = v19;
        v83 = v20;
        v15 = v20;
        if ( !v20 )
          goto LABEL_13;
        v12 = ExLockUserBuffer(v82, v20, a7, 0, &v77, &v76);
        if ( v12 >= 0 )
        {
          v74 = 1;
          v16 = v81;
LABEL_16:
          v17 = 0;
          goto LABEL_17;
        }
        goto LABEL_50;
      }
      result = -1073741820;
      v75 = -1073741820;
      break;
    case 10:
      if ( a3 == 16 )
      {
        v21 = a2[1];
        v22 = a2[2];
        v23 = a2[3];
        v84 = *a2;
        v85 = v21;
        v86 = v22;
        v87 = v23;
        v15 = v23;
        if ( !v23 )
          goto LABEL_13;
        v12 = ExLockUserBuffer(v86, v23, a7, 1, &v77, &v76);
        if ( v12 >= 0 )
        {
          v74 = 2;
          v17 = v85;
          v16 = v84;
          goto LABEL_17;
        }
        goto LABEL_50;
      }
      result = -1073741820;
      v75 = -1073741820;
      break;
    case 11:
      if ( a3 == 16 )
      {
        v24 = a2[1];
        v25 = a2[2];
        v26 = a2[3];
        v88 = *a2;
        v89 = v24;
        v90 = v25;
        v91 = v26;
        v15 = v26;
        if ( !v26 )
          goto LABEL_13;
        v12 = ExLockUserBuffer(v90, v26, a7, 0, &v77, &v76);
        if ( v12 >= 0 )
        {
          v74 = 3;
          v17 = v89;
          v16 = v88;
LABEL_17:
          v9 = v77;
          v18 = KdpCopyMemoryChunks(v16, v17, v77, v15, 0, v74, &v75);
          goto LABEL_18;
        }
        goto LABEL_50;
      }
      result = -1073741820;
      v75 = -1073741820;
      break;
    case 12:
      if ( a3 == 24 )
      {
        v27 = *a2;
        v28 = a2[1];
        v29 = a2[2];
        v30 = a2[3];
        v31 = a2 + 4;
        v104 = v27;
        v105 = v28;
        v106 = v29;
        v107 = v30;
        v32 = v31[1];
        v108 = *v31;
        v109 = v32;
        v33 = v107;
        if ( !v107 )
          goto LABEL_13;
        v12 = ExLockUserBuffer(v106, v107, a7, 1, &v77, &v76);
        if ( v12 >= 0 )
        {
          v9 = v77;
          v18 = KdpSysReadControlSpace(v108, v34, v104, v105, v77, v33, &v75);
          goto LABEL_18;
        }
        goto LABEL_50;
      }
      result = -1073741820;
      v75 = -1073741820;
      break;
    case 13:
      if ( a3 == 24 )
      {
        v35 = *a2;
        v36 = a2[1];
        v37 = a2[2];
        v38 = a2[3];
        v39 = a2 + 4;
        v110 = v35;
        v111 = v36;
        v112 = v37;
        v113 = v38;
        v40 = v39[1];
        v114 = *v39;
        v115 = v40;
        v41 = v113;
        if ( !v113 )
          goto LABEL_13;
        v12 = ExLockUserBuffer(v112, v113, a7, 0, &v77, &v76);
        if ( v12 >= 0 )
        {
          v9 = v77;
          v18 = KdpSysWriteControlSpace(v114, v42, v110, v111, v77, v41, &v75);
          goto LABEL_18;
        }
        goto LABEL_50;
      }
      result = -1073741820;
      v75 = -1073741820;
      break;
    case 14:
      if ( a3 == 32 )
      {
        v43 = *a2;
        v44 = a2[1];
        v45 = a2[2];
        v46 = a2[3];
        v47 = a2 + 4;
        v116 = v43;
        v117 = v44;
        v118 = v45;
        v119 = v46;
        v48 = v47[1];
        v49 = v47[2];
        v50 = v47[3];
        v120 = *v47;
        v121 = v48;
        v122 = v49;
        v123 = v50;
        if ( !v119 )
          goto LABEL_13;
        v12 = ExLockUserBuffer(v118, v119, a7, 1, &v77, &v76);
        if ( v12 < 0 )
          goto LABEL_50;
        goto LABEL_49;
      }
      result = -1073741820;
      v75 = -1073741820;
      break;
    case 15:
      if ( a3 == 32 )
      {
        v51 = *a2;
        v52 = a2[1];
        v53 = a2[2];
        v54 = a2[3];
        v55 = a2 + 4;
        v124 = v51;
        v125 = v52;
        v126 = v53;
        v127 = v54;
        v56 = v55[1];
        v57 = v55[2];
        v58 = v55[3];
        v128 = *v55;
        v129 = v56;
        v130 = v57;
        v131 = v58;
        if ( !v127 )
          goto LABEL_13;
        v12 = ExLockUserBuffer(v126, v127, a7, 0, &v77, &v76);
        if ( v12 >= 0 )
LABEL_49:
          v12 = HvlQueryActiveProcessors();
        goto LABEL_50;
      }
      result = -1073741820;
      v75 = -1073741820;
      break;
    case 16:
      if ( a3 == 16 )
      {
        v59 = KdpSysReadMsr(*a2, a2 + 2);
        goto LABEL_59;
      }
      result = -1073741820;
      v75 = -1073741820;
      break;
    case 17:
      if ( a3 == 16 )
      {
        v59 = KdpSysWriteMsr(*a2, a2 + 2);
        goto LABEL_59;
      }
      result = -1073741820;
      v75 = -1073741820;
      break;
    case 18:
      if ( a3 == 24 )
      {
        v60 = *a2;
        v61 = a2[1];
        v62 = a2[2];
        v63 = a2[3];
        v64 = a2 + 4;
        v92 = v60;
        v93 = v61;
        v94 = v62;
        v95 = v63;
        v65 = v64[1];
        v96 = *v64;
        v97 = v65;
        v66 = v62;
        if ( !v62 )
          goto LABEL_13;
        v12 = ExLockUserBuffer(v93, v62, a7, 1, &v77, &v76);
        if ( v12 >= 0 )
        {
          v9 = v77;
          v18 = KdpSysReadBusData(v95, v96, v97, v92, v77, v66, &v75);
          goto LABEL_18;
        }
        goto LABEL_50;
      }
      result = -1073741820;
      v75 = -1073741820;
      break;
    case 19:
      if ( a3 == 24 )
      {
        v67 = *a2;
        v68 = a2[1];
        v69 = a2[2];
        v70 = a2[3];
        v71 = a2 + 4;
        v98 = v67;
        v99 = v68;
        v100 = v69;
        v101 = v70;
        v72 = v71[1];
        v102 = *v71;
        v103 = v72;
        v73 = v69;
        if ( v69 )
        {
          v12 = ExLockUserBuffer(v99, v69, a7, 0, &v77, &v76);
          if ( v12 < 0 )
          {
LABEL_50:
            v9 = v77;
          }
          else
          {
            v9 = v77;
            v18 = KdpSysWriteBusData(v101, v102, v103, v98, v77, v73, &v75);
LABEL_18:
            v12 = v18;
            v8 = v75;
          }
          v10 = v76;
        }
        else
        {
LABEL_13:
          v12 = -1073741819;
        }
        goto LABEL_75;
      }
      result = -1073741820;
      v75 = -1073741820;
      break;
    case 20:
      v59 = KdpSysCheckLowMemory(0);
LABEL_59:
      v12 = v59;
      goto LABEL_75;
    default:
      v12 = -1073741821;
LABEL_75:
      if ( a6 )
        *a6 = v8;
      if ( v9 )
        ExUnlockUserBuffer(v10);
      result = v12;
      break;
  }
  return result;
}
