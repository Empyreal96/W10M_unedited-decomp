// MiOutSwapKernelStackPage 
 
int __fastcall MiOutSwapKernelStackPage(_DWORD *a1, int a2)
{
  int v3; // r4
  int result; // r0
  int v6; // r3
  int v7[22]; // [sp+0h] [bp-58h] BYREF

  v3 = a1[7];
  if ( !v3 )
    return -1073741653;
  if ( *(_DWORD *)(v3 + 4) <= *(_DWORD *)(v3 + 8) || !a1[9] )
    return -1073741303;
  memset(v7, 0, 72);
  v7[2] = (int)dword_634F00;
  LOBYTE(v7[3]) = 17;
  v6 = a1[8];
  v7[0] = v3;
  v7[4] = v6;
  v7[5] = a1[9];
  ((void (__fastcall *)(int *, int, int, _DWORD))MiOutSwapWorkingSetCallback)(v7, a2, a2, 0);
  result = 0;
  a1[8] = v7[4];
  a1[9] = v7[5];
  return result;
}
