// KdpCreateRemoteFile 
 
int __fastcall KdpCreateRemoteFile(_DWORD *a1, _DWORD *a2, __int64 a3)
{
  unsigned __int16 *v3; // r9
  int v6; // r10
  unsigned int v7; // r4
  int v8; // r1
  __int64 v9; // r2
  unsigned int v10; // r3
  unsigned int v11; // r0
  int v12; // r0
  _DWORD *v13; // r2
  int v14; // [sp+10h] [bp-80h] BYREF
  __int16 v15; // [sp+18h] [bp-78h]
  __int16 v16; // [sp+1Ah] [bp-76h]
  void *v17; // [sp+1Ch] [bp-74h]
  __int16 v18; // [sp+20h] [bp-70h]
  __int16 v19; // [sp+22h] [bp-6Eh]
  int *v20; // [sp+24h] [bp-6Ch]
  _DWORD *v21; // [sp+28h] [bp-68h]
  int v22; // [sp+30h] [bp-60h] BYREF
  int v23; // [sp+34h] [bp-5Ch]
  int v24; // [sp+38h] [bp-58h]
  int v25; // [sp+3Ch] [bp-54h]
  int v26; // [sp+40h] [bp-50h]
  int v27; // [sp+44h] [bp-4Ch]
  int v28; // [sp+48h] [bp-48h]
  int v29; // [sp+50h] [bp-40h]
  int v30; // [sp+54h] [bp-3Ch]
  unsigned __int64 v31; // [sp+58h] [bp-38h]

  v3 = (unsigned __int16 *)a3;
  v21 = a1;
  if ( *(unsigned __int16 *)a3 > (unsigned int)(KdTransportMaxPacketSize - 64) )
    return sub_9039C4();
  HIDWORD(a3) = (unsigned __int8)KdDebuggerNotPresent;
  if ( KdDebuggerNotPresent )
    return -1073740972;
  v6 = KdEnterDebugger(0, 0, a3);
  v7 = 0;
  v8 = (int)&KdpRemoteFiles;
  do
  {
    v9 = *(_QWORD *)v8;
    if ( !*(_QWORD *)v8 )
      break;
    ++v7;
    v8 += 8;
  }
  while ( v7 < 0x10 );
  if ( v7 >= 0x10 )
  {
    HIDWORD(v9) = -1073741801;
    v23 = -1073741801;
  }
  else
  {
    while ( 1 )
    {
      v22 = 13360;
      v24 = 1179785;
      v25 = 128;
      v26 = 1;
      v27 = 1;
      v28 = 0;
      v18 = 64;
      v19 = 64;
      v10 = *v3;
      v20 = &v22;
      v11 = *((_DWORD *)v3 + 1);
      v23 = 0;
      KdpCopyMemoryChunks(v11, 0, (int)&KdpMessageBuffer, v10, 0, 4, &v14);
      v15 = v14 + 2;
      v17 = &KdpMessageBuffer;
      *(_WORD *)((char *)&KdpMessageBuffer + (unsigned __int16)(v14 + 2) - 2) = 0;
      KdSendPacket_0();
      if ( KdDebuggerNotPresent )
        break;
      v17 = &KdpMessageBuffer;
      v16 = 4096;
      v12 = KdReceivePacket_0();
      LODWORD(v9) = &KdpMessageBuffer;
      v8 = 1179785;
      if ( !v12 )
      {
        HIDWORD(v9) = v23;
        goto LABEL_10;
      }
    }
    HIDWORD(v9) = -1073740972;
    v23 = -1073740972;
LABEL_10:
    if ( v9 >= 0 )
    {
      v13 = (_DWORD *)((char *)&KdpRemoteFiles + 8 * v7);
      *v13 = v29;
      v13[1] = v30;
      LODWORD(v9) = v21;
      HIDWORD(v9) = v7 + 1;
      *v21 = v7 + 1;
      if ( a2 )
      {
        v9 = __PAIR64__(v31, HIDWORD(v31));
        if ( v31 >= 0x10000000 )
        {
          HIDWORD(v9) = 0;
          *a2 = 4096;
          a2[1] = 0;
        }
        else
        {
          *a2 = v31;
          a2[1] = v9;
        }
      }
    }
  }
  KdExitDebugger(v6, v8, v9, SHIDWORD(v9));
  return v23;
}
