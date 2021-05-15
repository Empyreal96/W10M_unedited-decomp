// MiValidateSectionCreate 
 
int __fastcall MiValidateSectionCreate(int a1, int *a2, int a3, int a4, unsigned __int8 a5)
{
  int v6; // r10
  int v7; // r9
  int v8; // r8
  int v9; // r5
  int v10; // r1
  unsigned int v11; // r0
  unsigned int v12; // r4
  _DWORD *v13; // lr
  int v14; // r9
  unsigned int v15; // r2
  int v16; // r8
  int v17; // r3
  int v18; // r0
  int v19; // r3
  unsigned int v20; // r10
  int v21; // r3
  unsigned int v22; // r10
  unsigned int v23; // r9
  int v24; // r4
  int v25; // r0
  int v26; // r3
  int v27; // r2
  unsigned int v28; // r4
  _DWORD *v29; // r10
  int v30; // r2
  unsigned int *v31; // r1
  int v32; // r2
  int v33; // r0
  unsigned int *v34; // r2
  unsigned int v35; // r1
  int v36; // r1
  char v37; // r3
  unsigned int v39; // [sp+18h] [bp-E0h] BYREF
  char v40[4]; // [sp+1Ch] [bp-DCh] BYREF
  int v41; // [sp+20h] [bp-D8h]
  int v42; // [sp+24h] [bp-D4h]
  int v43; // [sp+28h] [bp-D0h]
  unsigned int v44; // [sp+2Ch] [bp-CCh]
  int v45; // [sp+30h] [bp-C8h]
  int v46; // [sp+34h] [bp-C4h]
  int v47; // [sp+38h] [bp-C0h]
  _DWORD *v48; // [sp+3Ch] [bp-BCh]
  int v49; // [sp+40h] [bp-B8h]
  int *v50; // [sp+44h] [bp-B4h]
  int v51; // [sp+48h] [bp-B0h]
  int v52; // [sp+4Ch] [bp-ACh]
  int v53; // [sp+50h] [bp-A8h]
  unsigned int v54; // [sp+54h] [bp-A4h]
  int v55; // [sp+58h] [bp-A0h]
  int v56; // [sp+5Ch] [bp-9Ch]
  _DWORD v57[2]; // [sp+60h] [bp-98h] BYREF
  int v58; // [sp+68h] [bp-90h]
  int v59; // [sp+6Ch] [bp-8Ch]
  int v60; // [sp+70h] [bp-88h]
  int v61; // [sp+74h] [bp-84h]
  int v62; // [sp+78h] [bp-80h]
  int v63; // [sp+7Ch] [bp-7Ch]
  int v64; // [sp+80h] [bp-78h]
  int v65; // [sp+84h] [bp-74h]
  int v66; // [sp+88h] [bp-70h]
  int v67; // [sp+8Ch] [bp-6Ch]
  int v68; // [sp+90h] [bp-68h]
  int v69; // [sp+94h] [bp-64h]
  int v70; // [sp+98h] [bp-60h]
  unsigned int v71; // [sp+9Ch] [bp-5Ch]
  int v72; // [sp+A0h] [bp-58h]
  int v73; // [sp+A4h] [bp-54h]
  unsigned int v74; // [sp+A8h] [bp-50h]
  _DWORD *v75; // [sp+ACh] [bp-4Ch]
  unsigned int v76; // [sp+B0h] [bp-48h] BYREF
  unsigned int v77; // [sp+B4h] [bp-44h]
  int varg_r0; // [sp+100h] [bp+8h]
  int *varg_r1; // [sp+104h] [bp+Ch]
  int varg_r2; // [sp+108h] [bp+10h]
  int varg_r3; // [sp+10Ch] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  v63 = a4;
  varg_r3 = a4;
  v62 = a3;
  varg_r2 = a3;
  v60 = a1;
  v72 = a1;
  v50 = a2;
  v45 = 0;
  v51 = 0;
  v6 = 6;
  v43 = 6;
  v52 = 6;
  v57[0] = 0;
  v7 = 0;
  v47 = 0;
  v64 = 0;
  v8 = 0;
  v46 = 0;
  v68 = 0;
  if ( (a4 & 0x40000000) != 0 && !a2[22] )
  {
    dword_632EE4 = 22;
    return -1073741701;
  }
  if ( (a4 & 5) != 0 )
  {
    v6 = 7;
    v43 = 7;
    v52 = 7;
  }
  v49 = 0;
  v59 = 0;
  v58 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v69 = v58;
  v65 = a5;
  while ( 1 )
  {
    if ( (v6 & 1) != 0 )
    {
      v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v46 = v8;
      v68 = v8;
      v7 = PsSetSystemPagePriorityThread(v8, 1);
      v47 = v7;
      v64 = v7;
      if ( (a2[7] & 0x4000000) != 0 )
      {
        v9 = MiCreatePerSessionProtos(a2, -1);
        if ( v9 < 0 )
          goto LABEL_10;
        v49 = 1;
        v59 = 1;
      }
      MiPrefetchControlArea((int)a2, v10, 0, 0, 0, 1, 0);
    }
    v9 = MiMapImageInSystemSpace(a2, v6, &v76);
    if ( v9 < 0 )
    {
      if ( v49 == 1 )
        MiDereferencePerSessionProtos(a2, -1);
      if ( (v6 & 1) != 0 )
      {
LABEL_10:
        PsRevertToUserPagePriorityThread(v8, v7);
        return v9;
      }
      return v9;
    }
    v11 = v77;
    v44 = v77;
    v74 = v77;
    v12 = v76;
    v54 = v76;
    v71 = v76;
    v13 = (_DWORD *)a2[14];
    v48 = v13;
    v75 = v13;
    v14 = v13[1];
    v67 = v14;
    v73 = v14;
    v15 = v14;
    v39 = v14;
    if ( v14 )
    {
      if ( (v14 & 0xFFFFFFF8) == 8 )
      {
        v16 = 1;
        v17 = v14 & 3;
      }
      else
      {
        if ( (v14 & 3) != 0 )
        {
          if ( (v14 & 3) == 1 )
            v16 = 2;
          else
            v16 = 3;
          v15 = v14 & 0xFFFFFFFC;
        }
        else
        {
          v16 = 4;
        }
        v17 = v15 & 0xFFFFFFFB;
      }
      v39 = v17;
    }
    else
    {
      v16 = 0;
    }
    v42 = v16;
    v41 = v16;
    v40[0] = 1;
    if ( *v13 && (BYTE2(MiFlags) & 3) != 3 )
    {
      v18 = ExAllocatePoolWithTag(1, v77 << 12, 1749642573);
      v12 = v18;
      v61 = v18;
      v55 = v18;
      if ( !v18 )
      {
        v9 = -1073741670;
        goto LABEL_50;
      }
      v9 = 0;
      v66 = 0;
      v70 = 0;
      v19 = v18;
      v56 = v18;
      v20 = 0;
      v11 = v44;
      while ( 1 )
      {
        v57[1] = v20;
        v53 = v19;
        if ( v20 >= v11 )
          break;
        memmove(v19, v54 + (v20 << 12), 0x1000u);
        v11 = v44;
        ++v20;
        v19 = v53 + 4096;
        v56 = v53 + 4096;
      }
      v21 = *(_DWORD *)a2[14];
      v55 = v21;
      v22 = 0;
      if ( v11 )
      {
        v23 = v12;
        v24 = v21;
        do
        {
          MiPerformFixups(v23, a2, v22++, -*(_DWORD *)(v24 + 20), 0, 0);
          v23 += 4096;
          v11 = v44;
        }
        while ( v22 < v44 );
        v9 = v66;
        v16 = v41;
        v14 = v67;
        v12 = v61;
      }
      v6 = v43;
    }
    if ( v9 >= 0 )
    {
      v25 = SeValidateImageHeader(v60, v12, v11 << 12, v58, v63, &v39, v65, v40, v57);
      v9 = v25;
      if ( v25 == 301 )
      {
        MiImageCantMove((int)a2);
        v45 = 1;
        v51 = 1;
LABEL_49:
        MiStrongCodeImage((int)a2, 1u);
        goto LABEL_50;
      }
      if ( v25 == 302 )
      {
        v26 = 1;
        v45 = 1;
        v51 = 1;
      }
      else
      {
        v26 = v45;
      }
      if ( v26 )
        goto LABEL_49;
    }
LABEL_50:
    if ( v12 != v54 && v12 )
      ExFreePoolWithTag(v12);
    MiUnmapImageInSystemSpace(&v76);
    if ( v49 == 1 )
      MiDereferencePerSessionProtos(a2, -1);
    if ( (v6 & 1) != 0 )
    {
      if ( (BYTE2(MiFlags) & 3u) > 1 )
      {
        ++dword_63381C;
        KeFlushTb(3, 2);
      }
      PsRevertToUserPagePriorityThread(v46, v47);
    }
    if ( v9 >= 0 )
      break;
    if ( v9 != -1073741789 || v44 == *(_DWORD *)(*a2 + 4) )
    {
      v27 = 4;
LABEL_64:
      dword_632EE4 = v27;
      return v9;
    }
    v6 |= 1u;
    v43 = v6;
    v52 = v6;
    v8 = v46;
    v7 = v47;
  }
  v28 = v39;
  if ( !v16 || v16 == 1 && (v39 & 0xFFFFFFF8) != 0 )
  {
    if ( (v39 & 0xFFFFFFF8) != 0 )
    {
      if ( v16 )
        v30 = v39 & 0xFFFFFFFC | 2;
      else
        v30 = v39 & 0xFFFFFFFC | 1;
    }
    else
    {
      v30 = v39 & 7 | 8;
    }
    v39 = v30;
    if ( (*(_WORD *)(*(_DWORD *)(*a2 + 36) + 30) & 0x80) != 0 )
    {
      v30 |= 4u;
      v39 = v30;
    }
    v29 = v48;
    v31 = v48 + 1;
    while ( 1 )
    {
      do
        v28 = __ldrex(v31);
      while ( v28 == v14 && __strex(v30, v31) );
      __dmb(0xBu);
      if ( v28 == v14 )
        break;
      v32 = v39;
      if ( (v39 & 0xFFFFFFF8) <= 8 )
        goto LABEL_85;
      if ( (v28 & 0xFFFFFFF8) != 8 )
      {
        v39 &= 0xFFFFFFF8;
        SeReleaseImageValidationContext(v32 & 0xFFFFFFF8);
LABEL_85:
        v39 = v28;
        goto LABEL_87;
      }
      v30 = v39 & 0xFFFFFFFC | 2;
      v39 = v30;
      v14 = v28;
    }
    v28 = v39;
LABEL_87:
    v14 = v28;
  }
  else
  {
    v29 = v48;
    if ( (unsigned int)(v16 - 2) <= 1 )
    {
      v28 = v39 & 0xFFFFFFFC | v14 & 3;
      v39 = v28;
    }
  }
  if ( (BYTE2(MiFlags) & 3) == 3 && (v28 & 0xFFFFFFF8) == 8 )
  {
    v28 = v28 & 0xFFFFFFFC | 1;
    v39 = v28;
  }
  if ( (v28 & 3) != 0 )
  {
    if ( (MiFlags & 0x100000) != 0 && (a2[13] & 0xC000000) != 0 )
    {
      if ( *v29 )
      {
        v9 = SeSetImageBaseAddress(v28 & 0xFFFFFFF8, *(_DWORD *)(*a2 + 24));
        if ( v9 < 0 )
        {
          v27 = 60;
          goto LABEL_64;
        }
      }
    }
    v9 = MiValidateImagePages(a2, 0, 1, v62);
    if ( v9 < 0 )
    {
      v27 = 59;
      goto LABEL_64;
    }
    v33 = v39 & 0xFFFFFFFC;
    v39 &= 0xFFFFFFFC;
    if ( (*(_WORD *)(*(_DWORD *)(*a2 + 36) + 30) & 0x80) != 0 )
    {
      v33 |= 4u;
      v39 = v33;
    }
    v34 = v29 + 1;
    do
      v35 = __ldrex(v34);
    while ( v35 == v14 && __strex(v33, v34) );
    __dmb(0xBu);
  }
  v36 = *a2;
  v50 = *(int **)(*a2 + 8);
  v37 = HIBYTE(v50) & 1 | (2 * (v57[0] & 7 | (8 * v40[0])));
  __dmb(0xBu);
  *(_BYTE *)(v36 + 11) = v37;
  if ( v45 )
    MiStrongCodeImage((int)a2, 2u);
  return v9;
}
