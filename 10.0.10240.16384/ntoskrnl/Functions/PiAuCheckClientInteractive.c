// PiAuCheckClientInteractive 
 
int __fastcall PiAuCheckClientInteractive(_BYTE *a1)
{
  int v2; // r0
  int v3; // r0
  _BYTE *v4; // r5
  int v5; // r4
  char v7[8]; // [sp+0h] [bp-20h] BYREF
  char v8[24]; // [sp+8h] [bp-18h] BYREF

  v8[0] = 0;
  v8[1] = 0;
  v8[2] = 0;
  v8[3] = 0;
  v8[4] = 0;
  v8[5] = 5;
  v7[0] = 0;
  *a1 = 0;
  v2 = RtlLengthRequiredSid(1u);
  v3 = ExAllocatePoolWithTag(1, v2, 538996816);
  v4 = (_BYTE *)v3;
  if ( !v3 )
    return -1073741670;
  v5 = RtlInitializeSid(v3, (int)v8, 1u);
  if ( v5 >= 0 )
  {
    *(_DWORD *)RtlSubAuthoritySid((int)v4, 0) = 4;
    if ( !RtlValidSid(v4) )
      v5 = -1073741595;
    if ( v5 >= 0 )
    {
      v5 = PiAuCheckTokenMembership(v4, v7);
      if ( v5 >= 0 )
        *a1 = v7[0];
    }
  }
  ExFreePoolWithTag((unsigned int)v4);
  return v5;
}
