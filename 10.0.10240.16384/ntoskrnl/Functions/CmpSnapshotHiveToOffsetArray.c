// CmpSnapshotHiveToOffsetArray 
 
int __fastcall CmpSnapshotHiveToOffsetArray(int a1, int *a2, unsigned int *a3, unsigned int *a4)
{
  int v5; // r8
  int v6; // r4
  unsigned int v7; // r7
  unsigned int v8; // r5
  unsigned int v9; // r6
  unsigned int v10; // r1
  __int16 v11; // r3
  int v12; // r6
  int v13; // r7
  int v14; // r9
  unsigned int v15; // r4
  _DWORD *v16; // r6
  int v17; // r0
  int v18; // r5
  _DWORD *v19; // r0
  int v20; // r7
  unsigned int v21; // r5
  unsigned int v22; // r2
  int v23; // r4
  _BYTE *v24; // r0
  int v25; // r0
  _DWORD *v26; // r4
  int v27; // r1
  int *v28; // r4
  int v29; // r3
  int v30; // r0
  int v31; // r9
  unsigned int v32; // r3
  unsigned int v33; // r2
  unsigned int v34; // r6
  int v35; // r1
  _DWORD *v36; // r4
  int v37; // r0
  unsigned int *v38; // lr
  int v39; // r1
  _DWORD *v40; // r3
  int v41; // r3
  int v42; // r0
  int v43; // lr
  unsigned int *v44; // r0
  int v45; // r0
  _DWORD *v46; // r1
  unsigned int v47; // r6
  _BYTE *v48; // r0
  unsigned int v49; // r7
  int v50; // r3
  int v51; // r6
  int v52; // r0
  unsigned int *v53; // r4
  int v54; // r3
  unsigned __int8 *v55; // r0
  unsigned int v56; // r4
  unsigned int v57; // r1
  unsigned int v58; // r1
  __int16 v59; // r3
  char v61[4]; // [sp+0h] [bp-48h] BYREF
  _DWORD *v62; // [sp+4h] [bp-44h]
  unsigned int v63; // [sp+8h] [bp-40h]
  unsigned int v64; // [sp+Ch] [bp-3Ch]
  int v65; // [sp+10h] [bp-38h]
  unsigned int *v66; // [sp+14h] [bp-34h]
  int v67; // [sp+18h] [bp-30h]
  int v68; // [sp+1Ch] [bp-2Ch]
  int v69; // [sp+20h] [bp-28h]
  int v70; // [sp+24h] [bp-24h] BYREF
  unsigned int *v71; // [sp+28h] [bp-20h]

  v71 = a4;
  v66 = a3;
  v69 = a1;
  v5 = 0;
  v6 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v6 & 0xFFFFFFC0) + 0x134);
  __pld(&CmpShutdownRundown);
  v7 = CmpShutdownRundown & 0xFFFFFFFE;
  v8 = (CmpShutdownRundown & 0xFFFFFFFE) + 2;
  do
    v9 = __ldrex((unsigned int *)&CmpShutdownRundown);
  while ( v9 == v7 && __strex(v8, (unsigned int *)&CmpShutdownRundown) );
  __dmb(0xBu);
  if ( v9 != v7 && !ExfAcquireRundownProtection(&CmpShutdownRundown) )
  {
    v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v11 = *(_WORD *)(v10 + 0x134) + 1;
    *(_WORD *)(v10 + 308) = v11;
    if ( !v11 && *(_DWORD *)(v10 + 100) != v10 + 100 && !*(_WORD *)(v10 + 310) )
      KiCheckForKernelApcDelivery(0);
    return -1073741431;
  }
  v12 = (int)v66;
  v13 = v69;
  *v66 = 0;
  *a2 = 0;
  v61[0] = 0;
  v14 = *(_DWORD *)(v13 + 952);
  v70 = -1;
  v15 = 0;
  v68 = *(_DWORD *)(v13 + 32);
  if ( v14 )
  {
    do
    {
      v16 = (_DWORD *)HvpGetCellMap(v13, v15);
      v17 = HvpMapEntryGetFreeBin((int)v16);
      if ( !v17 || (*(_DWORD *)(v17 + 16) & 1) != 0 )
      {
        v19 = (_DWORD *)HvpMapEntryGetBinAddress(v17, v16, v61, &v70);
        v18 = v19[2];
        if ( *v19 != 1852400232 || v19[1] != v15 || v18 + v15 > *(_DWORD *)(v13 + 952) || (v18 & 0xFFF) != 0 )
        {
          if ( v61[0] )
            HvpMapEntryReleaseBinAddress((int)v19, (int)v16);
          v5 = -1073741492;
LABEL_72:
          v53 = v66;
          if ( *v66 )
          {
            while ( *a2 )
            {
              v54 = *a2 - 1;
              *a2 = v54;
              ExFreePoolWithTag(*(_DWORD *)(*v53 + 12 * v54 + 4));
            }
            ExFreePoolWithTag(*v53);
            *a2 = 0;
          }
          goto LABEL_77;
        }
        if ( v61[0] )
          HvpMapEntryReleaseBinAddress((int)v19, (int)v16);
      }
      else
      {
        v18 = *(_DWORD *)(v17 + 8);
      }
      v15 += v18;
    }
    while ( v15 < *(_DWORD *)(v13 + 952) );
    v12 = (int)v66;
  }
  v20 = 4096;
  v21 = v14 + 4096;
  v22 = (unsigned int)(v14 + 4096) >> 20;
  v64 = 4096;
  if ( ((v14 + 4096) & 0xFFFFF) != 0 )
    ++v22;
  v23 = 3 * v22;
  v24 = (_BYTE *)ExAllocatePoolWithTag(1, 12 * v22, 538987843);
  *(_DWORD *)v12 = v24;
  if ( !v24 )
    goto LABEL_26;
  memset(v24, 0, 4 * v23);
  *v71 = v21;
  if ( v21 >= 0x100000 )
    v21 = 0x100000;
  v25 = ExAllocatePoolWithTag(1, v21, 538987843);
  v26 = *(_DWORD **)v12;
  *(_DWORD *)(*(_DWORD *)v12 + 4) = v25;
  if ( !v25 )
  {
LABEL_26:
    v5 = -1073741801;
    goto LABEL_72;
  }
  *v26 = 0;
  v27 = v68;
  v26[2] = v21;
  memmove(v26[1], v27, 0x1000u);
  v28 = (int *)v26[1];
  v29 = v28[1];
  v28[10] = v14;
  v28[2] = v29;
  v28[127] = HvpHeaderCheckSum(v28);
  v30 = v69;
  *a2 = 1;
  v71 = 0;
  v31 = 0;
  v61[0] = 0;
  v32 = *(_DWORD *)(v30 + 952);
  v33 = 0;
  v34 = 0;
  v35 = 0;
  v36 = 0;
  v62 = 0;
  v63 = 0;
  v67 = 4096;
  v68 = 0;
  v65 = 0;
  if ( v32 )
  {
    while ( 1 )
    {
      if ( v20 == v21 )
      {
        v21 = v32 - v33;
        if ( v32 - v33 >= 0x100000 )
          v21 = 0x100000;
        v37 = ExAllocatePoolWithTag(1, v21, 538987843);
        v38 = v66;
        v39 = *a2;
        v40 = (_DWORD *)(*v66 + 12 * *a2);
        v40[1] = v37;
        if ( !v37 )
          goto LABEL_26;
        v30 = v69;
        *v40 = v67;
        v40[2] = v21;
        v41 = v39 + 1;
        v20 = 0;
        v35 = (int)v62;
        v33 = v63;
        v64 = 0;
        *a2 = v41;
      }
      else
      {
        v38 = v66;
      }
      if ( v34 )
      {
        if ( v34 > v21 )
          v34 = v21;
        v42 = memmove(*(_DWORD *)(*v38 + 12 * *a2 - 8), v35, v34);
        v65 -= v34;
        if ( !v65 )
        {
          if ( v68 )
          {
            ExFreePoolWithTag((unsigned int)v36);
            v68 = 0;
          }
          else if ( v31 )
          {
            HvpMapEntryReleaseBinAddress(v42, (int)v71);
            v31 = 0;
            v61[0] = 0;
          }
        }
        v20 += v34;
        v33 = v63 + v34;
        v43 = v67 + v34;
        v34 = v65;
        v63 = v33;
        v64 = v20;
        v67 = v43;
        goto LABEL_68;
      }
      v44 = (unsigned int *)HvpGetCellMap(v30, v33);
      v71 = v44;
      if ( !v44 )
      {
        v5 = -1073741275;
        goto LABEL_72;
      }
      v45 = HvpMapEntryGetFreeBin((int)v44);
      if ( !v45 )
        break;
      v47 = *(_DWORD *)(v45 + 8);
      if ( (*(_DWORD *)(v45 + 16) & 1) != 0 )
      {
        v36 = (_DWORD *)HvpMapEntryGetBinAddress(v45, v46, v61, &v70);
LABEL_56:
        v31 = (unsigned __int8)v61[0];
        goto LABEL_57;
      }
      v48 = (_BYTE *)ExAllocatePoolWithTag(1, *(_DWORD *)(v45 + 8), 1648905539);
      v36 = v48;
      if ( !v48 )
        goto LABEL_26;
      v31 = 0;
      v68 = 1;
      v61[0] = 0;
      memset(v48, 0, v47);
      v36[2] = v47;
      *v36 = 1852400232;
      v36[1] = v63;
      v36[8] = v47 - 32;
LABEL_57:
      v49 = v21 - v20;
      v62 = v36;
      if ( v47 > v49 )
      {
        v50 = v47 - v49;
      }
      else
      {
        v49 = v47;
        v50 = 0;
      }
      v65 = v50;
      v51 = v64;
      v52 = memmove(*(_DWORD *)(*v66 + 12 * *a2 - 8) + v64, (int)v36, v49);
      v64 = v51 + v49;
      v34 = v65;
      v33 = v63 + v49;
      v67 += v49;
      v63 += v49;
      if ( !v65 )
      {
        if ( v68 )
        {
          ExFreePoolWithTag((unsigned int)v36);
          v68 = 0;
          goto LABEL_66;
        }
        if ( v31 )
        {
          HvpMapEntryReleaseBinAddress(v52, (int)v71);
          v31 = 0;
          v61[0] = 0;
LABEL_66:
          v33 = v63;
        }
        v20 = v64;
LABEL_68:
        v35 = (int)v62;
        goto LABEL_69;
      }
      v35 = (int)v36 + v49;
      v20 = v64;
      v62 = (_DWORD *)v35;
LABEL_69:
      v30 = v69;
      v32 = *(_DWORD *)(v69 + 952);
      if ( v33 >= v32 )
        goto LABEL_77;
    }
    v36 = (_DWORD *)HvpMapEntryGetBinAddress(0, v46, v61, &v70);
    v47 = v36[2];
    goto LABEL_56;
  }
LABEL_77:
  v55 = (unsigned __int8 *)&CmpShutdownRundown;
  __pld(&CmpShutdownRundown);
  v56 = CmpShutdownRundown & 0xFFFFFFFE;
  __dmb(0xBu);
  do
    v57 = __ldrex((unsigned int *)&CmpShutdownRundown);
  while ( v57 == v56 && __strex(v56 - 2, (unsigned int *)&CmpShutdownRundown) );
  if ( v57 != v56 )
    v55 = ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
  v58 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v59 = *(_WORD *)(v58 + 0x134) + 1;
  *(_WORD *)(v58 + 308) = v59;
  if ( !v59 && *(_DWORD *)(v58 + 100) != v58 + 100 && !*(_WORD *)(v58 + 310) )
    KiCheckForKernelApcDelivery((int)v55);
  return v5;
}
