// PiAuFreeUserSids 
 
int __fastcall PiAuFreeUserSids(unsigned int *a1)
{
  unsigned int v2; // r0
  unsigned int v3; // r0
  unsigned int v4; // r0
  unsigned int v5; // r0
  unsigned int v6; // r0
  unsigned int v7; // r0
  unsigned int v8; // r0

  v2 = *a1;
  if ( v2 )
    ExFreePoolWithTag(v2);
  v3 = a1[1];
  if ( v3 )
    ExFreePoolWithTag(v3);
  v4 = a1[2];
  if ( v4 )
    ExFreePoolWithTag(v4);
  v5 = a1[3];
  if ( v5 )
    ExFreePoolWithTag(v5);
  v6 = a1[4];
  if ( v6 )
    ExFreePoolWithTag(v6);
  v7 = a1[5];
  if ( v7 )
    ExFreePoolWithTag(v7);
  v8 = a1[6];
  if ( v8 )
    ExFreePoolWithTag(v8);
  return 0;
}
