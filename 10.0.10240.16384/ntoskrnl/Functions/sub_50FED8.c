// sub_50FED8 
 
void sub_50FED8()
{
  _BYTE *v0; // r4

  PopThermalStandbyNotify(1);
  v0[1] = 1;
  *v0 = 0;
  JUMPOUT(0x426464);
}
