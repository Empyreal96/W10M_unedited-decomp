// sub_50EC80 
 
void sub_50EC80()
{
  int v0; // r5
  int v1; // r6
  int v2; // r8
  int v3; // r10

  if ( v3 != 32 )
    EtwTraceAutoBoostSetFloor(v2, *(_DWORD *)(v0 + 16) & 0x7FFFFFFC | 0x80000000, v1, 0);
  JUMPOUT(0x4CC524);
}
