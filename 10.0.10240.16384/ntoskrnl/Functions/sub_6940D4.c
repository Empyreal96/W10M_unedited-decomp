// sub_6940D4 
 
void sub_6940D4()
{
  _DWORD *v0; // r5
  int v1; // r2

  KeInitializeGate((int)(v0 + 448));
  KiInitializeDpcList(v0 + 426);
  v0[428] = v1;
  v0[429] = v1;
  JUMPOUT(0x6939A0);
}
