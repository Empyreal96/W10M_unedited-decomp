// sub_54B0C8 
 
void sub_54B0C8()
{
  int v0; // r4
  int v1; // r5

  EtwWrite(v1, v0, (int)POP_ETW_EVENT_IRP_DRIVERRELEASE, 0);
  JUMPOUT(0x4D2558);
}
