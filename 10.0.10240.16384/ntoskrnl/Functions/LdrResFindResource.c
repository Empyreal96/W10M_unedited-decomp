// LdrResFindResource 
 
int __fastcall LdrResFindResource(int a1, int a2, int a3, int a4, _DWORD *a5, int *a6, int a7, int a8, int a9)
{
  _DWORD v10[6]; // [sp+10h] [bp-18h] BYREF

  if ( (a9 & 0xC02) != 0 )
    return -1073741811;
  v10[0] = a2;
  v10[1] = a3;
  v10[2] = a4;
  return LdrResSearchResource(a1, (int)v10, 3u, a9, a5, a6, a7, a8);
}
