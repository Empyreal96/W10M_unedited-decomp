// PipCheckForDenyExecute 
 
int __fastcall PipCheckForDenyExecute(unsigned __int16 *a1)
{
  unsigned __int16 *v2; // r4
  int v3; // r0
  unsigned __int16 *v5; // [sp+14h] [bp-34h] BYREF
  char v6[8]; // [sp+18h] [bp-30h] BYREF
  int v7; // [sp+20h] [bp-28h]
  int v8; // [sp+24h] [bp-24h]
  char *v9; // [sp+28h] [bp-20h]
  int v10; // [sp+2Ch] [bp-1Ch]
  int v11; // [sp+30h] [bp-18h]
  int v12; // [sp+34h] [bp-14h]

  v2 = 0;
  v5 = 0;
  if ( wcsicmp((int)L"{53f5630d-b6bf-11d0-94f2-00a0c91efb8b}", a1) )
  {
    v3 = PnpConcatPWSTR(
           512,
           1198550608,
           &v5,
           3,
           L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Storage",
           L"\\",
           a1);
    v2 = v5;
    if ( v3 >= 0 )
    {
      RtlInitUnicodeString((unsigned int)v6, v5);
      v7 = 24;
      v8 = 0;
      v10 = 576;
      v9 = v6;
      v11 = 0;
      v12 = 0;
      if ( ZwOpenKey() >= 0 )
        return sub_7C8F78();
    }
  }
  if ( v2 )
    ExFreePoolWithTag((unsigned int)v2);
  return 0;
}
