// sub_5508D0 
 
void sub_5508D0()
{
  int v0; // r4
  int v1; // r5
  int v2; // r6
  int v3; // r7
  int v4; // r9

  if ( !InbvIsBootDriverInstalled() || v0 != 3 && v0 != 5 )
  {
    ExFreePoolWithTag(*(_DWORD *)(v2 - 4), 0);
    *(_DWORD *)(v2 - 4) = v4;
    *(_DWORD *)(v1 + v3) = v4;
  }
  JUMPOUT(0x4EC98C);
}
