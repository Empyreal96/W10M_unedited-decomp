// ExInsertPoolTag 
 
BOOL __fastcall ExInsertPoolTag(int a1, int a2, int a3, int a4)
{
  return ExpAllocateBigPool(a2, a4) != 0;
}
