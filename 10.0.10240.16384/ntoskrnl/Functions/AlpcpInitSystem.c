// AlpcpInitSystem 
 
int AlpcpInitSystem()
{
  unsigned int v0; // r2
  int v1; // r0
  int v3; // r2
  int v4; // r0
  int v5; // r4
  unsigned int v6; // r1
  __int16 v7; // r3
  unsigned __int16 v8[4]; // [sp+10h] [bp-A8h] BYREF
  int v9[22]; // [sp+18h] [bp-A0h] BYREF
  char v10[8]; // [sp+70h] [bp-48h] BYREF
  int v11; // [sp+78h] [bp-40h]
  int v12; // [sp+88h] [bp-30h]

  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v0 + 308);
  v1 = ExAllocatePoolWithTag(512, 16, 1850305601);
  AlpcpDummyEvent = v1;
  if ( !v1 )
    return sub_81AB7C();
  KeInitializeEvent(v1, 0, 1);
  AlpcpPortList = (int)&AlpcpPortList;
  dword_621294 = (int)&AlpcpPortList;
  AlpcpPortListLock = 0;
  RtlInitUnicodeString((unsigned int)v8, L"ALPC Port");
  memset(v9, 0, sizeof(v9));
  LOWORD(v9[0]) = 88;
  v9[3] = 131073;
  v9[4] = 65537;
  v9[5] = 0;
  v9[6] = 2031617;
  v3 = BYTE2(v9[0]) & 0xDF;
  v9[9] = 512;
  v9[10] = 0;
  v9[11] = 304;
  v9[2] = 128;
  v9[7] = 2031617;
  v9[13] = (int)AlpcpOpenPort;
  v9[14] = (int)AlpcpClosePort;
  v9[15] = (int)AlpcpDeletePort;
  BYTE2(v9[0]) = BYTE2(v9[0]) & 0xCB | 0x10;
  v4 = ObCreateObjectTypeEx(v8, (int)v9, v3, 149, &AlpcPortObjectType);
  v5 = v4;
  if ( v4 >= 0 )
  {
    AlpcMessageTable = ExCreateHandleTable(0, 0);
    ExInitializePagedLookasideList(
      (int)AlpcpLookasides,
      (int)AlpcpAllocateMessageFunction,
      (int)AlpcpFreeMessageFunction,
      0,
      424,
      1934453825,
      32);
    ExInitializePagedLookasideList(
      (int)&AlpcpLookasides[32],
      (int)AlpcpAllocateBuffer,
      (int)RtlpSysVolFree,
      0,
      64,
      1229155393,
      32);
    ExInitializePagedLookasideList((int)&unk_643600, 0, 0, 0, 64, 1632136257, 32);
    ExInitializeNPagedLookasideList((int)&AlpcpNPLookasides, 0, 0, 512);
    v4 = NtQuerySystemInformation(0, (int)v10, 44, 0);
    v5 = v4;
    if ( v4 >= 0 )
    {
      AlpcpRegionGranularity = v12;
      AlpcpViewGranularity = v11;
    }
    if ( AlpcpMessageLogEnabled )
    {
      v4 = AlpcpInitializeMessageLog(4096, 0x8000);
    }
    else
    {
      AlpcpMessageLogLock = 0;
      AlpcpMessageLogListHead = (int)&AlpcpMessageLogListHead;
      dword_6212BC = (int)&AlpcpMessageLogListHead;
      AlpcpFreeMessageLogListHead = (int)&AlpcpFreeMessageLogListHead;
      dword_6212D4 = (int)&AlpcpFreeMessageLogListHead;
      AlpcpFreeMessageSnapshotListHead = (int)&AlpcpFreeMessageSnapshotListHead;
      dword_6212CC = (int)&AlpcpFreeMessageSnapshotListHead;
    }
    AlpcpCompletionListDatabase = 0;
    dword_6212AC = (int)&dword_6212A8;
    dword_6212A8 = (int)&dword_6212A8;
  }
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v7 = *(_WORD *)(v6 + 0x134) + 1;
  *(_WORD *)(v6 + 308) = v7;
  if ( !v7 && *(_DWORD *)(v6 + 100) != v6 + 100 && !*(_WORD *)(v6 + 310) )
    KiCheckForKernelApcDelivery(v4);
  return v5;
}
