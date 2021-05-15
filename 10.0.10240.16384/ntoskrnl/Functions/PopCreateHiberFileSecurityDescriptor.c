// PopCreateHiberFileSecurityDescriptor 
 
int __fastcall PopCreateHiberFileSecurityDescriptor(int a1, int a2, int a3, int a4)
{
  _BYTE *v4; // r4
  unsigned __int8 *v5; // r5
  int v6; // r0
  int v7; // r0
  unsigned int v8; // r7
  unsigned int v9; // r3
  unsigned int v10; // r6
  int v11; // r0
  int v13; // r0
  int v14; // [sp+0h] [bp-18h] BYREF
  char v15; // [sp+4h] [bp-14h]
  char v16; // [sp+5h] [bp-13h]
  __int16 v17; // [sp+6h] [bp-12h]

  v17 = HIWORD(a4);
  v14 = 0;
  v15 = 0;
  v16 = 1;
  v4 = 0;
  v5 = 0;
  v6 = RtlLengthRequiredSid(1u);
  v7 = ExAllocatePoolWithTag(1, v6, 1919052136);
  v8 = v7;
  if ( v7 )
  {
    if ( RtlInitializeSid(v7, (int)&v14, 1u) >= 0 )
    {
      *(_DWORD *)RtlSubAuthoritySid(v8, 0) = 0;
      v9 = 4 * (*(unsigned __int8 *)(v8 + 1) + 4);
      v10 = v9 + 8;
      if ( v9 + 8 < v9 )
        JUMPOUT(0x7F141A);
      v11 = ExAllocatePoolWithTag(1, v9 + 8, 1919052136);
      v5 = (unsigned __int8 *)v11;
      if ( !v11 )
        return sub_7F13A8();
      if ( RtlCreateAcl(v11, v10, 2) < 0 )
        JUMPOUT(0x7F13B8);
      if ( RtlAddAccessAllowedAce((int)v5, 2, 0x10000, v8) < 0 )
        JUMPOUT(0x7F13C8);
      RtlGetAce(v5, 0, (int)&v14);
      *(_BYTE *)(v14 + 1) |= 2u;
      v13 = ExAllocatePoolWithTag(1, v10 + 20, 1919052136);
      v4 = (_BYTE *)v13;
      if ( !v13 )
        JUMPOUT(0x7F13DE);
      memmove(v13 + 20, (int)v5, v10);
      if ( RtlCreateSecurityDescriptor(v4, 1) < 0 )
        JUMPOUT(0x7F13EE);
      if ( RtlSetDaclSecurityDescriptor((int)v4, 1, (int)(v4 + 20), 0) < 0 )
        JUMPOUT(0x7F140E);
    }
    ExFreePoolWithTag(v8);
    if ( v5 )
      ExFreePoolWithTag((unsigned int)v5);
  }
  return (int)v4;
}
