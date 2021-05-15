// sub_55133C 
 
void sub_55133C()
{
  int v0; // r5
  int v1; // r6

  EtwWrite(v1, v0, (int)POP_ETW_EVENT_DEVICE_IDLE_CONSTRAINTS, 0);
  JUMPOUT(0x4EE99E);
}
