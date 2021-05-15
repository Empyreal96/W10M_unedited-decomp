// ViScatterGatherCallback 
 
int __fastcall ViScatterGatherCallback(int a1, int a2, unsigned int *a3, int a4)
{
  int v4; // r4

  v4 = *(_DWORD *)(a4 + 32);
  ADD_MAP_REGISTERS(v4, *a3, 1);
  *(_DWORD *)(a4 + 36) = a3;
  ExInterlockedInsertHeadList((int *)(v4 + 32), (int *)(a4 + 40), (unsigned int *)(v4 + 40));
  VF_MARK_SCATTER_GATHER_LIST((int)a3, *(_DWORD *)(a4 + 52));
  return (*(int (__fastcall **)(int, int, unsigned int *, _DWORD))(a4 + 4))(a1, a2, a3, *(_DWORD *)a4);
}
