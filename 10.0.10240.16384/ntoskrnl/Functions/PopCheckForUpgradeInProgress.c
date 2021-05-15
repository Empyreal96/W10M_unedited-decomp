// PopCheckForUpgradeInProgress 
 
int PopCheckForUpgradeInProgress()
{
  int result; // r0
  int v1; // r4
  char v2[8]; // [sp+10h] [bp-48h] BYREF
  int v3; // [sp+18h] [bp-40h]
  int v4; // [sp+1Ch] [bp-3Ch]
  char *v5; // [sp+20h] [bp-38h]
  int v6; // [sp+24h] [bp-34h]
  int v7; // [sp+28h] [bp-30h]
  int v8; // [sp+2Ch] [bp-2Ch]
  int v9; // [sp+3Ch] [bp-1Ch]
  int v10; // [sp+40h] [bp-18h]
  int v11; // [sp+44h] [bp-14h]

  RtlInitUnicodeString((unsigned int)v2, L"\\Registry\\Machine\\System\\Setup");
  v3 = 24;
  v4 = 0;
  v6 = 576;
  v5 = v2;
  v7 = 0;
  v8 = 0;
  result = ZwOpenKey();
  if ( result >= 0 )
  {
    RtlInitUnicodeString((unsigned int)v2, L"SystemSetupInProgress");
    v1 = ZwQueryValueKey();
    result = ZwClose();
    if ( v1 >= 0 && v9 == 4 && v10 == 4 && v11 == 1 )
      result = sub_966AB0(result);
  }
  return result;
}
