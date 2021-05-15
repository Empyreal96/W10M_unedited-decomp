// IoCreateObjectTypes 
 
int IoCreateObjectTypes()
{
  unsigned int v0; // r0
  int result; // r0
  int v2; // r2
  unsigned __int16 v3[4]; // [sp+8h] [bp-80h] BYREF
  int v4[30]; // [sp+10h] [bp-78h] BYREF

  memset(v4, 0, 88);
  LOWORD(v4[0]) = 88;
  v4[2] = 256;
  v4[3] = 1179785;
  v4[4] = 1179926;
  v4[5] = 1179808;
  v4[6] = 2032127;
  v4[9] = 512;
  BYTE2(v4[0]) |= 4u;
  v4[7] = 2032127;
  RtlInitUnicodeString((unsigned int)v3, L"Adapter");
  if ( ObCreateObjectType() < 0 )
    goto LABEL_12;
  RtlInitUnicodeString((unsigned int)v3, L"Controller");
  v4[11] = 40;
  if ( ObCreateObjectType() < 0 )
    goto LABEL_12;
  RtlInitUnicodeString((unsigned int)v3, L"Device");
  v4[11] = 184;
  v4[16] = (int)IopParseDevice;
  BYTE2(v4[0]) |= 1u;
  v4[15] = (int)IopDeleteDevice;
  v4[17] = (int)IopGetSetSecurityObject;
  v4[18] = 0;
  if ( ObCreateObjectType() < 0 )
    goto LABEL_12;
  v0 = RtlInitUnicodeString((unsigned int)v3, L"Driver");
  v4[11] = 168;
  v4[16] = 0;
  v4[15] = (int)IopDeleteDriver;
  v4[17] = 0;
  v4[18] = 0;
  if ( ViVerifierDriverAddedThunkListHead )
    return sub_96617C(v0);
  if ( ObCreateObjectType() < 0 )
    goto LABEL_12;
  RtlInitUnicodeString((unsigned int)v3, L"IoCompletion");
  v4[11] = 48;
  v4[2] = 272;
  v4[3] = 131073;
  v4[4] = 131074;
  v4[5] = 1179648;
  v4[6] = 2031619;
  v4[7] = 2031619;
  v4[14] = (int)IopCloseIoCompletion;
  v4[15] = (int)IopDeleteIoCompletion;
  BYTE2(v4[0]) |= 0x80u;
  if ( ObCreateObjectType() < 0 )
    goto LABEL_12;
  BYTE2(v4[0]) &= 0x7Fu;
  RtlInitUnicodeString((unsigned int)v3, L"WaitCompletionPacket");
  v4[11] = 56;
  v4[2] = 272;
  v4[3] = 131073;
  v4[4] = 131073;
  v4[5] = 131073;
  v4[6] = 983041;
  v4[7] = 983041;
  v4[14] = (int)IopCloseWaitCompletionPacket;
  v4[15] = 0;
  if ( ObCreateObjectType() < 0 )
    goto LABEL_12;
  RtlInitUnicodeString((unsigned int)v3, L"File");
  v4[10] = 1024;
  v4[11] = 192;
  v4[2] = 304;
  v4[1] = 1;
  v4[3] = 1179785;
  v4[4] = 1179926;
  v4[5] = 1179808;
  v4[6] = 2032127;
  v2 = BYTE2(v4[0]) | 0x10;
  v4[7] = 2032127;
  v4[14] = (int)IopCloseFile;
  v4[15] = (int)IopDeleteFile;
  v4[16] = (int)IopParseFile;
  v4[17] = (int)IopGetSetSecurityObject;
  v4[18] = (int)IopQueryName;
  BYTE2(v4[0]) = v2 & 0xFB;
  v4[20] = 0x10000000;
  v4[21] = 1048620;
  if ( ObCreateObjectTypeEx(v3, (int)v4, v2, 95, (int *)&IoFileObjectType) < 0 )
LABEL_12:
    result = 0;
  else
    result = 1;
  return result;
}
