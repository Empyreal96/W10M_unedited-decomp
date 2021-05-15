// SmKmRegParamsLoad 
 
int __fastcall SmKmRegParamsLoad(_DWORD *a1)
{
  int result; // r0
  int v3; // [sp-4h] [bp-70h]
  unsigned int v4; // [sp+4h] [bp-68h] BYREF
  int v5; // [sp+8h] [bp-64h] BYREF
  int v6[24]; // [sp+Ch] [bp-60h] BYREF

  v6[0] = 0;
  v6[1] = 32;
  v6[2] = (int)L"EncryptionMode";
  v6[3] = (int)&v5;
  v6[4] = 4;
  v6[5] = 0;
  v6[6] = 0;
  v6[7] = 0;
  v6[8] = 32;
  v6[9] = (int)L"EncryptionScope";
  v6[10] = (int)&v4;
  v6[11] = 4;
  *a1 = 0;
  a1[1] = 0;
  v6[12] = 0;
  v6[13] = 0;
  v6[14] = 0;
  v6[15] = 0;
  v6[16] = 0;
  v6[17] = 0;
  v6[18] = 0;
  v6[19] = 0;
  v6[20] = 0;
  *a1 = 16;
  a1[1] &= 0xFFFFFFFC;
  v4 = 0;
  v5 = 0;
  result = RtlpQueryRegistryValues(
             0,
             L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Session Manager\\Memory Management\\StoreParameters",
             v6,
             0,
             v3,
             1u);
  if ( result >= 0 )
  {
    if ( v5 == 1 )
      *a1 *= 2;
    if ( v4 < 3 )
      a1[1] = a1[1] & 0xFFFFFFFC | v4 & 3;
  }
  else if ( result != -1073741772 )
  {
    return result;
  }
  return 0;
}
