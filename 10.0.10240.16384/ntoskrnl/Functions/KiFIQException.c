// KiFIQException 
 
void __fastcall __noreturn KiFIQException(__int64 a1, __int64 a2, int a3, unsigned int a4)
{
  unsigned int v4; // r12
  int v5; // lr
  __int64 v6; // d0
  __int64 v7; // d1
  __int64 v8; // d2
  __int64 v9; // d3
  __int64 v10; // d4
  __int64 v11; // d5
  __int64 v12; // d6
  __int64 v13; // d7
  __int64 v14; // d8
  __int64 v15; // d9
  __int64 v16; // d10
  __int64 v17; // d11
  __int64 v18; // d12
  __int64 v19; // d13
  __int64 v20; // d14
  __int64 v21; // d15
  __int64 v22; // d16
  __int64 v23; // d17
  __int64 v24; // d18
  __int64 v25; // d19
  __int64 v26; // d20
  __int64 v27; // d21
  __int64 v28; // d22
  __int64 v29; // d23
  __int64 v30; // d24
  __int64 v31; // d25
  __int64 v32; // d26
  __int64 v33; // d27
  __int64 v34; // d28
  __int64 v35; // d29
  __int64 v36; // d30
  __int64 v37; // d31
  unsigned int v42; // r12
  char v43; // r1
  char *v44; // r1
  unsigned int v46; // r0
  unsigned int v47; // r1
  __int64 v48; // r0
  int v49; // r3
  _QWORD *v50; // r12
  __int64 v51; // r2
  unsigned __int64 v52; // r2
  unsigned __int64 v53; // r2
  int v54[24]; // [sp+0h] [bp-1A4h] BYREF
  __int64 v55; // [sp+60h] [bp-144h]
  __int64 v56; // [sp+68h] [bp-13Ch]
  unsigned __int64 v57; // [sp+70h] [bp-134h]
  __int64 v58; // [sp+78h] [bp-12Ch]
  unsigned __int64 v59; // [sp+80h] [bp-124h]
  char v60; // [sp+88h] [bp-11Ch] BYREF
  int v61; // [sp+8Ch] [bp-118h]
  __int64 v62; // [sp+98h] [bp-10Ch]
  __int64 v63; // [sp+A0h] [bp-104h]
  __int64 v64; // [sp+A8h] [bp-FCh]
  __int64 v65; // [sp+B0h] [bp-F4h]
  __int64 v66; // [sp+B8h] [bp-ECh]
  __int64 v67; // [sp+C0h] [bp-E4h]
  __int64 v68; // [sp+C8h] [bp-DCh]
  __int64 v69; // [sp+D0h] [bp-D4h]
  __int64 v70; // [sp+D8h] [bp-CCh]
  __int64 v71; // [sp+E0h] [bp-C4h]
  __int64 v72; // [sp+E8h] [bp-BCh]
  __int64 v73; // [sp+F0h] [bp-B4h]
  __int64 v74; // [sp+F8h] [bp-ACh]
  __int64 v75; // [sp+100h] [bp-A4h]
  __int64 v76; // [sp+108h] [bp-9Ch]
  __int64 v77; // [sp+110h] [bp-94h]
  __int64 v78; // [sp+118h] [bp-8Ch]
  __int64 v79; // [sp+120h] [bp-84h]
  __int64 v80; // [sp+128h] [bp-7Ch]
  __int64 v81; // [sp+130h] [bp-74h]
  __int64 v82; // [sp+138h] [bp-6Ch]
  __int64 v83; // [sp+140h] [bp-64h]
  __int64 v84; // [sp+148h] [bp-5Ch]
  __int64 v85; // [sp+150h] [bp-54h]
  __int64 v86; // [sp+158h] [bp-4Ch]
  __int64 v87; // [sp+160h] [bp-44h]
  __int64 v88; // [sp+168h] [bp-3Ch]
  __int64 v89; // [sp+170h] [bp-34h]
  __int64 v90; // [sp+178h] [bp-2Ch]
  __int64 v91; // [sp+180h] [bp-24h]
  __int64 v92; // [sp+188h] [bp-1Ch]
  __int64 v93; // [sp+190h] [bp-14h]

  __asm
  {
    SRS.W           SP, #0x11
    CPS.W           #0x13
  }
  v54[0] = (int)&a3;
  v55 = a1;
  v56 = a2;
  v57 = __PAIR64__(&a3, v4);
  LODWORD(v58) = v5;
  v59 = __PAIR64__(a4, a3) | (a4 >> 5) & 1;
  v54[3] = (int)KiResetException;
  v54[4] = 0;
  if ( (a4 & 0xF) == 0 )
  {
    v42 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x584);
    __mcr(15, 0, v42, 13, 0, 3);
    v43 = *(_BYTE *)(v42 + 3);
    __asm { CPS.W           #0x1F }
    HIDWORD(v57) = v54;
    LODWORD(v58) = v5;
    __asm { CPS.W           #0x13 }
    if ( (v43 & 1) != 0 )
      KiReadDebugRegs((int)v54);
  }
  v44 = 0;
  if ( (__mrc(15, 0, 1, 0, 2) & 0xF00000) != 0 )
  {
    v44 = &v60;
    __asm { VMRS            R2, FPSCR }
    v61 = _R2;
    v62 = v6;
    v63 = v7;
    v64 = v8;
    v65 = v9;
    v66 = v10;
    v67 = v11;
    v68 = v12;
    v69 = v13;
    v70 = v14;
    v71 = v15;
    v72 = v16;
    v73 = v17;
    v74 = v18;
    v75 = v19;
    v76 = v20;
    v77 = v21;
    v78 = v22;
    v79 = v23;
    v80 = v24;
    v81 = v25;
    v82 = v26;
    v83 = v27;
    v84 = v28;
    v85 = v29;
    v86 = v30;
    v87 = v31;
    v88 = v32;
    v89 = v33;
    v90 = v34;
    v91 = v35;
    v92 = v36;
    v93 = v37;
    _R2 &= 0xFFC8FFFF;
    __asm { VMSR            FPSCR, R2 }
  }
  v54[5] = (int)v44;
  v46 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  v47 = *(_DWORD *)(v46 + 1428);
  if ( v47 < 4 )
  {
    LODWORD(v48) = *(_DWORD *)(v46 + 1412);
    v49 = KiTrapFrameLogIndex[v47] & 0x1F | (32 * v47);
    v50 = (_QWORD *)((char *)&KiTrapFrameLog + 32 * v49 + 16 * v49);
    KiTrapFrameLogIndex[v47] = v49 + 1;
    HIDWORD(v48) = v47 | 0x700;
    v51 = v55;
    *v50 = v48;
    v50[1] = v51;
    v52 = v57;
    v50[2] = v56;
    v50[3] = v52;
    v53 = v59;
    v50[4] = v58;
    v50[5] = v53;
  }
  KiBugCheckDispatch(61, 0, 0, 0);
}
