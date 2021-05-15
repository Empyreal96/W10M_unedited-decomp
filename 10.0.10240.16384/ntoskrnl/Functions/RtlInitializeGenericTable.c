// RtlInitializeGenericTable 
 
int __fastcall RtlInitializeGenericTable(int result, int a2, __int64 a3, int a4)
{
  *(_DWORD *)result = 0;
  *(_DWORD *)(result + 4) = result + 4;
  *(_DWORD *)(result + 8) = result + 4;
  *(_QWORD *)(result + 28) = a3;
  *(_DWORD *)(result + 16) = 0;
  *(_DWORD *)(result + 20) = 0;
  *(_DWORD *)(result + 12) = result + 4;
  *(_DWORD *)(result + 36) = a4;
  *(_DWORD *)(result + 24) = a2;
  return result;
}
