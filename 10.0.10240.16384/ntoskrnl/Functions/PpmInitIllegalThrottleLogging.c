// PpmInitIllegalThrottleLogging 
 
int PpmInitIllegalThrottleLogging()
{
  int result; // r0
  int v1; // [sp+8h] [bp-30h] BYREF
  char v2[8]; // [sp+10h] [bp-28h] BYREF
  char v3[20]; // [sp+18h] [bp-20h] BYREF

  result = PopOpenKey(&v1, L"Control\\Session Manager\\Power", 131103);
  if ( result >= 0 )
  {
    RtlInitUnicodeString((unsigned int)v2, L"ProcessorThrottleLogInterval");
    memset(v3, 0, sizeof(v3));
    if ( ZwQueryValueKey() < 0 )
      result = ZwClose();
    else
      result = sub_528EB4();
  }
  return result;
}
