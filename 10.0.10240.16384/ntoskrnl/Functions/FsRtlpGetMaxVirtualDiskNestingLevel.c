// FsRtlpGetMaxVirtualDiskNestingLevel 
 
unsigned int FsRtlpGetMaxVirtualDiskNestingLevel()
{
  unsigned int v0; // r4
  unsigned int v1; // r5
  char v3[8]; // [sp+28h] [bp-58h] BYREF
  char v4[8]; // [sp+30h] [bp-50h] BYREF
  char v5[8]; // [sp+38h] [bp-48h] BYREF
  unsigned int v6; // [sp+54h] [bp-2Ch]

  v0 = 0;
  v1 = 2;
  RtlInitUnicodeString(
    (unsigned int)v3,
    L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\FileSystem\\GroupPolicyKeys");
  RtlInitUnicodeString(
    (unsigned int)v5,
    L"\\Registry\\Machine\\System\\CurrentControlSet\\Services\\FsDepends\\Parameters");
  do
  {
    ++v0;
    if ( ZwOpenKey() >= 0 )
    {
      RtlInitUnicodeString((unsigned int)v4, L"VirtualDiskMaxTreeDepth");
      if ( ZwQueryValueKey() >= 0 && v6 <= 2 )
        v1 = v6;
      ZwClose();
    }
  }
  while ( v0 < 2 );
  return v1;
}
