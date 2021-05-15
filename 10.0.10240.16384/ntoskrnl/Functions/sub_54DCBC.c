// sub_54DCBC 
 
void sub_54DCBC()
{
  int v0; // r5
  int v1; // r0
  int v2; // r2
  int v3; // r4

  v1 = RtlImageNtHeader(v0 & 0xFFFFFFFC);
  if ( v1 )
  {
    v2 = *(unsigned __int16 *)(v1 + 24);
    if ( v2 == 267 || v2 == 523 )
      v3 = *(_DWORD *)(v1 + 80);
    else
      v3 = 0;
    if ( v3 )
      JUMPOUT(0x4E444C);
  }
  JUMPOUT(0x4E4466);
}
