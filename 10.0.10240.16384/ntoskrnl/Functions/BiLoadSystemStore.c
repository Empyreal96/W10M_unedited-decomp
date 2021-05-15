// BiLoadSystemStore 
 
int BiLoadSystemStore()
{
  int v0; // r4
  unsigned int v2[6]; // [sp+0h] [bp-18h] BYREF

  v2[0] = 0;
  v0 = BiGetSystemStorePath(v2);
  if ( v0 >= 0 )
    return sub_812C24();
  if ( v2[0] )
    ExFreePoolWithTag(v2[0]);
  return v0;
}
