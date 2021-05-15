// KiNonNumaQueryNodeCapacity 
 
int __fastcall KiNonNumaQueryNodeCapacity(int a1, _DWORD *a2)
{
  int result; // r0

  if ( a1 )
    return -1073741275;
  result = 0;
  *a2 = KiMaximumGroupSize;
  return result;
}
