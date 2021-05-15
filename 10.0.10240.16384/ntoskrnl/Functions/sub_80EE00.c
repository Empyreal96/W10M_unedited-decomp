// sub_80EE00 
 
void sub_80EE00()
{
  int v0; // r6
  _DWORD *v1; // r8
  _BYTE *v2; // r0
  _DWORD *v3; // r4

  v2 = (_BYTE *)ExAllocatePoolWithTag(1, 24, 1280468560);
  v3 = v2;
  if ( v2 )
  {
    memset(v2, 0, 24);
    v3[1] = v0;
    v3[2] = 0;
    v3[4] = 0;
    v3[5] = 0;
    *v1 = v3;
    JUMPOUT(0x798FEC);
  }
  JUMPOUT(0x798FF2);
}
