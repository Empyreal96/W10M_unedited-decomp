// ViLowerIrql 
 
unsigned int __fastcall ViLowerIrql(unsigned int a1)
{
  unsigned int result; // r0

  result = KeGetCurrentIrql(a1);
  if ( a1 < result )
    result = KfLowerIrql(a1);
  return result;
}
