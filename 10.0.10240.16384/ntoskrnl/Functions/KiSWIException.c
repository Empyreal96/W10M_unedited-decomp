// KiSWIException 
 
void __fastcall __noreturn KiSWIException(__int64 a1, __int64 a2, unsigned int a3, int a4)
{
  int v4; // r12
  unsigned int v5; // lr
  __int64 v6; // d8
  __int64 v7; // d9
  __int64 v8; // d10
  __int64 v9; // d11
  __int64 v10; // d12
  __int64 v11; // d13
  __int64 v12; // d14
  __int64 v13; // d15
  unsigned int v14; // r0
  unsigned int v15; // r12
  char v16; // r1
  char *v18; // r1
  unsigned int v23; // r0
  unsigned int v24; // r1
  __int64 v25; // r0
  int v26; // r3
  _QWORD *v27; // r12
  __int64 v28; // r2
  __int64 v29; // r2
  unsigned int v30; // r0
  int v31; // r0
  int v32; // r1
  int v33; // r2
  int v34; // r3
  int (__fastcall *v35[4])(int, int, int, int); // [sp+0h] [bp-1A0h] BYREF
  int v36; // [sp+10h] [bp-190h]
  char *v37; // [sp+14h] [bp-18Ch]
  int v38; // [sp+18h] [bp-188h]
  int v39; // [sp+1Ch] [bp-184h]
  int v40; // [sp+20h] [bp-180h]
  int v41; // [sp+24h] [bp-17Ch]
  int v42; // [sp+28h] [bp-178h]
  int v43; // [sp+2Ch] [bp-174h]
  int v44; // [sp+30h] [bp-170h]
  int v45; // [sp+34h] [bp-16Ch]
  int v46; // [sp+38h] [bp-168h]
  int v47; // [sp+3Ch] [bp-164h]
  int v48; // [sp+40h] [bp-160h]
  int v49; // [sp+44h] [bp-15Ch]
  int v50; // [sp+48h] [bp-158h]
  int v51; // [sp+4Ch] [bp-154h]
  int v52; // [sp+50h] [bp-150h]
  int v53; // [sp+54h] [bp-14Ch]
  int v54; // [sp+58h] [bp-148h]
  int v55; // [sp+5Ch] [bp-144h]
  __int64 v56; // [sp+60h] [bp-140h]
  __int64 v57; // [sp+68h] [bp-138h]
  __int64 v58; // [sp+70h] [bp-130h]
  __int64 v59; // [sp+78h] [bp-128h]
  unsigned __int64 v60; // [sp+80h] [bp-120h]
  char v61; // [sp+88h] [bp-118h] BYREF
  int v62; // [sp+8Ch] [bp-114h]
  __int64 v63[25]; // [sp+D8h] [bp-C8h] BYREF

  v56 = a1;
  v57 = a2;
  LODWORD(v58) = v4;
  v14 = __get_CPSR();
  if ( (v14 & 0x20) != 0 )
    v5 |= 1u;
  v15 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x584);
  __mcr(15, 0, v15, 13, 0, 3);
  v60 = __PAIR64__(v14, v5);
  v16 = *(_BYTE *)(v15 + 3);
  HIDWORD(_R2) = 2;
  v36 = 2;
  if ( (v16 & 1) != 0 )
  {
    KiReadDebugRegs((int)v35);
    v15 = __mrc(15, 0, 13, 0, 3);
  }
  v18 = 0;
  if ( (__mrc(15, 0, 1, 0, 2) & 0xF00000) != 0 )
  {
    HIDWORD(_R2) = v63;
    __asm { VMRS            R2, FPSCR }
    v18 = &v61;
    v62 = _R2;
    v63[0] = v6;
    v63[1] = v7;
    v63[2] = v8;
    v63[3] = v9;
    v63[4] = v10;
    v63[5] = v11;
    v63[6] = v12;
    v63[7] = v13;
    LODWORD(_R2) = _R2 & 0xFFC8FFFF;
    __asm { VMSR            FPSCR, R2 }
  }
  v37 = v18;
  __asm { CPS.W           #0x1F }
  HIDWORD(v58) = v35;
  LODWORD(v59) = v5;
  __enable_irq();
  if ( (*(_BYTE *)(v15 + 3) & 4) != 0 )
  {
    v31 = PsPicoSystemCallDispatch((int)v35);
  }
  else
  {
    *(_QWORD *)(v15 + 88) = __PAIR64__(v56, v58);
    v23 = (unsigned int)KeGetPcr() & 0xFFFFF000;
    v24 = *(_DWORD *)(v23 + 1428);
    LODWORD(_R2) = KiTrapFrameLogIndex;
    if ( v24 < 4 )
    {
      LODWORD(v25) = *(_DWORD *)(v23 + 1412);
      v26 = KiTrapFrameLogIndex[v24] & 0x1F | (32 * v24);
      v27 = (_QWORD *)((char *)&KiTrapFrameLog + 32 * v26 + 16 * v26);
      KiTrapFrameLogIndex[v24] = v26 + 1;
      HIDWORD(v25) = v24 | 0x200;
      v28 = v56;
      *v27 = v25;
      v27[1] = v28;
      v29 = v58;
      v27[2] = v57;
      v27[3] = v29;
      v24 = HIDWORD(v59);
      _R2 = v60;
      v27[4] = v59;
      v27[5] = _R2;
    }
    v30 = *(_DWORD *)(__mrc(15, 0, 13, 0, 3) + 88);
    v31 = KiSystemService(
            v30,
            v24,
            _R2,
            SHIDWORD(_R2),
            v35[0],
            (int)v35[1],
            (int)v35[2],
            (int)v35[3],
            v36,
            (int)v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            v45,
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            v54,
            v55,
            v56,
            SHIDWORD(v56),
            v57,
            SHIDWORD(v57));
  }
  KiSystemServiceExit(v31, v32, v33, v34, a3, a4);
}
