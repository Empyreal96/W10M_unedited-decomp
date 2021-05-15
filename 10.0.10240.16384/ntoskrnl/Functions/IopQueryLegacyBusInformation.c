// IopQueryLegacyBusInformation 
 
int __fastcall IopQueryLegacyBusInformation(int a1)
{
  int result; // r0
  int v3; // [sp+8h] [bp-40h] BYREF
  char v4[56]; // [sp+10h] [bp-38h] BYREF

  v3 = 0;
  memset(v4, 0, 40);
  v4[0] = 27;
  v4[1] = 24;
  result = IopSynchronousCall(a1, (int)v4, -1073741637, 0, &v3);
  if ( result >= 0 )
    result = sub_7EFAAC();
  return result;
}
