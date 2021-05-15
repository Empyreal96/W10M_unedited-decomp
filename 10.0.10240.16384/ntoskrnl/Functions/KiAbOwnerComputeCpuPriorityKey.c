// KiAbOwnerComputeCpuPriorityKey 
 
int __fastcall KiAbOwnerComputeCpuPriorityKey(int a1)
{
  int v2; // r3
  int result; // r0
  int v4; // r3

  v2 = *(unsigned __int16 *)(a1 + 44) >> 1;
  if ( v2 )
    result = (char)(32 - __clz(v2));
  else
    result = 0;
  v4 = *(char *)(a1 - 8 * *(unsigned __int8 *)(a1 + 12) + 347);
  if ( v4 > result )
  {
    result = *(char *)(a1 - 8 * *(unsigned __int8 *)(a1 + 12) + 347);
    if ( v4 > 15 )
      result = 15;
  }
  return result;
}
