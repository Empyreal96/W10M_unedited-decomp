// PnpProcessRelation 
 
int __fastcall PnpProcessRelation(int a1, int a2, int a3, _DWORD *a4, unsigned __int16 *a5, int a6)
{
  int v10; // r2
  int v11; // r0
  int v12; // r1
  int v13; // r6
  int v14; // r8
  int v16; // r2
  BOOL v17; // r7
  int v18; // r4
  _DWORD **v19; // r0
  _DWORD *v20; // r5
  _DWORD *v21; // r8
  unsigned int v22; // r0
  int v23; // r7
  int v24; // r4
  int v25; // r2
  int v26; // r0
  int v27; // r0
  int v28; // r2
  int v29; // r3
  int v30; // r5
  int v31; // r2
  int v32; // r2
  int v33; // r3
  int v34; // r0
  int v35; // r2
  int v36; // r3
  int v37; // r5
  int v38; // r2
  int v39; // r2
  int v40; // r3
  int v41; // r0
  int v42; // r7
  int v43; // r4
  int v44; // r2
  int v45; // r0
  int v46; // r0
  int v47; // r2
  int v48; // r3
  int v49; // r5
  int v50; // r2
  int v51; // r2
  int v52; // r3
  int v53; // r0
  int v54; // r2
  int v55; // r3
  int v56; // r5
  int v57; // r2
  int v58; // r2
  int v59; // r3
  int v60; // r10
  int v61; // r4
  int v62; // r3
  int v63; // r2
  int *v64; // r4
  int v65; // r0
  int v66; // r0
  int v67; // r0
  int v68; // r2
  int v69; // r2
  int v70; // r3
  int v71; // r4
  int v72; // r0
  int v73; // r2
  int v74; // r3
  int v75; // r3
  int v76; // r2
  int v77; // r1
  int v78; // r3
  int v79; // r2
  int v80; // r3
  int v81; // r3
  int v82; // r3
  int v83; // r2
  int v84; // r1
  int v85; // r2
  _DWORD *v86; // r4
  int v87; // r0
  int v88; // r0
  int v89; // r2
  int v90; // r2
  int v91; // r3
  int v92; // r4
  int v93; // r0
  int v94; // r2
  int v95; // r3
  int v96; // r3
  int v97; // r2
  int v98; // r1
  int v99; // r3
  int v100; // r2
  int v101; // r3
  int v102; // r3
  int v103; // r3
  int v104; // r2
  int v105; // r1
  int v106; // r2
  _DWORD *v107; // [sp+8h] [bp-28h] BYREF
  int v108; // [sp+Ch] [bp-24h] BYREF
  int v109[8]; // [sp+10h] [bp-20h] BYREF

  v108 = a3;
  v109[0] = (int)a4;
  if ( !a2 || a2 == 4 )
  {
    v10 = *(_DWORD *)(a1 + 172);
    if ( v10 == 788 || v10 == 783 || v10 == 782 )
      return -1073741823;
    if ( *(int *)(a1 + 416) > 0 || v10 == 785 || v10 == 787 )
    {
      *a4 = 5;
      RtlCopyUnicodeString(a5, (unsigned __int16 *)(a1 + 20));
      return -1073741823;
    }
    if ( v10 == 778 || v10 == 779 )
      return -1073741808;
  }
  else if ( *(_DWORD *)(a1 + 172) == 788 )
  {
    return 0;
  }
  v11 = IopAddRelationToList(a6, *(_DWORD *)(a1 + 16), a3, 0);
  v13 = v11;
  if ( v11 )
  {
    if ( v11 != -1073741771 )
    {
      if ( v11 != -1073741670 )
      {
        v87 = *(_DWORD *)(a1 + 16);
        if ( v87 )
        {
          IoAddTriageDumpDataBlock(v87, *(unsigned __int16 *)(v87 + 2));
          v88 = *(_DWORD *)(*(_DWORD *)(a1 + 16) + 8);
          if ( v88 )
          {
            IoAddTriageDumpDataBlock(v88, *(__int16 *)(v88 + 2));
            v89 = *(_DWORD *)(*(_DWORD *)(a1 + 16) + 8);
            if ( *(_WORD *)(v89 + 28) )
            {
              IoAddTriageDumpDataBlock(v89 + 28, 2);
              IoAddTriageDumpDataBlock(
                *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 16) + 8) + 32),
                *(unsigned __int16 *)(*(_DWORD *)(*(_DWORD *)(a1 + 16) + 8) + 28));
            }
          }
          v90 = *(_DWORD *)(a1 + 16);
          if ( v90 )
            v91 = *(_DWORD *)(*(_DWORD *)(v90 + 176) + 20);
          else
            v91 = 0;
          if ( v91 )
          {
            if ( v90 )
              v92 = *(_DWORD *)(*(_DWORD *)(v90 + 176) + 20);
            else
              v92 = 0;
            if ( v90 )
              v93 = *(_DWORD *)(*(_DWORD *)(v90 + 176) + 20);
            else
              v93 = 0;
            IoAddTriageDumpDataBlock(v93, 460);
            if ( *(_WORD *)(v92 + 20) )
            {
              IoAddTriageDumpDataBlock(v92 + 20, 2);
              IoAddTriageDumpDataBlock(*(_DWORD *)(v92 + 24), *(unsigned __int16 *)(v92 + 20));
            }
            v94 = *(_DWORD *)(a1 + 16);
            if ( v94 )
              v95 = *(_DWORD *)(*(_DWORD *)(v94 + 176) + 20);
            else
              v95 = 0;
            if ( *(_WORD *)(v95 + 28) )
            {
              if ( v94 )
                v96 = *(_DWORD *)(*(_DWORD *)(v94 + 176) + 20);
              else
                v96 = 0;
              IoAddTriageDumpDataBlock(v96 + 28, 2);
              v97 = *(_DWORD *)(a1 + 16);
              if ( v97 )
                v98 = *(_DWORD *)(*(_DWORD *)(v97 + 176) + 20);
              else
                v98 = 0;
              if ( v97 )
                v99 = *(_DWORD *)(*(_DWORD *)(v97 + 176) + 20);
              else
                v99 = 0;
              IoAddTriageDumpDataBlock(*(_DWORD *)(v99 + 32), *(unsigned __int16 *)(v98 + 28));
            }
            v100 = *(_DWORD *)(a1 + 16);
            if ( v100 )
              v101 = *(_DWORD *)(*(_DWORD *)(v100 + 176) + 20);
            else
              v101 = 0;
            if ( *(_DWORD *)(v101 + 8) )
            {
              v102 = v100 ? *(_DWORD *)(*(_DWORD *)(v100 + 176) + 20) : 0;
              if ( *(_WORD *)(*(_DWORD *)(v102 + 8) + 28) )
              {
                if ( v100 )
                  v103 = *(_DWORD *)(*(_DWORD *)(v100 + 176) + 20);
                else
                  v103 = 0;
                IoAddTriageDumpDataBlock(*(_DWORD *)(v103 + 8) + 28, 2);
                v104 = *(_DWORD *)(a1 + 16);
                if ( v104 )
                  v105 = *(_DWORD *)(*(_DWORD *)(v104 + 176) + 20);
                else
                  v105 = 0;
                if ( v104 )
                  v106 = *(_DWORD *)(*(_DWORD *)(v104 + 176) + 20);
                else
                  v106 = 0;
                IoAddTriageDumpDataBlock(
                  *(_DWORD *)(*(_DWORD *)(v106 + 8) + 32),
                  *(unsigned __int16 *)(*(_DWORD *)(v105 + 8) + 28));
              }
            }
          }
        }
        KeBugCheckEx(202, 7, *(_DWORD *)(a1 + 16), a6, v13);
      }
      return v13;
    }
    v86 = *(_DWORD **)(a1 + 4);
    if ( v86 )
    {
      while ( 1 )
      {
        v13 = PnpProcessRelation(v86, a2, v108, a4);
        if ( v13 < 0 )
          break;
        v86 = (_DWORD *)*v86;
        if ( !v86 )
          return 0;
      }
      return v13;
    }
    return 0;
  }
  if ( (*(_DWORD *)(a1 + 268) & 0x80000) != 0 )
  {
    v64 = (int *)IopPendingEjects;
    if ( (int *)IopPendingEjects == &IopPendingEjects )
      goto LABEL_123;
    while ( 1 )
    {
      v65 = v64[8];
      if ( v65 )
      {
        if ( IopIsRelationInList(v65, *(_DWORD *)(a1 + 16)) )
          break;
      }
      v64 = (int *)*v64;
      if ( v64 == &IopPendingEjects )
        goto LABEL_122;
    }
    if ( a2 == 4 )
    {
      v13 = IopRemoveRelationFromList(a6, *(_DWORD *)(a1 + 16));
      IopCancelPendingEject(v64);
      IopMergeRelationLists(a6, v64[8], 0);
      if ( v108 == 2 )
        IopAddRelationToList(a6, *(_DWORD *)(a1 + 16), 2, 0);
LABEL_122:
      if ( v64 != &IopPendingEjects )
        return v13;
LABEL_123:
      v66 = *(_DWORD *)(a1 + 16);
      if ( v66 )
      {
        IoAddTriageDumpDataBlock(v66, *(unsigned __int16 *)(v66 + 2));
        v67 = *(_DWORD *)(*(_DWORD *)(a1 + 16) + 8);
        if ( v67 )
        {
          IoAddTriageDumpDataBlock(v67, *(__int16 *)(v67 + 2));
          v68 = *(_DWORD *)(*(_DWORD *)(a1 + 16) + 8);
          if ( *(_WORD *)(v68 + 28) )
          {
            IoAddTriageDumpDataBlock(v68 + 28, 2);
            IoAddTriageDumpDataBlock(
              *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 16) + 8) + 32),
              *(unsigned __int16 *)(*(_DWORD *)(*(_DWORD *)(a1 + 16) + 8) + 28));
          }
        }
        v69 = *(_DWORD *)(a1 + 16);
        if ( v69 )
          v70 = *(_DWORD *)(*(_DWORD *)(v69 + 176) + 20);
        else
          v70 = 0;
        if ( v70 )
        {
          if ( v69 )
            v71 = *(_DWORD *)(*(_DWORD *)(v69 + 176) + 20);
          else
            v71 = 0;
          if ( v69 )
            v72 = *(_DWORD *)(*(_DWORD *)(v69 + 176) + 20);
          else
            v72 = 0;
          IoAddTriageDumpDataBlock(v72, 460);
          if ( *(_WORD *)(v71 + 20) )
          {
            IoAddTriageDumpDataBlock(v71 + 20, 2);
            IoAddTriageDumpDataBlock(*(_DWORD *)(v71 + 24), *(unsigned __int16 *)(v71 + 20));
          }
          v73 = *(_DWORD *)(a1 + 16);
          if ( v73 )
            v74 = *(_DWORD *)(*(_DWORD *)(v73 + 176) + 20);
          else
            v74 = 0;
          if ( *(_WORD *)(v74 + 28) )
          {
            if ( v73 )
              v75 = *(_DWORD *)(*(_DWORD *)(v73 + 176) + 20);
            else
              v75 = 0;
            IoAddTriageDumpDataBlock(v75 + 28, 2);
            v76 = *(_DWORD *)(a1 + 16);
            if ( v76 )
              v77 = *(_DWORD *)(*(_DWORD *)(v76 + 176) + 20);
            else
              v77 = 0;
            if ( v76 )
              v78 = *(_DWORD *)(*(_DWORD *)(v76 + 176) + 20);
            else
              v78 = 0;
            IoAddTriageDumpDataBlock(*(_DWORD *)(v78 + 32), *(unsigned __int16 *)(v77 + 28));
          }
          v79 = *(_DWORD *)(a1 + 16);
          if ( v79 )
            v80 = *(_DWORD *)(*(_DWORD *)(v79 + 176) + 20);
          else
            v80 = 0;
          if ( *(_DWORD *)(v80 + 8) )
          {
            v81 = v79 ? *(_DWORD *)(*(_DWORD *)(v79 + 176) + 20) : 0;
            if ( *(_WORD *)(*(_DWORD *)(v81 + 8) + 28) )
            {
              if ( v79 )
                v82 = *(_DWORD *)(*(_DWORD *)(v79 + 176) + 20);
              else
                v82 = 0;
              IoAddTriageDumpDataBlock(*(_DWORD *)(v82 + 8) + 28, 2);
              v83 = *(_DWORD *)(a1 + 16);
              if ( v83 )
                v84 = *(_DWORD *)(*(_DWORD *)(v83 + 176) + 20);
              else
                v84 = 0;
              if ( v83 )
                v85 = *(_DWORD *)(*(_DWORD *)(v83 + 176) + 20);
              else
                v85 = 0;
              IoAddTriageDumpDataBlock(
                *(_DWORD *)(*(_DWORD *)(v85 + 8) + 32),
                *(unsigned __int16 *)(*(_DWORD *)(v84 + 8) + 28));
            }
          }
        }
      }
      KeBugCheckEx(202, 6, *(_DWORD *)(a1 + 16), 0, 0);
    }
    if ( a2 )
    {
      v13 = IopRemoveRelationFromList(v64[8], *(_DWORD *)(a1 + 16));
      PipClearDevNodeFlags(a1, 0x80000);
      goto LABEL_122;
    }
    return -1073741823;
  }
  v14 = v109[0];
  if ( *(_DWORD *)(a1 + 4) )
    return sub_7DF320();
  v16 = *(_DWORD *)(a1 + 172);
  if ( v16 == 783 || v16 == 782 )
    v16 = *(_DWORD *)(a1 + 176);
  if ( (v16 == 776 || v16 == 778 || v16 == 775 || v16 == 779)
    && PnpQueryDeviceRelations(*(_DWORD *)(a1 + 16), 3, 0, &v107) >= 0 )
  {
    v22 = (unsigned int)v107;
    if ( v107 )
    {
      v23 = 0;
      if ( *v107 )
      {
        do
        {
          v24 = *(_DWORD *)(v22 + 4 * v23 + 4);
          v25 = *(_DWORD *)(v24 + 176);
          if ( (*(_DWORD *)(v25 + 16) & 2) != 0 )
          {
            IoAddTriageDumpDataBlock(*(_DWORD *)(v22 + 4 * v23 + 4), *(unsigned __int16 *)(v24 + 2));
            v34 = *(_DWORD *)(v24 + 8);
            if ( v34 )
            {
              IoAddTriageDumpDataBlock(v34, *(__int16 *)(v34 + 2));
              v35 = *(_DWORD *)(v24 + 8);
              if ( *(_WORD *)(v35 + 28) )
              {
                IoAddTriageDumpDataBlock(v35 + 28, 2);
                IoAddTriageDumpDataBlock(
                  *(_DWORD *)(*(_DWORD *)(v24 + 8) + 32),
                  *(unsigned __int16 *)(*(_DWORD *)(v24 + 8) + 28));
              }
            }
            v36 = *(_DWORD *)(v24 + 176);
            v37 = *(_DWORD *)(v36 + 20);
            if ( v37 )
            {
              IoAddTriageDumpDataBlock(*(_DWORD *)(v36 + 20), 460);
              if ( *(_WORD *)(v37 + 20) )
              {
                IoAddTriageDumpDataBlock(v37 + 20, 2);
                IoAddTriageDumpDataBlock(*(_DWORD *)(v37 + 24), *(unsigned __int16 *)(v37 + 20));
              }
              v38 = *(_DWORD *)(*(_DWORD *)(v24 + 176) + 20);
              if ( *(_WORD *)(v38 + 28) )
              {
                IoAddTriageDumpDataBlock(v38 + 28, 2);
                IoAddTriageDumpDataBlock(
                  *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v24 + 176) + 20) + 32),
                  *(unsigned __int16 *)(*(_DWORD *)(*(_DWORD *)(v24 + 176) + 20) + 28));
              }
              v39 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v24 + 176) + 20) + 8);
              if ( v39 && *(_WORD *)(v39 + 28) )
              {
                IoAddTriageDumpDataBlock(v39 + 28, 2);
                v40 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v24 + 176) + 20) + 8);
                IoAddTriageDumpDataBlock(*(_DWORD *)(v40 + 32), *(unsigned __int16 *)(v40 + 28));
              }
            }
            KeBugCheckEx(202, 11, v24, 3, 0);
          }
          v26 = *(_DWORD *)(v25 + 20);
          if ( !v26 || !*(_DWORD *)(v26 + 8) )
          {
            IoAddTriageDumpDataBlock(v24, *(unsigned __int16 *)(v24 + 2));
            v27 = *(_DWORD *)(v24 + 8);
            if ( v27 )
            {
              IoAddTriageDumpDataBlock(v27, *(__int16 *)(v27 + 2));
              v28 = *(_DWORD *)(v24 + 8);
              if ( *(_WORD *)(v28 + 28) )
              {
                IoAddTriageDumpDataBlock(v28 + 28, 2);
                IoAddTriageDumpDataBlock(
                  *(_DWORD *)(*(_DWORD *)(v24 + 8) + 32),
                  *(unsigned __int16 *)(*(_DWORD *)(v24 + 8) + 28));
              }
            }
            v29 = *(_DWORD *)(v24 + 176);
            v30 = *(_DWORD *)(v29 + 20);
            if ( v30 )
            {
              IoAddTriageDumpDataBlock(*(_DWORD *)(v29 + 20), 460);
              if ( *(_WORD *)(v30 + 20) )
              {
                IoAddTriageDumpDataBlock(v30 + 20, 2);
                IoAddTriageDumpDataBlock(*(_DWORD *)(v30 + 24), *(unsigned __int16 *)(v30 + 20));
              }
              v31 = *(_DWORD *)(*(_DWORD *)(v24 + 176) + 20);
              if ( *(_WORD *)(v31 + 28) )
              {
                IoAddTriageDumpDataBlock(v31 + 28, 2);
                IoAddTriageDumpDataBlock(
                  *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v24 + 176) + 20) + 32),
                  *(unsigned __int16 *)(*(_DWORD *)(*(_DWORD *)(v24 + 176) + 20) + 28));
              }
              v32 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v24 + 176) + 20) + 8);
              if ( v32 && *(_WORD *)(v32 + 28) )
              {
                IoAddTriageDumpDataBlock(v32 + 28, 2);
                v33 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v24 + 176) + 20) + 8);
                IoAddTriageDumpDataBlock(*(_DWORD *)(v33 + 32), *(unsigned __int16 *)(v33 + 28));
              }
            }
            KeBugCheckEx(202, 11, v24, 3, 0);
          }
          v13 = PnpProcessRelation(v26, a2, 0, v14);
          ObfDereferenceObject(v24);
          v22 = (unsigned int)v107;
          if ( v13 < 0 )
            goto LABEL_42;
        }
        while ( (unsigned int)++v23 < *v107 );
      }
      ExFreePoolWithTag(v22);
    }
  }
  if ( a2 )
  {
    if ( a2 != 5 && a2 != 6 )
    {
      v41 = PnpQueryDeviceRelations(*(_DWORD *)(a1 + 16), 1, 0, &v107);
      if ( v41 >= 0 )
      {
        v22 = (unsigned int)v107;
        if ( v107 )
        {
          v42 = 0;
          if ( *v107 )
          {
            while ( 1 )
            {
              v43 = *(_DWORD *)(v22 + 4 * v42 + 4);
              v44 = *(_DWORD *)(v43 + 176);
              if ( (*(_DWORD *)(v44 + 16) & 2) != 0 )
              {
                IoAddTriageDumpDataBlock(*(_DWORD *)(v22 + 4 * v42 + 4), *(unsigned __int16 *)(v43 + 2));
                v53 = *(_DWORD *)(v43 + 8);
                if ( v53 )
                {
                  IoAddTriageDumpDataBlock(v53, *(__int16 *)(v53 + 2));
                  v54 = *(_DWORD *)(v43 + 8);
                  if ( *(_WORD *)(v54 + 28) )
                  {
                    IoAddTriageDumpDataBlock(v54 + 28, 2);
                    IoAddTriageDumpDataBlock(
                      *(_DWORD *)(*(_DWORD *)(v43 + 8) + 32),
                      *(unsigned __int16 *)(*(_DWORD *)(v43 + 8) + 28));
                  }
                }
                v55 = *(_DWORD *)(v43 + 176);
                v56 = *(_DWORD *)(v55 + 20);
                if ( v56 )
                {
                  IoAddTriageDumpDataBlock(*(_DWORD *)(v55 + 20), 460);
                  if ( *(_WORD *)(v56 + 20) )
                  {
                    IoAddTriageDumpDataBlock(v56 + 20, 2);
                    IoAddTriageDumpDataBlock(*(_DWORD *)(v56 + 24), *(unsigned __int16 *)(v56 + 20));
                  }
                  v57 = *(_DWORD *)(*(_DWORD *)(v43 + 176) + 20);
                  if ( *(_WORD *)(v57 + 28) )
                  {
                    IoAddTriageDumpDataBlock(v57 + 28, 2);
                    IoAddTriageDumpDataBlock(
                      *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v43 + 176) + 20) + 32),
                      *(unsigned __int16 *)(*(_DWORD *)(*(_DWORD *)(v43 + 176) + 20) + 28));
                  }
                  v58 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v43 + 176) + 20) + 8);
                  if ( v58 && *(_WORD *)(v58 + 28) )
                  {
                    IoAddTriageDumpDataBlock(v58 + 28, 2);
                    v59 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v43 + 176) + 20) + 8);
                    IoAddTriageDumpDataBlock(*(_DWORD *)(v59 + 32), *(unsigned __int16 *)(v59 + 28));
                  }
                }
                KeBugCheckEx(202, 11, v43, 1, 0);
              }
              v45 = *(_DWORD *)(v44 + 20);
              if ( !v45 || !*(_DWORD *)(v45 + 8) )
              {
                IoAddTriageDumpDataBlock(v43, *(unsigned __int16 *)(v43 + 2));
                v46 = *(_DWORD *)(v43 + 8);
                if ( v46 )
                {
                  IoAddTriageDumpDataBlock(v46, *(__int16 *)(v46 + 2));
                  v47 = *(_DWORD *)(v43 + 8);
                  if ( *(_WORD *)(v47 + 28) )
                  {
                    IoAddTriageDumpDataBlock(v47 + 28, 2);
                    IoAddTriageDumpDataBlock(
                      *(_DWORD *)(*(_DWORD *)(v43 + 8) + 32),
                      *(unsigned __int16 *)(*(_DWORD *)(v43 + 8) + 28));
                  }
                }
                v48 = *(_DWORD *)(v43 + 176);
                v49 = *(_DWORD *)(v48 + 20);
                if ( v49 )
                {
                  IoAddTriageDumpDataBlock(*(_DWORD *)(v48 + 20), 460);
                  if ( *(_WORD *)(v49 + 20) )
                  {
                    IoAddTriageDumpDataBlock(v49 + 20, 2);
                    IoAddTriageDumpDataBlock(*(_DWORD *)(v49 + 24), *(unsigned __int16 *)(v49 + 20));
                  }
                  v50 = *(_DWORD *)(*(_DWORD *)(v43 + 176) + 20);
                  if ( *(_WORD *)(v50 + 28) )
                  {
                    IoAddTriageDumpDataBlock(v50 + 28, 2);
                    IoAddTriageDumpDataBlock(
                      *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v43 + 176) + 20) + 32),
                      *(unsigned __int16 *)(*(_DWORD *)(*(_DWORD *)(v43 + 176) + 20) + 28));
                  }
                  v51 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v43 + 176) + 20) + 8);
                  if ( v51 && *(_WORD *)(v51 + 28) )
                  {
                    IoAddTriageDumpDataBlock(v51 + 28, 2);
                    v52 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v43 + 176) + 20) + 8);
                    IoAddTriageDumpDataBlock(*(_DWORD *)(v52 + 32), *(unsigned __int16 *)(v52 + 28));
                  }
                }
                KeBugCheckEx(202, 11, v43, 1, 0);
              }
              v13 = PnpProcessRelation(v45, a2, 0, v14);
              ObfDereferenceObject(v43);
              v22 = (unsigned int)v107;
              if ( v13 < 0 )
                break;
              if ( (unsigned int)++v42 >= *v107 )
                goto LABEL_75;
            }
LABEL_42:
            ExFreePoolWithTag(v22);
            return v13;
          }
LABEL_75:
          ExFreePoolWithTag(v22);
        }
      }
    }
  }
  v17 = v108 != 0;
  v18 = *(_DWORD *)(a1 + 16);
  v13 = 0;
  PnpAcquireDependencyRelationsLock(0, v12);
  v19 = (_DWORD **)PiGetDependentList(v18);
  v20 = *v19;
  v21 = v19;
  if ( *v19 != v19 )
  {
    v60 = v109[0];
    while ( 1 )
    {
      PiEnumerateDependentListEntry(v20, v109, &v108);
      v20 = (_DWORD *)*v20;
      if ( v109[0] )
        break;
LABEL_110:
      if ( v20 == v21 )
        goto LABEL_20;
    }
    v61 = *(_DWORD *)(*(_DWORD *)(v109[0] + 176) + 20);
    v62 = *(_DWORD *)(v61 + 172);
    if ( v62 < 782 || v62 > 783 )
    {
      if ( !PipIsDevNodeDNStarted(*(_DWORD *)(*(_DWORD *)(v109[0] + 176) + 20)) )
        goto LABEL_109;
    }
    else
    {
      v63 = *(_DWORD *)(v61 + 176);
      if ( v63 == 786 || v63 == 788 )
      {
LABEL_109:
        if ( v13 < 0 )
          goto LABEL_20;
        goto LABEL_110;
      }
    }
    v13 = PnpProcessRelation(v61, a2, v17, v60);
    goto LABEL_109;
  }
LABEL_20:
  ExReleaseResourceLite((int)&PiDependencyRelationsLock);
  PpDevNodeUnlockTree(0);
  if ( v13 >= 0 )
    return 0;
  return v13;
}
