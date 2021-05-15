// ViRaiseIrqlToDpcLevel 
 
unsigned int __fastcall ViRaiseIrqlToDpcLevel(int a1)
{
  unsigned int v1; // r4

  v1 = KeGetCurrentIrql(a1);
  if ( v1 < 2 )
    KfRaiseIrql(2);
  return v1;
}
