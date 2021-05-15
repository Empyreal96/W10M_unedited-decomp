// CmpFlushBackupHive 
 
int __fastcall CmpFlushBackupHive(int a1)
{
  int v1; // r10
  __int16 *v2; // r6
  int v3; // r4
  int v4; // r8
  int v5; // r2
  int v6; // r3
  int v7; // r7
  int v8; // r5
  int v9; // r2
  int v10; // r0
  _DWORD *v11; // r4
  int v13; // [sp+Ch] [bp-D4h]
  int v14; // [sp+10h] [bp-D0h] BYREF
  int v15; // [sp+14h] [bp-CCh]
  unsigned __int16 v16[2]; // [sp+18h] [bp-C8h] BYREF
  char *v17; // [sp+1Ch] [bp-C4h]
  _DWORD *v18; // [sp+20h] [bp-C0h] BYREF
  int v19; // [sp+24h] [bp-BCh] BYREF
  int v20; // [sp+28h] [bp-B8h] BYREF
  unsigned __int16 v21[4]; // [sp+30h] [bp-B0h] BYREF
  char v22; // [sp+40h] [bp-A0h] BYREF

  v18 = 0;
  LOBYTE(v15) = 1;
  v1 = 24 * a1;
  v2 = CmpMachineHiveList[24 * a1 + 7];
  v16[1] = 128;
  v16[0] = 0;
  v3 = 0;
  v17 = &v22;
  v14 = 0;
  v4 = 0;
  v19 = 0;
  v20 = 0;
  RtlInitUnicodeString((unsigned int)v21, L"\\SystemRoot\\System32\\Config\\RegBack\\");
  RtlAppendStringToString(v16, v21);
  RtlInitUnicodeString((unsigned int)v21, (unsigned __int16 *)CmpMachineHiveList[v1]);
  RtlAppendStringToString(v16, v21);
  RtlAppendUnicodeToString(v16, (int)L".OLD", v5, v6);
  v7 = *((_DWORD *)v2 + 447);
  if ( !v7 )
    return -1073741431;
  v8 = CmpCmdRenameHive(v7, 0, v16, 0, 1);
  if ( v8 >= 0 )
  {
    v16[0] -= 8;
    *((_DWORD *)v2 + 447) = 0;
    v8 = CmpInitBackupHive(v2, (unsigned __int16 *)CmpMachineHiveList[v1]);
    if ( v8 < 0 )
      goto LABEL_19;
    CmpLockRegistry();
    if ( CmpDoIdleProcessing )
    {
      ExAcquireResourceExclusiveLite(*((_DWORD *)v2 + 468), 1, v9, CmpDoIdleProcessing);
      v8 = CmpSnapshotHiveToOffsetArray(v2, &v14, &v19, &v20);
      ExReleaseResourceLite(*((_DWORD *)v2 + 468));
      v3 = v14;
      v4 = v19;
    }
    else
    {
      v8 = -1073741431;
    }
    CmpUnlockRegistry();
    if ( v8 < 0 )
      goto LABEL_19;
    v8 = CmpWriteOffsetArrayToFile(v10);
    CmpFreeOffsetArray(v3, v4);
    if ( v8 < 0
      || (LOWORD(v14) = 0,
          ZwSetInformationObject(),
          ZwClose(),
          LOBYTE(v14) = 0,
          *((_DWORD *)v2 + 447) = 0,
          v8 = CmpCmdHiveOpen((int)v16, 0, (int)&v14, (int *)&v18, 16777217, 0, 0, v13, v14, v15, v16[0]),
          v8 < 0) )
    {
LABEL_19:
      if ( *((_DWORD *)v2 + 447) )
      {
        LOWORD(v14) = 0;
        ZwSetInformationObject();
        ZwClose();
        *((_DWORD *)v2 + 447) = 0;
      }
      if ( CmpCmdRenameHive(v7, 0, v16, 0, 1) >= 0 )
        *((_DWORD *)v2 + 447) = v7;
    }
    else
    {
      v11 = v18;
      CmpDestroySecurityCache(v18);
      HvFreeHive((int)v11, 1);
      *((_DWORD *)v2 + 447) = v11[444];
      v11[444] = 0;
      CmpCmdHiveClose((int)v11);
      CmpDereferenceHive(v11);
      ZwSetInformationFile();
      LOWORD(v14) = 0;
      ZwSetInformationObject();
      ZwClose();
    }
  }
  return v8;
}
