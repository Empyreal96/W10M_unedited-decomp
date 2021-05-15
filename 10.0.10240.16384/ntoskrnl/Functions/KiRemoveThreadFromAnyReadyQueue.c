// KiRemoveThreadFromAnyReadyQueue 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall KiRemoveThreadFromAnyReadyQueue(int a1, int a2, int a3, char a4)
{
  int v7; // r3
  int result; // r0
  _DWORD *v9; // r1 OVERLAPPED
  _DWORD *v10; // r2 OVERLAPPED
  bool v11; // zf
  int v12; // r3

  if ( (*(_DWORD *)(a3 + 76) & 0x2000) != 0 )
    return KiRemoveThreadFromScbQueue(a1, *(_DWORD *)(a3 + 824), a3, a4);
  v7 = *(_DWORD *)(a3 + 328);
  result = a3 + 144;
  *(_QWORD *)&v9 = *(_QWORD *)(a3 + 144);
  v11 = v7 >= 0;
  v12 = v9[1];
  if ( v11 )
  {
    if ( v12 != result || *v10 != result )
      __fastfail(3u);
    *v10 = v9;
    v9[1] = v10;
    if ( v10 == v9 )
      *(_DWORD *)(a1 + 1932) ^= 1 << a4;
  }
  else
  {
    if ( v12 != result || *v10 != result )
      sub_50A9A8();
    *v10 = v9;
    v9[1] = v10;
    if ( v10 == v9 )
      *(_DWORD *)(a2 + 4) ^= 1 << a4;
  }
  return result;
}
