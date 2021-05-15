// MiProcessWsInSwapRanges 
 
int __fastcall MiProcessWsInSwapRanges(_DWORD *a1, int a2, int a3, int a4)
{
  int v6; // r5
  unsigned int v7; // r2
  int v8; // r0
  int result; // r0
  char v10; // r3
  unsigned int v11; // r1
  __int16 v12; // r3
  _DWORD *varg_r0; // [sp+18h] [bp+8h]
  int varg_r1; // [sp+1Ch] [bp+Ch]

  varg_r0 = a1;
  varg_r1 = a2;
  v6 = 4157;
  if ( (a3 & 2) != 0 )
  {
    v6 = 13117;
    v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v7 + 310);
  }
  v8 = -1;
  if ( *a1 >= (unsigned int)dword_63389C )
    v8 = 0;
  result = MmPrefetchVirtualMemory(v8, ((a2 - (int)a1) >> 3) + 1, a1, v6);
  v10 = a3;
  if ( (a3 & 2) != 0 )
  {
    v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v12 = *(_WORD *)(v11 + 0x136) + 1;
    *(_WORD *)(v11 + 310) = v12;
    if ( !v12 && *(_DWORD *)(v11 + 100) != v11 + 100 )
      result = KiCheckForKernelApcDelivery(result);
    v10 = a3;
  }
  if ( (v10 & 1) == 0 )
    result = MiReleaseOutSwapReservations(a1, a2);
  return result;
}
