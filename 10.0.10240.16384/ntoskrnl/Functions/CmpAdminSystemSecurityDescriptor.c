// CmpAdminSystemSecurityDescriptor 
 
_BYTE *CmpAdminSystemSecurityDescriptor()
{
  int v0; // r0
  int v1; // r7
  int v2; // r0
  int v3; // r0
  unsigned int v4; // r6
  int v5; // r8
  int v6; // r0
  unsigned int v7; // r5
  int v8; // r0
  int v9; // r0
  int v10; // r0
  _BYTE *v11; // r4
  int v12; // r8
  int v13; // r8
  char v15[32]; // [sp+8h] [bp-20h] BYREF

  v15[0] = 0;
  v15[1] = 0;
  v15[2] = 0;
  v15[3] = 0;
  v15[4] = 0;
  v15[5] = 5;
  v0 = RtlLengthRequiredSid(1u);
  v1 = ExAllocatePoolWithTag(1, v0, 538987843);
  v2 = RtlLengthRequiredSid(2u);
  v3 = ExAllocatePoolWithTag(1, v2, 538987843);
  v4 = v3;
  if ( !v1 || !v3 )
    KeBugCheckEx(81, 11, 1, 0, 0);
  if ( RtlInitializeSid(v1, (int)v15, 1u) < 0 || RtlInitializeSid(v4, (int)v15, 2u) < 0 )
    KeBugCheckEx(81, 11, 2, 0, 0);
  *(_DWORD *)RtlSubAuthoritySid(v1, 0) = 18;
  *(_DWORD *)RtlSubAuthoritySid(v4, 0) = 32;
  *(_DWORD *)RtlSubAuthoritySid(v4, 1) = 544;
  v5 = 4 * (*(unsigned __int8 *)(v1 + 1) + *(unsigned __int8 *)(v4 + 1) + 10);
  v6 = ExAllocatePoolWithTag(1, v5, 538987843);
  v7 = v6;
  if ( !v6 )
    sub_80B86C();
  v8 = RtlCreateAcl(v6, v5, 2);
  if ( v8 < 0 )
    KeBugCheckEx(81, 11, 4, v8, 0);
  v9 = RtlAddAccessAllowedAce(v7, 2, 2032127, v1);
  if ( v9 < 0 || (v9 = RtlAddAccessAllowedAce(v7, 2, 2032127, v4), v9 < 0) )
    KeBugCheckEx(81, 11, 5, v9, 0);
  v10 = ExAllocatePoolWithTag(1, v5 + 20, 538987843);
  v11 = (_BYTE *)v10;
  if ( !v10 )
    KeBugCheckEx(81, 11, 6, 0, 0);
  memmove(v10 + 20, v7, v5);
  v12 = RtlCreateSecurityDescriptor(v11, 1);
  if ( v12 < 0 )
  {
    ExFreePoolWithTag((unsigned int)v11);
    KeBugCheckEx(81, 11, 7, v12, 0);
  }
  v13 = RtlSetDaclSecurityDescriptor((int)v11, 1, (int)(v11 + 20), 0);
  if ( v13 < 0 )
  {
    ExFreePoolWithTag((unsigned int)v11);
    KeBugCheckEx(81, 11, 8, v13, 0);
  }
  ExFreePoolWithTag(v1);
  ExFreePoolWithTag(v4);
  ExFreePoolWithTag(v7);
  return v11;
}
