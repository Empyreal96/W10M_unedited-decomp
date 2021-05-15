// EtwpUpdateStringFilterData 
 
unsigned int __fastcall EtwpUpdateStringFilterData(unsigned int *a1, unsigned int *a2, int a3)
{
  unsigned int result; // r0

  result = *a1;
  if ( a3 )
  {
    *a1 = 0;
  }
  else
  {
    *a1 = *a2;
    *a2 = 0;
  }
  if ( result )
    result = ExFreePoolWithTag(result);
  return result;
}
