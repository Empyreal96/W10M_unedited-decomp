// sub_812588 
 
void sub_812588()
{
  int v0; // r4
  int v1; // r5

  EtwWrite(v1, v0, (int)POP_ETW_EVENT_DEVICE_START_POWER_MANAGEMENT, 0);
  JUMPOUT(0x7A2F40);
}
