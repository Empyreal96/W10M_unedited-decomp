// AdtpDbInitializePrivilegeObject 
 
int AdtpDbInitializePrivilegeObject()
{
  unsigned int v0; // r5
  __int16 *v1; // r7
  unsigned __int16 **v2; // r8
  unsigned int i; // r4
  unsigned __int16 *v4; // t1
  unsigned int v5; // r3
  unsigned int v6; // t1
  int result; // r0

  v0 = 0;
  v1 = &AdtpKnownPrivilege;
  v2 = (unsigned __int16 **)off_413560;
  AdtpWellKnownPrivilegeMaxLen = 0;
  for ( i = 0; i < 0x22; ++i )
  {
    v4 = *v2++;
    *((_QWORD *)v1 + 1) = (int)(i + 2);
    RtlInitUnicodeString((unsigned int)v1, v4);
    v6 = (unsigned __int16)*v1;
    v1 += 8;
    v5 = v6;
    if ( v0 < v6 )
    {
      v0 = v5;
      AdtpWellKnownPrivilegeMaxLen = v5;
    }
  }
  result = 0;
  AdtpWellKnownPrivilegeCount = i;
  return result;
}
