// DbgkpSendApiMessageLpc 
 
int __fastcall DbgkpSendApiMessageLpc(int a1, int a2, int a3)
{
  int v5; // r4
  _BYTE v6[376]; // [sp-4h] [bp-178h] BYREF

  __mrc(15, 0, 13, 0, 3);
  if ( a3 )
    return sub_7D6D04();
  *(_DWORD *)(a1 + 28) = 259;
  v5 = LpcRequestWaitReplyPortEx(a2, a1, v6);
  ZwFlushInstructionCache();
  if ( v5 == 192 )
    return -1073741749;
  if ( v5 >= 0 )
    memmove(a1, (int)v6, 0xA8u);
  return v5;
}
