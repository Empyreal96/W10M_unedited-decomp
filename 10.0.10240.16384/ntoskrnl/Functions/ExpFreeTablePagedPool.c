// ExpFreeTablePagedPool 
 
unsigned int __fastcall ExpFreeTablePagedPool(int a1, unsigned int a2, unsigned int a3)
{
  unsigned int result; // r0

  result = ExFreePoolWithTag(a2);
  if ( a1 )
    result = PsReturnProcessPagedPoolQuota(a1, a3);
  return result;
}
