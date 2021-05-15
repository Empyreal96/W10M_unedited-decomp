// DbgkLkmdRegisterCallback 
 
int __fastcall DbgkLkmdRegisterCallback(int a1, int a2, int a3)
{
  unsigned int v6; // r4
  _DWORD *v7; // r6
  int *v9; // r7
  unsigned int v10; // r4
  _DWORD *v11; // r6

  if ( (a3 & 3) == 3 )
    return -1073741811;
  v6 = 0;
  v7 = &unk_641668;
  do
  {
    if ( ExReferenceCallBackBlock(v7) )
      return sub_7F1EFC();
    ++v6;
    v7 += 2;
  }
  while ( v6 < 8 );
  v9 = (int *)ExAllocateCallBack(a1, a2);
  if ( !v9 )
    return -1073741801;
  v10 = 0;
  v11 = &unk_641668;
  do
  {
    if ( ExCompareExchangeCallBack(v11, v9, 0) )
    {
      *((_DWORD *)&unk_641668 + 2 * v10 + 1) = a3;
      return 0;
    }
    ++v10;
    v11 += 2;
  }
  while ( v10 < 8 );
  ExFreePoolWithTag((unsigned int)v9);
  return -1073740757;
}
