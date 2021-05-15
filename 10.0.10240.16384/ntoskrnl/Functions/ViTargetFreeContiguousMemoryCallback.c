// ViTargetFreeContiguousMemoryCallback 
 
BOOL __fastcall ViTargetFreeContiguousMemoryCallback(int a1, int a2)
{
  return ViTargetFreeContiguousMemoryFromNode(a2, a1) == 0;
}
