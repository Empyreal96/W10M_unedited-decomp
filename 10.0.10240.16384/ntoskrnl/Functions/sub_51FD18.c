// sub_51FD18 
 
void sub_51FD18()
{
  _DWORD *v0; // r5
  int v1; // r3
  _DWORD *v2; // r7

  while ( 1 )
  {
    v1 = v0[67];
    v2 = (_DWORD *)*v0;
    if ( (v1 & 0x10) != 0 )
      v0[67] = v1 & 0xFFFFFFEF;
    if ( v0[71] || v0[90] || (v0[67] & 0x40) != 0 )
    {
      IopRemoveDevice(v0[4], 2);
      IopReleaseDeviceResources(v0, 0);
    }
    PipSetDevNodeState(v0, 788);
    v0 = v2;
    if ( !v2 )
      JUMPOUT(0x4DB072);
  }
}
