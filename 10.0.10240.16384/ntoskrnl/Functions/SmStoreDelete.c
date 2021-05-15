// SmStoreDelete 
 
int __fastcall SmStoreDelete(int result, int a2)
{
  char v2[8]; // [sp+8h] [bp-28h] BYREF
  int v3[8]; // [sp+10h] [bp-20h] BYREF

  v3[1] = a2;
  v3[2] = 1;
  v3[3] = 4;
  v3[4] = (int)v3;
  v3[5] = 8;
  v3[0] = 1;
  if ( !result )
    return SmStorePhysicalRequestIssue(dword_636C98, 2261404, v3, 8, 0, v2);
  if ( result == 1 )
    result = ZwSetSystemInformation();
  return result;
}
