// CmpCheckWrpKeyAccess 
 
BOOL __fastcall CmpCheckWrpKeyAccess(int a1)
{
  int v2; // r0
  int v3; // r5
  int v4; // r4
  unsigned int v5; // r0
  bool v7; // [sp+8h] [bp-20h] BYREF
  int v8; // [sp+Ch] [bp-1Ch] BYREF
  unsigned __int16 *v9[6]; // [sp+10h] [bp-18h] BYREF

  if ( !CmpTrustedInstallerSid
    || PsReferenceProcessFilePointer(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), &v8) < 0 )
  {
    return 0;
  }
  if ( ObQuerySecurityObject(v8, 1, 0, 0, v9) != -1073741789 )
  {
    v2 = v8;
LABEL_5:
    ObfDereferenceObject(v2);
    return 0;
  }
  v3 = ExAllocatePoolWithTag(1, (int)v9[0], 538987843);
  v2 = v8;
  if ( !v3 )
    goto LABEL_5;
  v4 = ObQuerySecurityObject(v8, 1, v3, v9[0], v9);
  ObfDereferenceObject(v8);
  v5 = v3;
  if ( v4 < 0 )
  {
LABEL_13:
    ExFreePoolWithTag(v5);
    return 0;
  }
  if ( RtlGetOwnerSecurityDescriptor(v3, v9, &v7) < 0 || RtlEqualSid((unsigned __int16 *)CmpTrustedInstallerSid, v9[0]) )
  {
    v5 = v3;
    goto LABEL_13;
  }
  ExFreePoolWithTag(v3);
  if ( RtlGetOwnerSecurityDescriptor(*(_DWORD *)(a1 + 48) + 24, v9, &v7) >= 0 )
    return RtlEqualSid((unsigned __int16 *)CmpTrustedInstallerSid, v9[0]);
  return 0;
}
