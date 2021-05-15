// sub_525AD0 
 
void sub_525AD0()
{
  int v0; // r4
  int v1; // r5

  EtwWrite(v1, v0, (int)PPM_ETW_LATENCY_SENSITIVITY_HINT, 0);
  JUMPOUT(0x45FE2C);
}
