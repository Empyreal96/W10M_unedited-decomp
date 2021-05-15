// EtwpInitializeRegistration 
 
int EtwpInitializeRegistration()
{
  _DWORD *v0; // r2
  int v1; // r1
  _DWORD *v2; // r3
  int v3; // r0
  int v5; // [sp+0h] [bp-68h] BYREF
  int v6[22]; // [sp+8h] [bp-60h] BYREF

  KiInitializeMutant((int)&EtwpNotificationMutex, 0, 1);
  v0 = &EtwpGuidHashTable;
  v1 = 64;
  do
  {
    v0[6] = 0;
    v2 = v0;
    v3 = 3;
    do
    {
      *v2 = v2;
      v2[1] = v2;
      v2 += 2;
      --v3;
    }
    while ( v3 );
    v0 += 7;
    --v1;
  }
  while ( v1 );
  EtwpReplyListHead = (int)&EtwpReplyListHead;
  *(_DWORD *)algn_61B5E4 = &EtwpReplyListHead;
  memset(v6, 0, sizeof(v6));
  LOWORD(v6[0]) = 88;
  v6[2] = 256;
  v6[3] = 131085;
  v6[4] = 131170;
  v6[5] = 134800;
  v6[6] = 134911;
  v6[7] = 2052;
  BYTE2(v6[0]) |= 0x18u;
  v6[9] = 512;
  v6[11] = 60;
  v6[13] = (int)EtwpOpenRealTimeConnectionObject;
  v6[14] = (int)EtwpCloseRegistrationObject;
  v6[15] = (int)EtwpDeleteRegistrationObject;
  RtlInitUnicodeString((unsigned int)&v5, L"EtwRegistration");
  return ObCreateObjectType();
}
