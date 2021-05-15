// KiResetException 
 
void __fastcall __noreturn KiResetException(__int64 a1, __int64 a2)
{
  unsigned int v2; // r12
  int v3; // lr
  __int64 v4; // d0
  __int64 v5; // d1
  __int64 v6; // d2
  __int64 v7; // d3
  __int64 v8; // d4
  __int64 v9; // d5
  __int64 v10; // d6
  __int64 v11; // d7
  __int64 v12; // d8
  __int64 v13; // d9
  __int64 v14; // d10
  __int64 v15; // d11
  __int64 v16; // d12
  __int64 v17; // d13
  __int64 v18; // d14
  __int64 v19; // d15
  __int64 v20; // d16
  __int64 v21; // d17
  __int64 v22; // d18
  __int64 v23; // d19
  __int64 v24; // d20
  __int64 v25; // d21
  __int64 v26; // d22
  __int64 v27; // d23
  __int64 v28; // d24
  __int64 v29; // d25
  __int64 v30; // d26
  __int64 v31; // d27
  __int64 v32; // d28
  __int64 v33; // d29
  __int64 v34; // d30
  __int64 v35; // d31
  unsigned int v40; // r12
  char v41; // r1
  char *v42; // r1
  unsigned int v44; // r0
  unsigned int v45; // r1
  __int64 v46; // r0
  int v47; // r3
  _QWORD *v48; // r12
  __int64 v49; // r2
  unsigned __int64 v50; // r2
  __int64 v51; // r2
  int v52[24]; // [sp+0h] [bp-1C4h] BYREF
  __int64 v53; // [sp+60h] [bp-164h]
  __int64 v54; // [sp+68h] [bp-15Ch]
  unsigned __int64 v55; // [sp+70h] [bp-154h]
  __int64 v56; // [sp+78h] [bp-14Ch]
  __int64 v57; // [sp+80h] [bp-144h]
  char v58; // [sp+88h] [bp-13Ch] BYREF
  int v59; // [sp+8Ch] [bp-138h]
  __int64 v60; // [sp+98h] [bp-12Ch]
  __int64 v61; // [sp+A0h] [bp-124h]
  __int64 v62; // [sp+A8h] [bp-11Ch]
  __int64 v63; // [sp+B0h] [bp-114h]
  __int64 v64; // [sp+B8h] [bp-10Ch]
  __int64 v65; // [sp+C0h] [bp-104h]
  __int64 v66; // [sp+C8h] [bp-FCh]
  __int64 v67; // [sp+D0h] [bp-F4h]
  __int64 v68; // [sp+D8h] [bp-ECh]
  __int64 v69; // [sp+E0h] [bp-E4h]
  __int64 v70; // [sp+E8h] [bp-DCh]
  __int64 v71; // [sp+F0h] [bp-D4h]
  __int64 v72; // [sp+F8h] [bp-CCh]
  __int64 v73; // [sp+100h] [bp-C4h]
  __int64 v74; // [sp+108h] [bp-BCh]
  __int64 v75; // [sp+110h] [bp-B4h]
  __int64 v76; // [sp+118h] [bp-ACh]
  __int64 v77; // [sp+120h] [bp-A4h]
  __int64 v78; // [sp+128h] [bp-9Ch]
  __int64 v79; // [sp+130h] [bp-94h]
  __int64 v80; // [sp+138h] [bp-8Ch]
  __int64 v81; // [sp+140h] [bp-84h]
  __int64 v82; // [sp+148h] [bp-7Ch]
  __int64 v83; // [sp+150h] [bp-74h]
  __int64 v84; // [sp+158h] [bp-6Ch]
  __int64 v85; // [sp+160h] [bp-64h]
  __int64 v86; // [sp+168h] [bp-5Ch]
  __int64 v87; // [sp+170h] [bp-54h]
  __int64 v88; // [sp+178h] [bp-4Ch]
  __int64 v89; // [sp+180h] [bp-44h]
  __int64 v90; // [sp+188h] [bp-3Ch]
  __int64 v91; // [sp+190h] [bp-34h]
  __int64 v92; // [sp+1A4h] [bp-20h] BYREF

  __asm
  {
    SRS.W           SP, #0x13
    CPS.W           #0x13
  }
  v52[0] = (int)&v92;
  v53 = a1;
  v54 = a2;
  v55 = __PAIR64__(&v92, v2);
  LODWORD(v56) = v3;
  v57 = v92 | (HIDWORD(v92) >> 5) & 1;
  v52[3] = (int)KiResetException;
  v52[4] = 0;
  if ( (v92 & 0xF00000000i64) == 0 )
  {
    v40 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x584);
    __mcr(15, 0, v40, 13, 0, 3);
    v41 = *(_BYTE *)(v40 + 3);
    __asm { CPS.W           #0x1F }
    HIDWORD(v55) = v52;
    LODWORD(v56) = v3;
    __asm { CPS.W           #0x13 }
    if ( (v41 & 1) != 0 )
      KiReadDebugRegs((int)v52);
  }
  v42 = 0;
  if ( (__mrc(15, 0, 1, 0, 2) & 0xF00000) != 0 )
  {
    v42 = &v58;
    __asm { VMRS            R2, FPSCR }
    v59 = _R2;
    v60 = v4;
    v61 = v5;
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
    _R2 &= 0xFFC8FFFF;
    __asm { VMSR            FPSCR, R2 }
  }
  v52[5] = (int)v42;
  v44 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  v45 = *(_DWORD *)(v44 + 1428);
  if ( v45 < 4 )
  {
    LODWORD(v46) = *(_DWORD *)(v44 + 1412);
    v47 = KiTrapFrameLogIndex[v45] & 0x1F | (32 * v45);
    v48 = (_QWORD *)((char *)&KiTrapFrameLog + 32 * v47 + 16 * v47);
    KiTrapFrameLogIndex[v45] = v47 + 1;
    HIDWORD(v46) = v45 | 0x600;
    v49 = v53;
    *v48 = v46;
    v48[1] = v49;
    v50 = v55;
    v48[2] = v54;
    v48[3] = v50;
    v51 = v57;
    v48[4] = v56;
    v48[5] = v51;
  }
  KiBugCheckDispatch(61, 0, 0, 0);
}
