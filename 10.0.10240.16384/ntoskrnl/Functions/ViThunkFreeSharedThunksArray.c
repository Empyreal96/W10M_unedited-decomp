// ViThunkFreeSharedThunksArray 
 
unsigned int __fastcall ViThunkFreeSharedThunksArray(unsigned int *a1)
{
  unsigned int result; // r0

  result = *a1;
  if ( result )
  {
    result = ExFreePoolWithTag(result);
    *a1 = 0;
  }
  return result;
}
