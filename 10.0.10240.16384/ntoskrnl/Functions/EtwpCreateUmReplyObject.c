// EtwpCreateUmReplyObject 
 
int EtwpCreateUmReplyObject()
{
  _BYTE *v0; // r0
  unsigned int v1; // r6
  int v2; // r5
  int v4; // [sp+18h] [bp-38h] BYREF
  int v5[12]; // [sp+20h] [bp-30h] BYREF

  v5[0] = 24;
  v5[1] = 0;
  v5[3] = 64;
  v5[2] = 0;
  v5[4] = 0;
  v5[5] = 0;
  v0 = (_BYTE *)ExAllocatePoolWithTag(512, 44, 1903653957);
  v1 = (unsigned int)v0;
  if ( !v0 )
    return -1073741801;
  memset(v0, 0, 44);
  KeInitializeQueue(v1, 0);
  v2 = ObCreateObject(0, (_DWORD *)EtwpRegistrationObjectType, (int)v5, 1, 0, 60, 0, 0, &v4);
  if ( v2 >= 0 )
    return sub_7EB7BC();
  ExFreePoolWithTag(v1);
  return v2;
}
