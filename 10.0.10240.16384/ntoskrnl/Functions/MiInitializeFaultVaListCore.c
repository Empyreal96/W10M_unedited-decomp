// MiInitializeFaultVaListCore 
 
int __fastcall MiInitializeFaultVaListCore(int result, __int64 a2, char a3)
{
  *(_BYTE *)result = a3;
  *(_BYTE *)(result + 1) = 0;
  *(_DWORD *)(result + 12) = 0;
  *(_DWORD *)(result + 16) = 0;
  *(_QWORD *)(result + 4) = a2;
  return result;
}
