// ArbpGetRegistryValue 
 
int __fastcall ArbpGetRegistryValue(int a1, unsigned __int16 *a2, int *a3)
{
  int v4; // r0
  int v5; // r5
  int v8; // [sp+8h] [bp-20h]
  char v9[24]; // [sp+10h] [bp-18h] BYREF

  RtlInitUnicodeString((unsigned int)v9, a2);
  v4 = ZwQueryValueKey();
  if ( v4 != -2147483643 && v4 != -1073741789 )
    return -1073741823;
  v5 = ExAllocatePoolWithTag(1, v8, 1298297409);
  if ( !v5 )
    return -1073741670;
  if ( ZwQueryValueKey() < 0 )
    return sub_80E824();
  *a3 = v5;
  return 0;
}
