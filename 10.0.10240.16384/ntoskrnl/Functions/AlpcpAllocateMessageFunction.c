// AlpcpAllocateMessageFunction 
 
int __fastcall AlpcpAllocateMessageFunction(int a1, int a2, int a3)
{
  int v3; // r0
  int v4; // r4
  int v5; // r0

  v3 = ExAllocatePoolWithTag(a1, a2, a3);
  v4 = v3;
  if ( v3 )
  {
    memset((_BYTE *)(v3 + 24), 0, 144);
    v5 = ExCreateHandleEx(AlpcMessageTable);
    if ( !v5 )
      return sub_7E7FD8();
    *(_DWORD *)(v4 + 160) = v5 | 0x80000000;
  }
  return v4;
}
