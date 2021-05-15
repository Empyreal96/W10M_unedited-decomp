// HvpMapEntryGetFreeBin 
 
int __fastcall HvpMapEntryGetFreeBin(int a1)
{
  int *v1; // r2
  int result; // r0

  if ( HvpMapEntryIsDiscardable(a1) )
    result = *v1;
  else
    result = 0;
  return result;
}
