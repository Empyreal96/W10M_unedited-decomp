// IoCsqInitialize 
 
int __fastcall IoCsqInitialize(int a1, int a2, __int64 a3, int a4, int a5, int a6)
{
  *(_QWORD *)(a1 + 8) = a3;
  *(_DWORD *)(a1 + 4) = a2;
  *(_DWORD *)(a1 + 16) = a4;
  *(_DWORD *)(a1 + 20) = a5;
  *(_DWORD *)(a1 + 24) = a6;
  *(_DWORD *)(a1 + 28) = 0;
  *(_DWORD *)a1 = 2;
  return 0;
}
