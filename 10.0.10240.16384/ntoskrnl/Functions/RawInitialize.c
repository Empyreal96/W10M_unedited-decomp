// RawInitialize 
 
int __fastcall RawInitialize(_DWORD *a1)
{
  int v2; // r4
  char v4[32]; // [sp+10h] [bp-20h] BYREF

  RtlInitUnicodeString((unsigned int)v4, L"\\Device\\RawDisk");
  v2 = IoCreateDevice((int)a1, 0, v4, 8u, 0, 0, &RawDeviceDiskObject);
  if ( v2 >= 0 )
  {
    a1[13] = RawUnload;
    RtlInitUnicodeString((unsigned int)v4, L"\\Device\\RawCdRom");
    if ( IoCreateDevice((int)a1, 0, v4, 3u, 0, 0, &RawDeviceCdRomObject) < 0 )
      JUMPOUT(0x96916A);
    RtlInitUnicodeString((unsigned int)v4, L"\\Device\\RawTape");
    if ( IoCreateDevice((int)a1, 0, v4, 0x20u, 0, 0, &RawDeviceTapeObject) < 0 )
      JUMPOUT(0x969162);
    if ( IoRegisterShutdownNotification(RawDeviceTapeObject) < 0 )
      return sub_96915C();
    *(_DWORD *)(RawDeviceDiskObject + 28) |= 0x10u;
    *(_DWORD *)(RawDeviceCdRomObject + 28) |= 0x10u;
    *(_DWORD *)(RawDeviceTapeObject + 28) |= 0x10u;
    a1[23] = RawDispatch;
    a1[41] = RawDispatch;
    a1[28] = RawDispatch;
    a1[27] = RawDispatch;
    a1[24] = RawDispatch;
    a1[20] = RawDispatch;
    a1[19] = RawDispatch;
    a1[18] = RawDispatch;
    a1[17] = RawDispatch;
    a1[16] = RawDispatch;
    a1[32] = RawDispatch;
    a1[14] = RawDispatch;
    a1[30] = RawShutdown;
    IoRegisterFileSystem((_DWORD *)RawDeviceDiskObject);
    IoRegisterFileSystem((_DWORD *)RawDeviceCdRomObject);
    IoRegisterFileSystem((_DWORD *)RawDeviceTapeObject);
    ObfReferenceObjectWithTag(RawDeviceDiskObject);
    ObfReferenceObjectWithTag(RawDeviceCdRomObject);
    ObfReferenceObjectWithTag(RawDeviceTapeObject);
    RawMountedQueue = (int)&RawMountedQueue;
    *(_DWORD *)algn_61D984 = &RawMountedQueue;
    RawDismountedQueue = (int)&RawDismountedQueue;
    dword_61D98C = (int)&RawDismountedQueue;
    RawGlobalLock = 1;
    dword_61D964 = 0;
    unk_61D968 = 0;
    byte_61D96C = 1;
    byte_61D96D = 0;
    byte_61D96E = 4;
    dword_61D970 = 0;
    dword_61D978 = (int)&dword_61D974;
    dword_61D974 = (int)&dword_61D974;
    v2 = 0;
  }
  return v2;
}
