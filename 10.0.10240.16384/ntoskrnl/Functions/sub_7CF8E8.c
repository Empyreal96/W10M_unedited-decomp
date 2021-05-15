// sub_7CF8E8 
 
void sub_7CF8E8()
{
  int v0; // r4
  int v1; // r5
  _DWORD *v2; // r6
  int v3; // r7
  int v4; // r8

  if ( v2 && (*v2 & 1) != 0 && !v4 )
    EtwpTraceProcessRundown(v1, v0, (int *)0x327, v3);
  JUMPOUT(0x7890A2);
}
