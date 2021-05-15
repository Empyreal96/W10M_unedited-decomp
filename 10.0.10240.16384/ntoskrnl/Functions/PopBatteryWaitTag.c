// PopBatteryWaitTag 
 
int __fastcall PopBatteryWaitTag(int *a1)
{
  __int64 v1; // r3
  int v2; // r2

  HIDWORD(v1) = a1;
  a1[14] = 0;
  a1[30] = -1;
  PopPrepareIoctl(a1[7], 2703424, 0, (int)(a1 + 30), 4, 4);
  v2 = *(_DWORD *)(*(_DWORD *)(HIDWORD(v1) + 28) + 96);
  LODWORD(v1) = PopBatteryIrpComplete;
  *(_QWORD *)(v2 - 8) = v1;
  *(_BYTE *)(v2 - 37) = -32;
  return IofCallDriver(*(_DWORD *)(HIDWORD(v1) + 24), *(_DWORD *)(HIDWORD(v1) + 28));
}
