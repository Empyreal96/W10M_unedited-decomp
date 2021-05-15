// sub_7F5510 
 
void sub_7F5510()
{
  _DWORD *v0; // r5
  int v1; // r6

  MiInsertVadCharges((int)v0, v1);
  MiGetWsAndInsertVad(v0);
  JUMPOUT(0x7160A4);
}
