// PopSaveHibernateEnabled 
 
int PopSaveHibernateEnabled()
{
  int result; // r0
  int v1; // r4
  int v2; // [sp+8h] [bp-18h] BYREF
  char v3[16]; // [sp+10h] [bp-10h] BYREF

  PopHiberEnabledReg = PopHiberEnabled != 0;
  result = PopOpenKey(&v2, L"Control\\Power");
  if ( result >= 0 )
  {
    RtlInitUnicodeString((unsigned int)v3, L"HibernateEnabled");
    v1 = v2;
    result = ZwSetValueKey();
    if ( v1 )
      result = ZwClose();
  }
  return result;
}
