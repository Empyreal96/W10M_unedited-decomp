// KdpReadRemoteFile 
 
int __fastcall KdpReadRemoteFile(int a1, __int64 a2, int a3, int a4, _DWORD *a5)
{
  int v7; // r4
  int v8; // r5
  int v9; // r7
  int v11; // r1
  int *v12; // r2
  int v13; // r3
  int v14; // r4
  int v15; // [sp+8h] [bp-80h]
  int v16; // [sp+18h] [bp-70h]
  int v17; // [sp+2Ch] [bp-5Ch]

  v7 = a1 - 1;
  v8 = 0;
  v9 = a2;
  if ( (unsigned int)(a1 - 1) >= 0x10 )
    return -1073741811;
  v11 = KdEnterDebugger(0, 0, a2);
  v15 = v11;
  v12 = (int *)KdpRemoteFiles[v7];
  if ( KdpRemoteFiles[v7] )
  {
    v14 = a4;
    v13 = 0;
    v17 = 0;
    if ( a4 )
    {
      while ( 1 )
      {
        v17 = 0;
        KdSendPacket_0();
        v12 = (int *)&KdDebuggerNotPresent;
        if ( KdDebuggerNotPresent )
          break;
        if ( !KdReceivePacket_0() )
        {
          v13 = v16;
          v8 += v16;
          v9 += v16;
          v14 -= v16;
          a3 += v16;
        }
        v12 = &KdpContext;
        if ( !v14 )
          goto LABEL_12;
      }
      v13 = -1073740972;
      v17 = -1073740972;
LABEL_12:
      v11 = v15;
    }
    *a5 = v8;
  }
  else
  {
    v13 = -1073741811;
    v17 = -1073741811;
  }
  KdExitDebugger(v11, v11, (int)v12, v13);
  return v17;
}
