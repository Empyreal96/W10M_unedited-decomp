// sub_7F229C 
 
void sub_7F229C()
{
  int v0; // r4
  int v1; // r5

  EtwWrite(v1, v0, (int)POP_ETW_ADPM_INPUT_TIMEOUT, 0);
  JUMPOUT(0x708370);
}
