// KiDataAbortException 
 
void __fastcall KiDataAbortException(__int64 a1, __int64 a2, int a3, unsigned int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
  int v10; // r4
  int v11; // r5
  int v12; // r6
  int v13; // r7
  unsigned int v14; // r11
  unsigned int v15; // r12
  unsigned int v16; // lr
  __int64 v17; // d0
  __int64 v18; // d1
  __int64 v19; // d2
  __int64 v20; // d3
  __int64 v21; // d4
  __int64 v22; // d5
  __int64 v23; // d6
  __int64 v24; // d7
  __int64 v25; // d8
  __int64 v26; // d9
  __int64 v27; // d10
  __int64 v28; // d11
  __int64 v29; // d12
  __int64 v30; // d13
  __int64 v31; // d14
  __int64 v32; // d15
  __int64 v33; // d16
  __int64 v34; // d17
  __int64 v35; // d18
  __int64 v36; // d19
  __int64 v37; // d20
  __int64 v38; // d21
  __int64 v39; // d22
  __int64 v40; // d23
  __int64 v41; // d24
  __int64 v42; // d25
  __int64 v43; // d26
  __int64 v44; // d27
  __int64 v45; // d28
  __int64 v46; // d29
  __int64 v47; // d30
  __int64 v48; // d31
  unsigned int v53; // r12
  char v54; // r1
  char *v55; // r1
  unsigned int v57; // r0
  unsigned int v58; // r1
  __int64 v59; // r0
  int v60; // r3
  _QWORD *v61; // r12
  __int64 v62; // r2
  unsigned __int64 v63; // r2
  unsigned __int64 v64; // r2
  char v65; // r0
  unsigned int v66; // r2
  int v67; // r1
  unsigned int v68; // r7
  int v69; // r6
  int v70[24]; // [sp+0h] [bp-1A4h] BYREF
  __int64 v71; // [sp+60h] [bp-144h]
  __int64 v72; // [sp+68h] [bp-13Ch]
  unsigned __int64 v73; // [sp+70h] [bp-134h]
  unsigned __int64 v74; // [sp+78h] [bp-12Ch]
  unsigned __int64 v75; // [sp+80h] [bp-124h]
  char v76; // [sp+88h] [bp-11Ch] BYREF
  int v77; // [sp+8Ch] [bp-118h]
  __int64 v78; // [sp+98h] [bp-10Ch]
  __int64 v79; // [sp+A0h] [bp-104h]
  __int64 v80; // [sp+A8h] [bp-FCh]
  __int64 v81; // [sp+B0h] [bp-F4h]
  __int64 v82; // [sp+B8h] [bp-ECh]
  __int64 v83; // [sp+C0h] [bp-E4h]
  __int64 v84; // [sp+C8h] [bp-DCh]
  __int64 v85; // [sp+D0h] [bp-D4h]
  __int64 v86; // [sp+D8h] [bp-CCh]
  __int64 v87; // [sp+E0h] [bp-C4h]
  __int64 v88; // [sp+E8h] [bp-BCh]
  __int64 v89; // [sp+F0h] [bp-B4h]
  __int64 v90; // [sp+F8h] [bp-ACh]
  __int64 v91; // [sp+100h] [bp-A4h]
  __int64 v92; // [sp+108h] [bp-9Ch]
  __int64 v93; // [sp+110h] [bp-94h]
  __int64 v94; // [sp+118h] [bp-8Ch]
  __int64 v95; // [sp+120h] [bp-84h]
  __int64 v96; // [sp+128h] [bp-7Ch]
  __int64 v97; // [sp+130h] [bp-74h]
  __int64 v98; // [sp+138h] [bp-6Ch]
  __int64 v99; // [sp+140h] [bp-64h]
  __int64 v100; // [sp+148h] [bp-5Ch]
  __int64 v101; // [sp+150h] [bp-54h]
  __int64 v102; // [sp+158h] [bp-4Ch]
  __int64 v103; // [sp+160h] [bp-44h]
  __int64 v104; // [sp+168h] [bp-3Ch]
  __int64 v105; // [sp+170h] [bp-34h]
  __int64 v106; // [sp+178h] [bp-2Ch]
  __int64 v107; // [sp+180h] [bp-24h]
  __int64 v108; // [sp+188h] [bp-1Ch]
  __int64 v109; // [sp+190h] [bp-14h]

  a7 = v12;
  a8 = v13;
  if ( v16 - (unsigned int)&loc_420888 >= 0x1C80 )
    goto LABEL_2;
  switch ( v16 - (_DWORD)&loc_420888 )
  {
    case 0x284u:
    case 0x292u:
      __asm { CPS.W           #0x1B }
      ((void (__fastcall *)(_DWORD, _DWORD, _DWORD, _DWORD, int, unsigned int))(v16 - 2))(
        a1,
        HIDWORD(a1),
        a2,
        HIDWORD(a2),
        a3,
        a4);
      return;
    case 0x34Cu:
    case 0x4DAu:
    case 0x688u:
      goto LABEL_16;
    case 0x96Au:
    case 0x974u:
      JUMPOUT(0x4210AC);
    case 0xAFAu:
    case 0xC3Au:
LABEL_16:
      KiDataAbortPanicBugcheck(a1, SHIDWORD(a1), a2, SHIDWORD(a2));
  }
  if ( v16 - (unsigned int)&loc_420888 - 6168 >= 0x26 )
  {
LABEL_2:
    __asm { SRS.W           SP, #0x17 }
    if ( (__mrc(15, 0, 5, 0, 0) & 0x40F) != 1 )
      goto LABEL_3;
    a9 = a7;
    a10 = a8;
    v68 = *(unsigned __int16 *)(v16 - 8);
    if ( v68 >= 0xE800 )
      v68 = *(unsigned __int16 *)(v16 - 6) | (v68 << 16);
    if ( HIBYTE(v68) == 237 && ((v68 >> 9) & 7) == 5 && (v68 & 0x200000) == 0 )
    {
      KiEmulateLoadStoreVfp(a1, SHIDWORD(a1), a2, SHIDWORD(a2), a3, a4, a5, a6, a7, a8, a9);
    }
    else if ( v68 >> 25 == 116 && (v68 & 0x400000) != 0 && ((v68 | (8 * v68)) & 0x1000000) != 0 )
    {
      KiEmulateLoadStoreDouble(a1, SHIDWORD(a1), a2, SHIDWORD(a2), a3, a4, a5, a6, a7, a8, a9);
    }
    else if ( v68 >> 12 == 12 )
    {
      KiEmulateLoadStoreMultiple16(a1, SHIDWORD(a1), a2, SHIDWORD(a2), a3, a4, a5, a6, a7, a8, a9);
    }
    else
    {
      if ( v68 >> 25 != 116
        || (v68 & 0x400000) != 0
        || ((v68 ^ (2 * v68)) & 0x1000000) == 0
        || (v69 = HIWORD(v68) & 0xF, v69 == 13)
        || v69 == 15 )
      {
LABEL_3:
        a5 = v10;
        a6 = v11;
        __asm { CPS.W           #0x13 }
        v70[0] = (int)&a3;
        v71 = a1;
        v72 = a2;
        v73 = __PAIR64__(&a3, v15);
        v74 = __PAIR64__(v14, v16);
        v75 = __PAIR64__(a4, a3) | (a4 >> 5) & 1;
        v70[3] = (int)KiResetException;
        v70[4] = 1;
        if ( (a4 & 0xF) == 0 )
        {
          v53 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x584);
          __mcr(15, 0, v53, 13, 0, 3);
          v54 = *(_BYTE *)(v53 + 3);
          __asm { CPS.W           #0x1F }
          HIDWORD(v73) = v70;
          LODWORD(v74) = v16;
          __asm { CPS.W           #0x13 }
          if ( (v54 & 1) != 0 )
            KiReadDebugRegs((int)v70);
        }
        v55 = 0;
        if ( (__mrc(15, 0, 1, 0, 2) & 0xF00000) != 0 )
        {
          v55 = &v76;
          __asm { VMRS            R2, FPSCR }
          v77 = _R2;
          v78 = v17;
          v79 = v18;
          v80 = v19;
          v81 = v20;
          v82 = v21;
          v83 = v22;
          v84 = v23;
          v85 = v24;
          v86 = v25;
          v87 = v26;
          v88 = v27;
          v89 = v28;
          v90 = v29;
          v91 = v30;
          v92 = v31;
          v93 = v32;
          v94 = v33;
          v95 = v34;
          v96 = v35;
          v97 = v36;
          v98 = v37;
          v99 = v38;
          v100 = v39;
          v101 = v40;
          v102 = v41;
          v103 = v42;
          v104 = v43;
          v105 = v44;
          v106 = v45;
          v107 = v46;
          v108 = v47;
          v109 = v48;
          _R2 &= 0xFFC8FFFF;
          __asm { VMSR            FPSCR, R2 }
        }
        v70[5] = (int)v55;
        v57 = (unsigned int)KeGetPcr() & 0xFFFFF000;
        v58 = *(_DWORD *)(v57 + 1428);
        if ( v58 < 4 )
        {
          LODWORD(v59) = *(_DWORD *)(v57 + 1412);
          v60 = KiTrapFrameLogIndex[v58] & 0x1F | (32 * v58);
          v61 = (_QWORD *)((char *)&KiTrapFrameLog + 32 * v60 + 16 * v60);
          KiTrapFrameLogIndex[v58] = v60 + 1;
          HIDWORD(v59) = v58 | 0x400;
          v62 = v71;
          *v61 = v59;
          v61[1] = v62;
          v63 = v73;
          v61[2] = v72;
          v61[3] = v63;
          v64 = v75;
          v61[4] = v74;
          v61[5] = v64;
        }
        v65 = BYTE4(v75);
        v66 = __mrc(15, 0, 5, 0, 0);
        v67 = __mrc(15, 0, 6, 0, 0);
        if ( (v65 & 0x80) == 0 )
          __enable_irq();
        KiCommonMemoryManagementAbort(
          *((unsigned __int8 *)&word_420E8A + (((v66 >> 6) & 0xF0 | v66 & 0xF) & 0x1F)) | ((unsigned __int16)(v66 & 0x800) >> 11),
          v67);
      }
      KiEmulateLoadStoreMultiple(a1, SHIDWORD(a1), a2, SHIDWORD(a2), a3, a4, a5, a6, a7, a8, a9);
    }
  }
  else
  {
    KiEmulatedLoadStoreEnd(a1, SHIDWORD(a1), a2, SHIDWORD(a2), a3, a4);
  }
}
