// PopUmpoSendPowerMessage 
 
int __fastcall PopUmpoSendPowerMessage(int a1, unsigned int a2)
{
  int v4; // r0
  int v5; // r1
  int v6; // r2
  int *v7; // r3
  int v9; // r4
  __int16 v10[264]; // [sp+10h] [bp-210h] BYREF

  v4 = PopAcquireUmpoPushLock(0);
  v7 = &PopAlpcClientPort;
  if ( PopAlpcClientPort )
  {
    if ( a2 > 0x1E8 )
      return sub_52954C(v4);
    memset(v10, 0, 512);
    v10[1] = a2 + 24;
    v10[0] = a2;
    memmove((int)&v10[12], a1, a2);
    v4 = ZwAlpcSendWaitReceivePort();
    v9 = v4;
  }
  else
  {
    v9 = -1073741758;
  }
  PopReleaseUmpoPushLock(v4, v5, v6, v7);
  return v9;
}
