// AlpcpLogConnectFail 
 
unsigned int __fastcall AlpcpLogConnectFail(int a1, int a2)
{
  int v2; // r3
  int v3; // r3
  int v5[8]; // [sp+0h] [bp-20h] BYREF

  v2 = __mrc(15, 0, 13, 0, 3);
  v5[0] = *(_DWORD *)((v2 & 0xFFFFFFC0) + 0x36C);
  v3 = *(_DWORD *)((v2 & 0xFFFFFFC0) + 0x370);
  v5[3] = a1;
  v5[4] = a2;
  v5[1] = v3;
  v5[2] = 8;
  return AlpcpInvokeLogCallbacks((int)v5, 20);
}
