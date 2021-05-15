// FsRtlNotifyVolumeEventEx 
 
int __fastcall FsRtlNotifyVolumeEventEx(int a1, int a2, _DWORD *a3, int a4)
{
  int v6; // r8
  GUID *v7; // r5
  int v8; // r1
  int v9; // r2
  int v10; // r3
  int v11; // r4
  GUID *v13; // r5
  int v14; // r1
  int v15; // r2
  int v16; // r3
  int v17[6]; // [sp+0h] [bp-18h] BYREF

  v17[0] = a4;
  v6 = IoGetRelatedTargetDevice(a1, v17);
  if ( v6 >= 0 )
  {
    switch ( a2 )
    {
      case 1:
        a3[1] = -781560344;
        a3[2] = 298979417;
        a3[3] = -1610547825;
        a3[4] = 846045385;
        return sub_7CFD50();
      case 2:
        v13 = &GUID_IO_VOLUME_DISMOUNT_FAILED;
        goto LABEL_10;
      case 3:
        v13 = &GUID_IO_VOLUME_LOCK;
        goto LABEL_10;
      case 4:
        v13 = &GUID_IO_VOLUME_LOCK_FAILED;
LABEL_10:
        v14 = *(_DWORD *)&v13->Data2;
        v15 = *(_DWORD *)v13->Data4;
        v16 = *(_DWORD *)&v13->Data4[4];
        a3[1] = v13->Data1;
        a3[2] = v14;
        a3[3] = v15;
        a3[4] = v16;
        return sub_7CFD50();
      case 5:
        a3[1] = -1702085272;
        a3[2] = 298963147;
        a3[3] = -1610551409;
        a3[4] = 846045385;
        return sub_7CFD50();
      case 6:
        v7 = &GUID_IO_VOLUME_MOUNT;
        goto LABEL_4;
      case 7:
        v7 = &GUID_IO_VOLUME_NEED_CHKDSK;
        goto LABEL_4;
      case 8:
        v7 = &GUID_IO_VOLUME_WORM_NEAR_FULL;
        goto LABEL_4;
      case 9:
        v7 = &GUID_IO_VOLUME_WEARING_OUT;
        goto LABEL_4;
      case 10:
        v7 = &GUID_IO_VOLUME_FORCE_CLOSED;
        goto LABEL_4;
      case 11:
        v7 = &GUID_IO_VOLUME_INFO_MAKE_COMPAT;
        goto LABEL_4;
      case 12:
        v7 = &GUID_IO_VOLUME_PREPARING_EJECT;
        goto LABEL_4;
      case 13:
        v7 = &GUID_IO_VOLUME_CHANGE_SIZE;
LABEL_4:
        v8 = *(_DWORD *)&v7->Data2;
        v9 = *(_DWORD *)v7->Data4;
        v10 = *(_DWORD *)&v7->Data4[4];
        a3[1] = v7->Data1;
        a3[2] = v8;
        a3[3] = v9;
        a3[4] = v10;
        break;
      case 14:
        a3[1] = -1561985914;
        a3[2] = 1077466573;
        a3[3] = 1162142642;
        a3[4] = 1998806022;
        break;
      default:
        ObfDereferenceObject(v17[0]);
        return -1073741811;
    }
    v11 = v17[0];
    IoReportTargetDeviceChangeAsynchronous(v17[0], (int)a3, 0, 0);
    ObfDereferenceObject(v11);
  }
  return v6;
}
