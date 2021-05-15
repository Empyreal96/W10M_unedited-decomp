// WmipDriverEntry 
 
int __fastcall WmipDriverEntry(_DWORD *a1)
{
  int v2; // r0
  int v3; // r4
  int v4; // r3
  int v5; // r0
  char v7[8]; // [sp+10h] [bp-28h] BYREF
  unsigned __int16 v8[4]; // [sp+18h] [bp-20h] BYREF
  char v9[24]; // [sp+20h] [bp-18h] BYREF

  KiInitializeMutant((int)&WmipSMMutex, 0, 1);
  v2 = WmipInitializeRegistration(0);
  dword_61B678 = (int)WmipEventNotification;
  dword_61B67C = 0;
  WmipEventWorkQueueItem = 0;
  WmipNPNotificationSpinlock = 0;
  v3 = WmipInitializeDataStructs(v2);
  if ( v3 >= 0 )
  {
    RtlInitAnsiString((unsigned int)v8, (unsigned int)"\\Registry\\Machine\\System\\CurrentControlSet\\Services\\WMI");
    v5 = RtlAnsiStringToUnicodeString(WmipRegistryPath, v8, 1, v4);
    v3 = WmipInitializeSecurity(v5);
    if ( v3 >= 0 )
    {
      RtlInitUnicodeString((unsigned int)v7, L"\\Device\\WMIDataDevice");
      v3 = IoCreateDevice((int)a1, 0, v7, 0x22u, 256, 0, &WmipServiceDeviceObject);
      if ( v3 >= 0 )
      {
        RtlInitUnicodeString((unsigned int)v9, L"\\DosDevices\\WMIDataDevice");
        v3 = IoCreateSymbolicLink();
        if ( v3 < 0 )
          return sub_969174();
        *(_BYTE *)(WmipServiceDeviceObject + 48) = 2;
        a1[14] = WmipOpenCloseCleanup;
        a1[16] = WmipOpenCloseCleanup;
        a1[28] = WmipIoControl;
        a1[32] = WmipOpenCloseCleanup;
        a1[37] = WmipSystemControl;
        *(_DWORD *)(WmipServiceDeviceObject + 28) &= 0xFFFFFF7F;
        IoWMIRegistrationControl(WmipServiceDeviceObject, 1);
        IoRegisterShutdownNotification(WmipServiceDeviceObject);
      }
    }
  }
  return v3;
}
