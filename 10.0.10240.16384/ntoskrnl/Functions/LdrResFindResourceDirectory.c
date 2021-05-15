// LdrResFindResourceDirectory 
 
int __fastcall LdrResFindResourceDirectory(int a1, int a2, int a3, _DWORD *a4, int a5, int a6, int a7)
{
  unsigned int v8; // r2
  int v10[6]; // [sp+10h] [bp-18h] BYREF

  v8 = 0;
  if ( (a7 & 0xC00) != 0 )
    return -1073741811;
  if ( a2 )
  {
    v10[0] = a2;
    v8 = 1;
  }
  if ( a3 )
  {
    v10[1] = a3;
    v8 = 2;
  }
  return LdrResSearchResource(a1, (int)v10, v8, a7 | 2, a4, 0, a5, a6);
}
