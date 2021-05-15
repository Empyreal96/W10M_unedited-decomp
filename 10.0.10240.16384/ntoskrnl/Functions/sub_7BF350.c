// sub_7BF350 
 
void sub_7BF350()
{
  int v0; // r4
  int v1; // r5

  EtwWrite(v1, v0, (int)POP_ETW_EVENT_CS_ENTER_REASON, 0);
  JUMPOUT(0x6A3634);
}
