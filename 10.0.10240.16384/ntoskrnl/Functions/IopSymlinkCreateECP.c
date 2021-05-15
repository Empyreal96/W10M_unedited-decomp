// IopSymlinkCreateECP 
 
int __fastcall IopSymlinkCreateECP(int a1, int a2, unsigned __int16 *a3, int a4, int *a5)
{
  unsigned int v6; // r2
  int v7; // r7
  int result; // r0
  int v9; // r4
  int v10[8]; // [sp+18h] [bp-20h] BYREF

  v6 = *a3;
  v7 = 0;
  v10[0] = 0;
  if ( v6 > 2 && *(_WORD *)(*((_DWORD *)a3 + 1) + 2 * (v6 >> 1) - 2) == 92 )
  {
    *a3 = v6 - 2;
    v7 = 1;
  }
  if ( *(_DWORD *)(a2 + 32) )
    return sub_7DD5D8();
  result = IopSymlinkAllocateAndAddECP(a1, v10, *a3);
  if ( result >= 0 )
  {
    v9 = v10[0];
    IopSymlinkInitializeSymlinkInfo(v10[0], *a3 + 20, *((_DWORD *)a3 + 1));
    *a5 = v9;
    result = 0;
  }
  if ( v7 )
    *a3 += 2;
  if ( result < 0 )
    *a5 = 0;
  return result;
}
