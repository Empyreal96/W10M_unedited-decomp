// MiResolveMappedFileFault 
 
int MiResolveMappedFileFault(int a1, unsigned int a2, unsigned int *a3, int a4, unsigned __int8 a5, ...)
{
  unsigned int v5; // r5
  unsigned int v7; // lr
  int v9; // r10
  int v10; // r6
  unsigned int v11; // r7
  int v12; // r8
  int v13; // r2
  __int16 v14; // r3
  int v15; // r1
  int v16; // r2
  int v17; // r3
  int v18; // r4
  int v19; // r0
  _DWORD *v20; // r6
  int v21; // r4
  int v22; // r2
  int v23; // r3
  int v24; // r10
  int v25; // r8
  int v26; // r2
  int v27; // r3
  int v28; // r4
  int v29; // r0
  int v30; // r3
  int v31; // r2
  int v32; // r7
  int v33; // r3
  int v34; // r5
  int v35; // r4
  _DWORD *v36; // r0
  int v37; // r3
  unsigned int v38; // r0
  _DWORD *v39; // r2
  int v40; // r3
  _DWORD *v41; // r0
  int v42; // r2
  int v43; // r4
  int v44; // r0
  unsigned int v45; // [sp+18h] [bp-50h]
  int v46; // [sp+1Ch] [bp-4Ch]
  int v47; // [sp+20h] [bp-48h] BYREF
  int v48; // [sp+24h] [bp-44h]
  int v49; // [sp+28h] [bp-40h]
  _BYTE *v50; // [sp+2Ch] [bp-3Ch]
  _DWORD *v51; // [sp+30h] [bp-38h] BYREF
  unsigned int v52; // [sp+34h] [bp-34h]
  int v53; // [sp+38h] [bp-30h]
  int v54; // [sp+3Ch] [bp-2Ch] BYREF
  _WORD *v55; // [sp+40h] [bp-28h] BYREF
  unsigned __int16 v56; // [sp+44h] [bp-24h]
  unsigned __int16 v57; // [sp+46h] [bp-22h]
  int v58; // [sp+84h] [bp+1Ch] BYREF
  va_list va; // [sp+84h] [bp+1Ch]
  int v60; // [sp+88h] [bp+20h]
  _DWORD *v61; // [sp+8Ch] [bp+24h]
  va_list va1; // [sp+90h] [bp+28h] BYREF

  va_start(va1, a5);
  va_start(va, a5);
  v58 = va_arg(va1, _DWORD);
  v60 = va_arg(va1, _DWORD);
  v61 = va_arg(va1, _DWORD *);
  v49 = a4;
  v45 = a2;
  v46 = 0;
  v5 = *a3;
  v51 = (_DWORD *)a1;
  v52 = 2;
  v7 = a2;
  if ( (*(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3C8) & 4) != 0 )
    return sub_544C80();
  v9 = v60;
  v10 = v60 & 1;
  if ( (v60 & 1) != 0 && *(_BYTE *)(v60 & 0xFFFFFFFE) == 1 )
  {
    v46 = v60 & 0xFFFFFFFE;
    if ( (*(_DWORD *)((v60 & 0xFFFFFFFE) + 0x28) & 0x100) != 0 )
    {
      MiUnlockProtoPoolPage(v58, 17);
      return 0;
    }
    v52 = 0;
  }
  else if ( (v60 & 1) != 0 && *(_BYTE *)(v60 & 0xFFFFFFFE) == 2 )
  {
    v46 = v60 & 0xFFFFFFFE;
  }
  if ( (v5 & 0x400) != 0 )
  {
    v11 = v5 & 0xFFFFF800 | (2 * (v5 & 0x3FC));
    v50 = 0;
  }
  else
  {
    v42 = *(_DWORD *)(MmPfnDatabase + 24 * (v5 >> 12) + 8);
    v50 = (_BYTE *)(MmPfnDatabase + 24 * (v5 >> 12));
    v11 = v42 & 0xFFFFF800 | (2 * (v42 & 0x3FC));
  }
  v12 = *(_DWORD *)v11;
  v13 = *(_DWORD *)(*(_DWORD *)v11 + 28);
  if ( (v13 & 0x10) != 0 )
  {
    MiUnlockProtoPoolPage(v58, 17);
    return -1073741818;
  }
  v14 = *(_WORD *)(v11 + 18);
  v15 = 32;
  v53 = -1;
  if ( (v14 & 2) != 0 && (v13 & 0x4000000) != 0 )
  {
    v43 = MiGetSessionIdForVa(v7);
    v53 = v43;
    if ( v45 >= dword_63389C )
    {
      if ( v10 && *(_BYTE *)(v9 & 0xFFFFFFFE) == 1 )
        goto LABEL_77;
      if ( v10 )
      {
        if ( *(_BYTE *)(v9 & 0xFFFFFFFE) == 3 )
          goto LABEL_77;
      }
      else if ( KeInvalidAccessAllowed(v9) == 1 )
      {
        goto LABEL_77;
      }
    }
    v17 = *(_DWORD *)(MiGetSharedProtos(v12, v43, v11) + 16);
    v7 = v45;
  }
  else if ( (v13 & 0x20) != 0 && (v16 = *(_DWORD *)(v11 + 12)) != 0 && v7 >= dword_63389C )
  {
    v17 = *(_DWORD *)(v16 + 16);
  }
  else
  {
    v17 = *(_DWORD *)(v11 + 4);
  }
  v48 = v17;
  if ( (unsigned int)a3 >= v17 + 4 * *(_DWORD *)(v11 + 28) )
  {
LABEL_77:
    MiUnlockProtoPoolPage(v58, 17);
    return -1073741819;
  }
  v18 = 0;
  if ( (*(_DWORD *)(v12 + 28) & 0x40000000) == 0 )
    goto LABEL_14;
  v5 = 0;
  if ( v10 && *(_BYTE *)(v9 & 0xFFFFFFFE) == 1 )
  {
    MiUnlockProtoPoolPage(v58, 17);
    v18 = 0;
    *v61 = 0;
    return v18;
  }
  v44 = MiResolveFileOnlyFault(a3, v15);
  v18 = v44;
  if ( v44 >= 0 )
  {
    v5 = *a3;
LABEL_86:
    MiUnlockProtoPoolPage(v58, 17);
    if ( v18 >= 0 )
      v18 = MiCompleteProtoPteFault(v49, a5, v45, v5, (int)v51, 0, v9);
    *v61 = 0;
    return v18;
  }
  if ( v44 != -1073532109 )
    goto LABEL_86;
  v7 = v45;
LABEL_14:
  v47 = 0;
  v54 = MiComputeFaultNode(v49, v7, v12, v9, &v51);
  if ( v18 == -1073532109 )
  {
    v40 = 1;
    goto LABEL_48;
  }
  if ( v46 )
  {
    v41 = v51;
    if ( !v51 )
      v41 = MiLocateAddress(v45);
    v47 = MiComputeFaultCluster((int)MiSystemPartition, v46, (int)v41, 0);
  }
  else if ( (v5 & 0x400) != 0 && (*(_DWORD *)(v12 + 28) & 0x20) == 0 && *(_DWORD *)(v49 + 92) == -1069539328 )
  {
    v36 = v51;
    if ( !v51 )
      v36 = MiLocateAddress(v45);
    v37 = v36[17];
    if ( v37 >= 0 )
    {
      v38 = v36[17] & 0x7FF;
      if ( v38 >= 0x11 && (v45 & 0xFFFFF000) == (v38 + ((unsigned int)v37 >> 11) - 1) << 12 )
      {
        v39 = a3 + 1;
        if ( (((_WORD)a3 + 4) & 0xFFF) != 0 && (unsigned int)v39 < v48 + 4 * *(_DWORD *)(v11 + 28) && *v39 == v5 )
        {
          v40 = v38 - 1;
LABEL_48:
          v47 = v40;
          goto LABEL_18;
        }
      }
    }
  }
LABEL_18:
  v19 = MiAllocateInPageSupport(a3, v52, &v47, (int *)va);
  v20 = (_DWORD *)v19;
  if ( !v19 )
  {
    v18 = -1073741670;
    goto LABEL_94;
  }
  if ( *a3 != v5
    || (v21 = (v5 >> 10) & 1) == 0 && ((v50[18] & 0x20) == 0 || (*(_BYTE *)(*(_DWORD *)v50 + 97) & 0x10) != 0) )
  {
    v18 = -1073740748;
    MiUnlockProtoPoolPage(v58, 17);
    MiFreeInPageSupportBlock((int)v20);
LABEL_94:
    if ( v46 )
    {
      if ( v18 == -1073741670 )
        *(_BYTE *)(v46 + 1) = 2;
      else
        *(_BYTE *)(v46 + 1) = 1;
    }
    return v18;
  }
  if ( v46 && *(_BYTE *)v46 == 1 )
    MiSetInPagePrefetchPriority(v46, v19);
  if ( v21 )
    v22 = (*(unsigned __int16 *)((v5 & 0xFFFFF800 | (2 * (v5 & 0x3FC))) + 0x10) >> 1) & 0x1F;
  else
    v22 = (v5 >> 5) & 0x1F;
  v52 = MiSanitizePfnProtection(0, (*(unsigned __int16 *)(v11 + 16) >> 1) & 0x1F, v22);
  MI_INITIALIZE_COLOR_BASE(v49, v54, &v55);
  v23 = *(_DWORD *)(v12 + 28);
  v24 = -1;
  if ( (v23 & 0x20) == 0 )
    goto LABEL_32;
  if ( (v23 & 0x40000) != 0 )
    goto LABEL_32;
  if ( !v21 )
    goto LABEL_32;
  if ( dword_6348DC )
    goto LABEL_32;
  v25 = v57;
  v26 = (unsigned __int16)(*v55 + 1);
  v27 = v56;
  *v55 = v26;
  v28 = v27 & v26;
  if ( v46 )
  {
    if ( *(_BYTE *)v46 == 1
      && !MiGetAvailablePagesBelowPriority(MiSystemPartition, ((*(_DWORD *)(v46 + 40) >> 3) & 7) + 1) )
    {
      goto LABEL_32;
    }
  }
  if ( !MiObtainFaultCharges(MiSystemPartition, 1, 1) )
    goto LABEL_32;
  v29 = MiGetPage((int)MiSystemPartition, v28 | v25, 0);
  v24 = v29;
  if ( v29 == -1 )
  {
    MiReturnFaultCharges(MiSystemPartition, 1, 1);
    goto LABEL_32;
  }
  v20[32] = v45;
  if ( MiCopyDataPageToImagePage(v20, v11, a3, v60, v29, v58) != 1 )
  {
LABEL_32:
    v30 = v58;
    v31 = v47;
    v20[30] = v11;
    v32 = v53;
    v20[23] = v30;
    v20[24] = v5;
    v33 = v48;
    v20[26] = v31;
    v20[33] = a3;
    v34 = MiPickClusterForMappedFileFault(MiSystemPartition, v20, v46, v33, v32, v24, &v51, &v54);
    v35 = MiBuildMdlForMappedFileFault(v20, v51, v54, MiSystemPartition, v34, v24, v52, v46, &v55);
    if ( v35 != v34 )
      MiReturnFaultCharges(MiSystemPartition, v34 - v35, 1);
    if ( !v35 )
    {
      MiUnlockProtoPoolPage(v58, 17);
      MiFreeInPageSupportBlock((int)v20);
      return -1073741801;
    }
    MiFinishMdlForMappedFileFault((int)v20, v60, v35, (int)v50, v32);
  }
  *v61 = v20;
  return -1073532109;
}
