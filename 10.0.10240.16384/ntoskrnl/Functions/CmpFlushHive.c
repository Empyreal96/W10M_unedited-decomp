// CmpFlushHive 
 
int __fastcall CmpFlushHive(int a1, int a2)
{
  int v2; // r9
  int v4; // r0
  int v6; // r2
  unsigned int v7; // r6
  int v8; // r3
  int v9; // r0
  unsigned int v10; // r5
  int v11; // r3
  int v12; // r7
  _DWORD *v13; // r0
  int v14; // r10
  int v15; // r4
  unsigned int v16; // r7
  int v17; // r0
  int v18; // r0
  int v19; // r1
  char v20; // r4
  int v21; // r6
  int v22; // r0
  int v23; // r0
  int v24; // r1
  int v25; // r0
  int v26; // r6
  _DWORD *v27; // r6
  int v28; // r5
  int v29; // r1
  int v30; // r7
  int v31; // r0
  int v32; // r0
  _DWORD *v33; // r2
  int v34; // r3
  int v35; // r0
  __int64 v36; // kr00_8
  unsigned int v37; // lr
  int v38; // r4
  unsigned int v39; // r3
  int v40; // r1
  int v41; // [sp+8h] [bp-B8h]
  BOOL v42; // [sp+10h] [bp-B0h]
  int v43; // [sp+18h] [bp-A8h] BYREF
  unsigned int v44; // [sp+20h] [bp-A0h] BYREF
  int v45; // [sp+24h] [bp-9Ch]
  int v46; // [sp+28h] [bp-98h]
  int v47; // [sp+2Ch] [bp-94h]
  unsigned int v48; // [sp+30h] [bp-90h]
  int v49; // [sp+34h] [bp-8Ch]
  int v50; // [sp+40h] [bp-80h] BYREF
  int v51; // [sp+44h] [bp-7Ch]
  int v52; // [sp+48h] [bp-78h]
  int v53; // [sp+4Ch] [bp-74h]

  v41 = 0;
  v43 = a2;
  v2 = a2;
  v50 = 285212694;
  v51 = 196868;
  v52 = 0;
  v53 = 0x40000000;
  v4 = EtwEventEnabled(EtwpRegTraceHandle, dword_92026C, (int)&v50);
  if ( v4 )
    return sub_7D3A24();
  v6 = *(_DWORD *)(a1 + 92);
  if ( (v6 & 0x8001) != 0 )
  {
LABEL_81:
    v30 = 0;
    goto LABEL_77;
  }
  if ( !*(_DWORD *)(a1 + 1776) )
  {
    v30 = -1073741811;
    goto LABEL_77;
  }
  if ( (v6 & 2) != 0 )
    v2 |= 0xCu;
  v42 = (v2 & 0x10) != 0;
  v7 = 0;
  while ( 1 )
  {
    if ( (v2 & 1) != 0 )
      CmpLockRegistry(v4, 1);
    else
      CmpLockRegistryFreezeAware(0);
    CmpLockHiveFlusherExclusive(a1);
    if ( (v2 & 2) != 0 )
    {
      v8 = *(_DWORD *)(a1 + 3312);
      if ( (v8 & 2) != 0 || (v8 & 1) != 0 && (v2 & 4) == 0 )
      {
LABEL_80:
        v32 = CmpUnlockHiveFlusher(a1);
        CmpUnlockRegistry(v32);
        goto LABEL_81;
      }
    }
    if ( (v2 & 4) == 0 || (*(_DWORD *)(a1 + 3312) & 2) == 0 )
      break;
LABEL_96:
    v4 = CmpWaitOnHiveWriteQueue(a1, a1 + 3300, v2);
    v30 = v41;
LABEL_137:
    if ( v7 >= 2 )
      goto LABEL_77;
  }
  if ( (*(_DWORD *)(a1 + 3312) & 1) != 0 )
  {
    if ( (v2 & 4) != 0 )
    {
      v38 = 0;
    }
    else if ( *(_DWORD *)(a1 + 44) || *(_BYTE *)(a1 + 123) )
    {
      v38 = 1;
    }
    else
    {
      v38 = 2;
    }
    v4 = CmpWaitOnHiveWriteQueue(a1, a1 + 3288, v2);
    v30 = v4;
    v41 = v4;
    if ( v4 >= 0 )
      v7 += v38;
    goto LABEL_137;
  }
  v9 = CmpGenerateFlushControlData(a1, v2, &v44);
  v10 = v44;
  if ( (v44 & 0x358) == 0 )
    goto LABEL_80;
  if ( (v44 & 2) != 0 )
  {
    v11 = *(_DWORD *)(a1 + 3312);
    if ( (v11 & 2) == 0 )
    {
      *(_DWORD *)(a1 + 3312) = v11 | 2;
      *(_DWORD *)(a1 + 3300) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      goto LABEL_19;
    }
    goto LABEL_96;
  }
  if ( (v44 & 0x2000) != 0 )
    CmpBoostActiveHiveWriter(v9, a1 + 3300);
LABEL_19:
  if ( (v10 & 1) != 0 )
  {
    *(_DWORD *)(a1 + 3312) |= 1u;
    *(_DWORD *)(a1 + 3288) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  }
  v12 = (v10 >> 6) & 1;
  if ( (v10 & 8) == 0 )
  {
LABEL_24:
    if ( (v10 & 0x158) != 0 && (v13 = (_DWORD *)HvStoreModifiedData(a1, (v10 & 0x110) != 0, v12 != 0)) != 0 )
    {
      if ( v13 == (_DWORD *)1 )
      {
        v20 = v45 | 2;
        v41 = 0;
        goto LABEL_67;
      }
      v14 = -1073741823;
      v41 = -1073741823;
      if ( v13 == (_DWORD *)2 )
        goto LABEL_141;
    }
    else
    {
      v14 = v41;
    }
    if ( (v10 & 0x80) != 0 )
    {
      v39 = *(_DWORD *)(a1 + 952);
      v16 = *(_DWORD *)(a1 + 3316);
      if ( v39 > v16 )
      {
        v15 = v39 + 4096;
        *(_DWORD *)(a1 + 3316) = 0;
LABEL_29:
        v17 = CmpUnlockHiveFlusher(a1);
        v18 = CmpUnlockRegistry(v17);
        if ( (v10 & 0x80) != 0 )
        {
          v18 = HvExtendHivePrimaryFileValidDataLength(a1, v15, v42);
          v41 = v18;
          if ( v18 < 0 )
          {
            v20 = v45;
            goto LABEL_51;
          }
          v14 = v18;
          v20 = v45 | 0x21;
        }
        else
        {
          v20 = v45;
        }
        v21 = (v10 >> 3) & 1;
        if ( v21 )
        {
          v18 = HvWriteLogFile(a1, 1);
          v41 = v18;
          if ( v18 < 0 )
            goto LABEL_51;
          v18 = HvTruncateCurrentLogFileIfRequired(a1);
          v14 = v41;
          v20 |= 2u;
        }
        if ( (v10 & 0x10) != 0 )
        {
          v18 = HvValidateOrInvalidatePrimaryFileHeader(a1, 0, 1, v42);
          v41 = v18;
          if ( v18 < 0 )
          {
            v10 |= 0x400u;
            goto LABEL_51;
          }
          v20 |= 0x20u;
          v14 = v18;
        }
        if ( v21 && (v10 & 0x40) != 0 && (v10 & 0x400) == 0 )
        {
          RtlMergeBitMaps((unsigned int *)(a1 + 1904), (unsigned int *)(a1 + 1876));
          v18 = HvFreeDirtyData((_DWORD *)a1);
          v20 |= 4u;
        }
        if ( (v10 & 0x20) != 0 )
        {
          v18 = (int)HvSwapLogFiles((_DWORD *)a1, (v46 & 4) != 0);
          v20 |= 8u;
        }
        if ( (v10 & 1) != 0 && (v10 & 0x40) != 0 && (v10 & 4) == 0 )
        {
          if ( (v2 & 1) != 0 )
            CmpLockRegistry(v18, v19);
          else
            CmpLockRegistryFreezeAware(0);
          v22 = CmpLockHiveFlusherExclusive(a1);
          v23 = CmpReleaseWriteQueue(v22, a1 + 3288);
          if ( (v20 & 2) != 0 )
            v24 = v14;
          else
            v24 = -1073741823;
          CmpWakeWriteQueueWaiters(v23, v24);
          v20 |= 0x10u;
          *(_DWORD *)(a1 + 3312) &= 0xFFFFFFFE;
          v25 = CmpUnlockHiveFlusher(a1);
          v18 = CmpUnlockRegistry(v25);
        }
        if ( (v10 & 0x40) != 0 )
        {
          v18 = HvWriteHivePrimaryFile(a1, 1, v42);
          v41 = v18;
          if ( v18 < 0 )
            goto LABEL_51;
          v20 |= 0x20u;
        }
        if ( (v10 & 0x100) == 0 )
        {
LABEL_50:
          if ( (v10 & 0x200) != 0 && (v20 & 0x20) == 0 )
          {
            v18 = CmpFileFlushAndPurge(a1, 0);
            if ( v18 )
              v20 |= 0x20u;
          }
LABEL_51:
          CmpLockRegistry(v18, v19);
          v13 = (_DWORD *)CmpLockHiveFlusherExclusive(a1);
          v26 = v41;
          if ( v41 < 0 && (v10 & 0x80) != 0 && (v20 & 1) == 0 )
            *(_DWORD *)(a1 + 3316) = v16;
          if ( (v20 & 0x20) != 0 )
          {
            *(_DWORD *)(a1 + 3316) = 0;
            *(_DWORD *)(a1 + 3312) |= 4u;
          }
          if ( v41 < 0 )
          {
            if ( (v20 & 2) != 0 && (v10 & 0x400) != 0 )
            {
              v20 &= 0xFDu;
              *(_DWORD *)(a1 + 108) = *(_DWORD *)(a1 + 108);
              --*(_DWORD *)(a1 + 100);
            }
          }
          else
          {
            if ( (v10 & 0x800) != 0 )
            {
              do
              {
                v36 = MEMORY[0xFFFF93B0];
                while ( 1 )
                {
                  v13 = (_DWORD *)MEMORY[0xFFFF900C];
                  __dmb(0xBu);
                  v37 = MEMORY[0xFFFF9008];
                  __dmb(0xBu);
                  if ( v13 == (_DWORD *)MEMORY[0xFFFF9010] )
                    break;
                  __dmb(0xAu);
                  __yield();
                }
              }
              while ( v36 != MEMORY[0xFFFF93B0] );
              *(_QWORD *)(a1 + 3248) = __PAIR64__((unsigned int)v13, v37) - v36;
              if ( (v10 & 0x1000) == 0 )
                v13 = (_DWORD *)CmpArmLazyWriter(1, 0, 0);
              v26 = v41;
            }
            if ( (v10 & 0x1000) != 0 )
              v13 = (_DWORD *)CmpArmLazyWriter(1, 0, 1);
          }
          v12 = (v10 >> 6) & 1;
          if ( !v12 )
            goto LABEL_59;
          v33 = *(_DWORD **)(a1 + 1916);
          if ( v26 < 0 )
          {
            HvSynchronizeAndDropTemporaryBins(a1, 1, v33, *(_DWORD *)(a1 + 1920), 1);
            v13 = (_DWORD *)HvFoldBackUnreconciledData(a1);
            goto LABEL_59;
          }
          HvSynchronizeAndDropTemporaryBins(a1, 1, v33, *(_DWORD *)(a1 + 1920), 0);
          v13 = (_DWORD *)HvFreeUnreconciledData(a1);
          if ( (v10 & 1) != 0 && (v20 & 0x10) == 0 )
          {
            HvResetLogFileStatusAll(a1);
            *(_DWORD *)(a1 + 108) = 0;
            v13 = (_DWORD *)HvIsCurrentLogSwappable(a1);
            if ( v13 )
              v13 = HvSwapLogFiles((_DWORD *)a1, 0);
            goto LABEL_59;
          }
          v34 = *(_DWORD *)(a1 + 96);
          if ( v34 == 4 )
          {
            v35 = 5;
          }
          else
          {
            if ( v34 != 5 )
            {
LABEL_59:
              if ( (v10 & 0x110) != 0 )
                v13 = (_DWORD *)HvFreeUnreconciledData(a1);
              if ( (v10 & 8) != 0 && (v20 & 4) == 0 )
              {
                if ( (v20 & 2) != 0 )
                {
                  if ( !v12 )
                    HvUpdateUnreconciledVector((unsigned int *)a1, 1);
                  v13 = (_DWORD *)HvFreeDirtyData((_DWORD *)a1);
                }
                else
                {
                  v13 = (_DWORD *)HvFoldBackDirtyData(a1);
                }
              }
              goto LABEL_67;
            }
            v35 = 4;
          }
          v13 = (_DWORD *)HvpLogTypeToLogArrayIndex(v35);
          *((_BYTE *)v13 + a1 + 120) = 0;
          goto LABEL_59;
        }
        v18 = HvValidateOrInvalidatePrimaryFileHeader(a1, 1, 1, v42);
        v41 = v18;
        if ( v18 < 0 )
          goto LABEL_51;
        v20 |= 0x20u;
        if ( *(_DWORD *)(a1 + 96) == 1 )
        {
          v18 = HvpShouldTruncateLogFile(a1, 1);
          if ( !v18 )
            goto LABEL_50;
          v40 = 1;
        }
        else
        {
          if ( HvpShouldTruncateLogFile(a1, 4) )
            CmpDoFileSetSizeEx(a1, 4, 0, 0, 0);
          v18 = HvpShouldTruncateLogFile(a1, 5);
          if ( !v18 )
            goto LABEL_50;
          v40 = 5;
        }
        v18 = CmpDoFileSetSizeEx(a1, v40, 0, 0, 0);
        goto LABEL_50;
      }
      v10 &= 0xFFFFFF7F;
    }
    v16 = v48;
    v15 = v49;
    goto LABEL_29;
  }
  CmpLockHiveWriter(a1);
  if ( HvMarkDirty(a1, 0, 4096) )
  {
    CmpUnlockHiveWriter(a1);
    goto LABEL_24;
  }
  v13 = (_DWORD *)CmpUnlockHiveWriter(a1);
  v41 = -1073741823;
LABEL_141:
  v20 = v45;
LABEL_67:
  if ( (v10 & 1) == 0 || (v20 & 0x10) != 0 )
  {
    v27 = 0;
  }
  else
  {
    *(_DWORD *)(a1 + 3312) &= 0xFFFFFFFE;
    v13 = (_DWORD *)CmpReleaseWriteQueue(v13, a1 + 3288);
    v27 = v13;
  }
  if ( (v10 & 2) != 0 )
  {
    *(_DWORD *)(a1 + 3312) &= 0xFFFFFFFD;
    v28 = CmpReleaseWriteQueue(v13, a1 + 3300);
  }
  else
  {
    v28 = 0;
  }
  if ( (v20 & 2) != 0 )
    v29 = 0;
  else
    v29 = -1073741823;
  CmpWakeWriteQueueWaiters(v27, v29);
  if ( v12 )
  {
    v30 = v41;
    CmpWakeWriteQueueWaiters(v28, v41);
  }
  else
  {
    CmpWakeWriteQueueWaiters(v28, -1073741823);
    v30 = v41;
  }
  v31 = CmpUnlockHiveFlusher(a1);
  CmpUnlockRegistry(v31);
LABEL_77:
  v43 = v30;
  v44 = 285212703;
  v45 = 197124;
  v46 = 0;
  v47 = 0x40000000;
  if ( EtwEventEnabled(EtwpRegTraceHandle, dword_92026C, (int)&v44) )
  {
    v50 = (int)&v43;
    v51 = 0;
    v52 = 4;
    v53 = 0;
    EtwWrite(EtwpRegTraceHandle, dword_92026C, (int)&v44, 0);
  }
  return v30;
}
