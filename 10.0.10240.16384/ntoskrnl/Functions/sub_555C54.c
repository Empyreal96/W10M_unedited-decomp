// sub_555C54 
 
void sub_555C54()
{
  int v0; // r4
  int v1; // r5

  EtwWrite(v1, v0, (int)POP_ETW_EVENT_ENERGY_SAVER_STATE, 0);
  JUMPOUT(0x4F90BE);
}
