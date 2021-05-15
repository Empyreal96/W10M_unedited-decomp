// sub_529728 
 
void sub_529728()
{
  int v0; // r4
  int v1; // r5

  EtwWrite(v1, v0, (int)POP_ETW_EVENT_SETSYSTEMSTATE, 0);
  JUMPOUT(0x466C38);
}
