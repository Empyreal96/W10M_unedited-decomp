// WmipQuerySingleMultiple 
 
int __fastcall WmipQuerySingleMultiple(_DWORD *a1, int a2, _DWORD *a3, unsigned int a4, int a5, unsigned int a6, int a7, int a8, int *a9)
{
  _DWORD *v9; // lr
  int v10; // r9
  int v11; // r0
  unsigned int v12; // r10
  unsigned int v13; // r3
  int v14; // r6
  int v15; // r4
  int v16; // r8
  int v17; // r0
  _DWORD *v18; // r2
  unsigned int v19; // lr
  unsigned int v20; // r5
  unsigned int v21; // r3
  int v22; // r1
  int *v23; // r2
  unsigned int v24; // r5
  int v25; // r4
  _BYTE *v26; // r0
  unsigned int v27; // r3
  int v28; // r5
  unsigned int v29; // r1
  int v30; // r3
  int v31; // r3
  unsigned int v32; // r3
  _DWORD *v33; // r3
  int v35; // [sp+14h] [bp-304h]
  _DWORD *v36; // [sp+18h] [bp-300h]
  unsigned int v37; // [sp+1Ch] [bp-2FCh] BYREF
  _DWORD *v38; // [sp+20h] [bp-2F8h]
  int v39; // [sp+24h] [bp-2F4h]
  unsigned int v40; // [sp+28h] [bp-2F0h]
  int v41; // [sp+2Ch] [bp-2ECh]
  int v42; // [sp+30h] [bp-2E8h]
  int v43; // [sp+34h] [bp-2E4h]
  int v44; // [sp+38h] [bp-2E0h]
  int v45; // [sp+3Ch] [bp-2DCh]
  int v46; // [sp+40h] [bp-2D8h]
  unsigned int v47; // [sp+44h] [bp-2D4h]
  int v48; // [sp+48h] [bp-2D0h]
  _DWORD *v49; // [sp+4Ch] [bp-2CCh]
  unsigned int v50; // [sp+50h] [bp-2C8h]
  int *v51; // [sp+54h] [bp-2C4h]
  int v52; // [sp+58h] [bp-2C0h]
  int v53; // [sp+5Ch] [bp-2BCh]
  _DWORD *v54; // [sp+60h] [bp-2B8h]
  int v55; // [sp+64h] [bp-2B4h]
  int v56; // [sp+68h] [bp-2B0h]
  unsigned int v57; // [sp+6Ch] [bp-2ACh]
  unsigned int v58; // [sp+70h] [bp-2A8h]
  unsigned int v59; // [sp+74h] [bp-2A4h]
  _DWORD *v60; // [sp+78h] [bp-2A0h]
  int *v61; // [sp+7Ch] [bp-29Ch]
  _DWORD *v62; // [sp+80h] [bp-298h]
  int v63; // [sp+84h] [bp-294h]
  int v64; // [sp+88h] [bp-290h]
  _DWORD *v65; // [sp+8Ch] [bp-28Ch]
  int v66; // [sp+90h] [bp-288h]
  _DWORD *v67; // [sp+94h] [bp-284h]
  _DWORD *v68; // [sp+98h] [bp-280h]
  int v69; // [sp+9Ch] [bp-27Ch]
  int v70; // [sp+A0h] [bp-278h]
  int v71; // [sp+A8h] [bp-270h]
  _DWORD _B0[157]; // [sp+B0h] [bp-268h] BYREF
  int varg_r1; // [sp+324h] [bp+Ch]
  _DWORD *varg_r2; // [sp+328h] [bp+10h]
  unsigned int varg_r3; // [sp+32Ch] [bp+14h]

  _B0[156] = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  v40 = a4;
  varg_r3 = a4;
  v9 = a3;
  v49 = a3;
  v41 = (char)a2;
  LOBYTE(varg_r1) = a2;
  v65 = a1;
  v67 = a1;
  v68 = a3;
  v64 = a7;
  v69 = a7;
  v66 = a8;
  v70 = a8;
  v51 = a9;
  v61 = a9;
  v48 = 0;
  v56 = 0;
  v39 = 0;
  v45 = 0;
  v10 = 0;
  v42 = 0;
  v53 = 0;
  if ( a7 )
  {
    v12 = 0;
    v55 = 0;
  }
  else
  {
    v11 = ExAllocatePoolWithTag(1, 24 * a6, 1885957463);
    v12 = v11;
    v55 = v11;
    if ( v11 )
      memmove(v11, a5 + 8, 24 * a6);
    else
      v10 = -1073741670;
    v39 = 0;
    v45 = 0;
    v9 = v49;
  }
  v13 = a6;
  if ( v10 < 0 )
    return v10;
  v14 = 0;
  v43 = 0;
  v15 = 0;
  v35 = 0;
  v16 = 0;
  v44 = 0;
  v17 = (int)v9;
  v36 = v9;
  v54 = v9;
  v18 = _B0;
  v38 = _B0;
  v60 = _B0;
  v19 = 580;
  v47 = 580;
  v57 = 580;
  v20 = 0;
  while ( 1 )
  {
    v58 = v20;
    v46 = v20;
    if ( v20 >= v13 )
      break;
    if ( v64 )
    {
      v23 = (int *)(v66 + 8 * v20);
      v71 = *v23;
      v50 = v23[1];
      v39 = *(_DWORD *)(v64 + 4 * v20);
      v45 = v39;
      v63 = 0;
      v22 = (unsigned __int16)v71;
      v18 = v38;
    }
    else
    {
      v21 = v12 + 24 * v20;
      v22 = *(unsigned __int16 *)(v21 + 8);
      v50 = *(_DWORD *)(v21 + 16);
      v63 = *(_DWORD *)v21;
      v17 = (int)v36;
    }
    v52 = v22;
    v24 = (v22 + 73) & 0xFFFFFFF8;
    if ( v15 || v40 < v24 )
    {
      if ( v24 > v19 )
      {
        if ( v18 != _B0 )
          ExFreePoolWithTag((unsigned int)v18);
        v18 = (_DWORD *)ExAllocatePoolWithTag(512, v24, 1885957463);
        v38 = v18;
        v60 = v18;
        if ( !v18 )
        {
          v10 = -1073741670;
          break;
        }
        v47 = v24;
        v57 = v24;
      }
      v25 = (int)v18;
      v62 = v18;
      v37 = v24;
      v59 = v24;
      v16 = 0;
      v44 = 0;
      v35 = 1;
    }
    else
    {
      v25 = v17;
      v62 = (_DWORD *)v17;
      v37 = v40;
      v59 = v40;
    }
    v26 = memset((_BYTE *)v25, 0, 64);
    *(_DWORD *)(v25 + 44) = 2;
    *(_DWORD *)v25 = v24;
    *(_DWORD *)(v25 + 16) = v63;
    *(_DWORD *)(v25 + 48) = 64;
    *(_DWORD *)(v25 + 56) = v24;
    v27 = v52;
    *(_WORD *)(v25 + 64) = v52;
    if ( v41 == 1 && v27 )
    {
      if ( (v50 & 1) != 0 )
        ExRaiseDatatypeMisalignment(v26);
      if ( v27 + v50 > MmUserProbeAddress || v27 + v50 < v50 )
        *(_BYTE *)MmUserProbeAddress = 0;
    }
    memmove(v25 + 66, v50, v27);
    v28 = v46;
    v29 = v37;
    v37 = *(_DWORD *)v25;
    if ( WmipQuerySetExecuteSI(v39, v65, v41, 1, v25, v29, &v37) < 0 )
      goto LABEL_42;
    v30 = *(_DWORD *)(v25 + 44);
    if ( (v30 & 0x100) != 0 )
      goto LABEL_42;
    v53 = ++v42;
    if ( (v30 & 0x20) != 0 )
    {
      v14 += (*(_DWORD *)(v25 + 48) + 7) & 0xFFFFFFF8;
      v43 = v14;
      v15 = 1;
      v35 = 1;
      goto LABEL_43;
    }
    if ( v35 )
    {
      v14 += (v37 + 7) & 0xFFFFFFF8;
      v43 = v14;
LABEL_42:
      v15 = v35;
LABEL_43:
      v17 = (int)v36;
      goto LABEL_44;
    }
    if ( v16 )
      *(_DWORD *)(v16 + 12) = v48;
    v16 = v25;
    v44 = v25;
    while ( 1 )
    {
      v31 = *(_DWORD *)(v16 + 12);
      if ( !v31 )
        break;
      v16 += v31;
    }
    v44 = v16;
    v32 = (v37 + 7) & 0xFFFFFFF8;
    v14 += v32;
    v43 = v14;
    v40 -= v32;
    varg_r3 = v40;
    v17 = (int)v36 + v32;
    v36 = (_DWORD *)v17;
    v54 = (_DWORD *)v17;
    v48 = v17 - v16;
    v56 = v17 - v16;
    v15 = 0;
LABEL_44:
    v20 = v28 + 1;
    v18 = v38;
    v13 = a6;
    v19 = v47;
  }
  if ( v18 != _B0 )
    ExFreePoolWithTag((unsigned int)v18);
  if ( !v42 )
    v10 = -1073741163;
  if ( v10 >= 0 && v15 )
  {
    v33 = v49;
    *v49 = 56;
    v33[11] = 32;
    v33[12] = v14;
    *v51 = 56;
  }
  else
  {
    *v51 = v14;
  }
  if ( v12 )
    ExFreePoolWithTag(v12);
  return v10;
}
