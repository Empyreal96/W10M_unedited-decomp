// HvpExpandMap 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall HvpExpandMap(int a1, int a2, unsigned int a3, unsigned int a4)
{
  unsigned int v7; // r3
  _BYTE *v10; // r0
  _BYTE *v11; // r4 OVERLAPPED
  int v12; // r2
  int v13; // r3

  if ( a3 )
  {
    v7 = (a3 >> 12) - 1;
  }
  else
  {
    v10 = (_BYTE *)(*(int (__fastcall **)(int, _DWORD, int))(a1 + 12))(10240, 0, 925977923);
    v11 = v10;
    if ( !v10 )
      return -1073741801;
    memset(v10, 0, 10240);
    v12 = a1 + 412 * a2;
    v13 = v12 + 960;
    *(_QWORD *)(v12 + 956) = *(_QWORD *)(&v11 - 1);
    v7 = 0;
  }
  if ( ((a4 >> 12) - 1) >> 9 > v7 >> 9 )
    return sub_80A2BC();
  return 0;
}
