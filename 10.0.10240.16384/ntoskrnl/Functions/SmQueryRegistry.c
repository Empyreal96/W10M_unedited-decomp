// SmQueryRegistry 
 
int __fastcall SmQueryRegistry(int a1)
{
  int v2[16]; // [sp+8h] [bp-40h] BYREF

  v2[0] = 0;
  v2[1] = 32;
  v2[2] = (int)L"EnableDirtyStores";
  v2[3] = a1 + 5952;
  v2[4] = 4;
  v2[5] = 0;
  v2[6] = 0;
  v2[7] = 0;
  v2[8] = 0;
  v2[9] = 0;
  v2[10] = 0;
  v2[11] = 0;
  v2[12] = 0;
  v2[13] = 0;
  RtlQueryRegistryValuesEx(
    0,
    (int)L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Session Manager\\Memory Management\\StoreParameters",
    (int)v2,
    0);
  return 0;
}
