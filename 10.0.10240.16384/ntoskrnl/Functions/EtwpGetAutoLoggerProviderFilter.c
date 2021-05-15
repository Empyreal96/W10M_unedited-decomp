// EtwpGetAutoLoggerProviderFilter 
 
int __fastcall EtwpGetAutoLoggerProviderFilter(unsigned __int16 *a1)
{
  unsigned int v2; // r5
  unsigned int v3; // r4
  unsigned int v4; // r4
  unsigned __int16 *v5; // r0
  unsigned __int16 *v6; // r6
  int result; // r0
  int *v8; // r5
  int v9; // r4
  unsigned int v10; // r0
  unsigned int v11; // t1
  int v12[2]; // [sp+Ch] [bp-280h] BYREF
  int v13; // [sp+14h] [bp-278h]
  int v14; // [sp+3Ch] [bp-250h]
  int v15; // [sp+40h] [bp-24Ch]
  char *v16; // [sp+44h] [bp-248h]
  int v17; // [sp+48h] [bp-244h]
  int v18; // [sp+4Ch] [bp-240h]
  int v19; // [sp+50h] [bp-23Ch]
  char v20[568]; // [sp+54h] [bp-238h] BYREF

  v2 = wcslen(a1);
  v3 = wcslen(L"\\");
  v4 = wcslen(L"Filters") + v3 + v2 + 1;
  v12[1] = 0;
  v13 = 0;
  v12[0] = 0;
  v5 = (unsigned __int16 *)ExAllocatePoolWithTag(1, 2 * v4, 1350005829);
  v6 = v5;
  if ( v5 )
  {
    if ( !RtlStringCbPrintfW(v5, 2 * v4, (int)L"%ws\\Filters", (int)a1) )
    {
      RtlInitUnicodeString((unsigned int)v20, v6);
      v14 = 24;
      v15 = 0;
      v17 = 576;
      v16 = v20;
      v18 = 0;
      v19 = 0;
      if ( ZwOpenKey() >= 0 )
        return sub_810F5C();
    }
  }
  v8 = v12;
  v9 = 2;
  do
  {
    v11 = *v8++;
    v10 = v11;
    if ( v11 )
      ExFreePoolWithTag(v10);
    --v9;
  }
  while ( v9 );
  result = v13;
  if ( v13 )
    result = ZwClose();
  if ( v6 )
    result = ExFreePoolWithTag((unsigned int)v6);
  return result;
}
