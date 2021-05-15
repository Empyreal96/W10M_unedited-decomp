// sub_50CEC0 
 
void sub_50CEC0()
{
  int v0; // r5
  int v1; // r6

  EtwTraceAutoBoostClearFloor(v1, *(_DWORD *)(v0 + 16) & 0xFFFFFFFC | 0x80000000, *(_WORD *)(v0 + 44));
  JUMPOUT(0x482384);
}
