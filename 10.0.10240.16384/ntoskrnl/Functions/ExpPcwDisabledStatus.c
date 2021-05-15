// ExpPcwDisabledStatus 
 
int ExpPcwDisabledStatus()
{
  int v0; // r3
  int result; // r0
  int v2; // [sp+0h] [bp-50h]
  int v3; // [sp+8h] [bp-48h] BYREF
  int v4; // [sp+Ch] [bp-44h] BYREF
  int v5[7]; // [sp+10h] [bp-40h] BYREF
  char v6[28]; // [sp+2Ch] [bp-24h] BYREF

  v0 = ExpPcwEnableState;
  if ( ExpPcwEnableState )
  {
LABEL_9:
    if ( v0 == 1 )
      result = 0;
    else
      result = -1073741822;
    return result;
  }
  v3 = -1;
  v5[0] = 0;
  v5[1] = 288;
  v5[2] = (int)L"Start";
  v5[3] = (int)&v4;
  v5[4] = 67108868;
  v5[5] = (int)&v3;
  v5[6] = 4;
  memset(v6, 0, sizeof(v6));
  result = RtlpQueryRegistryValues(1, L"pcw", v5, 0, v2, 1u);
  if ( result == -1073741772 )
    result = 0;
  if ( result >= 0 )
  {
    if ( v4 )
      v0 = 1;
    else
      v0 = 2;
    ExpPcwEnableState = v0;
    goto LABEL_9;
  }
  return result;
}
