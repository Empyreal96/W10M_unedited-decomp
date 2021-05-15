// CmpLoadHiveThread 
 
int __fastcall CmpLoadHiveThread(int a1)
{
  int v1; // r8
  unsigned int v2; // r9
  int v3; // r5
  int v4; // r0
  int v5; // r3
  __int16 **v7; // r6
  __int16 *v8; // r4
  int v9; // r0
  int v10; // r1
  __int16 *v11; // r4
  int v12; // r3
  unsigned int v13; // r1
  unsigned int v14; // r1
  unsigned int v15; // r0
  __int16 *v16; // r3
  int v17; // r10
  char v18; // r3
  char v19; // r3
  int v20; // r10
  int v21; // r2
  int v22; // r3
  int v23; // r3
  unsigned int v24; // r8
  unsigned int i; // r5
  int v26; // r2
  int v27; // r2
  unsigned int v28; // r3
  char *v29; // r8
  int v30; // r10
  int v31; // r3
  int v32; // r2
  int v33; // r3
  int v34; // [sp+0h] [bp-198h]
  int v35; // [sp+4h] [bp-194h]
  int v36; // [sp+8h] [bp-190h]
  char v37[4]; // [sp+18h] [bp-180h] BYREF
  __int16 *v38; // [sp+1Ch] [bp-17Ch] BYREF
  int v39; // [sp+20h] [bp-178h]
  int v40; // [sp+24h] [bp-174h] BYREF
  int v41; // [sp+28h] [bp-170h] BYREF
  int v42; // [sp+2Ch] [bp-16Ch] BYREF
  int v43[2]; // [sp+30h] [bp-168h] BYREF
  int v44[2]; // [sp+38h] [bp-160h] BYREF
  int v45[2]; // [sp+40h] [bp-158h] BYREF
  int v46; // [sp+48h] [bp-150h] BYREF
  int v47; // [sp+50h] [bp-148h] BYREF
  __int16 *v48; // [sp+58h] [bp-140h] BYREF
  char v49[284]; // [sp+5Ch] [bp-13Ch] BYREF

  v1 = a1;
  v39 = a1;
  v48 = 0;
  memset(v49, 0, sizeof(v49));
  v2 = 96 * v1;
  v3 = 0;
  v4 = KeWaitForSingleObject((unsigned int)&unk_60E7A0 + 96 * v1, 0, 0, 0, 0);
  v5 = CmpCheckHiveIndex;
  __dmb(0xBu);
  if ( v1 == v5 )
    return sub_80AE5C(v4);
  v7 = &CmpMachineHiveList[v2 / 4];
  v8 = CmpMachineHiveList[v2 / 4 + 3];
  BYTE2(CmpMachineHiveList[v2 / 4 + 8]) = 1;
  if ( v8 )
  {
    if ( (*((_DWORD *)v8 + 23) & 0x8001) == 0 )
    {
      v17 = 0;
      v38 = &word_60E7D0[v2 / 2];
      v3 = CmpOpenHiveFile((int)&word_60E7D0[v2 / 2], 0, v43, &v40, 7, (int)v44, 0, 0);
      if ( v3 < 0 )
      {
        v34 = 0;
        *((_DWORD *)v8 + 7) = &v48;
      }
      else
      {
        if ( v40 == 2 )
        {
          v17 = 1;
          v18 = 16;
        }
        else
        {
          v18 = 0;
        }
        v3 = CmpOpenHiveFile((int)v38, 4u, &v42, &v46, v18 | 2, 0, 0, 0);
        if ( v3 < 0 )
        {
          *((_DWORD *)v8 + 7) = &v48;
          v31 = 16;
        }
        else
        {
          if ( v17 )
            v19 = 16;
          else
            v19 = 0;
          v3 = CmpOpenHiveFile((int)v38, 5u, &v41, &v47, v19 | 2, 0, 0, 0);
          if ( v3 < 0 )
          {
            *((_DWORD *)v8 + 7) = &v48;
            v31 = 32;
          }
          else
          {
            v20 = v43[0];
            v3 = CmpGetFileSize(v43[0], v45);
            if ( v3 < 0 )
            {
              *((_DWORD *)v8 + 7) = &v48;
              v31 = 40;
            }
            else
            {
              CmpBecomeActiveFlusherAndReconciler(v8);
              CmpLockRegistry();
              ExAcquireResourceExclusiveLite(*((_DWORD *)v8 + 468), 1, v21, v22);
              v23 = v42;
              *((_DWORD *)v8 + 444) = v20;
              *((_DWORD *)v8 + 448) = v23;
              *((_DWORD *)v8 + 449) = v41;
              *((_DWORD *)v8 + 486) = v45[0];
              *((_DWORD *)v8 + 487) = v45[1];
              *((_DWORD *)v8 + 23) &= 0xFFFFFFFD;
              *((_DWORD *)v8 + 807) = v7[5];
              *((_DWORD *)v8 + 29) = v44[1];
              if ( CmpDoFileSetSizeEx((int)v8, 0, *((_DWORD *)v8 + 238) + 4096, 0, 1) < 0 )
              {
                CmpCannotWriteConfiguration = 1;
                *((_DWORD *)v8 + 23) &= 0xFFFDFFFF;
              }
              v24 = v44[0];
              if ( *((_DWORD *)v8 + 17) != v44[0] )
              {
                for ( i = 0; i < *((_DWORD *)v8 + 9); i += v24 )
                {
                  if ( !RtlAreBitsClear((unsigned int *)v8 + 9, i, v24) )
                    RtlSetBits((_BYTE *)v8 + 36, i, v24);
                }
                *((_DWORD *)v8 + 11) = RtlNumberOfSetBits((unsigned int *)v8 + 9);
                *((_DWORD *)v8 + 17) = v24;
              }
              v26 = *((_DWORD *)v8 + 8);
              if ( *(_DWORD *)(v26 + 4092) || (*(_DWORD *)(v26 + 4088) & 4) != 0 )
              {
                RtlSetAllBits((_DWORD *)v8 + 9);
                *((_DWORD *)v8 + 11) = *((_DWORD *)v8 + 9);
              }
              ExReleaseResourceLite(*((_DWORD *)v8 + 468));
              CmpUnlockRegistry();
              CmpLockRegistryExclusive();
              v1 = v39;
              if ( v39 == 3 )
              {
                ExAcquireResourceSharedLite(*((_DWORD *)v8 + 468), 1);
                CmpMarkCurrentValueDirty(v8, *(_DWORD *)(*((_DWORD *)v8 + 8) + 36));
                ExReleaseResourceLite(*((_DWORD *)v8 + 468));
              }
              v7[7] = v8;
              v3 = HvpDropPagedBins(v8);
              if ( v3 >= 0 )
              {
                CmpUnlockRegistry();
                CmpFinishBeingActiveFlusherAndReconciler(v8);
                v27 = *((_DWORD *)v8 + 8);
                if ( *(_DWORD *)(v27 + 4092) || (*(_DWORD *)(v27 + 4088) & 4) != 0 )
                {
                  CmpFlushHive((int)v8, 12);
                  CmpLockRegistry();
                  ExAcquireResourceExclusiveLite(*((_DWORD *)v8 + 468), 1, v32, v33);
                  *(_DWORD *)(*((_DWORD *)v8 + 8) + 4092) = 0;
                  *(_DWORD *)(*((_DWORD *)v8 + 8) + 4088) &= 0xFFFFFFFB;
                  ExReleaseResourceLite(*((_DWORD *)v8 + 468));
                  CmpUnlockRegistry();
                }
                if ( CmpCannotWriteConfiguration )
                  CmpDiskFullWarning();
                word_920732 = 128;
                SystemHiveFullPathName = 0;
                dword_920734 = (int)&SystemHiveFullPathBuffer;
                RtlAppendStringToString(&SystemHiveFullPathName, v38);
                if ( CmpInitBackupHive(v8, CmpMachineHiveList[v2 / 4]) < 0 )
                  CmpDoIdleProcessing = 0;
LABEL_48:
                *((_DWORD *)v8 + 807) |= 4u;
                if ( v1 == 3 )
                {
                  CmpLockRegistry();
                  ExAcquireResourceSharedLite(*((_DWORD *)v8 + 468), 1);
                  *((_DWORD *)v8 + 23) |= 0x200u;
                  ExReleaseResourceLite(*((_DWORD *)v8 + 468));
                  CmpUnlockRegistry();
                }
                goto LABEL_14;
              }
              *((_DWORD *)v8 + 7) = &v48;
              v31 = 80;
            }
          }
        }
        v34 = v31;
      }
      v48 = v8;
      SetFailureLocation((int)&v48, 0, 22, v3, v34);
      CmpPuntBoot = 1;
      v43[1] = (int)v38;
      ExRaiseHardError(-1073741288, 1);
      KeBugCheckEx(116, 2, 1, v1, v3);
    }
    if ( CmpMiniNTBoot || CmpVolatileBoot )
    {
      word_920732 = 128;
      SystemHiveFullPathName = 0;
      dword_920734 = (int)&SystemHiveFullPathBuffer;
      RtlAppendStringToString(&SystemHiveFullPathName, &word_60E7D0[v2 / 2]);
    }
    goto LABEL_48;
  }
  v9 = CmpInitHiveFromFile(
         (int)&word_60E7D0[v2 / 2],
         (int)v7[4],
         (int *)&v38,
         (int)&unk_60E79B + v2,
         16777217,
         v35,
         v36,
         (int)v37,
         &v48);
  v3 = v9;
  if ( v1 == 6 && !byte_60E9DC && (v9 == -1073741772 || v9 == -1073741765)
    || (v10 = (unsigned int)v7[4] & 0x8000) != 0 && !*((_BYTE *)v7 + 36) && v9 == -1073741772 )
  {
    v3 = 0;
  }
  else
  {
    if ( v9 < 0 || (v11 = v38, !v10) && (!*((_DWORD *)v38 + 448) || !*((_DWORD *)v38 + 449)) )
    {
      CmpPuntBoot = 1;
      KeBugCheckEx(116, 2, (int)&v48, v1, v9);
    }
    *((_DWORD *)v38 + 807) = (unsigned int)v7[5] | 4;
    v12 = (unsigned __int8)v37[0];
    v7[7] = v11;
    if ( v12 )
    {
      v29 = (char *)&unk_60E7A0;
      CmpInitRmLogOnLoad = 1;
      v30 = 6;
      do
      {
        KeSetEvent((int)v29, 0, 0);
        v29 += 96;
        --v30;
      }
      while ( v30 );
    }
    if ( (*((_DWORD *)v11 + 23) & 0x8001) == 0 && CmpInitBackupHive(v11, CmpMachineHiveList[v2 / 4]) < 0 )
      CmpDoIdleProcessing = 0;
  }
LABEL_14:
  *((_BYTE *)v7 + 33) = 1;
  KeSetEvent((int)&unk_60E7B0 + v2, 0, 0);
  __dmb(0xBu);
  do
  {
    v13 = __ldrex(&CmpLoadWorkerIncrement);
    v14 = v13 + 1;
  }
  while ( __strex(v14, &CmpLoadWorkerIncrement) );
  __dmb(0xBu);
  if ( v14 == 5 )
  {
    v28 = CmpCheckHiveIndex;
    __dmb(0xBu);
    if ( v28 < 6 )
      KeSetEvent((int)&CmpLoadWorkerDebugEvent, 0, 0);
  }
  v15 = (unsigned int)v7[23];
  if ( v15 )
  {
    ExFreePoolWithTag(v15);
    v16 = &word_60E7D0[v2 / 2];
    *v16 = 0;
    v16[1] = 0;
    *((_DWORD *)v16 + 1) = 0;
  }
  return PsTerminateSystemThread(v3);
}
