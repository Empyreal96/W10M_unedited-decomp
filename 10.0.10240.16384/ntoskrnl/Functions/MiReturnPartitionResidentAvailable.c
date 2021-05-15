// MiReturnPartitionResidentAvailable 
 
int __fastcall MiReturnPartitionResidentAvailable(int a1, int a2)
{
  unsigned int *v2; // r2
  unsigned int v3; // r4
  int result; // r0

  v2 = (unsigned int *)(a1 + 3840);
  do
  {
    v3 = __ldrex(v2);
    result = v3 + a2;
  }
  while ( __strex(v3 + a2, v2) );
  return result;
}
