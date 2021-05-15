// KiSWIException 
 
void __fastcall __noreturn KiSWIException(__int64 a1, __int64 a2)
{
  int v2; // r12
  unsigned int v3; // lr
  __int64 v4; // d8
  __int64 v5; // d9
  __int64 v6; // d10
  __int64 v7; // d11
  __int64 v8; // d12
  __int64 v9; // d13
  __int64 v10; // d14
  __int64 v11; // d15
  unsigned int v12; // r0
  unsigned int v13; // r12
  char v14; // r1
  char *v15; // r1
  unsigned int v21; // r0
  unsigned int v22; // r1
  __int64 v23; // r0
  int v24; // r3
  _QWORD *v25; // r12
  __int64 v26; // r2
  __int64 v27; // r2
  unsigned __int64 v28; // r2
  int v29; // r0
  int v30; // r1
  _DWORD v31[24]; // [sp+0h] [bp-1A0h] BYREF
  __int64 v32; // [sp+60h] [bp-140h]
  __int64 v33; // [sp+68h] [bp-138h]
  __int64 v34; // [sp+70h] [bp-130h]
  __int64 v35; // [sp+78h] [bp-128h]
  unsigned __int64 v36; // [sp+80h] [bp-120h]
  char v37; // [sp+88h] [bp-118h] BYREF
  int v38; // [sp+8Ch] [bp-114h]
  __int64 v39; // [sp+D8h] [bp-C8h]
  __int64 v40; // [sp+E0h] [bp-C0h]
  __int64 v41; // [sp+E8h] [bp-B8h]
  __int64 v42; // [sp+F0h] [bp-B0h]
  __int64 v43; // [sp+F8h] [bp-A8h]
  __int64 v44; // [sp+100h] [bp-A0h]
  __int64 v45; // [sp+108h] [bp-98h]
  __int64 v46; // [sp+110h] [bp-90h]

  v32 = a1;
  v33 = a2;
  LODWORD(v34) = v2;
  v12 = __get_CPSR();
  if ( (v12 & 0x20) != 0 )
    v3 |= 1u;
  v13 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x584);
  __mcr(15, 0, v13, 13, 0, 3);
  v36 = __PAIR64__(v12, v3);
  v14 = *(_BYTE *)(v13 + 3);
  v31[4] = 2;
  if ( (v14 & 1) != 0 )
  {
    KiReadDebugRegs(v31);
    v13 = __mrc(15, 0, 13, 0, 3);
  }
  v15 = 0;
  if ( (__mrc(15, 0, 1, 0, 2) & 0xF00000) != 0 )
  {
    __asm { VMRS            R2, FPSCR }
    v15 = &v37;
    v38 = _R2;
    v39 = v4;
    v40 = v5;
    v41 = v6;
    v42 = v7;
    v43 = v8;
    v44 = v9;
    v45 = v10;
    v46 = v11;
    _R2 &= 0xFFC8FFFF;
    __asm { VMSR            FPSCR, R2 }
  }
  v31[5] = v15;
  __asm { CPS.W           #0x1F }
  HIDWORD(v34) = v31;
  LODWORD(v35) = v3;
  __enable_irq();
  if ( (*(_BYTE *)(v13 + 3) & 4) != 0 )
  {
    v29 = PsPicoSystemCallDispatch(v31);
  }
  else
  {
    *(_QWORD *)(v13 + 88) = __PAIR64__(v32, v34);
    v21 = (unsigned int)KeGetPcr() & 0xFFFFF000;
    v22 = *(_DWORD *)(v21 + 1428);
    if ( v22 < 4 )
    {
      LODWORD(v23) = *(_DWORD *)(v21 + 1412);
      v24 = KiTrapFrameLogIndex[v22] & 0x1F | (32 * v22);
      v25 = (_QWORD *)((char *)&KiTrapFrameLog + 32 * v24 + 16 * v24);
      KiTrapFrameLogIndex[v22] = v24 + 1;
      HIDWORD(v23) = v22 | 0x200;
      v26 = v32;
      *v25 = v23;
      v25[1] = v26;
      v27 = v34;
      v25[2] = v33;
      v25[3] = v27;
      v28 = v36;
      v25[4] = v35;
      v25[5] = v28;
    }
    v29 = KiSystemService(*(_DWORD *)(__mrc(15, 0, 13, 0, 3) + 88));
  }
  KiSystemServiceExit(v29, v30);
}
