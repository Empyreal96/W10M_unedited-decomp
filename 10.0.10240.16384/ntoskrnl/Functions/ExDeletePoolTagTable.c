// ExDeletePoolTagTable 
 
int __fastcall ExDeletePoolTagTable(int a1)
{
  int v2; // r5
  int v3; // r7
  int v4; // r0

  v2 = ExPoolTagTables[a1];
  v3 = 7 * (PoolTrackTableSize + 1);
  v4 = KfRaiseIrql(2);
  ExPoolTagTables[a1] = 0;
  KfLowerIrql(v4);
  return MmFreeIndependentPages(v2, 4 * v3);
}
