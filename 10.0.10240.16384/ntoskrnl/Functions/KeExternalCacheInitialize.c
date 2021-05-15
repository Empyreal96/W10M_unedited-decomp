// KeExternalCacheInitialize 
 
int KeExternalCacheInitialize()
{
  int result; // r0
  int v1; // [sp-4h] [bp-30h] BYREF
  char v2[40]; // [sp+4h] [bp-28h] BYREF

  result = off_617B54(32, 16, v2, &v1);
  if ( result >= 0 )
    result = sub_555BB4();
  return result;
}
