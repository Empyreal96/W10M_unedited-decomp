// RtlCheckPortableOperatingSystem 
 
int RtlCheckPortableOperatingSystem()
{
  int result; // r0
  int v1; // r4
  int v2; // [sp+8h] [bp-48h] BYREF
  int v3[16]; // [sp+10h] [bp-40h] BYREF

  v2 = 0;
  if ( RtlCheckRegistryKey(2, L"MiniNT") >= 0 )
    goto LABEL_2;
  memset(v3, 0, 56);
  v3[1] = 36;
  v3[2] = (int)L"PortableOperatingSystem";
  v3[3] = (int)&v2;
  v1 = RtlQueryRegistryValuesEx(2, 0, v3);
  if ( v1 == -1073741772 )
    v1 = -1073741275;
  if ( v1 >= 0 )
LABEL_2:
    result = sub_550BF0();
  else
    result = v1;
  return result;
}
