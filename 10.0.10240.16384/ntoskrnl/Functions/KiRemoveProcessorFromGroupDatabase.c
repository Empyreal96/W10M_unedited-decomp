// KiRemoveProcessorFromGroupDatabase 
 
int __fastcall KiRemoveProcessorFromGroupDatabase(int a1)
{
  int v2; // r4
  bool v3; // zf
  int result; // r0
  int v5; // r2

  v2 = *(unsigned __int16 *)(*(_DWORD *)(a1 + 2360) + 264);
  v3 = (KiGroupBlock[2 * v2] & ~*(_DWORD *)(a1 + 1048)) == 0;
  KiGroupBlock[2 * v2] &= ~*(_DWORD *)(a1 + 1048);
  if ( v3 )
    KiUncommitNodeAssignment();
  result = 0;
  v5 = *(unsigned __int8 *)(a1 + 1052);
  KiProcessorIndexToNumberMappingTable[*(_DWORD *)(a1 + 20)] = 0;
  KiProcessorNumberToIndexMappingTable[64 * v5 + *(unsigned __int8 *)(a1 + 1053)] = 0;
  return result;
}
