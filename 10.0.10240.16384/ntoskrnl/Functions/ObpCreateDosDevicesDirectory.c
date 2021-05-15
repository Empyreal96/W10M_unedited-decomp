// ObpCreateDosDevicesDirectory 
 
int ObpCreateDosDevicesDirectory()
{
  int result; // r0
  int v1; // [sp+0h] [bp-50h] BYREF
  int v2; // [sp+4h] [bp-4Ch]
  int v3[2]; // [sp+8h] [bp-48h] BYREF
  int v4[2]; // [sp+10h] [bp-40h] BYREF
  char v5[24]; // [sp+18h] [bp-38h] BYREF
  int v6; // [sp+30h] [bp-20h] BYREF
  int v7; // [sp+34h] [bp-1Ch]
  int *v8; // [sp+38h] [bp-18h]
  int v9; // [sp+3Ch] [bp-14h]
  char *v10; // [sp+40h] [bp-10h]
  int v11; // [sp+44h] [bp-Ch]

  result = ObpGetDosDevicesProtection(v5);
  if ( result >= 0 )
  {
    RtlInitUnicodeString((unsigned int)v3, L"\\GLOBAL??");
    v6 = 24;
    v7 = 0;
    v9 = 16;
    v8 = v3;
    v10 = v5;
    v11 = 0;
    result = NtCreateDirectoryObject();
    if ( result >= 0 )
    {
      result = ObSetDeviceMap(0, v2);
      if ( result >= 0 )
      {
        RtlInitUnicodeString((unsigned int)v4, (unsigned __int16 *)&dword_97E66C);
        v6 = 24;
        v7 = v2;
        v9 = 16;
        v8 = (int *)&GlobalRootNameString;
        v10 = v5;
        v11 = 0;
        result = NtCreateSymbolicLinkObject((unsigned int)&v1, 983041, (int)&v6, v4);
        if ( result >= 0 )
        {
          NtClose();
          v6 = 24;
          v7 = v2;
          v9 = 16;
          v8 = (int *)&GlobalNameString;
          v10 = v5;
          v11 = 0;
          result = NtCreateSymbolicLinkObject((unsigned int)&v1, 983041, (int)&v6, v3);
          if ( result >= 0 )
          {
            NtClose();
            NtClose();
            RtlInitUnicodeString((unsigned int)v3, L"\\??");
            v6 = 24;
            v7 = 0;
            v9 = 16;
            v8 = (int *)&DosDevicesNameString;
            v10 = v5;
            v11 = 0;
            result = NtCreateSymbolicLinkObject((unsigned int)&v1, 983041, (int)&v6, v3);
            if ( result >= 0 )
            {
              NtClose();
              ObpFreeDosDevicesProtection(v5);
              result = 0;
            }
          }
        }
      }
    }
  }
  return result;
}
