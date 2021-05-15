// IoWriteCrashDump 
 
int __fastcall IoWriteCrashDump(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, char a9)
{
  int v12; // r10
  int v13; // r2
  unsigned int v14; // r0
  int v15; // r1
  int v16; // r3
  int v17; // r0
  int v18; // r9
  _DWORD *v19; // r0
  int v20; // r1
  int v21; // r2
  _DWORD *v22; // r5
  int v23; // r1
  int v24; // r3
  int v25; // r2
  int v26; // r5
  int v29; // [sp+30h] [bp-60h]
  int (__fastcall *v30)(_DWORD *, int, int, int); // [sp+38h] [bp-58h] BYREF
  int v31; // [sp+3Ch] [bp-54h]
  unsigned int *v32; // [sp+40h] [bp-50h]
  int v33; // [sp+44h] [bp-4Ch]
  int v34; // [sp+48h] [bp-48h]
  unsigned int v35[2]; // [sp+50h] [bp-40h] BYREF
  int v36; // [sp+58h] [bp-38h] BYREF
  int v37; // [sp+5Ch] [bp-34h]
  _DWORD v38[12]; // [sp+60h] [bp-30h] BYREF

  v29 = a3;
  v37 = a8;
  v12 = 0;
  v35[0] = 3583;
  v36 = 0;
  KdCheckForDebugBreak();
  if ( CapsuleTriageDumpBlockInitialized != 1 )
  {
    v38[0] = a2;
    v38[1] = a3;
    v38[2] = a4;
    v38[3] = a5;
    MmSnapTriageDumpInformation(a6, v38);
    v13 = CrashdmpDumpBlock;
    if ( !CrashdmpDumpBlock )
      return v12;
    if ( (*(_DWORD *)(CrashdmpDumpBlock + 492) & 1) != 0 && *(_DWORD *)(CrashdmpDumpBlock + 476) == 6 )
    {
      v14 = 0;
      v15 = CrashdmpDumpBlock;
      while ( *(_DWORD *)(v15 + 496) != a1 )
      {
        ++v14;
        v15 += 4;
        if ( v14 >= 8 )
          goto LABEL_11;
      }
      *(_DWORD *)(CrashdmpDumpBlock + 476) = 5;
      v13 = CrashdmpDumpBlock;
    }
LABEL_11:
    if ( a8 )
    {
      v16 = 0;
    }
    else
    {
      *(_DWORD *)(v13 + 8) = 0;
      v35[0] = 3319;
      v16 = 1;
    }
    v17 = dword_637660(1, 0, v16);
    VfDisableHalVerifier(v17);
    v18 = dword_637678(1);
    IoSaveBugCheckProgress(32);
    KiSweepCurrentIcache();
    *(_DWORD *)(CrashdmpDumpBlock + 16) = a1;
    *(_DWORD *)(CrashdmpDumpBlock + 20) = a2;
    *(_DWORD *)(CrashdmpDumpBlock + 24) = v29;
    *(_DWORD *)(CrashdmpDumpBlock + 28) = a4;
    *(_DWORD *)(CrashdmpDumpBlock + 32) = a5;
    memmove(CrashdmpDumpBlock + 40, a6, 0x1A0u);
    *(_DWORD *)(CrashdmpDumpBlock + 456) = &KdDebuggerDataBlock;
    *(_DWORD *)(CrashdmpDumpBlock + 460) = &PsActiveProcessHead;
    *(_DWORD *)(CrashdmpDumpBlock + 464) = &PsLoadedModuleList;
    *(_DWORD *)(CrashdmpDumpBlock + 468) = MmPfnDatabase;
    *(_DWORD *)(CrashdmpDumpBlock + 12) = &KeBugCheckReasonCallbackListHead;
    if ( a8 )
      *(_DWORD *)(CrashdmpDumpBlock + 480) = *(_DWORD *)(*(_DWORD *)(a7 + 116) + 24);
    v19 = (_DWORD *)CrashdmpDumpBlock;
    if ( *(_DWORD *)(CrashdmpDumpBlock + 472) || v18 != 1 || !a8 )
    {
      IopUpdateMinidumpContext(a1, a2, v29, a4, a5, a6, a7);
      MmSnapTriageDumpInformation(a6, v38);
      v20 = CrashdmpDumpBlock;
      v30 = (int (__fastcall *)(_DWORD *, int, int, int))IopNumTriageDumpDataBlocks;
      v31 = 256;
      v32 = (unsigned int *)&IopTriageDumpDataBlocks;
      if ( v18 == 1 || (v21 = *(_DWORD *)(CrashdmpDumpBlock + 488)) == 0 )
      {
        if ( !*(_DWORD *)(CrashdmpDumpBlock + 472) && !a8 )
        {
          *(_DWORD *)(CrashdmpDumpBlock + 472) = *(_DWORD *)(CrashdmpDumpBlock + 488) + 4096;
          v20 = CrashdmpDumpBlock;
        }
      }
      else
      {
        *(_DWORD *)(CrashdmpDumpBlock + 472) = v21 + 8220;
        *(_DWORD *)(CrashdmpDumpBlock + 8) = 0;
        v20 = CrashdmpDumpBlock;
      }
      if ( IoFillTriageDumpBuffer(
             0x1F000u,
             *(_DWORD *)(v20 + 472),
             1,
             v35[0],
             0,
             a6,
             a7,
             CmNtCSDVersion,
             65,
             1,
             (int)&v30,
             (int)&v30,
             &v36) < 0 )
        goto LABEL_53;
      v19 = (_DWORD *)CrashdmpDumpBlock;
    }
    v22 = (_DWORD *)v19[2];
    if ( !v22 )
    {
LABEL_36:
      v26 = dword_637664(v19, v37);
      if ( v26 == -1073741267 )
      {
        if ( *(_DWORD *)(CrashdmpDumpBlock + 472) )
        {
          IoSetBugCheckProgressFlag(0x2000000);
          IopUpdateMinidumpContext(a1, a2, v29, a4, a5, a6, a7);
          MmSnapTriageDumpInformation(a6, v38);
          v30 = (int (__fastcall *)(_DWORD *, int, int, int))IopNumTriageDumpDataBlocks;
          v31 = 256;
          v32 = (unsigned int *)&IopTriageDumpDataBlocks;
          v26 = IoFillTriageDumpBuffer(
                  0x1F000u,
                  *(_DWORD *)(CrashdmpDumpBlock + 472),
                  1,
                  3583,
                  0,
                  a6,
                  a7,
                  CmNtCSDVersion,
                  65,
                  1,
                  (int)&v30,
                  (int)&v30,
                  &v36);
          if ( v26 >= 0 )
          {
            v26 = dword_637664(CrashdmpDumpBlock, v37);
            IoSaveBugCheckProgress(35);
          }
        }
      }
      if ( (DumpPolicyAttemptOffline & 1) != 0 && v26 < 0 || (DumpPolicyAttemptOffline & 2) != 0 && !v18 )
      {
        IoSaveBugCheckProgress(36);
        if ( off_617B14(0) >= 0 )
        {
          IoSetBugCheckProgressFlag(0x8000000);
          while ( 1 )
          {
            KeStallExecutionProcessor(1000000);
            ++AttemptOfflineStallCount;
          }
        }
      }
      else if ( v26 >= 0 )
      {
        if ( v18 != 1 && *(_DWORD *)(CrashdmpDumpBlock + 488) )
        {
          IoSetBugCheckProgressFlag(0x4000000);
          v26 = IopWriteTriageDumpToFirmware(*(_DWORD *)(CrashdmpDumpBlock + 488));
          IoSetBugCheckProgressFlag(0x10000000);
        }
        if ( v26 >= 0 )
          v12 = 1;
      }
LABEL_53:
      KiSweepCurrentIcache();
      return v12;
    }
    v30 = 0;
    v31 = 0;
    v32 = 0;
    v33 = 0;
    v34 = 0;
    v23 = 1;
    v35[0] = v22[12];
    v35[1] = (unsigned int)(v22 + 14);
    v32 = v35;
    v33 = 0;
    v30 = IoSetDumpRange;
    v31 = (int)IoFreeDumpRange;
    v24 = v19[119];
    if ( v24 == 6 )
    {
      v23 = 0;
      if ( a9 )
      {
        v25 = 1;
LABEL_35:
        MmGetDumpRange(&v30, v23, v25);
        IopDumpCallAddPagesCallbacks(a1);
        IoSaveBugCheckProgress(33);
        IopDumpCallRemovePagesCallbacks(a1);
        IoSaveBugCheckProgress(34);
        v22[10] = RtlNumberOfSetBits(v35);
        v22[11] = 0;
        v19 = (_DWORD *)CrashdmpDumpBlock;
        goto LABEL_36;
      }
    }
    else if ( v24 == 5 && (v19[123] & 2) != 0 )
    {
      v23 = 0;
      v25 = 2;
      goto LABEL_35;
    }
    v25 = 0;
    goto LABEL_35;
  }
  return IopWriteCapsuleTriageDumpToFirmware(a1, a2, a3, a4, a5, a6, a7);
}
