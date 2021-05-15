// KeInitializeAffinityEx 
 
int __fastcall KeInitializeAffinityEx(int result)
{
  *(_WORD *)result = 1;
  *(_WORD *)(result + 2) = 1;
  *(_DWORD *)(result + 4) = 0;
  *(_DWORD *)(result + 8) = 0;
  return result;
}
