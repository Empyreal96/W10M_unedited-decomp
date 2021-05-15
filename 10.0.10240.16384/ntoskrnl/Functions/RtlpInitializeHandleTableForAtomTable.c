// RtlpInitializeHandleTableForAtomTable 
 
BOOL __fastcall RtlpInitializeHandleTableForAtomTable(int a1)
{
  int v2; // r0

  v2 = ExCreateHandleTable(0, 0);
  *(_DWORD *)(a1 + 12) = v2;
  return v2 != 0;
}
