// PopUmpoProcessMessages 
 
int PopUmpoProcessMessages()
{
  int result; // r0
  char *v1; // r0
  char *v2; // [sp+0h] [bp-2A8h]
  int *v3; // [sp+4h] [bp-2A4h]
  _DWORD *v4; // [sp+8h] [bp-2A0h]
  _DWORD *v5; // [sp+Ch] [bp-29Ch]
  int v6[2]; // [sp+10h] [bp-298h] BYREF
  _DWORD v7[2]; // [sp+18h] [bp-290h] BYREF
  _DWORD v8[26]; // [sp+20h] [bp-288h] BYREF
  char v9[544]; // [sp+88h] [bp-220h] BYREF

  v7[0] = 0;
  v7[1] = 0;
  memset(v8, 0, 100);
  while ( 1 )
  {
    AlpcInitializeMessageAttribute(0x20000000, v8, 100, v6, v2, v3, v4, v5);
    v6[0] = 512;
    v5 = v7;
    v4 = v8;
    v3 = v6;
    v2 = v9;
    result = ZwAlpcSendWaitReceivePort();
    if ( result )
      break;
    v1 = AlpcGetMessageAttribute(v8, 0x20000000);
    PopUmpoProcessMessage(v9, v1);
  }
  if ( result != 258 )
    result = sub_50A2F0();
  return result;
}
