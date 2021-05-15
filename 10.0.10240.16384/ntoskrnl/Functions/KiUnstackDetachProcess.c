// KiUnstackDetachProcess 
 
unsigned int __fastcall KiUnstackDetachProcess(unsigned int result, int a2)
{
  int v2; // r3

  v2 = *(_DWORD *)(result + 16);
  if ( v2 != 1 )
  {
    if ( !v2 )
      result = (__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 372;
    result = KiDetachProcess(result, a2);
  }
  return result;
}
