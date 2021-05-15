// sub_7BF17C 
 
void sub_7BF17C()
{
  int v0; // r4
  int v1; // r5

  EtwWrite(v1, v0, (int)POP_ETW_EVENT_CLOSE_POWER_REQUEST, 0);
  JUMPOUT(0x6A2918);
}
