// sub_80D384 
 
void sub_80D384()
{
  _DWORD *v0; // r4
  unsigned int v1; // r0
  unsigned int v2; // r0
  unsigned int v3; // r0
  unsigned int v4; // r0
  unsigned int v5; // r0

  v1 = v0[1];
  if ( v1 )
    ExFreePoolWithTag(v1);
  v2 = v0[37];
  if ( v2 )
    ExFreePoolWithTag(v2);
  v3 = v0[5];
  if ( v3 )
    ExFreePoolWithTag(v3);
  v4 = v0[6];
  if ( v4 )
    ExFreePoolWithTag(v4);
  v5 = v0[14];
  if ( v5 )
    ExFreePoolWithTag(v5);
  JUMPOUT(0x794546);
}
