// sub_8DFBAC 
 
void sub_8DFBAC()
{
  int v0; // r5
  int *v1; // r6
  int v2; // r0

  v1 = *(int **)(v0 + 64);
  if ( v1 )
  {
    if ( *v1 )
      BgpFwFreeMemory(*v1);
    v2 = v1[3];
    if ( v2 )
      BgpFwFreeMemory(v2);
    BgpFwFreeMemory((int)v1);
  }
  BgpFwFreeMemory(v0);
  JUMPOUT(0x8DE134);
}
