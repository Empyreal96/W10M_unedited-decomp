// MiSystemPartitionObjectCreate 
 
int MiSystemPartitionObjectCreate()
{
  int v0; // r4
  int v1; // r4
  int v2; // r0
  unsigned int v3; // r5
  int v4; // r0
  int v5; // r2
  int v7[6]; // [sp+8h] [bp-118h] BYREF
  char v8[8]; // [sp+20h] [bp-100h] BYREF
  _DWORD v9[2]; // [sp+28h] [bp-F8h] BYREF
  char v10[24]; // [sp+30h] [bp-F0h] BYREF
  unsigned __int16 v11[108]; // [sp+48h] [bp-D8h] BYREF

  RtlStringCbPrintfW(v11, 0xC2u, (int)L"\\KernelObjects\\MemoryPartition%d", 0);
  RtlInitUnicodeString((unsigned int)v8, v11);
  v0 = RtlCreateSecurityDescriptor(v10, 1);
  if ( v0 >= 0 )
  {
    v1 = *(unsigned __int8 *)(SeAliasAdminsSid + 1) + 7;
    v2 = ExAllocatePoolWithTag(1, 4 * v1, 1818452292);
    v3 = v2;
    if ( v2 )
    {
      v0 = RtlCreateAcl(v2, 4 * v1, 2);
      if ( v0 >= 0 )
      {
        v0 = RtlAddAccessAllowedAce(v3, 2, 2031619, SeAliasAdminsSid);
        if ( v0 >= 0 )
        {
          v4 = RtlSetDaclSecurityDescriptor((int)v10, 1, v3, 0);
          v0 = v4;
          if ( v4 >= 0 )
          {
            v7[0] = 24;
            v7[1] = 0;
            v7[3] = 512;
            v7[2] = (int)v8;
            v7[4] = (int)v10;
            v7[5] = 0;
            v0 = MiPartitionObjectCreate(v4, (int)v7, v5, (int)v9, v9);
          }
        }
      }
      ExFreePoolWithTag(v3);
    }
    else
    {
      v0 = -1073741670;
    }
  }
  return v0;
}
