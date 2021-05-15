// CmpHiveRootSecurityDescriptor 
 
_BYTE *CmpHiveRootSecurityDescriptor()
{
  int v0; // r4
  unsigned int v1; // r10
  int v2; // r8
  int v3; // r9
  int v4; // r4
  int v5; // r6
  int v6; // r0
  unsigned int v7; // r7
  unsigned int v8; // r5
  int v9; // r0
  unsigned __int8 *v10; // r4
  int v11; // r0
  int v12; // r0
  unsigned int v13; // r10
  int v14; // r0
  _BYTE *v15; // r5
  int v16; // r10
  int v17; // r10
  int v19; // [sp+8h] [bp-40h] BYREF
  char v20; // [sp+Ch] [bp-3Ch]
  char v21; // [sp+Dh] [bp-3Bh]
  int v22; // [sp+10h] [bp-38h] BYREF
  char v23; // [sp+14h] [bp-34h]
  char v24; // [sp+15h] [bp-33h]
  unsigned int v25; // [sp+18h] [bp-30h]
  char v26[40]; // [sp+20h] [bp-28h] BYREF

  v19 = 0;
  v20 = 0;
  v21 = 1;
  v22 = 0;
  v23 = 0;
  v24 = 5;
  v26[0] = 0;
  v26[1] = 0;
  v26[2] = 0;
  v26[3] = 0;
  v26[4] = 0;
  v26[5] = 15;
  v0 = RtlLengthRequiredSid(1u);
  v1 = ExAllocatePoolWithTag(1, v0, 538987843);
  v25 = v1;
  v2 = ExAllocatePoolWithTag(1, v0, 538987843);
  v3 = ExAllocatePoolWithTag(1, v0, 538987843);
  v4 = RtlLengthRequiredSid(2u);
  v5 = ExAllocatePoolWithTag(1, v4, 538987843);
  v6 = ExAllocatePoolWithTag(1, v4, 538987843);
  v7 = v6;
  if ( !v1 || !v2 || !v3 || !v5 || !v6 )
    KeBugCheckEx(81, 11, 1, 0, 0);
  if ( RtlInitializeSid(v1, (int)&v19, 1u) < 0
    || RtlInitializeSid(v2, (int)&v22, 1u) < 0
    || RtlInitializeSid(v3, (int)&v22, 1u) < 0
    || RtlInitializeSid(v5, (int)&v22, 2u) < 0
    || RtlInitializeSid(v7, (int)v26, 2u) < 0 )
  {
    KeBugCheckEx(81, 11, 2, 0, 0);
  }
  *(_DWORD *)RtlSubAuthoritySid(v1, 0) = 0;
  *(_DWORD *)RtlSubAuthoritySid(v2, 0) = 12;
  *(_DWORD *)RtlSubAuthoritySid(v3, 0) = 18;
  *(_DWORD *)RtlSubAuthoritySid(v5, 0) = 32;
  *(_DWORD *)RtlSubAuthoritySid(v5, 1) = 544;
  *(_DWORD *)RtlSubAuthoritySid(v7, 0) = 2;
  *(_DWORD *)RtlSubAuthoritySid(v7, 1) = 1;
  v22 = 4
      * (*(unsigned __int8 *)(v7 + 1)
       + *(unsigned __int8 *)(v5 + 1)
       + *(unsigned __int8 *)(v3 + 1)
       + *(unsigned __int8 *)(v2 + 1)
       + *(unsigned __int8 *)(v1 + 1)
       + 22);
  v8 = v22;
  v9 = ExAllocatePoolWithTag(1, v22, 538987843);
  v10 = (unsigned __int8 *)v9;
  if ( !v9 )
    sub_80B8F4();
  v11 = RtlCreateAcl(v9, v8, 2);
  if ( v11 < 0 )
    KeBugCheckEx(81, 11, 4, v11, 0);
  v12 = RtlAddAccessAllowedAce((int)v10, 2, 983103, v3);
  if ( v12 < 0
    || (v12 = RtlAddAccessAllowedAce((int)v10, 2, 983103, v5), v12 < 0)
    || (v12 = RtlAddAccessAllowedAce((int)v10, 2, 131097, v1), v12 < 0)
    || (v12 = RtlAddAccessAllowedAce((int)v10, 2, 131097, v2), v12 < 0)
    || (v12 = RtlAddAccessAllowedAce((int)v10, 2, 131097, v7), v12 < 0) )
  {
    KeBugCheckEx(81, 11, 5, v12, 0);
  }
  RtlGetAce(v10, 0, (int)&v19);
  *(_BYTE *)(v19 + 1) |= 2u;
  RtlGetAce(v10, 1u, (int)&v19);
  *(_BYTE *)(v19 + 1) |= 2u;
  RtlGetAce(v10, 2u, (int)&v19);
  *(_BYTE *)(v19 + 1) |= 2u;
  RtlGetAce(v10, 3u, (int)&v19);
  *(_BYTE *)(v19 + 1) |= 2u;
  RtlGetAce(v10, 4u, (int)&v19);
  v13 = v22;
  *(_BYTE *)(v19 + 1) |= 2u;
  v14 = ExAllocatePoolWithTag(1, v13 + 20, 538987843);
  v15 = (_BYTE *)v14;
  if ( !v14 )
    KeBugCheckEx(81, 11, 6, 0, 0);
  memmove(v14 + 20, (int)v10, v13);
  v16 = RtlCreateSecurityDescriptor(v15, 1);
  if ( v16 < 0 )
  {
    ExFreePoolWithTag((unsigned int)v15);
    KeBugCheckEx(81, 11, 7, v16, 0);
  }
  v17 = RtlSetDaclSecurityDescriptor((int)v15, 1, (int)(v15 + 20), 0);
  if ( v17 < 0 )
  {
    ExFreePoolWithTag((unsigned int)v15);
    KeBugCheckEx(81, 11, 8, v17, 0);
  }
  ExFreePoolWithTag(v25);
  ExFreePoolWithTag(v2);
  ExFreePoolWithTag(v3);
  ExFreePoolWithTag(v5);
  ExFreePoolWithTag(v7);
  ExFreePoolWithTag((unsigned int)v10);
  return v15;
}
