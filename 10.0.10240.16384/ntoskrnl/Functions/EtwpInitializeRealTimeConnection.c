// EtwpInitializeRealTimeConnection 
 
int EtwpInitializeRealTimeConnection()
{
  int v1; // [sp+0h] [bp-68h] BYREF
  int v2[22]; // [sp+8h] [bp-60h] BYREF

  memset(v2, 0, sizeof(v2));
  LOWORD(v2[0]) = 88;
  v2[2] = 256;
  v2[3] = 131085;
  v2[4] = 131170;
  v2[5] = 134800;
  v2[6] = 134911;
  v2[7] = 1024;
  BYTE2(v2[0]) |= 0x18u;
  v2[9] = 512;
  v2[11] = 84;
  v2[13] = (int)EtwpOpenRealTimeConnectionObject;
  v2[14] = (int)EtwpCloseRealTimeConnectionObject;
  v2[15] = (int)EtwpDeleteRealTimeConnectionObject;
  RtlInitUnicodeString((unsigned int)&v1, L"EtwConsumer");
  return ObCreateObjectType();
}
