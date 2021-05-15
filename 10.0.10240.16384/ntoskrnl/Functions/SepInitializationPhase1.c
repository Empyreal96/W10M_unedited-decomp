// SepInitializationPhase1 
 
int SepInitializationPhase1()
{
  BOOL v0; // r5
  int v1; // r0
  int v2; // r3
  int v3; // r0
  unsigned int v4; // r6
  int v6; // r3
  int v7; // r0
  int v8; // r1
  int v9; // r2
  int v10; // r0
  int v11; // r0
  int v12; // [sp+4h] [bp-74h]
  __int64 v13; // [sp+8h] [bp-70h] BYREF
  int v14; // [sp+10h] [bp-68h]
  int v15; // [sp+14h] [bp-64h]
  int v16; // [sp+18h] [bp-60h]
  int v17; // [sp+1Ch] [bp-5Ch]
  __int64 *v18; // [sp+20h] [bp-58h]
  int v19; // [sp+24h] [bp-54h]
  char *v20; // [sp+28h] [bp-50h]
  int v21; // [sp+2Ch] [bp-4Ch]
  unsigned __int16 v22[4]; // [sp+30h] [bp-48h] BYREF
  int v23[6]; // [sp+38h] [bp-40h] BYREF
  char v24[40]; // [sp+50h] [bp-28h] BYREF

  v13 = 0i64;
  v14 = 0;
  v0 = PsIsCurrentThreadInServerSilo();
  if ( !v0 )
  {
    v1 = ObInsertObject(
           *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 244) & 0xFFFFFFF8,
           0,
           0,
           0,
           0,
           0);
    SeAnonymousLogonToken = SeMakeAnonymousLogonToken(v1);
    SeAnonymousLogonTokenNoEveryone = SeMakeAnonymousLogonTokenNoEveryone();
  }
  RtlInitAnsiString((unsigned int)v22, (unsigned int)"\\Security");
  RtlAnsiStringToUnicodeString((unsigned __int16 *)&v13, v22, 1, v2);
  RtlCreateSecurityDescriptor(v24, 1);
  v3 = ExAllocatePoolWithTag(512, 256, 538994003);
  v4 = v3;
  if ( !v3 )
    return sub_81086C();
  RtlCreateAcl(v3, 0x100u, 2);
  RtlAddAccessAllowedAce(v4, 2, 983055, SeLocalSystemSid);
  RtlAddAccessAllowedAce(v4, 2, 131075, SeAliasAdminsSid);
  RtlAddAccessAllowedAce(v4, 2, 2, SeWorldSid);
  RtlSetDaclSecurityDescriptor((int)v24, 1, v4, 0);
  v16 = 24;
  v17 = 0;
  v19 = 80;
  v18 = &v13;
  v20 = v24;
  v21 = 0;
  ZwCreateDirectoryObject();
  RtlFreeAnsiString(&v13);
  ExFreePoolWithTag(v4);
  RtlInitAnsiString((unsigned int)v22, (unsigned int)"LSA_AUTHENTICATION_INITIALIZED");
  RtlAnsiStringToUnicodeString((unsigned __int16 *)&v13, v22, 1, v6);
  v16 = 24;
  v17 = v15;
  v19 = 80;
  v18 = &v13;
  v20 = (char *)SePublicDefaultSd;
  v21 = 0;
  ZwCreateEvent();
  RtlFreeAnsiString(&v13);
  ZwClose();
  v7 = ZwClose();
  if ( !v0 )
  {
    v10 = SepInitProcessAuditSd(v7, v8, v9);
    v11 = SepInitializeCodeIntegrity(v10);
    SepInitializeAuthorizationCallbacks(v11);
    memset(v23, 0, sizeof(v23));
    LOWORD(v23[0]) = 1;
    HIWORD(v23[0]) |= 1u;
    v23[1] = (int)SeInitServerSilo;
    v23[2] = (int)SeShutdownServerSilo;
    PsRegisterMonitorServerSilo(0, L"NTOS_SE", v23, &SeSiloMonitor, 0, v12, v13, HIDWORD(v13), v14);
    PsStartMonitorServerSilo(SeSiloMonitor);
  }
  return 1;
}
