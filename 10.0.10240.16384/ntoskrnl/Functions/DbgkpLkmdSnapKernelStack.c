// DbgkpLkmdSnapKernelStack 
 
int __fastcall DbgkpLkmdSnapKernelStack(int a1, int a2, int a3, int a4, int *a5, int a6)
{
  int *v6; // r4
  int v11; // r5
  int v12; // r5
  int v13; // r3
  void (__fastcall *v14)(int, int *, int, int, int, _DWORD); // r4
  _DWORD v16[2]; // [sp+8h] [bp-1E0h] BYREF
  char v17; // [sp+10h] [bp-1D8h]
  int v18; // [sp+14h] [bp-1D4h]
  int v19[4]; // [sp+18h] [bp-1D0h] BYREF
  int v20[112]; // [sp+28h] [bp-1C0h] BYREF

  v6 = a5;
  if ( a5 )
    v11 = a5[14];
  else
    v11 = *(_DWORD *)(a3 + 64);
  if ( !a5 && a4 )
  {
    memset(v20, 0, 416);
    v20[14] = v11;
    v20[12] = v11;
  }
  v16[0] = a1;
  v16[1] = v11;
  v17 = a4;
  v18 = a6;
  KeEnumerateKernelStackSegments(
    a2,
    (int (__fastcall *)(int, int *, int))DbgkpLkmdSnapKernelStackSegmentCallback,
    (int)v16);
  if ( a4 )
  {
    if ( !a5 )
      v6 = v20;
    v19[0] = 0;
    v12 = v11 - 16;
    v19[3] = v6[16];
    v13 = v6[12];
    v14 = *(void (__fastcall **)(int, int *, int, int, int, _DWORD))(a1 + 168);
    v19[2] = v13;
    v14(a1 + 128, v19, 16, 5, v12, 0);
    *(_DWORD *)(a3 + 64) = v12;
    __dmb(0xBu);
    *(_BYTE *)(a3 + 132) = -1;
  }
  return 0;
}
