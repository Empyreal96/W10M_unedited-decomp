// CmpSetVersionData 
 
unsigned int CmpSetVersionData()
{
  __int16 **v0; // r8
  unsigned int v1; // r5
  int v2; // r4
  int v3; // r4
  __int16 *v5; // t1
  int v6; // [sp+10h] [bp-1E8h]
  unsigned __int16 v7; // [sp+18h] [bp-1E0h] BYREF
  __int16 v8; // [sp+1Ah] [bp-1DEh]
  char *v9; // [sp+1Ch] [bp-1DCh]
  unsigned __int16 v10[4]; // [sp+20h] [bp-1D8h] BYREF
  int v11; // [sp+28h] [bp-1D0h]
  int v12; // [sp+30h] [bp-1C8h]
  int v13; // [sp+34h] [bp-1C4h]
  int *v14; // [sp+38h] [bp-1C0h]
  int v15; // [sp+3Ch] [bp-1BCh]
  unsigned int v16; // [sp+40h] [bp-1B8h]
  int v17; // [sp+44h] [bp-1B4h]
  int v18; // [sp+48h] [bp-1B0h]
  char v19[8]; // [sp+50h] [bp-1A8h] BYREF
  char v20[128]; // [sp+58h] [bp-1A0h] BYREF
  char v21[288]; // [sp+D8h] [bp-120h] BYREF

  v0 = &VersionDataKeys;
  v1 = CmpHiveRootSecurityDescriptor();
  if ( VersionDataKeys )
  {
    while ( 1 )
    {
      RtlInitUnicodeString((unsigned int)v19, (unsigned __int16 *)*v0);
      v12 = 24;
      v13 = 0;
      v14 = (int *)v19;
      v16 = v1;
      v17 = 0;
      v15 = 576;
      if ( ZwCreateKey() < 0 )
        break;
      v12 = 24;
      v13 = v6;
      v14 = &CmpWindowsNtString;
      v16 = v1;
      v17 = 0;
      v15 = 576;
      v2 = ZwCreateKey();
      ZwClose();
      if ( v2 < 0 )
        break;
      v12 = 24;
      v13 = v18;
      v14 = &CmpCurrentVersionString;
      v15 = 576;
      v16 = v1;
      v17 = 0;
      v3 = ZwCreateKey();
      ZwClose();
      if ( v3 < 0 )
        break;
      ZwSetValueKey();
      v11 = 10;
      ZwSetValueKey();
      v11 = 0;
      ZwSetValueKey();
      v11 = 0;
      sprintf_s((int)v20, 128, (int)"%u", 10240);
      RtlInitAnsiString((unsigned int)v10, (unsigned int)v20);
      v9 = v21;
      v7 = 0;
      v8 = 256;
      if ( RtlAnsiStringToUnicodeString(&v7, v10, 0, 0) >= 0 )
        ZwSetValueKey();
      RtlInitAnsiString((unsigned int)v10, (unsigned int)"10240.th1.150709-1700");
      v9 = v21;
      v7 = 0;
      v8 = 256;
      if ( RtlAnsiStringToUnicodeString(&v7, v10, 0, 0) >= 0 )
        ZwSetValueKey();
      RtlInitAnsiString((unsigned int)v10, (unsigned int)"10240.16384.armfre.th1.150709-1700");
      v9 = v21;
      v7 = 0;
      v8 = 256;
      if ( RtlAnsiStringToUnicodeString(&v7, v10, 0, 0) >= 0 )
        ZwSetValueKey();
      RtlInitAnsiString((unsigned int)v10, (unsigned int)"ffffffff-ffff-ffff-ffff-ffffffffffff");
      v9 = v21;
      v7 = 0;
      v8 = 256;
      if ( RtlAnsiStringToUnicodeString(&v7, v10, 0, 0) >= 0 )
        ZwSetValueKey();
      sprintf_s((int)v20, 128, (int)"%s %s", "Multiprocessor", "Free");
      RtlInitAnsiString((unsigned int)v10, (unsigned int)v20);
      v9 = v21;
      v7 = 0;
      v8 = 256;
      if ( RtlAnsiStringToUnicodeString(&v7, v10, 0, 0) >= 0 )
      {
        ZwSetValueKey();
        if ( (_WORD)CmCSDVersionString )
          return sub_80B344(v6, &CmpCsdVersionString);
        ZwDeleteValueKey();
      }
      if ( CmNtSpBuildNumber )
      {
        sprintf_s((int)v20, 128, (int)"%u", CmNtSpBuildNumber);
        RtlInitAnsiString((unsigned int)v10, (unsigned int)v20);
        v9 = v21;
        v7 = 0;
        v8 = 256;
        if ( RtlAnsiStringToUnicodeString(&v7, v10, 0, 0) < 0 )
          ZwSetValueKey();
      }
      else
      {
        ZwDeleteValueKey();
      }
      ZwSetValueKey();
      ZwClose();
      v5 = v0[2];
      v0 += 2;
      if ( !v5 )
        goto LABEL_21;
    }
  }
  else
  {
LABEL_21:
    if ( dword_63285C )
      ExFreePool(dword_63285C);
    RtlInitUnicodeString((unsigned int)&CmCSDVersionString, 0);
  }
  return ExFreePoolWithTag(v1);
}
