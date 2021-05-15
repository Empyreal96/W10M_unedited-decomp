// KiUndefinedInstructionException 
 
int __fastcall KiUndefinedInstructionException(__int64 a1, __int64 a2, int a3, unsigned int a4, int a5, int a6, int a7, int a8, unsigned int a9)
{
  int v9; // r4
  int v10; // r5
  int v11; // r6
  int v12; // r7
  unsigned int v13; // r11
  unsigned int v14; // r12
  unsigned __int16 *v15; // lr
  __int64 v16; // d0
  __int64 v17; // d1
  __int64 v18; // d2
  __int64 v19; // d3
  __int64 v20; // d4
  __int64 v21; // d5
  __int64 v22; // d6
  __int64 v23; // d7
  __int64 v24; // d8
  __int64 v25; // d9
  __int64 v26; // d10
  __int64 v27; // d11
  __int64 v28; // d12
  __int64 v29; // d13
  __int64 v30; // d14
  __int64 v31; // d15
  __int64 v32; // d16
  __int64 v33; // d17
  __int64 v34; // d18
  __int64 v35; // d19
  __int64 v36; // d20
  __int64 v37; // d21
  __int64 v38; // d22
  __int64 v39; // d23
  __int64 v40; // d24
  __int64 v41; // d25
  __int64 v42; // d26
  __int64 v43; // d27
  __int64 v44; // d28
  __int64 v45; // d29
  __int64 v46; // d30
  __int64 v47; // d31
  unsigned int v48; // r7
  unsigned __int64 *v49; // r2
  unsigned __int64 v50; // kr00_8
  unsigned __int64 v51; // r0
  unsigned int v61; // r2
  __int64 v62; // r0
  unsigned int v63; // r12
  char v64; // r1
  char *v65; // r1
  unsigned int v67; // r0
  unsigned int v68; // r1
  __int64 v69; // r0
  int v70; // r3
  _QWORD *v71; // r12
  __int64 v72; // r2
  unsigned __int64 v73; // r2
  __int64 v74; // r2
  int v75[24]; // [sp+0h] [bp-1A4h] BYREF
  __int64 v76; // [sp+60h] [bp-144h]
  __int64 v77; // [sp+68h] [bp-13Ch]
  unsigned __int64 v78; // [sp+70h] [bp-134h]
  unsigned __int64 v79; // [sp+78h] [bp-12Ch]
  __int64 v80; // [sp+80h] [bp-124h]
  char v81; // [sp+88h] [bp-11Ch] BYREF
  int v82; // [sp+8Ch] [bp-118h]
  __int64 v83; // [sp+98h] [bp-10Ch]
  __int64 v84; // [sp+A0h] [bp-104h]
  __int64 v85; // [sp+A8h] [bp-FCh]
  __int64 v86; // [sp+B0h] [bp-F4h]
  __int64 v87; // [sp+B8h] [bp-ECh]
  __int64 v88; // [sp+C0h] [bp-E4h]
  __int64 v89; // [sp+C8h] [bp-DCh]
  __int64 v90; // [sp+D0h] [bp-D4h]
  __int64 v91; // [sp+D8h] [bp-CCh]
  __int64 v92; // [sp+E0h] [bp-C4h]
  __int64 v93; // [sp+E8h] [bp-BCh]
  __int64 v94; // [sp+F0h] [bp-B4h]
  __int64 v95; // [sp+F8h] [bp-ACh]
  __int64 v96; // [sp+100h] [bp-A4h]
  __int64 v97; // [sp+108h] [bp-9Ch]
  __int64 v98; // [sp+110h] [bp-94h]
  __int64 v99; // [sp+118h] [bp-8Ch]
  __int64 v100; // [sp+120h] [bp-84h]
  __int64 v101; // [sp+128h] [bp-7Ch]
  __int64 v102; // [sp+130h] [bp-74h]
  __int64 v103; // [sp+138h] [bp-6Ch]
  __int64 v104; // [sp+140h] [bp-64h]
  __int64 v105; // [sp+148h] [bp-5Ch]
  __int64 v106; // [sp+150h] [bp-54h]
  __int64 v107; // [sp+158h] [bp-4Ch]
  __int64 v108; // [sp+160h] [bp-44h]
  __int64 v109; // [sp+168h] [bp-3Ch]
  __int64 v110; // [sp+170h] [bp-34h]
  __int64 v111; // [sp+178h] [bp-2Ch]
  __int64 v112; // [sp+180h] [bp-24h]
  __int64 v113; // [sp+188h] [bp-1Ch]
  __int64 v114; // [sp+190h] [bp-14h]

  a7 = v11;
  a8 = v12;
  v48 = *(v15 - 1);
  if ( v48 < 0xE800 )
  {
    if ( (v48 ^ 0xDE00) == 250 )
    {
      v49 = (unsigned __int64 *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 3824);
      while ( 1 )
      {
        v50 = __ldrexd(v49);
        v51 = __PAIR64__(HIDWORD(v50), __mrc(15, 0, 9, 13, 0));
        if ( ((v50 ^ v51) & 0x80000000) != 0i64 )
          HIDWORD(v51) = HIDWORD(v50) + ((unsigned int)v50 >> 31);
        if ( !__strexd(v51, v49) )
          __asm { ERET.W }
      }
    }
  }
  else
  {
    v48 = *v15 | (v48 << 16);
  }
  if ( HIBYTE(v48) == 251 && ((v48 >> 20) & 0xD) == 9 && ((unsigned __int8)v48 & BYTE1(v48) & 0xF0) == 240 )
    return KiEmulateDivide(a1, SHIDWORD(a1), a2, SHIDWORD(a2), a3, a4, a5, a6, a7, a8, a9);
  if ( (v48 & 0xE8000000) != -402653184 )
    goto LABEL_18;
  if ( (__mrc(15, 0, 1, 0, 2) & 0xF00000) == 0 )
    return KiEnableVfp();
  __asm { VMRS            R6, FPEXC }
  if ( (_R6 & 0xA0000000) == 0 )
  {
LABEL_18:
    a9 = v48;
    __asm { SRS.W           SP, #0x1B }
    a5 = v9;
    a6 = v10;
    __asm { CPS.W           #0x13 }
    v75[0] = (int)&a3;
    v76 = a1;
    HIDWORD(v62) = a4;
    v77 = a2;
    v61 = (a4 >> 5) & 1;
    v78 = __PAIR64__(&a3, v14);
    v79 = __PAIR64__(v13, (unsigned int)v15);
    LODWORD(v62) = (a3 | v61) - 2;
    if ( !v61 )
      LODWORD(v62) = a3 - 4;
    v80 = v62;
    v75[3] = (int)KiResetException;
    v75[4] = 1;
    if ( (a4 & 0xF) == 0 )
    {
      v63 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x584);
      __mcr(15, 0, v63, 13, 0, 3);
      v64 = *(_BYTE *)(v63 + 3);
      __asm { CPS.W           #0x1F }
      HIDWORD(v78) = v75;
      LODWORD(v79) = v15;
      __asm { CPS.W           #0x13 }
      if ( (v64 & 1) != 0 )
        KiReadDebugRegs((int)v75);
    }
    v65 = 0;
    if ( (__mrc(15, 0, 1, 0, 2) & 0xF00000) != 0 )
    {
      v65 = &v81;
      __asm { VMRS            R2, FPSCR }
      v82 = _R2;
      v83 = v16;
      v84 = v17;
      v85 = v18;
      v86 = v19;
      v87 = v20;
      v88 = v21;
      v89 = v22;
      v90 = v23;
      v91 = v24;
      v92 = v25;
      v93 = v26;
      v94 = v27;
      v95 = v28;
      v96 = v29;
      v97 = v30;
      v98 = v31;
      v99 = v32;
      v100 = v33;
      v101 = v34;
      v102 = v35;
      v103 = v36;
      v104 = v37;
      v105 = v38;
      v106 = v39;
      v107 = v40;
      v108 = v41;
      v109 = v42;
      v110 = v43;
      v111 = v44;
      v112 = v45;
      v113 = v46;
      v114 = v47;
      _R2 &= 0xFFC8FFFF;
      __asm { VMSR            FPSCR, R2 }
    }
    v75[5] = (int)v65;
    v67 = (unsigned int)KeGetPcr() & 0xFFFFF000;
    v68 = *(_DWORD *)(v67 + 1428);
    if ( v68 < 4 )
    {
      LODWORD(v69) = *(_DWORD *)(v67 + 1412);
      v70 = KiTrapFrameLogIndex[v68] & 0x1F | (32 * v68);
      v71 = (_QWORD *)((char *)&KiTrapFrameLog + 32 * v70 + 16 * v70);
      KiTrapFrameLogIndex[v68] = v70 + 1;
      HIDWORD(v69) = v68 | 0x300;
      v72 = v76;
      *v71 = v69;
      v71[1] = v72;
      v73 = v78;
      v71[2] = v77;
      v71[3] = v73;
      v74 = v80;
      v71[4] = v79;
      v71[5] = v74;
    }
    __asm
    {
      CPS.W           #0x1B
      CPS.W           #0x13
    }
    if ( (v80 & 0x8000000000i64) == 0 )
      __enable_irq();
    KiExceptionDispatch(268435458, 1, v80, v75[6], v75[0]);
  }
  _R6 = _R6 & 0x5FFFFFFF;
  __asm
  {
    VMSR            FPEXC, R6
    VMRS            R7, FPSCR
  }
  _R7 &= 0xFFFF00FF;
  __asm { VMSR            FPSCR, R7 }
  return ((int (__fastcall *)(_DWORD, _DWORD, _DWORD, _DWORD, int, unsigned int, int, int, int, int))(v15 - 1))(
           a1,
           HIDWORD(a1),
           a2,
           HIDWORD(a2),
           a3,
           a4,
           a5,
           a6,
           a7,
           a8);
}
