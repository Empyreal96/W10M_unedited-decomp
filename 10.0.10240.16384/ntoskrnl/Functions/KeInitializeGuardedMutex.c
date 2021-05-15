// KeInitializeGuardedMutex 
 
int __fastcall KeInitializeGuardedMutex(int result)
{
  *(_DWORD *)result = 1;
  *(_DWORD *)(result + 4) = 0;
  *(_DWORD *)(result + 8) = 0;
  *(_BYTE *)(result + 12) = 1;
  *(_BYTE *)(result + 14) = 4;
  *(_BYTE *)(result + 13) = 0;
  *(_DWORD *)(result + 16) = 0;
  *(_DWORD *)(result + 20) = result + 20;
  *(_DWORD *)(result + 24) = result + 20;
  return result;
}
