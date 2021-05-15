// KeInitializeSemaphore 
 
int __fastcall KeInitializeSemaphore(int result, int a2, int a3)
{
  *(_BYTE *)result = 5;
  *(_BYTE *)(result + 2) = 5;
  *(_DWORD *)(result + 4) = a2;
  *(_DWORD *)(result + 8) = result + 8;
  *(_DWORD *)(result + 12) = result + 8;
  *(_DWORD *)(result + 16) = a3;
  return result;
}
