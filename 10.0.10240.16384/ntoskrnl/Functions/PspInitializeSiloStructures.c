// PspInitializeSiloStructures 
 
int PspInitializeSiloStructures()
{
  int v0; // r0
  int v1; // r2
  void *v2; // r0
  int result; // r0
  int v4; // [sp+0h] [bp-68h] BYREF
  int v5[22]; // [sp+8h] [bp-60h] BYREF

  PspSiloList = (int)&PspSiloList;
  dword_61DA6C = (int)&PspSiloList;
  PspSiloListLock = 1;
  dword_61DA44 = 0;
  unk_61DA48 = 0;
  byte_61DA4C = 1;
  byte_61DA4D = 0;
  byte_61DA4E = 4;
  dword_61DA50 = 0;
  dword_61DA58 = (int)&dword_61DA54;
  dword_61DA54 = (int)&dword_61DA54;
  memset(v5, 0, sizeof(v5));
  LOWORD(v5[0]) = 88;
  BYTE2(v5[0]) |= 8u;
  v5[9] = 0;
  RtlInitUnicodeString((unsigned int)&v4, L"Silo");
  v5[10] = 0;
  v5[11] = 152;
  v5[15] = (int)PspSiloDelete;
  v5[14] = (int)AlpcMessageDeleteProcedure;
  v5[7] = 2031647;
  v5[3] = 131076;
  v5[4] = 131083;
  v5[5] = 1179648;
  v5[6] = 0x1FFFFF;
  v5[2] = 0;
  if ( ObCreateObjectType() < 0 )
    return 0;
  v0 = ExCreateHandleTable(0, 0);
  PspSiloIdTable = v0;
  if ( !v0 )
    return 0;
  *(_BYTE *)(v0 + 28) |= 1u;
  unk_641770 = 1;
  unk_641774 = 1;
  v1 = ExAllocatePoolWithTag(1, 4, 1114401107);
  if ( !v1 )
    return 0;
  MonitorContextIndexBitmapBuffer = v1;
  MonitorContextIndexBitmap = 32;
  dword_61DA8C = v1;
  RtlClearAllBits((int)&MonitorContextIndexBitmap);
  v2 = PsGetServerSiloGlobals(0);
  if ( PspAllocateMonitorContextArrayServerSilo((int)v2) < 0 )
    return 0;
  result = 1;
  SiloMonitorLock = 0;
  SiloMonitorList = (int)&SiloMonitorList;
  dword_61DA74 = (int)&SiloMonitorList;
  SiloMonitorNonpagedContextSpinLock = 0;
  return result;
}
