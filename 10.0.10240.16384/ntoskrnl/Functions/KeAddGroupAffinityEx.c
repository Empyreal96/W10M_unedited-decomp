// KeAddGroupAffinityEx 
 
int __fastcall KeAddGroupAffinityEx(int result, int a2, int a3)
{
  *(_DWORD *)(result + 8) |= a3;
  return result;
}
