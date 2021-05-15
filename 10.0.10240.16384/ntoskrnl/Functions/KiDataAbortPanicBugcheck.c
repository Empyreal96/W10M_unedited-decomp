// KiDataAbortPanicBugcheck 
 
void __fastcall __noreturn KiDataAbortPanicBugcheck(int a1, int a2, int a3, int a4)
{
  __int64 *v4; // r4
  int v5; // r12
  int v6; // lr
  __int64 v7; // d0
  __int64 v8; // d1
  __int64 v9; // d2
  __int64 v10; // d3
  __int64 v11; // d4
  __int64 v12; // d5
  __int64 v13; // d6
  __int64 v14; // d7
  __int64 v15; // d8
  __int64 v16; // d9
  __int64 v17; // d10
  __int64 v18; // d11
  __int64 v19; // d12
  __int64 v20; // d13
  __int64 v21; // d14
  __int64 v22; // d15
  __int64 v23; // d16
  __int64 v24; // d17
  __int64 v25; // d18
  __int64 v26; // d19
  __int64 v27; // d20
  __int64 v28; // d21
  __int64 v29; // d22
  __int64 v30; // d23
  __int64 v31; // d24
  __int64 v32; // d25
  __int64 v33; // d26
  __int64 v34; // d27
  __int64 v35; // d28
  __int64 v36; // d29
  __int64 v37; // d30
  __int64 v38; // d31
  __int64 v43; // r6
  _DWORD v45[28]; // [sp+0h] [bp-220h] BYREF
  int v46; // [sp+70h] [bp-1B0h]
  char *v47; // [sp+74h] [bp-1ACh]
  int v48; // [sp+78h] [bp-1A8h]
  char *v49; // [sp+7Ch] [bp-1A4h]
  int v50; // [sp+80h] [bp-1A0h]
  unsigned int v51; // [sp+84h] [bp-19Ch]
  char v52; // [sp+88h] [bp-198h] BYREF
  int v53; // [sp+98h] [bp-188h]
  char *v54; // [sp+9Ch] [bp-184h]
  int v55; // [sp+A0h] [bp-180h]
  int v56; // [sp+E8h] [bp-138h]
  int v57; // [sp+ECh] [bp-134h]
  int v58; // [sp+F0h] [bp-130h]
  int v59; // [sp+F4h] [bp-12Ch]
  int v60; // [sp+F8h] [bp-128h]
  int v61; // [sp+100h] [bp-120h]
  char v62; // [sp+104h] [bp-11Ch] BYREF
  int v63; // [sp+108h] [bp-118h]
  int v64; // [sp+10Ch] [bp-114h]
  char v65; // [sp+110h] [bp-110h] BYREF
  int v66; // [sp+114h] [bp-10Ch]
  __int64 v67; // [sp+120h] [bp-100h]
  __int64 v68; // [sp+128h] [bp-F8h]
  __int64 v69; // [sp+130h] [bp-F0h]
  __int64 v70; // [sp+138h] [bp-E8h]
  __int64 v71; // [sp+140h] [bp-E0h]
  __int64 v72; // [sp+148h] [bp-D8h]
  __int64 v73; // [sp+150h] [bp-D0h]
  __int64 v74; // [sp+158h] [bp-C8h]
  __int64 v75; // [sp+160h] [bp-C0h]
  __int64 v76; // [sp+168h] [bp-B8h]
  __int64 v77; // [sp+170h] [bp-B0h]
  __int64 v78; // [sp+178h] [bp-A8h]
  __int64 v79; // [sp+180h] [bp-A0h]
  __int64 v80; // [sp+188h] [bp-98h]
  __int64 v81; // [sp+190h] [bp-90h]
  __int64 v82; // [sp+198h] [bp-88h]
  __int64 v83; // [sp+1A0h] [bp-80h]
  __int64 v84; // [sp+1A8h] [bp-78h]
  __int64 v85; // [sp+1B0h] [bp-70h]
  __int64 v86; // [sp+1B8h] [bp-68h]
  __int64 v87; // [sp+1C0h] [bp-60h]
  __int64 v88; // [sp+1C8h] [bp-58h]
  __int64 v89; // [sp+1D0h] [bp-50h]
  __int64 v90; // [sp+1D8h] [bp-48h]
  __int64 v91; // [sp+1E0h] [bp-40h]
  __int64 v92; // [sp+1E8h] [bp-38h]
  __int64 v93; // [sp+1F0h] [bp-30h]
  __int64 v94; // [sp+1F8h] [bp-28h]
  __int64 v95; // [sp+200h] [bp-20h]
  __int64 v96; // [sp+208h] [bp-18h]
  __int64 v97; // [sp+210h] [bp-10h]
  __int64 v98; // [sp+218h] [bp-8h]

  __asm { CPS.W           #0x13 }
  v45[24] = a1;
  v45[25] = a2;
  v45[26] = a3;
  v45[27] = a4;
  v46 = v5;
  v47 = &v52;
  v48 = v6;
  v49 = &v62;
  __asm
  {
    CPS.W           #0x17
    CPS.W           #0x13
  }
  v50 = (v6 - 8) | 1;
  v51 = __get_CPSR();
  v45[4] = 1;
  v45[5] = 0;
  v56 = a1;
  v57 = a2;
  v58 = a3;
  v59 = a4;
  v60 = v5;
  v61 = v6;
  v43 = *v4;
  __asm
  {
    CPS.W           #0x17
    CPS.W           #0x13
  }
  v63 = (*(_DWORD *)v4 - v55) | 1;
  v64 = HIDWORD(v43);
  v53 = 1;
  v54 = 0;
  if ( (__mrc(15, 0, 1, 0, 2) & 0xF00000) != 0 )
  {
    v54 = &v65;
    __asm { VMRS            R7, FPSCR }
    v66 = _R7;
    v67 = v7;
    v68 = v8;
    v69 = v9;
    v70 = v10;
    v71 = v11;
    v72 = v12;
    v73 = v13;
    v74 = v14;
    v75 = v15;
    v76 = v16;
    v77 = v17;
    v78 = v18;
    v79 = v19;
    v80 = v20;
    v81 = v21;
    v82 = v22;
    v83 = v23;
    v84 = v24;
    v85 = v25;
    v86 = v26;
    v87 = v27;
    v88 = v28;
    v89 = v29;
    v90 = v30;
    v91 = v31;
    v92 = v32;
    v93 = v33;
    v94 = v34;
    v95 = v35;
    v96 = v36;
    v97 = v37;
    v98 = v38;
  }
  __asm
  {
    CPS.W           #0x17
    CPS.W           #0x13
  }
  KiBugCheckDispatch(43, (int)v45, 0, 0);
}
