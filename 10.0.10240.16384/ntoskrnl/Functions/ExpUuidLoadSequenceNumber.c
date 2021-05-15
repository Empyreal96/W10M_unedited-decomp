// ExpUuidLoadSequenceNumber 
 
int ExpUuidLoadSequenceNumber()
{
  int v0; // r4
  char v2[8]; // [sp+28h] [bp-38h] BYREF
  char v3[8]; // [sp+38h] [bp-28h] BYREF
  int v4; // [sp+44h] [bp-1Ch]
  int v5; // [sp+48h] [bp-18h]
  int v6; // [sp+4Ch] [bp-14h]

  RtlInitUnicodeString(
    (unsigned int)v2,
    L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Session Manager\\Executive");
  RtlInitUnicodeString((unsigned int)v3, L"UuidSequenceNumber");
  v0 = ZwOpenKey();
  if ( v0 >= 0 )
  {
    v0 = ZwQueryValueKey();
    ZwClose();
    if ( v0 >= 0 )
    {
      if ( v4 == 4 && v5 == 4 )
        ExpUuidSequenceNumber = v6;
      else
        v0 = -1073741823;
    }
  }
  return v0;
}
