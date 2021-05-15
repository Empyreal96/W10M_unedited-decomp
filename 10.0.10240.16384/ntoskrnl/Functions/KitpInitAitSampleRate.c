// KitpInitAitSampleRate 
 
int __fastcall KitpInitAitSampleRate(int a1)
{
  _BYTE *v1; // r0
  BOOL v2; // r3
  int v3; // r1
  int result; // r0
  int v5; // [sp+0h] [bp-8h] BYREF
  int v6; // [sp+4h] [bp-4h]

  v5 = 0;
  v6 = 0;
  if ( a1 )
  {
    v1 = *(_BYTE **)(a1 + 120);
    v2 = v1 && strstr(v1, "SAFEBOOT:");
    if ( !v2 && KitpOpenRegKey() >= 0 && KitpReadUlongFromKey(v6, v3, &v5) < 0 )
      v5 = 0;
  }
  ZwSetSystemInformation();
  result = v6;
  if ( v6 )
    result = ZwClose();
  return result;
}
