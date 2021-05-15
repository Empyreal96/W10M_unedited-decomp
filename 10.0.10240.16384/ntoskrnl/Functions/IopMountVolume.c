// IopMountVolume 
 
int __fastcall IopMountVolume(_DWORD *a1, int a2, int a3, int a4, int *a5)
{
  int v7; // r6
  int v8; // r9
  int v9; // r0
  int v10; // r4
  unsigned int v11; // r8
  unsigned int v12; // r2
  int v13; // r8
  int v14; // r6
  BOOL v15; // r3
  char v16; // r2
  int v17; // r0
  int v18; // r4
  unsigned int v19; // r1
  int v20; // r3
  int v21; // r0
  int v22; // r8
  int i; // r9
  int v24; // r3
  int *v25; // r2
  _DWORD *v26; // r4
  int v27; // lr
  BOOL v28; // r1
  int v29; // r8
  int v30; // r6
  int v31; // r0
  int v32; // r6
  int v33; // r3
  int v34; // r2
  unsigned int v35; // r2
  int v36; // r0
  unsigned int v37; // r2
  _DWORD *v38; // r8
  int v39; // r0
  int v40; // r0
  int v41; // r4
  int v42; // r6
  __int16 v43; // r3
  int v44; // r4
  int v45; // r2
  BOOL v46; // r3
  char v47; // r2
  int v48; // r0
  unsigned int v49; // r1
  int v50; // r3
  char v51; // r0
  int v52; // r6
  unsigned int v53; // r1
  __int16 v54; // r3
  int v55; // r1
  __int16 v56; // r3
  int v57; // r8
  int v58; // r9
  int v59; // r10
  int v60; // r0
  unsigned int v61; // r5
  int *v62; // r2
  int v63; // r0
  char v65; // [sp+8h] [bp-148h]
  char v66; // [sp+9h] [bp-147h]
  int v67; // [sp+Ch] [bp-144h]
  int *v68; // [sp+10h] [bp-140h] BYREF
  char v69; // [sp+14h] [bp-13Ch]
  char v70; // [sp+15h] [bp-13Bh]
  unsigned __int16 v71; // [sp+18h] [bp-138h] BYREF
  char v72[6]; // [sp+1Ah] [bp-136h]
  int v73; // [sp+20h] [bp-130h]
  int v74; // [sp+24h] [bp-12Ch]
  int v75; // [sp+28h] [bp-128h]
  int v76; // [sp+2Ch] [bp-124h]
  int v77; // [sp+30h] [bp-120h] BYREF
  int v78; // [sp+34h] [bp-11Ch] BYREF
  _DWORD *v79; // [sp+38h] [bp-118h]
  _DWORD *v80; // [sp+3Ch] [bp-114h]
  _DWORD *v81; // [sp+40h] [bp-110h]
  unsigned int v82; // [sp+44h] [bp-10Ch]
  int v83; // [sp+48h] [bp-108h]
  int v84; // [sp+50h] [bp-100h] BYREF
  int v85; // [sp+54h] [bp-FCh]
  int v86; // [sp+58h] [bp-F8h]
  int *v87; // [sp+5Ch] [bp-F4h]
  int v88; // [sp+60h] [bp-F0h]
  _DWORD v89[2]; // [sp+68h] [bp-E8h] BYREF
  _BYTE v90[16]; // [sp+70h] [bp-E0h] BYREF
  _DWORD v91[50]; // [sp+80h] [bp-D0h] BYREF

  v73 = a4;
  v78 = a3;
  v74 = a2;
  v80 = a1;
  v87 = a5;
  v7 = -1073741823;
  v8 = 0;
  v68 = 0;
  v76 = 0;
  v91[0] = 0;
  v91[1] = 0;
  v91[2] = 0;
  v91[3] = 0;
  v71 = 0;
  *(_DWORD *)v72 = 0;
  *(_WORD *)&v72[4] = 0;
  v69 = 0;
  v66 = 0;
  v9 = MmIsThisAnNtAsSystem();
  v10 = v9;
  v75 = v9;
  v70 = v9;
  v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v82 = v11;
  v83 = v11;
  if ( IopShutdownFileSystems != 1 )
  {
    if ( v9 )
    {
      v8 = IoGetActivityIdThread();
      v68 = (int *)v8;
      v76 = v8;
      IoVolumeDeviceToGuid(a1, v91);
      IoVolumeDeviceToDosName((int)a1, &v71);
    }
    if ( !a3 )
    {
      v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v12 + 308);
      v13 = *(char *)(v11 + 346);
      v14 = v73;
      do
      {
        v15 = v14 || v13 == 1;
        if ( v14 )
          v16 = v13;
        else
          v16 = 0;
        v17 = KeWaitForSingleObject((unsigned int)(a1 + 39), 0, v16, (_DWORD *)v15, 0);
        v18 = v17;
      }
      while ( (v17 == 257 || v17 == 192)
           && !v14
           && (*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3C0) & 1) == 0 );
      v7 = -1073741823;
      v8 = (int)v68;
      if ( v17 == 257 || v17 == 192 )
      {
        v19 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v20 = (__int16)(*(_WORD *)(v19 + 0x134) + 1);
        *(_WORD *)(v19 + 308) = v20;
        if ( !v20 && *(_DWORD *)(v19 + 100) != v19 + 100 && !*(_WORD *)(v19 + 310) )
          KiCheckForKernelApcDelivery(v17);
        return v18;
      }
      v66 = 1;
      v10 = v75;
      v11 = v82;
    }
    --*(_WORD *)(v11 + 308);
    ExAcquireResourceSharedLite((int)&IopDatabaseResource, 1);
    v65 = 1;
    v21 = IopQueryVpbFlagsSafe((int)a1);
    if ( (v21 & 9) == 0 )
    {
      if ( v10 )
      {
        v22 = v71;
        LOWORD(v77) = v71 >> 1;
        v75 = dword_631B0C;
        v79 = (_DWORD *)IoMgrTraceHandle;
        if ( EtwEventEnabled(IoMgrTraceHandle, dword_631B0C, (int)IoMgr_MountBegin) )
        {
          v91[32] = v91;
          v91[33] = 0;
          v91[34] = 16;
          v91[35] = 0;
          v91[36] = &v77;
          v91[37] = 0;
          v91[38] = 2;
          v91[39] = 0;
          v91[40] = *(_DWORD *)&v72[2];
          v91[41] = 0;
          v91[42] = v22;
          v91[43] = 0;
          EtwWrite((int)v79, v75, (int)IoMgr_MountBegin, v8);
        }
        v69 = 1;
      }
      KeInitializeEvent((int)v90, 0, 0);
      v67 = -1073741823;
      a1[7] &= 0xFFFFFFFD;
      for ( i = (int)a1; *(_DWORD *)(i + 16); i = *(_DWORD *)(i + 16) )
        ;
      ObfReferenceObject(i);
      v24 = a1[11];
      if ( v24 == 7 || v24 == 36 )
      {
        v25 = &IopDiskFileSystemQueueHead;
      }
      else if ( v24 == 2 )
      {
        v25 = &IopCdRomFileSystemQueueHead;
      }
      else
      {
        v25 = &IopTapeFileSystemQueueHead;
      }
      v68 = v25;
      v21 = *(unsigned __int16 *)(a1[9] + 4);
      v75 = v21;
      v26 = (_DWORD *)*v25;
      v81 = (_DWORD *)*v25;
      v27 = v74;
      while ( v26 != v25 )
      {
        if ( v7 >= 0 )
          goto LABEL_119;
        v28 = *v26 == (_DWORD)v25;
        v77 = v28;
        if ( !v27 && v28 && v26 != (_DWORD *)*v25 )
          break;
        if ( (v21 & 0x10) == 0 || v28 )
        {
          v29 = (int)(v26 - 13);
          v79 = v26 - 13;
          v30 = 1;
          v88 = 1;
          while ( *(_DWORD *)(v29 + 16) )
          {
            v29 = *(_DWORD *)(v29 + 16);
            v88 = ++v30;
          }
          KeResetEvent((int)v90);
          v31 = IopAllocateIrpWithExtension(0, *(_BYTE *)(i + 48) + v30, 0);
          v32 = v31;
          if ( !v31 )
          {
            v33 = -1073741670;
            goto LABEL_52;
          }
          *(_DWORD *)(v31 + 8) = 66;
          *(_BYTE *)(v31 + 32) = 0;
          *(_DWORD *)(v31 + 44) = v90;
          *(_DWORD *)(v31 + 40) = &v84;
          *(_DWORD *)(v31 + 80) = v82;
          v34 = *(_DWORD *)(v31 + 96);
          *(_BYTE *)(v34 - 40) = 13;
          *(_BYTE *)(v34 - 39) = 1;
          *(_BYTE *)(v34 - 38) = v74;
          *(_DWORD *)(v34 - 32) = a1[9];
          *(_DWORD *)(v34 - 28) = i;
          v86 = IopFsRegistrationOps;
          ObfReferenceObject(v29);
          IopIncrementDeviceObjectRefCount((int)v79, 1);
          __dmb(0xBu);
          do
            v35 = __ldrex((unsigned int *)&IopMountsInProgress);
          while ( __strex(v35 + 1, (unsigned int *)&IopMountsInProgress) );
          __dmb(0xBu);
          ExReleaseResourceLite((int)&IopDatabaseResource);
          v36 = IofCallDriver(v29, v32);
          if ( v36 == 259 )
          {
            KeWaitForSingleObject((unsigned int)v90, 0, 0, 0, 0);
          }
          else
          {
            v84 = v36;
            v85 = 0;
          }
          ExAcquireResourceSharedLite((int)&IopDatabaseResource, 1);
          v65 = 1;
          __dmb(0xBu);
          do
            v37 = __ldrex((unsigned int *)&IopMountsInProgress);
          while ( __strex(v37 - 1, (unsigned int *)&IopMountsInProgress) );
          __dmb(0xBu);
          if ( IopMountCompletionWaiters )
            KeSetEvent((int)&IopMountCompletionEvent, 0, 0);
          ObfDereferenceObject(v29);
          v38 = v79;
          v21 = IopDecrementDeviceObjectRef(v79, 0, 0);
          v7 = v84;
          v67 = v84;
          if ( v84 < 0 )
          {
            if ( (v84 == -1073741661
               || v84 == -1073741643
               || v84 == -1073741662
               || v84 == -1073741805
               || v84 == -2147483626
               || v84 == -1073741804
               || v84 == -1073741806)
              && v85 == 1 )
            {
              break;
            }
            v25 = v68;
            if ( v86 != IopFsRegistrationOps )
            {
              v89[0] = *v68;
              v26 = v89;
              v81 = v89;
              v7 = -1073741489;
              v67 = -1073741489;
            }
            if ( v7 == -1073741412 )
            {
              IopIncrementDeviceObjectRefCount((int)v38, 1);
              v40 = ExReleaseResourceLite((int)&IopDatabaseResource);
              v65 = 0;
              v41 = v78;
              if ( !v78 )
              {
                v40 = KeSetEvent((int)(a1 + 39), 0, 0);
                v66 = 0;
              }
              v42 = v82;
              v43 = *(_WORD *)(v82 + 308) + 1;
              *(_WORD *)(v82 + 308) = v43;
              if ( !v43 && *(_DWORD *)(v42 + 100) != v42 + 100 && !*(_WORD *)(v42 + 310) )
                KiCheckForKernelApcDelivery(v40);
              IopLoadFileSystemDriver(v38);
              if ( !v41 )
              {
                v44 = *(char *)(v42 + 346);
                v45 = v73;
                do
                {
                  v46 = v45 || v44 == 1;
                  if ( v45 )
                    v47 = v44;
                  else
                    v47 = 0;
                  v48 = KeWaitForSingleObject((unsigned int)(a1 + 39), 0, v47, (_DWORD *)v46, 0);
                  if ( v48 != 257 && v48 != 192 )
                    break;
                  v45 = v73;
                  if ( v73 )
                    break;
                }
                while ( (*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3C0) & 1) == 0 );
                v67 = v48;
                if ( v48 == 257 || v48 == 192 )
                {
                  v21 = ObfDereferenceObject(i);
                  v49 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
                  v50 = (__int16)(*(_WORD *)(v49 + 0x134) + 1);
                  *(_WORD *)(v49 + 308) = v50;
                  if ( !v50 && *(_DWORD *)(v49 + 100) != v49 + 100 && !*(_WORD *)(v49 + 310) )
                    v21 = KiCheckForKernelApcDelivery(v21);
                  goto LABEL_119;
                }
                v66 = 1;
              }
              --*(_WORD *)(v42 + 308);
              ExAcquireResourceSharedLite((int)&IopDatabaseResource, 1);
              v65 = 1;
              v51 = IopQueryVpbFlagsSafe((int)a1);
              if ( (v51 & 8) != 0 )
              {
                v33 = -1073741632;
LABEL_52:
                v67 = v33;
LABEL_115:
                v21 = ObfDereferenceObject(i);
                goto LABEL_119;
              }
              if ( (v51 & 1) != 0 )
              {
                v21 = ObfDereferenceObject(i);
                goto LABEL_118;
              }
              v25 = v68;
              v89[0] = *v68;
              v26 = v89;
              v81 = v89;
              v7 = -1073741489;
              v67 = -1073741489;
            }
            if ( v7 != -1073741489 )
            {
              v21 = FsRtlIsTotalDeviceFailure(v7);
              if ( v21 )
              {
                if ( !v74 || v77 )
                  break;
                v25 = v68;
                v26 = *(_DWORD **)(v68[1] + 4);
                v81 = v26;
              }
              else
              {
                v25 = v68;
              }
            }
          }
          else
          {
            v39 = IopMountInitializeVpb((int)a1, i, v75 & 0x10, v77);
            *v87 = v39;
            v25 = v68;
          }
          v21 = v75;
          v27 = v74;
        }
        v26 = (_DWORD *)*v26;
        v81 = v26;
      }
      if ( v7 >= 0 )
        goto LABEL_119;
      goto LABEL_115;
    }
    if ( (v21 & 8) != 0 )
      v67 = -1073741632;
    else
LABEL_118:
      v67 = 0;
LABEL_119:
    if ( v65 )
      v21 = ExReleaseResourceLite((int)&IopDatabaseResource);
    v52 = (int)v80;
    if ( v66 )
    {
      v21 = KeSetEvent((int)(v80 + 39), 0, 0);
      v53 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v54 = *(_WORD *)(v53 + 0x134) + 1;
      *(_WORD *)(v53 + 308) = v54;
      if ( !v54 && *(_DWORD *)(v53 + 100) != v53 + 100 && !*(_WORD *)(v53 + 310) )
        v21 = KiCheckForKernelApcDelivery(v21);
    }
    v55 = v83;
    v56 = *(_WORD *)(v83 + 308) + 1;
    *(_WORD *)(v83 + 308) = v56;
    if ( !v56 && *(_DWORD *)(v55 + 100) != v55 + 100 && !*(_WORD *)(v55 + 310) )
      KiCheckForKernelApcDelivery(v21);
    v18 = v67;
    if ( !v70 )
    {
LABEL_141:
      if ( v67 < 0 && (*(_DWORD *)(v52 + 28) & 0x100) != 0 && (unsigned int)InitializationPhase < 2 )
        KeBugCheckEx(237, v52, v67, 0, 0);
      return v18;
    }
    if ( v69 )
    {
      v57 = v71;
      LOWORD(v68) = v71 >> 1;
      v58 = dword_631B0C;
      v59 = IoMgrTraceHandle;
      if ( v67 >= 0 )
      {
        v60 = EtwEventEnabled(IoMgrTraceHandle, dword_631B0C, (int)IoMgr_MountSucceeded);
        v61 = *(_DWORD *)&v72[2];
        if ( !v60 )
          goto LABEL_139;
        v91[4] = v91;
        v91[5] = 0;
        v91[6] = 16;
        v91[7] = 0;
        v91[8] = &v68;
        v91[9] = 0;
        v91[10] = 2;
        v91[11] = 0;
        v91[12] = *(_DWORD *)&v72[2];
        v91[13] = 0;
        v91[14] = v57;
        v91[15] = 0;
        v62 = IoMgr_MountSucceeded;
        goto LABEL_135;
      }
      v78 = v67;
      v63 = EtwEventEnabled(IoMgrTraceHandle, dword_631B0C, (int)IoMgr_MountFailed);
      v61 = *(_DWORD *)&v72[2];
      if ( v63 )
      {
        v91[16] = v91;
        v91[17] = 0;
        v91[18] = 16;
        v91[19] = 0;
        v91[20] = &v68;
        v91[21] = 0;
        v91[22] = 2;
        v91[23] = 0;
        v91[24] = *(_DWORD *)&v72[2];
        v91[25] = 0;
        v91[26] = v57;
        v91[27] = 0;
        v91[28] = &v78;
        v91[29] = 0;
        v91[30] = 4;
        v91[31] = 0;
        v62 = IoMgr_MountFailed;
LABEL_135:
        EtwWrite(v59, v58, (int)v62, v76);
        goto LABEL_139;
      }
    }
    else
    {
      v61 = *(_DWORD *)&v72[2];
    }
LABEL_139:
    if ( v61 )
      ExFreePoolWithTag(v61);
    goto LABEL_141;
  }
  return -1073741431;
}
