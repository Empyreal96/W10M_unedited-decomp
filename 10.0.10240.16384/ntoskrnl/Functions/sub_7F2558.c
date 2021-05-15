// sub_7F2558 
 
void sub_7F2558()
{
  int v0; // r4
  int v1; // r5

  EtwWrite(v1, v0, (int)POP_ETW_EVENT_CONSOLE_DISPLAY_STATE, 0);
  JUMPOUT(0x708898);
}
