// IopProtectSystemPartition 
 
int IopProtectSystemPartition()
{
  int v1; // [sp+8h] [bp-90h]
  char v2[8]; // [sp+28h] [bp-70h] BYREF
  char v3[8]; // [sp+30h] [bp-68h] BYREF
  _DWORD v4[2]; // [sp+38h] [bp-60h] BYREF
  char v5[88]; // [sp+40h] [bp-58h] BYREF

  RtlInitUnicodeString((unsigned int)v2, L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Lsa");
  if ( NtOpenKey() >= 0 )
  {
    RtlInitUnicodeString((unsigned int)v4, L"Protect System Partition");
    if ( NtQueryValueKey(v1, v4, 2, (int)v5, 20, (unsigned int)v3) >= 0 )
      return sub_970210();
    NtClose();
  }
  return 1;
}
