// PopReadHiberbootPolicy 
 
int __fastcall PopReadHiberbootPolicy(char *a1)
{
  char v2; // r4
  int result; // r0
  char v4[4]; // [sp+8h] [bp-38h] BYREF
  int v5; // [sp+Ch] [bp-34h] BYREF
  char v6[8]; // [sp+18h] [bp-28h] BYREF
  char v7[20]; // [sp+20h] [bp-20h] BYREF

  v2 = 0;
  result = PopReadHiberbootGroupPolicy(v4);
  if ( result < 0 )
  {
    result = PopOpenPowerKey((int)&v5);
    if ( result >= 0 )
    {
      RtlInitUnicodeString((unsigned int)v6, L"HiberbootEnabled");
      memset(v7, 0, sizeof(v7));
      if ( ZwQueryValueKey() >= 0 )
        v2 = v7[12];
      result = ZwClose();
    }
  }
  else
  {
    v2 = v4[0];
  }
  *a1 = v2;
  return result;
}
