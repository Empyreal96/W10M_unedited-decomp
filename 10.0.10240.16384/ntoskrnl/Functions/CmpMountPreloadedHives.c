// CmpMountPreloadedHives 
 
unsigned int CmpMountPreloadedHives()
{
  int v0; // r8
  int i; // r7
  int v3; // r2
  int v4; // r3
  __int16 v5; // r3
  int v6; // r2
  int v7; // r3
  int v8; // r2
  int v9; // r3
  int v10; // r3
  int v11; // r5
  int v12; // r2
  unsigned int v13; // r6
  int v14; // r3
  int v15; // r9
  unsigned int j; // r5
  int v17; // r1
  int v18; // r2
  int v19; // r0
  int v20; // r5
  int v21; // r2
  int v22; // r3
  int v23; // [sp+0h] [bp-190h]
  unsigned __int16 v24; // [sp+10h] [bp-180h] BYREF
  _BYTE v25[6]; // [sp+12h] [bp-17Eh]
  __int16 v26[4]; // [sp+18h] [bp-178h] BYREF
  unsigned int v27; // [sp+20h] [bp-170h] BYREF
  int v28; // [sp+24h] [bp-16Ch]
  int v29; // [sp+28h] [bp-168h] BYREF
  int v30; // [sp+2Ch] [bp-164h] BYREF
  _DWORD v31[2]; // [sp+30h] [bp-160h] BYREF
  int v32; // [sp+38h] [bp-158h] BYREF
  int v33; // [sp+3Ch] [bp-154h] BYREF
  int v34; // [sp+40h] [bp-150h] BYREF
  int v35; // [sp+44h] [bp-14Ch] BYREF
  char v36[8]; // [sp+48h] [bp-148h] BYREF
  int v37; // [sp+50h] [bp-140h] BYREF
  char v38[284]; // [sp+54h] [bp-13Ch] BYREF

  v24 = 0;
  *(_DWORD *)v25 = 0;
  *(_WORD *)&v25[4] = 0;
  v26[0] = 0;
  v26[1] = 0;
  v37 = 0;
  memset(v38, 0, sizeof(v38));
  v27 = 0;
  v28 = 0;
  v0 = ExAllocatePoolWithTag(1, 4096, 1649626435);
  if ( !v0 )
    sub_80B570();
  for ( i = CmpPreloadedHivesList; (int *)i != &CmpPreloadedHivesList; i = *(_DWORD *)i )
  {
    if ( (*(_DWORD *)(i - 1724) & 1) == 0 )
    {
      v24 = 0;
      *(_WORD *)v25 = 4096;
      *(_DWORD *)&v25[2] = v0;
      if ( !CmpQueryHiveRedirectionFileList(i + 168, &v24) || v24 == 2 )
      {
        v4 = *(_DWORD *)(i - 1724);
        if ( (v4 & 0x1000) != 0 )
        {
          v5 = *(_WORD *)dword_63282C;
          *(_WORD *)v25 = 4096;
          *(_DWORD *)&v25[2] = v0;
          v26[0] = v5;
          v24 = 0;
          RtlAppendUnicodeToString(&v24, (int)L"\\??\\", v3, 0);
          RtlAppendUnicodeToString(&v24, (int)v26, v6, v7);
          RtlAppendUnicodeToString(&v24, (int)L":", v8, v9);
        }
        else
        {
          *(_WORD *)v25 = 4096;
          *(_DWORD *)&v25[2] = v0;
          if ( (v4 & 0x2000) != 0 )
          {
            v24 = 0;
            v11 = SyspartGetSystemPartition(v0, 4096, v36);
            if ( v11 < 0 )
            {
              *(_DWORD *)(i - 1788) = &v37;
              v23 = 0;
              goto LABEL_45;
            }
          }
          else
          {
            v10 = 0;
            v24 = 0;
          }
        }
        RtlAppendUnicodeToString(&v24, *(_DWORD *)(i + 156), v3, v10);
      }
      ExFreePoolWithTag(*(_DWORD *)(i + 156));
      *(_WORD *)(i + 152) = 0;
      *(_WORD *)(i + 154) = 0;
      *(_DWORD *)(i + 156) = 0;
      v11 = CmpOpenHiveFile((int)&v24, 0, &v32, &v33, 7, (int)&v27, 0, 0);
      if ( v11 < 0 )
      {
        *(_DWORD *)(i - 1788) = &v37;
        v22 = 16;
LABEL_44:
        v23 = v22;
LABEL_45:
        v37 = i - 1816;
        SetFailureLocation(*(_DWORD *)(i - 1788), 0, 21, v11, v23);
        CmpPuntBoot = 1;
        v31[1] = &v24;
        ExRaiseHardError(-1073741288, 1);
        KeBugCheckEx(116, 2, 1, i - 1816, v11);
      }
      v11 = CmpOpenHiveFile((int)&v24, 4u, &v30, &v34, 18, 0, 0, 0);
      if ( v11 < 0 )
      {
        *(_DWORD *)(i - 1788) = &v37;
        v22 = 32;
        goto LABEL_44;
      }
      v11 = CmpOpenHiveFile((int)&v24, 5u, &v29, &v35, 18, 0, 0, 0);
      if ( v11 < 0 )
      {
        *(_DWORD *)(i - 1788) = &v37;
        v22 = 48;
        goto LABEL_44;
      }
      v13 = v27;
      *(_DWORD *)(i - 40) = v32;
      *(_DWORD *)(i - 24) = v30;
      *(_DWORD *)(i - 20) = v29;
      *(_DWORD *)(i - 1724) &= 0xFFFFFFFD;
      *(_DWORD *)(i - 1700) = v28;
      v14 = *(_DWORD *)(i - 1748);
      v15 = *(_DWORD *)(i - 864);
      if ( v14 != v13 )
      {
        for ( j = 0; j < *(_DWORD *)(i - 1780); j += v13 )
        {
          if ( !RtlAreBitsClear((unsigned int *)(i - 1780), j, v13) )
            RtlSetBits((_BYTE *)(i - 1780), j, v13);
        }
        *(_DWORD *)(i - 1772) = RtlNumberOfSetBits((unsigned int *)(i - 1780));
        *(_DWORD *)(i - 1748) = v13;
      }
      v11 = CmpInitializeActualPrimaryFileSize((_DWORD *)(i - 1816), v31, v12, v14);
      if ( v11 < 0 )
      {
        *(_DWORD *)(i - 1788) = &v37;
        v22 = 64;
        goto LABEL_44;
      }
      if ( CmpDoFileSetSizeEx(i - 1816, 0, v15 + 4096, 0, 1) < 0 )
      {
        CmpCannotWriteConfiguration = 1;
        *(_DWORD *)(i - 1724) &= 0xFFFDFFFF;
      }
      if ( *(_DWORD *)(*(_DWORD *)(i - 1784) + 4092) )
      {
        RtlSetAllBits((_DWORD *)(i - 1780));
        *(_DWORD *)(i - 1772) = *(_DWORD *)(i - 1780);
      }
      v19 = HvpDropPagedBins(i - 1816, v17, v18);
      v11 = v19;
      if ( v19 < 0 )
      {
        *(_DWORD *)(i - 1788) = &v37;
        v22 = 96;
        goto LABEL_44;
      }
      if ( *(_DWORD *)(*(_DWORD *)(i - 1784) + 4092) )
      {
        v19 = HvSyncHive(i - 1816);
        *(_DWORD *)(*(_DWORD *)(i - 1784) + 4092) = 0;
      }
      if ( CmpCannotWriteConfiguration )
        CmpDiskFullWarning(v19);
      v20 = (*(_DWORD *)(i - 1724) & 0x800) != 0;
      *(_DWORD *)(i - 1724) &= 0xFFFFF7FF;
      CmpUnlockRegistry();
      CmpInitCmRM((_DWORD *)(i - 1816), v20);
      v21 = *(_DWORD *)(i + 1440);
      *(_DWORD *)(i + 1412) |= 8u;
      if ( v21 )
      {
        TmEnableCallbacks();
        CmRmFinalizeRecovery(*(_DWORD *)(i + 1440));
      }
      CmpLockRegistryExclusive();
    }
    *(_DWORD *)(i + 1412) |= 4u;
  }
  return ExFreePoolWithTag(v0);
}
