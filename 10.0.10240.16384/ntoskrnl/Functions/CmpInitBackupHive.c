// CmpInitBackupHive 
 
int __fastcall CmpInitBackupHive(_DWORD *a1, unsigned __int16 *a2)
{
  __int16 v5[2]; // [sp+20h] [bp-C0h] BYREF
  char *v6; // [sp+24h] [bp-BCh]
  char v7[8]; // [sp+28h] [bp-B8h] BYREF
  int v8; // [sp+30h] [bp-B0h]
  int v9; // [sp+34h] [bp-ACh]
  __int16 *v10; // [sp+38h] [bp-A8h]
  int v11; // [sp+3Ch] [bp-A4h]
  int v12; // [sp+40h] [bp-A0h]
  int v13; // [sp+44h] [bp-9Ch]
  char v14; // [sp+50h] [bp-90h] BYREF

  if ( CmpSpecialBootCondition && CmpAdminSystemFileSecurityDescriptor && a1[444] )
  {
    if ( ZwSetSecurityObject() < 0 )
      sub_80B030();
    if ( a1[448] )
      ZwSetSecurityObject();
    if ( a1[449] )
      ZwSetSecurityObject();
    if ( a1[445] )
      ZwSetSecurityObject();
  }
  v5[1] = 128;
  v5[0] = 0;
  v6 = &v14;
  RtlInitUnicodeString((unsigned int)v7, L"\\SystemRoot\\System32\\Config\\RegBack\\");
  RtlAppendStringToString(v5, v7);
  RtlInitUnicodeString((unsigned int)v7, a2);
  RtlAppendStringToString(v5, v7);
  v8 = 24;
  v9 = 0;
  v11 = 576;
  v10 = v5;
  v12 = CmpAdminSystemFileSecurityDescriptor;
  v13 = 0;
  return ZwCreateFile();
}
