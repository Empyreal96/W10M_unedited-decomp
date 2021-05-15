// SeMakeAnonymousLogonTokenNoEveryone 
 
int *SeMakeAnonymousLogonTokenNoEveryone()
{
  unsigned __int16 *v0; // r8
  unsigned int v1; // r9
  int v2; // r7
  int v3; // r0
  unsigned int v4; // r5
  _BYTE *v5; // r0
  int v6; // r6
  int v8; // r4
  int v9; // r1
  int v10; // r2
  int v11; // [sp-4h] [bp-298h]
  int v12; // [sp+0h] [bp-294h]
  int v13; // [sp+3Ch] [bp-258h] BYREF
  int v14; // [sp+40h] [bp-254h]
  __int16 v15; // [sp+44h] [bp-250h]
  __int16 v16; // [sp+46h] [bp-24Eh]
  __int16 v17; // [sp+48h] [bp-24Ch]
  __int16 v18; // [sp+4Ah] [bp-24Ah]
  int *v19; // [sp+4Ch] [bp-248h] BYREF
  int v20; // [sp+50h] [bp-244h] BYREF
  int v21[6]; // [sp+54h] [bp-240h] BYREF
  __int64 v22; // [sp+6Ch] [bp-228h] BYREF
  _DWORD v23[136]; // [sp+74h] [bp-220h] BYREF

  v20 = 1;
  v13 = 68536;
  v14 = 65537;
  v15 = 1;
  v16 = 1;
  v17 = 1;
  v18 = 1;
  RtlTimeFieldsToTime((__int16 *)&v13, &v22);
  v14 = 0;
  v0 = (unsigned __int16 *)SeAnonymousLogonSid;
  v23[0] = SeUntrustedMandatorySid;
  v23[1] = 96;
  v1 = ((4 * *(unsigned __int8 *)(SeUntrustedMandatorySid + 1) + 11) & 0xFFFFFFFC) + 8;
  v13 = SeAnonymousLogonSid;
  v2 = *(unsigned __int8 *)(SeAnonymousLogonSid + 1) + *(unsigned __int8 *)(SeWorldSid + 1) + 12;
  v3 = ExAllocatePoolWithTag(1, 200, 1665230163);
  v4 = v3;
  if ( !v3 )
    JUMPOUT(0x96C684);
  RtlCreateAcl(v3, 4 * v2, 2);
  RtlAddAccessAllowedAce(v4, 2, 983551, SeWorldSid);
  RtlAddAccessAllowedAce(v4, 2, 983551, SeAnonymousLogonSid);
  v5 = (_BYTE *)ExAllocatePoolWithTag(1, 20, 1683187027);
  v6 = (int)v5;
  if ( !v5 )
    return (int *)sub_96C67C();
  RtlCreateSecurityDescriptor(v5, 1);
  RtlSetDaclSecurityDescriptor(v6, 1, v4, 0);
  v8 = SeWorldSid;
  RtlSetOwnerSecurityDescriptor(v6, SeWorldSid, 0);
  RtlSetGroupSecurityDescriptor(v6, v8, 0);
  v21[0] = 24;
  v21[1] = 0;
  v21[2] = 0;
  v21[3] = 0;
  v21[4] = v6;
  v21[5] = 0;
  SepCreateToken(
    (int *)&v19,
    v9,
    v10,
    (int)v21,
    v11,
    v12,
    (int)SeAnonymousAuthenticationId,
    &v22,
    (unsigned __int16 **)&v13,
    1u,
    (int)v23,
    v1,
    0,
    0,
    0,
    v0,
    v4);
  SeSetMandatoryPolicyToken(v19, &v20);
  ExFreePoolWithTag(v4);
  ExFreePoolWithTag(v6);
  return v19;
}
