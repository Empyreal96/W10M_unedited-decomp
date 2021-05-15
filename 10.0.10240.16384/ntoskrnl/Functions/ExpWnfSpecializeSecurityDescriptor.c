// ExpWnfSpecializeSecurityDescriptor 
 
int __fastcall ExpWnfSpecializeSecurityDescriptor(int a1, int a2, int a3, int a4)
{
  int result; // r0
  char v6; // [sp+0h] [bp-10h] BYREF
  bool v7[3]; // [sp+1h] [bp-Fh] BYREF
  int v8[3]; // [sp+4h] [bp-Ch] BYREF

  v8[1] = a4;
  v8[0] = 0;
  if ( RtlGetDaclSecurityDescriptor(a1, &v6, v8, v7) >= 0 && v6 && v8[0] )
    RtlpApplyAclToObject(v8[0], ExpWnfNotificationMapping);
  result = RtlGetSaclSecurityDescriptor(a1, &v6, v8, v7);
  if ( result >= 0 && v6 )
  {
    result = v8[0];
    if ( v8[0] )
      result = RtlpApplyAclToObject(v8[0], ExpWnfNotificationMapping);
  }
  return result;
}
