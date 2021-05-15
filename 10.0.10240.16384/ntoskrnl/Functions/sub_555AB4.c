// sub_555AB4 
 
void sub_555AB4()
{
  int v0; // r4
  int v1; // r5

  EtwWrite(v1, v0, (int)POP_ETW_EVENT_TIME_RESOLUTION_UPDATE, 0);
  JUMPOUT(0x4F8B38);
}
