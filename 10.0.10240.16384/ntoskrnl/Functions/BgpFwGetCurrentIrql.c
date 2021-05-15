// BgpFwGetCurrentIrql 
 
int __fastcall BgpFwGetCurrentIrql(int a1)
{
  return KeGetCurrentIrql(a1);
}
