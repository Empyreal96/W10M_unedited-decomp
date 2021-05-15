// EtwActivityIdControlKernel 
 
int __fastcall EtwActivityIdControlKernel(int a1, _DWORD *a2)
{
  int result; // r0

  result = 0;
  if ( a1 != 1 )
    return sub_50A1EC(0);
  *a2 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x40C);
  return result;
}
