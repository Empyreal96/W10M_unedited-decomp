// KeQueryRuntimeThread 
 
int __fastcall KeQueryRuntimeThread(int a1, _DWORD *a2)
{
  *a2 = *(_DWORD *)(a1 + 448);
  return *(_DWORD *)(a1 + 404);
}
