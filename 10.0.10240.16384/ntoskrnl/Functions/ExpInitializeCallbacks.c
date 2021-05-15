// ExpInitializeCallbacks 
 
int ExpInitializeCallbacks()
{
  int v0; // r5
  int v1; // r2
  void **v2; // r6
  _DWORD *v3; // r0
  char v5[8]; // [sp+8h] [bp-98h] BYREF
  int v6; // [sp+10h] [bp-90h] BYREF
  int v7; // [sp+14h] [bp-8Ch]
  char *v8; // [sp+18h] [bp-88h]
  int v9; // [sp+1Ch] [bp-84h]
  int v10; // [sp+20h] [bp-80h]
  int v11; // [sp+24h] [bp-7Ch]
  int v12[22]; // [sp+28h] [bp-78h] BYREF

  ExpCallbackListLock = 0;
  ExpCallbackListHead = (int)&ExpCallbackListHead;
  dword_61A16C = (int)&ExpCallbackListHead;
  RtlInitUnicodeString((unsigned int)v5, L"Callback");
  memset(v12, 0, sizeof(v12));
  LOWORD(v12[0]) = 88;
  v12[2] = 256;
  v12[3] = 0x20000;
  v12[4] = 131073;
  v12[5] = 1179648;
  v12[6] = 2031617;
  v12[15] = (int)ExpDeleteCallback;
  v12[9] = 512;
  v12[7] = 2031617;
  BYTE2(v12[0]) |= 4u;
  if ( ObCreateObjectType() < 0 )
    return 0;
  RtlInitUnicodeString((unsigned int)v5, L"\\Callback");
  v6 = 24;
  v7 = 0;
  v9 = 80;
  v8 = v5;
  v10 = SePublicDefaultSd;
  v11 = 0;
  if ( NtCreateDirectoryObject() < 0 )
    return 0;
  NtClose();
  ExpCallbackEvent = 0;
  byte_61A151 = 0;
  byte_61A152 = 4;
  dword_61A154 = 0;
  dword_61A15C = (int)&dword_61A158;
  dword_61A158 = (int)&dword_61A158;
  v0 = 0;
  if ( &ExCbEnlightenmentState )
  {
    v1 = 0;
    v2 = &ExpInitializeCallback;
    while ( 1 )
    {
      RtlInitUnicodeString((unsigned int)v5, *(unsigned __int16 **)((char *)&ExpInitializeCallback + v1 + 4));
      v3 = *v2;
      v10 = 0;
      v11 = 0;
      v6 = 24;
      v7 = 0;
      v8 = v5;
      v9 = 80;
      if ( ExCreateCallback(v3, &v6, 1, 1) < 0 )
        break;
      ++v0;
      v1 = 8 * v0;
      v2 = &ExpInitializeCallback + 2 * v0;
      if ( !*v2 )
        return 1;
    }
    return 0;
  }
  return 1;
}
