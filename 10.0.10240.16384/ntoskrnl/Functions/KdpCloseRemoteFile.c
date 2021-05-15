// KdpCloseRemoteFile 
 
int __fastcall KdpCloseRemoteFile(int a1, __int64 a2)
{
  int v3; // r4
  int v5; // r6
  int *v6; // r4
  int v7; // r1
  int v8; // r2
  int v9; // r3
  int v10; // [sp+24h] [bp-5Ch]

  v3 = a1 - 1;
  if ( (unsigned int)(a1 - 1) >= 0x10 )
    return -1073741811;
  v5 = KdEnterDebugger(0, 0, a2);
  v6 = (int *)((char *)&KdpRemoteFiles + 8 * v3);
  v7 = v6[1];
  v8 = *v6;
  if ( *(_QWORD *)v6 )
  {
    v10 = 0;
    KdSendPacket_0();
    if ( KdDebuggerNotPresent )
    {
LABEL_8:
      v9 = -1073740972;
      v10 = -1073740972;
    }
    else
    {
      while ( KdReceivePacket_0() )
      {
        v10 = 0;
        KdSendPacket_0();
        if ( KdDebuggerNotPresent )
          goto LABEL_8;
      }
      v9 = 0;
    }
    if ( v9 >= 0 )
    {
      v9 = 0;
      *v6 = 0;
      v6[1] = 0;
    }
  }
  else
  {
    v9 = -1073741811;
    v10 = -1073741811;
  }
  KdExitDebugger(v5, v7, v8, v9);
  return v10;
}
