// PopSetHiberFileSize 
 
int __fastcall PopSetHiberFileSize(unsigned int a1, __int64 *a2)
{
  int v3; // r6
  __int64 v4; // kr00_8
  int v5; // r5
  __int64 v7; // [sp+8h] [bp-28h] BYREF
  char v8[32]; // [sp+10h] [bp-20h] BYREF

  if ( a1 > 0x64 )
    return -1073741811;
  v3 = PopHiberFileSizePercent;
  PopHiberFileSizePercent = a1;
  PopCalculateHiberFileSize(&v7, 0);
  v4 = v7;
  v5 = PopValidateHiberFileSize(v7, HIDWORD(v7), 0);
  if ( v5 < 0
    || (unsigned int)PopHiberFileSizePercent >= 0x28 && (v5 = PopSetHiberFileType(2, 0), v5 < 0)
    || (v5 = PopOpenKey(&v7, L"Control\\Power"), v5 < 0)
    || (RtlInitUnicodeString((unsigned int)v8, L"HiberFileSizePercent"), v5 = ZwSetValueKey(), ZwClose(), v5 < 0) )
  {
    PopHiberFileSizePercent = v3;
  }
  else if ( a2 )
  {
    *a2 = v4;
  }
  return v5;
}
