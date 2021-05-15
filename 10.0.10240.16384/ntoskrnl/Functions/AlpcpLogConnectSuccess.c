// AlpcpLogConnectSuccess 
 
unsigned int __fastcall AlpcpLogConnectSuccess(int a1)
{
  int v1; // r3
  int v2; // r3
  int v4[8]; // [sp+0h] [bp-20h] BYREF

  v1 = __mrc(15, 0, 13, 0, 3);
  v4[0] = *(_DWORD *)((v1 & 0xFFFFFFC0) + 0x36C);
  v2 = *(_DWORD *)((v1 & 0xFFFFFFC0) + 0x370);
  v4[3] = a1;
  v4[1] = v2;
  v4[2] = 7;
  return AlpcpInvokeLogCallbacks((int)v4, 16);
}
