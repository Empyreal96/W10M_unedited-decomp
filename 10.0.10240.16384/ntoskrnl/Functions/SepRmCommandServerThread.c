// SepRmCommandServerThread 
 
int SepRmCommandServerThread()
{
  int v1; // r0
  int v2; // r4
  int v3; // r4
  int v4; // [sp+4h] [bp-258h]
  __int16 v5[2]; // [sp+3Ch] [bp-220h] BYREF
  int v6; // [sp+40h] [bp-21Ch]
  int v7; // [sp+44h] [bp-218h]
  int v8; // [sp+48h] [bp-214h]
  int v9; // [sp+4Ch] [bp-210h]
  int v10; // [sp+54h] [bp-208h]
  __int16 v11[2]; // [sp+13Ch] [bp-120h] BYREF
  int v12; // [sp+140h] [bp-11Ch]
  int v13; // [sp+144h] [bp-118h]
  int v14; // [sp+148h] [bp-114h]
  int v15; // [sp+14Ch] [bp-110h]

  SepRmLsaCallProcess = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  ObfReferenceObject(SepRmLsaCallProcess);
  if ( PoRequestShutdownEvent(0) >= 0 )
  {
    v6 = 0;
    v5[0] = 232;
    v5[1] = 256;
    v11[1] = 256;
    v11[0] = 232;
    v12 = 0;
    while ( 1 )
    {
      v1 = ZwReplyWaitReceivePort();
      v2 = v4;
      if ( v4 == -8 )
      {
        v2 = 0;
        v4 = 0;
      }
      if ( v1 < 0 )
        JUMPOUT(0x816736);
      LOWORD(v6) = v6 & 0x7FFF;
      switch ( (unsigned __int16)v6 )
      {
        case 1u:
          if ( (unsigned int)(v10 - 1) <= 8 )
          {
            v3 = PsAttachSiloToCurrentThread(v2);
            ((void (__fastcall *)(__int16 *, __int16 *))SepRmCommandDispatch[v10])(v5, v11);
            PsDetachSiloFromCurrentThread(v3);
            v13 = v7;
            v14 = v8;
            v15 = v9;
          }
          break;
        case 5u:
          JUMPOUT(0x816752);
        case 0xAu:
          SepRmLsaConnectRequest(v5);
          break;
      }
    }
  }
  return sub_816724();
}
