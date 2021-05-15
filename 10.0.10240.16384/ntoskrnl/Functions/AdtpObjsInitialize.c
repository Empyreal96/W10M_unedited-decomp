// AdtpObjsInitialize 
 
int AdtpObjsInitialize()
{
  __int16 *v0; // r5
  int v1; // r7
  unsigned int v2; // r6
  char *v3; // r8
  int v4; // r4
  unsigned int v5; // r6
  __int16 *v6; // r5
  char *i; // r7
  char v9[8]; // [sp+28h] [bp-40h] BYREF
  int v10; // [sp+30h] [bp-38h]
  int v11; // [sp+34h] [bp-34h]
  char *v12; // [sp+38h] [bp-30h]
  int v13; // [sp+3Ch] [bp-2Ch]
  int v14; // [sp+40h] [bp-28h]
  int v15; // [sp+44h] [bp-24h]

  AdtpSourceModules = 0;
  ExInitializeResourceLite((int)&AdtpSourceModuleLock);
  v0 = &AdtpEventIdStringStandard;
  v1 = 0;
  v2 = 0;
  v3 = (char *)&AdtpAccessIdsStringBuffer;
  while ( 1 )
  {
    *v0 = 0;
    v0[1] = 24;
    *((_DWORD *)v0 + 1) = v3;
    v4 = RtlIntegerToUnicodeString(v2 + 1537, 10, (unsigned __int16 *)v0);
    if ( v4 < 0 )
      break;
    ++v2;
    v1 += 12;
    v0 += 4;
    v3 += 24;
    if ( v2 > 6 )
    {
      v5 = 0;
      v6 = &AdtpEventIdStringSpecific;
      for ( i = (char *)&AdtpAccessIdsStringBuffer + 2 * v1; ; i += 24 )
      {
        *v6 = 0;
        v6[1] = 24;
        *((_DWORD *)v6 + 1) = i;
        v4 = RtlIntegerToUnicodeString(v5 + 1552, 10, (unsigned __int16 *)v6);
        if ( v4 < 0 )
          break;
        ++v5;
        v6 += 4;
        if ( v5 > 0xF )
        {
          RtlInitUnicodeString(
            (unsigned int)v9,
            L"\\Registry\\Machine\\System\\CurrentControlSet\\Services\\EventLog\\Security");
          v10 = 24;
          v11 = 0;
          v12 = v9;
          v14 = 0;
          v15 = 0;
          v13 = 576;
          if ( NtOpenKey() != -1073741772 )
            return sub_8102AC();
          return 0;
        }
      }
      return v4;
    }
  }
  return v4;
}
