// KeSetProfileIrql 
 
char __fastcall KeSetProfileIrql(char result)
{
  KiProfileIrql = result;
  return result;
}
