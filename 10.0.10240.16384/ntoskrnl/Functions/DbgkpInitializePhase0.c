// DbgkpInitializePhase0 
 
int DbgkpInitializePhase0()
{
  int v0; // r2
  _DWORD *v1; // r0
  int v2; // r1
  _WORD v4[5]; // [sp+0h] [bp-70h] BYREF
  _WORD v5[43]; // [sp+Ah] [bp-66h] BYREF

  memset(v5, 0, sizeof(v5));
  DbgkpProcessDebugPortMutex = 1;
  dword_631F64 = 0;
  unk_631F68 = 0;
  byte_631F6C = 1;
  byte_631F6D = 0;
  byte_631F6E = 4;
  dword_631F70 = 0;
  dword_631F78 = (int)&dword_631F74;
  dword_631F74 = (int)&dword_631F74;
  DbgkpErrorPortLock = 0;
  RtlInitUnicodeString((unsigned int)v4, L"DebugObject");
  v4[4] = 88;
  *(_DWORD *)&v5[5] = 131073;
  *(_DWORD *)&v5[7] = 131074;
  LOBYTE(v5[0]) |= 8u;
  *(_DWORD *)&v5[3] = 0;
  *(_DWORD *)&v5[17] = 512;
  *(_DWORD *)&v5[29] = AlpcMessageDeleteProcedure;
  *(_DWORD *)&v5[11] = 2031631;
  *(_DWORD *)&v5[13] = 2031631;
  *(_DWORD *)&v5[27] = DbgkpCloseObject;
  *(_DWORD *)&v5[19] = 0;
  *(_DWORD *)&v5[21] = 0;
  *(_DWORD *)&v5[9] = 1179648;
  v0 = ObCreateObjectType();
  if ( v0 >= 0 )
  {
    if ( !DbgkpMaxModuleMsgs )
      DbgkpMaxModuleMsgs = 500;
    v1 = &unk_641668;
    do
      v1 = SmRegistrationCtxInitialize(v1) + 2;
    while ( v2 != 1 );
  }
  return v0;
}
