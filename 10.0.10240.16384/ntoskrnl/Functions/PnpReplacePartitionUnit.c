// PnpReplacePartitionUnit 
 
int __fastcall PnpReplacePartitionUnit(int *a1)
{
  int v2; // r8
  int v3; // r2
  int v4; // r3
  int v5; // r0
  int v6; // r3
  int *v7; // r0
  int *v8; // r5
  int v9; // r4
  int v10; // r0
  int v11; // r2
  int v12; // r2
  int v13; // r3
  int v14; // r4
  int v15; // r0
  int v16; // r2
  int v17; // r3
  int v18; // r3
  int v19; // r2
  int v20; // r1
  int v21; // r3
  int v22; // r2
  int v23; // r3
  int v24; // r3
  int v25; // r3
  int v26; // r2
  int v27; // r1
  int v28; // r2
  int v29; // r0
  int v30; // r2
  int v31; // r2
  int v32; // r3
  int v33; // r4
  int v34; // r0
  int v35; // r2
  int v36; // r3
  int v37; // r3
  int v38; // r2
  int v39; // r1
  int v40; // r3
  int v41; // r2
  int v42; // r3
  int v43; // r3
  int v44; // r3
  int v45; // r2
  int v46; // r1
  int v47; // r2
  int v48; // r3
  int v49; // r3
  int v50; // r3
  int v51; // r3
  int v52; // r3
  int v53; // r2
  int v54; // r2
  int v55; // r0
  int v56; // r0
  int v57; // r2
  int v58; // r2
  char v59; // r8
  int v60; // r0
  int v61; // r2
  int v62; // r3
  int v63; // r2
  int v64; // r2
  int v65; // r2
  int v66; // r3
  int v67; // r2
  int v68; // r2
  int v69; // r2
  int *v70; // r3
  int v71; // r2
  int *v72; // r1
  int v73; // r2
  int v74; // r1
  int v75; // r2
  int v76; // r3
  unsigned int v77; // r7
  void (__fastcall *v78)(int *); // r3
  int v79; // r7
  unsigned int v80; // r0
  unsigned int v81; // r0
  unsigned int v82; // r0
  unsigned int v83; // r0
  int v85; // [sp+8h] [bp-88h]
  int v86; // [sp+10h] [bp-80h] BYREF
  int v87; // [sp+14h] [bp-7Ch]
  unsigned int v88; // [sp+18h] [bp-78h]
  _DWORD v89[4]; // [sp+20h] [bp-70h] BYREF
  int v90[24]; // [sp+30h] [bp-60h] BYREF

  v2 = KeNumberProcessors_0;
  v85 = KeNumberProcessors_0;
  KeWaitForSingleObject((unsigned int)&PnpReplaceEvent, 0, 0, 0, 0);
  if ( a1[2] >= 0 )
  {
    v3 = a1[1];
    if ( v3 )
    {
      v4 = *(_DWORD *)(*(_DWORD *)(v3 + 176) + 20);
      if ( v4 && (*(_DWORD *)(v4 + 268) & 0x20000) == 0 )
      {
        v5 = *a1;
        if ( *a1 )
        {
          v6 = *(_DWORD *)(*(_DWORD *)(v5 + 176) + 20);
          if ( v6 && (*(_DWORD *)(v6 + 268) & 0x20000) == 0 )
          {
            PnprLogStartEvent();
            goto LABEL_9;
          }
          IoAddTriageDumpDataBlock(v5, *(unsigned __int16 *)(v5 + 2));
          v10 = *(_DWORD *)(*a1 + 8);
          if ( v10 )
          {
            IoAddTriageDumpDataBlock(v10, *(__int16 *)(v10 + 2));
            v11 = *(_DWORD *)(*a1 + 8);
            if ( *(_WORD *)(v11 + 28) )
            {
              IoAddTriageDumpDataBlock(v11 + 28, 2);
              IoAddTriageDumpDataBlock(
                *(_DWORD *)(*(_DWORD *)(*a1 + 8) + 32),
                *(unsigned __int16 *)(*(_DWORD *)(*a1 + 8) + 28));
            }
          }
          v12 = *a1;
          if ( *a1 )
            v13 = *(_DWORD *)(*(_DWORD *)(v12 + 176) + 20);
          else
            v13 = 0;
          if ( v13 )
          {
            if ( v12 )
              v14 = *(_DWORD *)(*(_DWORD *)(v12 + 176) + 20);
            else
              v14 = 0;
            if ( v12 )
              v15 = *(_DWORD *)(*(_DWORD *)(v12 + 176) + 20);
            else
              v15 = 0;
            IoAddTriageDumpDataBlock(v15, 460);
            if ( *(_WORD *)(v14 + 20) )
            {
              IoAddTriageDumpDataBlock(v14 + 20, 2);
              IoAddTriageDumpDataBlock(*(_DWORD *)(v14 + 24), *(unsigned __int16 *)(v14 + 20));
            }
            v16 = *a1;
            if ( *a1 )
              v17 = *(_DWORD *)(*(_DWORD *)(v16 + 176) + 20);
            else
              v17 = 0;
            if ( *(_WORD *)(v17 + 28) )
            {
              if ( v16 )
                v18 = *(_DWORD *)(*(_DWORD *)(v16 + 176) + 20);
              else
                v18 = 0;
              IoAddTriageDumpDataBlock(v18 + 28, 2);
              v19 = *a1;
              if ( *a1 )
                v20 = *(_DWORD *)(*(_DWORD *)(v19 + 176) + 20);
              else
                v20 = 0;
              if ( v19 )
                v21 = *(_DWORD *)(*(_DWORD *)(v19 + 176) + 20);
              else
                v21 = 0;
              IoAddTriageDumpDataBlock(*(_DWORD *)(v21 + 32), *(unsigned __int16 *)(v20 + 28));
            }
            v22 = *a1;
            if ( *a1 )
              v23 = *(_DWORD *)(*(_DWORD *)(v22 + 176) + 20);
            else
              v23 = 0;
            if ( *(_DWORD *)(v23 + 8) )
            {
              v24 = v22 ? *(_DWORD *)(*(_DWORD *)(v22 + 176) + 20) : 0;
              if ( *(_WORD *)(*(_DWORD *)(v24 + 8) + 28) )
              {
                if ( v22 )
                  v25 = *(_DWORD *)(*(_DWORD *)(v22 + 176) + 20);
                else
                  v25 = 0;
                IoAddTriageDumpDataBlock(*(_DWORD *)(v25 + 8) + 28, 2);
                v26 = *a1;
                if ( *a1 )
                  v27 = *(_DWORD *)(*(_DWORD *)(v26 + 176) + 20);
                else
                  v27 = 0;
                if ( v26 )
                  v28 = *(_DWORD *)(*(_DWORD *)(v26 + 176) + 20);
                else
                  v28 = 0;
                IoAddTriageDumpDataBlock(
                  *(_DWORD *)(*(_DWORD *)(v28 + 8) + 32),
                  *(unsigned __int16 *)(*(_DWORD *)(v27 + 8) + 28));
              }
            }
          }
        }
        KeBugCheckEx(202, 2, *a1, 0, 0);
      }
      IoAddTriageDumpDataBlock(a1[1], *(unsigned __int16 *)(v3 + 2));
      v29 = *(_DWORD *)(a1[1] + 8);
      if ( v29 )
      {
        IoAddTriageDumpDataBlock(v29, *(__int16 *)(v29 + 2));
        v30 = *(_DWORD *)(a1[1] + 8);
        if ( *(_WORD *)(v30 + 28) )
        {
          IoAddTriageDumpDataBlock(v30 + 28, 2);
          IoAddTriageDumpDataBlock(
            *(_DWORD *)(*(_DWORD *)(a1[1] + 8) + 32),
            *(unsigned __int16 *)(*(_DWORD *)(a1[1] + 8) + 28));
        }
      }
      v31 = a1[1];
      if ( v31 )
        v32 = *(_DWORD *)(*(_DWORD *)(v31 + 176) + 20);
      else
        v32 = 0;
      if ( v32 )
      {
        if ( v31 )
          v33 = *(_DWORD *)(*(_DWORD *)(v31 + 176) + 20);
        else
          v33 = 0;
        if ( v31 )
          v34 = *(_DWORD *)(*(_DWORD *)(v31 + 176) + 20);
        else
          v34 = 0;
        IoAddTriageDumpDataBlock(v34, 460);
        if ( *(_WORD *)(v33 + 20) )
        {
          IoAddTriageDumpDataBlock(v33 + 20, 2);
          IoAddTriageDumpDataBlock(*(_DWORD *)(v33 + 24), *(unsigned __int16 *)(v33 + 20));
        }
        v35 = a1[1];
        if ( v35 )
          v36 = *(_DWORD *)(*(_DWORD *)(v35 + 176) + 20);
        else
          v36 = 0;
        if ( *(_WORD *)(v36 + 28) )
        {
          if ( v35 )
            v37 = *(_DWORD *)(*(_DWORD *)(v35 + 176) + 20);
          else
            v37 = 0;
          IoAddTriageDumpDataBlock(v37 + 28, 2);
          v38 = a1[1];
          if ( v38 )
            v39 = *(_DWORD *)(*(_DWORD *)(v38 + 176) + 20);
          else
            v39 = 0;
          if ( v38 )
            v40 = *(_DWORD *)(*(_DWORD *)(v38 + 176) + 20);
          else
            v40 = 0;
          IoAddTriageDumpDataBlock(*(_DWORD *)(v40 + 32), *(unsigned __int16 *)(v39 + 28));
        }
        v41 = a1[1];
        if ( v41 )
          v42 = *(_DWORD *)(*(_DWORD *)(v41 + 176) + 20);
        else
          v42 = 0;
        if ( *(_DWORD *)(v42 + 8) )
        {
          v43 = v41 ? *(_DWORD *)(*(_DWORD *)(v41 + 176) + 20) : 0;
          if ( *(_WORD *)(*(_DWORD *)(v43 + 8) + 28) )
          {
            if ( v41 )
              v44 = *(_DWORD *)(*(_DWORD *)(v41 + 176) + 20);
            else
              v44 = 0;
            IoAddTriageDumpDataBlock(*(_DWORD *)(v44 + 8) + 28, 2);
            v45 = a1[1];
            if ( v45 )
              v46 = *(_DWORD *)(*(_DWORD *)(v45 + 176) + 20);
            else
              v46 = 0;
            if ( v45 )
              v47 = *(_DWORD *)(*(_DWORD *)(v45 + 176) + 20);
            else
              v47 = 0;
            IoAddTriageDumpDataBlock(
              *(_DWORD *)(*(_DWORD *)(v47 + 8) + 32),
              *(unsigned __int16 *)(*(_DWORD *)(v46 + 8) + 28));
          }
        }
      }
    }
    KeBugCheckEx(202, 2, a1[1], 0, 0);
  }
LABEL_9:
  v7 = (int *)ExAllocatePoolWithTag(512, 672, 1366322768);
  v8 = v7;
  if ( !v7 )
  {
    v9 = -1073741670;
    goto LABEL_186;
  }
  v7 = (int *)memset(v7, 0, 672);
  *v8 = *a1;
  v48 = a1[1];
  PnprContext = (int)v8;
  v8[6] = v48;
  v8[12] = a1[2];
  v49 = (unsigned __int8)KeDynamicPartitioningSupported;
  v8[28] = (int)(v8 + 28);
  v8[29] = (int)(v8 + 28);
  if ( v49 || (a1[2] & 0x80000000) != 0 )
  {
    v7 = (int *)PnprLegacyDeviceDriversPresent(v7);
    if ( v7 )
    {
      v52 = PnprContext;
      v9 = -1073741621;
      v53 = *(_DWORD *)(PnprContext + 608);
      if ( !v53 )
        v53 = 186;
      *(_DWORD *)(PnprContext + 608) = v53;
      v54 = *(_DWORD *)(v52 + 612);
      if ( !v54 )
        v54 = 7;
LABEL_119:
      *(_DWORD *)(v52 + 612) = v54;
      goto LABEL_186;
    }
    v55 = PnprGetMillisecondCounter(1);
    if ( (a1[2] & 0x80000000) != 0 )
    {
      PnprLockPagesForReplace(v55);
      PnprQuiesceDevices(v90);
      v56 = PnprWakeDevices((int)v90);
      v7 = (int *)PnprUnlockPagesForReplace(v56);
      v9 = 0;
      goto LABEL_186;
    }
    v7 = (int *)PnprIdentifyUnits(*v8, v8[6], v8 + 2, v8 + 8);
    v9 = (int)v7;
    if ( (int)v7 < 0 )
    {
      v52 = PnprContext;
      v57 = *(_DWORD *)(PnprContext + 608);
      if ( !v57 )
        v57 = 223;
      *(_DWORD *)(PnprContext + 608) = v57;
      v54 = *(_DWORD *)(v52 + 612);
      if ( !v54 )
        v54 = 3;
      goto LABEL_119;
    }
    v7 = (int *)PnprCollectResources(v8, v8 + 6);
    v9 = (int)v7;
    if ( (int)v7 < 0 )
    {
      v52 = PnprContext;
      v58 = *(_DWORD *)(PnprContext + 608);
      if ( !v58 )
        v58 = 236;
      *(_DWORD *)(PnprContext + 608) = v58;
      v54 = *(_DWORD *)(v52 + 612);
      if ( !v54 )
        v54 = 1;
      goto LABEL_119;
    }
    v7 = (int *)PnprLoadPluginDriver(v8 + 136, v8 + 139);
    v9 = (int)v7;
    v59 = 0;
    if ( (int)v7 < 0 )
    {
      if ( *(_DWORD *)(v8[5] + 4) )
      {
        v62 = PnprContext;
        v64 = *(_DWORD *)(PnprContext + 608);
        if ( !v64 )
          v64 = 262;
        goto LABEL_144;
      }
    }
    else
    {
      v60 = PnprQueryReplaceFeatures((int)(v8 + 139), v8 + 6);
      v59 = v60;
      v8[12] |= v60;
    }
    v7 = (int *)v8[5];
    if ( v7[1] )
    {
      v61 = v8[141];
      if ( (v61 & 1) == 0 || !v8[145] )
      {
        v62 = PnprContext;
        v9 = -1073741637;
        v63 = *(_DWORD *)(PnprContext + 608);
        if ( !v63 )
          v63 = 277;
        goto LABEL_165;
      }
      if ( (v61 & 2) != 0 && !v8[146] )
      {
        v62 = PnprContext;
        v9 = -1073741637;
        v63 = *(_DWORD *)(PnprContext + 608);
        if ( !v63 )
          v63 = 285;
LABEL_165:
        *(_DWORD *)(v62 + 608) = v63;
        v65 = *(_DWORD *)(v62 + 612);
        if ( !v65 )
          v65 = 9;
LABEL_146:
        v2 = v85;
        *(_DWORD *)(v62 + 612) = v65;
        goto LABEL_186;
      }
      v7 = (int *)PnprMmConstruct();
      v9 = (int)v7;
      if ( (int)v7 < 0 )
      {
        v62 = PnprContext;
        v64 = *(_DWORD *)(PnprContext + 608);
        if ( !v64 )
          v64 = 297;
LABEL_144:
        *(_DWORD *)(v62 + 608) = v64;
        v65 = *(_DWORD *)(v62 + 612);
        if ( !v65 )
          v65 = 1;
        goto LABEL_146;
      }
      if ( (v59 & 8) != 0 )
      {
        *(_DWORD *)(v8[11] + 4) = 0;
      }
      else if ( !v8[150] || (v8[12] & 0x20) != 0 )
      {
        v62 = PnprContext;
        v9 = -1073741637;
        v63 = *(_DWORD *)(PnprContext + 608);
        if ( !v63 )
          v63 = 321;
        goto LABEL_165;
      }
      v2 = v85;
      v7 = (int *)PnprAllocateMappingReserves(v8 + 26, v8 + 27, v85);
      v9 = (int)v7;
      if ( (int)v7 < 0 )
      {
        v66 = PnprContext;
        v67 = *(_DWORD *)(PnprContext + 608);
        if ( !v67 )
          v67 = 336;
        *(_DWORD *)(PnprContext + 608) = v67;
        v68 = *(_DWORD *)(v66 + 612);
        if ( !v68 )
          v68 = 10;
        goto LABEL_159;
      }
      v8[30] = 0;
    }
    else
    {
      v2 = v85;
    }
    if ( (v8[12] & 0x20) == 0 || v8[151] )
    {
      v8[31] = v2;
      v86 = *(_DWORD *)&KeActiveProcessors;
      v87 = dword_681D74;
      v88 = dword_681D78[0];
      v70 = (int *)v8[4];
      v7 = (int *)v70[1];
      if ( v7 )
      {
        v71 = *v70;
        v72 = &v86;
        do
        {
          v72[2] &= ~*(int *)((char *)v72 + v71 - (_DWORD)&v86);
          ++v72;
          v7 = (int *)((char *)v7 - 1);
        }
        while ( v7 );
      }
      if ( v88 )
      {
        if ( (v88 & 1) != 0 )
          v8[32] = 0;
        else
          v8[32] = 31 - __clz(v88);
        v86 = 0;
        v87 = 0;
        v88 = 0;
        v86 = 1 << v8[32];
        KeSetSystemGroupAffinityThread((int)&v86, v89);
        v9 = PnprInitiateReplaceOperation();
        v7 = (int *)KeRevertToUserGroupAffinityThread((int)v89, v74, v75, v76);
        goto LABEL_186;
      }
      v66 = PnprContext;
      v9 = -1073741621;
      v73 = *(_DWORD *)(PnprContext + 608);
      if ( !v73 )
        v73 = 383;
      *(_DWORD *)(PnprContext + 608) = v73;
      v68 = *(_DWORD *)(v66 + 612);
      if ( !v68 )
        v68 = 6;
    }
    else
    {
      v66 = PnprContext;
      v9 = -1073741637;
      v69 = *(_DWORD *)(PnprContext + 608);
      if ( !v69 )
        v69 = 356;
      *(_DWORD *)(PnprContext + 608) = v69;
      v68 = *(_DWORD *)(v66 + 612);
      if ( !v68 )
        v68 = 9;
    }
LABEL_159:
    *(_DWORD *)(v66 + 612) = v68;
    goto LABEL_186;
  }
  v50 = v8[152];
  v9 = -1073741637;
  if ( !v50 )
    v50 = 174;
  v8[152] = v50;
  v51 = v8[153];
  if ( !v51 )
    v51 = 2;
  v8[153] = v51;
LABEL_186:
  if ( (a1[2] & 0x80000000) == 0 )
  {
    if ( v9 < 0 )
    {
      v7 = (int *)PnprLogFailureEvent(*a1, a1[1], v9);
    }
    else
    {
      v8[166] = PnprGetMillisecondCounter(0);
      v7 = (int *)PnprLogSuccessEvent();
    }
  }
  if ( v8 )
  {
    v77 = v8[136];
    if ( v77 )
    {
      v78 = (void (__fastcall *)(int *))v8[142];
      if ( v78 )
        v78(v7);
      MmUnloadSystemImage(v77);
    }
    if ( v8[26] && v8[27] )
    {
      if ( v2 )
      {
        v79 = 0;
        do
        {
          PnprFreeMappingReserve(v79 + v8[26]);
          PnprFreeMappingReserve(v79 + v8[27]);
          v79 += 12;
          --v2;
        }
        while ( v2 );
      }
      ExFreePoolWithTag(v8[26]);
      ExFreePoolWithTag(v8[27]);
    }
    PnprMmFree(v8 + 28);
    v80 = v8[4];
    if ( v80 )
    {
      ExFreePoolWithTag(v80);
      v8[4] = 0;
    }
    v81 = v8[5];
    if ( v81 )
    {
      ExFreePoolWithTag(v81);
      v8[5] = 0;
    }
    v82 = v8[10];
    if ( v82 )
    {
      ExFreePoolWithTag(v82);
      v8[10] = 0;
    }
    v83 = v8[11];
    if ( v83 )
    {
      ExFreePoolWithTag(v83);
      v8[11] = 0;
    }
    ExFreePoolWithTag((unsigned int)v8);
  }
  KeSetEvent((int)&PnpReplaceEvent, 0, 0);
  a1[3] = v9;
  return KeSetEvent((int)(a1 + 4), 0, 0);
}
