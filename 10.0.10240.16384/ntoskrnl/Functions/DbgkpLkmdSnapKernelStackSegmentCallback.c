// DbgkpLkmdSnapKernelStackSegmentCallback 
 
int __fastcall DbgkpLkmdSnapKernelStackSegmentCallback(int a1, unsigned int *a2, int a3)
{
  unsigned int v4; // r2
  unsigned int v5; // r6
  int v6; // r0
  int result; // r0

  v4 = *(_DWORD *)(a3 + 4);
  v5 = a2[1];
  v6 = 0;
  if ( v4 >= v5 && v4 < *a2 && !*(_BYTE *)(a3 + 8) )
    v6 = 5;
  result = (*(int (__fastcall **)(int, unsigned int, unsigned int, int))(*(_DWORD *)a3 + 168))(
             *(_DWORD *)a3 + 128,
             v5,
             *a2 - v5,
             v6);
  if ( result >= 0 )
    *(_DWORD *)(*(_DWORD *)(a3 + 12) + 4) |= 2u;
  return result;
}
