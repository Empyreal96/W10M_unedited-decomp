// IopCreateArcNamesDisk 
 
int IopCreateArcNamesDisk()
{
  unsigned int v0; // r4
  unsigned int v1; // r5
  unsigned __int16 *v2; // r7
  unsigned int i; // r6
  int v5; // r9
  BOOL v6; // r8
  unsigned int v7; // [sp+10h] [bp-B0h] BYREF
  unsigned __int16 *v8; // [sp+14h] [bp-ACh] BYREF
  char v9[8]; // [sp+18h] [bp-A8h] BYREF
  unsigned __int16 v10[80]; // [sp+20h] [bp-A0h] BYREF

  v8 = 0;
  v0 = *IoGetConfigurationInformation();
  v7 = 0;
  v6 = IopFetchConfigurationInformation(
         &v8,
         GUID_DEVINTERFACE_DISK.Data1,
         *(_DWORD *)&GUID_DEVINTERFACE_DISK.Data2,
         -1610550636,
         -1946476855,
         v0,
         &v7) < 0;
  v1 = (unsigned int)v8;
  v2 = v8;
  if ( v7 > v0 )
    v0 = v7;
  if ( v6 )
    return sub_969250();
  for ( i = 0; i < v0; ++i )
  {
    if ( v2 && *v2 )
    {
      v5 = -1;
      RtlInitUnicodeString((unsigned int)v9, v2);
      v2 += wcslen(v2) + 1;
    }
    else
    {
      v5 = i;
      RtlStringCchPrintfW(v10, 0x40u, (int)L"\\Device\\Harddisk%d\\Partition0", i);
      RtlInitUnicodeString((unsigned int)v9, v10);
    }
    if ( IoGetDeviceObjectPointer((int)v9, 128, &v8, (int *)&v7) >= 0 )
    {
      IopCreateArcName(v7, v5);
      ObfDereferenceObjectWithTag((int)v8);
    }
  }
  if ( v1 )
    ExFreePoolWithTag(v1);
  return 0;
}
