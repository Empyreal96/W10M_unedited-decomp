// sub_8066E4 
 
// positive sp value has been detected, the output may be wrong!
int __fastcall sub_8066E4(int a1, int a2, int a3, int a4, int (__fastcall *a5)(int), int a6, int a7, unsigned int a8, unsigned int a9, int a10, unsigned int a11, int a12, int a13, _DWORD *a14)
{
  unsigned __int64 v14; // r0
  unsigned int v15; // r5
  _DWORD *v16; // r0
  unsigned int *v17; // r9
  int v18; // r4
  __int16 *v19; // r0
  unsigned int v20; // r4
  unsigned int v21; // r7
  int v22; // lr
  unsigned int v23; // r2
  int v24; // r0
  int v25; // r1
  int v26; // r4
  int v27; // r10
  __int64 v28; // r0
  unsigned int *v29; // r3
  unsigned __int64 *v30; // r1
  unsigned int v31; // r0
  unsigned int *v32; // r1
  unsigned int *v33; // r3
  __int16 *v34; // r0
  __int16 v35; // r3
  int v36; // r0
  _DWORD *v37; // r2
  int result; // r0
  int v39; // r3
  int v40; // r6
  int v41; // r7
  unsigned int *v42; // r10
  unsigned int v43; // r6
  unsigned int v44; // r5
  int v45; // r0
  unsigned int v46; // r6
  _DWORD *v47; // r4
  _DWORD *v48; // r0
  int v49; // r1
  _DWORD *v50; // r2
  unsigned __int64 v51; // kr00_8
  int v52; // r3
  int v53; // r4
  int v54; // r4
  _DWORD *v55; // r8
  int v56; // [sp-84h] [bp-84h]
  int v57; // [sp-84h] [bp-84h]
  int v58; // [sp-80h] [bp-80h]
  unsigned int v59; // [sp-7Ch] [bp-7Ch]
  unsigned int v60; // [sp-78h] [bp-78h]
  unsigned __int64 *v61; // [sp-74h] [bp-74h]
  unsigned int v62; // [sp-70h] [bp-70h]
  unsigned int v63; // [sp-6Ch] [bp-6Ch]
  int v64; // [sp-64h] [bp-64h] BYREF
  unsigned int v65; // [sp-60h] [bp-60h]
  unsigned int *v66; // [sp-5Ch] [bp-5Ch]
  unsigned int *v67; // [sp-58h] [bp-58h]
  int v68; // [sp-54h] [bp-54h]
  unsigned int *v69; // [sp-50h] [bp-50h]
  unsigned int *v70; // [sp-4Ch] [bp-4Ch]
  unsigned int *v71; // [sp-48h] [bp-48h]
  __int16 *v72; // [sp-44h] [bp-44h]
  int i; // [sp-40h] [bp-40h]
  unsigned int *v74; // [sp-3Ch] [bp-3Ch]
  unsigned int v75; // [sp-38h] [bp-38h]
  int v76; // [sp-34h] [bp-34h]
  _WORD *v77; // [sp-2Ch] [bp-2Ch] BYREF
  __int16 v78; // [sp-28h] [bp-28h]
  unsigned __int16 v79; // [sp-26h] [bp-26h]

  if ( !v42[8] )
    JUMPOUT(0x754130);
  LODWORD(v14) = MiGetControlAreaPtes(v42);
  if ( a11 )
  {
    v15 = a11 >> 12;
    v62 = a11 >> 12;
    if ( a11 >> 12 > v14 )
      goto LABEL_86;
  }
  else
  {
    if ( HIDWORD(v14) )
LABEL_86:
      JUMPOUT(0x754132);
    v15 = v14;
    v62 = v14;
  }
  if ( v15 > 0x3FFFFFEE )
    goto LABEL_86;
  v16 = (_DWORD *)ExAllocatePoolWithTag(512, 4 * (v15 + 16), 1817341261);
  v55 = v16;
  if ( !v16 )
    return a5(-1073741670);
  v16[5] = v40;
  *v16 = v40;
  v16[1] = v42;
  v16[14] = v16 + 14;
  v16[15] = v16 + 14;
  v16[12] = v40;
  v16[13] = v40;
  v16[2] = v40;
  v16[3] = v16 + 3;
  v16[4] = v16 + 3;
  v64 = 0;
  v65 = 0;
  v58 = 0;
  v68 = 0;
  v69 = 0;
  v75 = 0;
  v17 = v42 + 20;
  if ( a11 )
  {
    v17 = MiOffsetToProtos(v42, __PAIR64__(a9, a8), (int)&v64);
    v68 = v64;
  }
  v18 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v19 = MiGetThreadPartition();
  v43 = 0;
  v44 = 0;
  v60 = 0;
  v70 = 0;
  v71 = 0;
  v72 = v19;
  if ( v41 )
  {
    v61 = *(unsigned __int64 **)(v41 + 32);
    v64 = 0;
    v59 = 0;
    v63 = *(_DWORD *)(v41 + 8) & 0x1FF | 0x200;
  }
  else
  {
    v61 = 0;
    v63 = 0;
    v59 = v65;
  }
  v67 = v55 + 16;
  v55[6] = a12;
  v55[7] = 5;
  v55[8] = 7;
  MI_INITIALIZE_COLOR_BASE(v18 + 492, (v42[7] >> 20) & 0x3F, (int)&v77);
  v20 = v62;
  v21 = 0;
  v57 = 0;
  v66 = 0;
  if ( !v62 )
  {
    v53 = 0;
    v52 = 0;
    goto LABEL_62;
  }
  v22 = 4194300;
  for ( i = 4194300; ; v22 = i )
  {
    if ( v44 < v43 )
    {
      v30 = v61;
      goto LABEL_47;
    }
    if ( v44 )
    {
      v17 = (unsigned int *)v17[2];
      if ( !v17 )
      {
LABEL_60:
        v52 = v58;
        goto LABEL_61;
      }
      v68 = 0;
      v65 = 0;
    }
    v23 = v42[7];
    if ( (v23 & 0x20) != 0 )
    {
      v46 = v17[1];
      if ( (*((_WORD *)v17 + 9) & 2) != 0 && (v23 & 0x4000000) != 0 )
      {
        if ( !v17[3] )
        {
          v43 = v60;
          v44 = v60 - 4;
          goto LABEL_58;
        }
        v45 = MiGetSharedProtos((int)v42, a13, (int)v17);
        if ( !v45 )
        {
          v43 = v60;
          v44 = v60 - 4;
          goto LABEL_58;
        }
        v46 = *(_DWORD *)(v45 + 16);
      }
      goto LABEL_42;
    }
    v57 = MiAddViewsForSection((int)v17, v17[7], 0);
    if ( v57 < 0 )
    {
      MiReleaseReadListResources((int)v55);
      ExFreePoolWithTag((unsigned int)v55);
      goto LABEL_86;
    }
    v47 = v55 + 3;
    v46 = v17[1];
    v48 = (_DWORD *)v55[4];
    if ( (_DWORD *)v55[3] == v55 + 3 || v48[2] == 5 )
    {
      v48 = (_DWORD *)ExAllocatePoolWithTag(1, 32, 1817406797);
      if ( v48 )
      {
        v48[2] = 0;
        v50 = (_DWORD *)v55[4];
        *v48 = v47;
        v48[1] = v50;
        if ( (_DWORD *)*v50 != v47 )
          __fastfail(3u);
        *v50 = v48;
        v55[4] = v48;
        goto LABEL_80;
      }
      MiRemoveViewsFromSectionWithPfn(v17, v49, v17[7], 0);
      MiReleaseReadListResources((int)v55);
      ExFreePoolWithTag((unsigned int)v55);
      return a5(-1073741670);
    }
LABEL_80:
    if ( !v55[2] )
      v55[2] = v17;
    v48[v48[2]++ + 3] = v17;
LABEL_42:
    v44 = v46 + 4 * v68;
    v60 = v46 + 4 * v17[7];
    v24 = MiStartingOffset(v17, v46);
    v26 = v25;
    v27 = v24;
    v64 = v25;
    LODWORD(v28) = MiEndingOffsetWithLock(v17);
    if ( (((_WORD)v28 - (_WORD)v27) & 0xFFF) != 0 )
    {
      v39 = v46 + 4 * ((__int64)(v28 - __PAIR64__(v26, v27) + 4095) >> 12);
      v26 = v64;
      v29 = (unsigned int *)(v39 - 4);
    }
    else
    {
      v29 = 0;
    }
    v30 = v61;
    v22 = i;
    v71 = v29;
    if ( v61 )
    {
      v64 = v27;
      v70 = (unsigned int *)v46;
      v59 = v26;
      v63 = v27 & 0xFFFFFE00 | *(_DWORD *)(v76 + 8) & 0x1FF | 0x200;
    }
    v42 = v74;
    v20 = v62;
    v43 = v60;
LABEL_47:
    v31 = *(_DWORD *)v44;
    if ( (*(_DWORD *)v44 & 2) != 0 )
      goto LABEL_48;
    if ( (v31 & 0x400) != 0 )
    {
      if ( v30 )
      {
        v51 = __PAIR64__(v59, v63) + ((int)(v44 - (_DWORD)v70) >> 2 << 12);
        *v30 = v51;
        v59 = HIDWORD(v51);
        v61 = v30 + 1;
        v63 = v51;
        v70 = (unsigned int *)v44;
      }
    }
    else
    {
      if ( (v31 & 0x800) != 0 )
      {
LABEL_48:
        MiUpdatePfnPriorityByPte(v31, a12);
        goto LABEL_58;
      }
      if ( (v31 & 0x10) == 0 )
        goto LABEL_58;
    }
    v32 = v67;
    v33 = v69;
    *v67 = v44;
    if ( !v33 )
      v69 = v32;
    if ( v66 != v17 || (v22 & (v75 >> 10)) - 0x40000000 != (v22 & (v44 >> 10)) - 0x40000000 )
    {
      *v32 = v44 | 2;
      v66 = v17;
    }
    v75 = v44;
    if ( (unsigned int *)v44 == v71 )
      *v32 |= 1u;
    v67 = v32 + 1;
    if ( !MiObtainFaultCharges(v72, 1u, 1) )
      break;
    v34 = v72;
    v35 = *v77 + 1;
    *v77 = v35;
    v36 = MiGetPage((int)v34, (unsigned __int16)(v35 & v78) | v79, 0);
    if ( v36 == -1 )
    {
      MiReturnFaultCharges(v72, 1, 1);
      v52 = v58;
      if ( !v58 )
      {
        v53 = -1073741801;
        goto LABEL_62;
      }
      goto LABEL_61;
    }
    v37 = (_DWORD *)(MmPfnDatabase + 24 * v36);
    *v37 = v55[5];
    v55[5] = v37;
    ++v58;
LABEL_58:
    ++v21;
    v44 += 4;
    if ( v21 >= v20 )
      goto LABEL_60;
  }
  v52 = v58;
  if ( !v58 )
  {
    v53 = -1073741670;
    goto LABEL_62;
  }
LABEL_61:
  v53 = v57;
LABEL_62:
  if ( v76 )
    *(_DWORD *)(v76 + 24) = v61;
  if ( v52 )
  {
    v55[10] = v69;
    v55[9] = ((char *)v67 - (char *)v55 - 64) >> 2;
    v56 = MiPfAllocateMdls(v55, a13, 0);
    if ( (_DWORD *)v55[14] == v55 + 14 )
    {
      MiReleaseReadListResources((int)v55);
      ExFreePoolWithTag((unsigned int)v55);
      v54 = v56;
      v55 = 0;
    }
    else
    {
      v54 = 0;
    }
    *a14 = v55;
    result = a5(v54);
  }
  else
  {
    MiReleaseReadListResources((int)v55);
    ExFreePoolWithTag((unsigned int)v55);
    result = a5(v53);
  }
  return result;
}
