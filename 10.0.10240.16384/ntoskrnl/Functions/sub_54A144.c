// sub_54A144 
 
void sub_54A144()
{
  int v0; // r4
  int v1; // r5
  int v2; // r6
  int v3; // r7
  int v4; // r9

  if ( v4 )
    EtwTraceAutoBoostSetFloor(v1, *(_DWORD *)(v3 + 16) & 0xFFFFFFFC | 0x80000000, v2, v0);
  JUMPOUT(0x4CC8C2);
}
