// KeRemoveGroupAffinityEx 
 
int __fastcall KeRemoveGroupAffinityEx(int result, int a2, int a3)
{
  *(_DWORD *)(result + 8) &= ~a3;
  return result;
}
