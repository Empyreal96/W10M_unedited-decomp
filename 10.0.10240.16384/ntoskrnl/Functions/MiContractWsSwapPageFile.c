// MiContractWsSwapPageFile 
 
int __fastcall MiContractWsSwapPageFile(int a1)
{
  int result; // r0

  result = MiNumberWsSwapPagefiles(a1);
  if ( result )
    result = sub_7EB384();
  return result;
}
