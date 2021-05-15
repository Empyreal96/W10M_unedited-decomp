// PspIsDfssEnabled 
 
int PspIsDfssEnabled()
{
  int v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // [sp+8h] [bp-40h]
  int v4[15]; // [sp+Ch] [bp-3Ch] BYREF

  v4[5] = 0;
  v4[6] = 0;
  v4[1] = 24;
  v4[2] = 0;
  v4[3] = (int)&PspQuotaKeyNames;
  v4[4] = 576;
  if ( ZwOpenKey() < 0 || (v0 = RtlQueryImageFileKeyOption(v3, L"EnableCpuQuota", 4, v4, 4u, 0), v1 = ZwClose(), v0 < 0) )
    result = 0;
  else
    result = sub_80BB70(v1);
  return result;
}
