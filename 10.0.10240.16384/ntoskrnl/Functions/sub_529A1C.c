// sub_529A1C 
 
void sub_529A1C()
{
  int v0; // r4
  int v1; // r5
  int v2; // r6
  int *v3; // r2

  if ( v0 )
    v3 = POP_ETW_EVENT_SYSTEM_LATENCY_RUNDOWN;
  else
    v3 = POP_ETW_EVENT_SYSTEM_LATENCY_UPDATE;
  EtwWrite(v2, v1, (int)v3, 0);
  JUMPOUT(0x46765C);
}
