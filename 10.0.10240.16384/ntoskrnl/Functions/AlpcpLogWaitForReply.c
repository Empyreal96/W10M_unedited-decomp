// AlpcpLogWaitForReply 
 
unsigned int __fastcall AlpcpLogWaitForReply(int a1)
{
  int v1; // r3
  int v3[8]; // [sp+0h] [bp-20h] BYREF

  v1 = __mrc(15, 0, 13, 0, 3);
  v3[0] = *(_DWORD *)((v1 & 0xFFFFFFC0) + 0x36C);
  v3[1] = *(_DWORD *)((v1 & 0xFFFFFFC0) + 0x370);
  v3[2] = 3;
  v3[3] = *(_DWORD *)(a1 + 136);
  return AlpcpInvokeLogCallbacks((int)v3, 16);
}
