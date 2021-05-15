// sub_7EFF58 
 
void sub_7EFF58()
{
  int v0; // r4
  int v1; // r5
  int v2; // r6
  int *v3; // r7
  int v4; // r8
  int v5; // r9

  if ( v0 != -1073741275 || PnpSetObjectProperty(*v3, v2, 5, 0, v4, v1, 7, (int)&unconfiguredConfigFlags, v5, v4) >= 0 )
    ZwUpdateWnfStateData();
  JUMPOUT(0x78BB9C);
}
