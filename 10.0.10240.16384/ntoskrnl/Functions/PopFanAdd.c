// PopFanAdd 
 
int __fastcall PopFanAdd(int a1)
{
  __int64 v1; // r3
  int v2; // r0

  HIDWORD(v1) = a1;
  *(_DWORD *)(*(_DWORD *)(a1 + 28) + 24) = -1073741667;
  v2 = KeInitializeEvent(a1 + 68, 0, 0);
  LODWORD(v1) = PopFanWorker;
  *(_QWORD *)(HIDWORD(v1) + 52) = v1;
  *(_DWORD *)(HIDWORD(v1) + 44) = 0;
  *(_QWORD *)(HIDWORD(v1) + 60) = 0i64;
  *(_DWORD *)(HIDWORD(v1) + 60) = 0;
  PopSqmFanEnumeration(v2);
  return ExQueueWorkItem((_DWORD *)(HIDWORD(v1) + 44), 1);
}
