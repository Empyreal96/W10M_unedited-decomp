// sub_7CA7E4 
 
void __fastcall sub_7CA7E4(int a1, int a2, int a3, int a4)
{
  int v4; // r4

  PipAddDependentsToRebuildPowerRelationsQueue(v4, a2, a3, a4);
  PipDeleteAllDependencyRelations(v4);
  JUMPOUT(0x76AA8E);
}
