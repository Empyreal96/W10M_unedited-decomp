// SeMakeAnonymousLogonToken 
 
int *SeMakeAnonymousLogonToken()
{
  int v0; // r3
  unsigned int v1; // r2
  int v2; // r3
  unsigned __int16 *v3; // r8
  unsigned int v4; // r9
  int v5; // r3
  int v6; // r7
  int v7; // r0
  unsigned int v8; // r5
  _BYTE *v9; // r0
  int v10; // r6
  int v12; // r4
  int v13; // r1
  int v14; // r2
  int v15; // [sp-4h] [bp-298h]
  int v16; // [sp+0h] [bp-294h]
  int v17; // [sp+3Ch] [bp-258h] BYREF
  int v18; // [sp+40h] [bp-254h]
  __int16 v19; // [sp+44h] [bp-250h]
  __int16 v20; // [sp+46h] [bp-24Eh]
  __int16 v21; // [sp+48h] [bp-24Ch]
  __int16 v22; // [sp+4Ah] [bp-24Ah]
  int *v23; // [sp+4Ch] [bp-248h] BYREF
  int v24; // [sp+50h] [bp-244h] BYREF
  int v25[6]; // [sp+54h] [bp-240h] BYREF
  __int64 v26; // [sp+6Ch] [bp-228h] BYREF
  int v27[136]; // [sp+74h] [bp-220h] BYREF

  v24 = 1;
  v17 = 68536;
  v18 = 65537;
  v19 = 1;
  v20 = 1;
  v21 = 1;
  v22 = 1;
  RtlTimeFieldsToTime((__int16 *)&v17, &v26);
  v18 = 0;
  v27[1] = 7;
  v27[2] = SeLowMandatorySid;
  v0 = *(unsigned __int8 *)(SeLowMandatorySid + 1);
  v27[3] = 96;
  v1 = (4 * v0 + 11) & 0xFFFFFFFC;
  v2 = *(unsigned __int8 *)(SeWorldSid + 1);
  v27[0] = SeWorldSid;
  v3 = (unsigned __int16 *)SeAnonymousLogonSid;
  v4 = ((4 * v2 + 11) & 0xFFFFFFFC) + v1 + 8;
  v5 = *(unsigned __int8 *)(SeAnonymousLogonSid + 1) + *(unsigned __int8 *)(SeWorldSid + 1);
  v17 = SeAnonymousLogonSid;
  v6 = v5 + 12;
  v7 = ExAllocatePoolWithTag(1, 200, 1665230163);
  v8 = v7;
  if ( !v7 )
    JUMPOUT(0x96C694);
  RtlCreateAcl(v7, 4 * v6, 2);
  RtlAddAccessAllowedAce(v8, 2, 983551, SeWorldSid);
  RtlAddAccessAllowedAce(v8, 2, 983551, SeAnonymousLogonSid);
  v9 = (_BYTE *)ExAllocatePoolWithTag(1, 20, 1683187027);
  v10 = (int)v9;
  if ( !v9 )
    return (int *)sub_96C68C();
  RtlCreateSecurityDescriptor(v9, 1);
  RtlSetDaclSecurityDescriptor(v10, 1, v8, 0);
  v12 = SeWorldSid;
  RtlSetOwnerSecurityDescriptor(v10, SeWorldSid, 0);
  RtlSetGroupSecurityDescriptor(v10, v12, 0);
  v25[0] = 24;
  v25[1] = 0;
  v25[2] = 0;
  v25[3] = 0;
  v25[4] = v10;
  v25[5] = 0;
  SepCreateToken(
    (int *)&v23,
    v13,
    v14,
    (int)v25,
    v15,
    v16,
    (int)SeAnonymousAuthenticationId,
    &v26,
    (unsigned __int16 **)&v17,
    2u,
    (int)v27,
    v4,
    0,
    0,
    0,
    v3,
    v8);
  SeSetMandatoryPolicyToken(v23, &v24);
  ExFreePoolWithTag(v8);
  ExFreePoolWithTag(v10);
  return v23;
}
