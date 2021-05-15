// WdipSemFastAllocate 
 
int __fastcall WdipSemFastAllocate(int a1, int a2)
{
  int result; // r0

  result = RtlpInterlockedPopEntrySList((unsigned __int64 *)&byte_61CAD8[8 * a1]);
  if ( !result )
    result = WdipSemAllocatePool(a2);
  return result;
}
