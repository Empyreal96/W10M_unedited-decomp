// SmKmIsVolumeIoPossible 
 
int __fastcall SmKmIsVolumeIoPossible(int a1, int *a2)
{
  int v4; // r5
  int v5; // r7
  int v6; // r8
  int v7; // r4
  int v8; // r0
  int v9; // r0
  int v11; // [sp+8h] [bp-28h]
  char v12; // [sp+14h] [bp-1Ch]

  v4 = 0;
  v5 = 0;
  v6 = IoSetThreadHardErrorMode(0);
  v7 = ZwQueryVolumeInformationFile();
  if ( v7 == 259 )
  {
    KeWaitForSingleObject(*(_DWORD *)(a1 + 4) + 92, 0, 0, 0, 0);
    v7 = v11;
  }
  if ( v7 >= 0 )
  {
    if ( (v12 & 1) != 0 )
      goto LABEL_8;
    v8 = IoGetRelatedDeviceObject(*(_DWORD **)(a1 + 4));
    v9 = IoAllocateIrp(*(_BYTE *)(v8 + 48), 0);
    v4 = v9;
    if ( !v9 )
    {
      v7 = -1073741670;
      goto LABEL_10;
    }
    v7 = SmKmSendUsageNotification(v9, *(_DWORD *)(a1 + 4), 0);
    if ( v7 < 0 )
    {
LABEL_8:
      v7 = 0;
    }
    else
    {
      v5 = 1;
      *(_DWORD *)(a1 + 20) = v4;
      v4 = 0;
    }
  }
LABEL_10:
  *a2 = v5;
  if ( v4 )
    IoFreeIrp(v4);
  IoSetThreadHardErrorMode(v6);
  return v7;
}
