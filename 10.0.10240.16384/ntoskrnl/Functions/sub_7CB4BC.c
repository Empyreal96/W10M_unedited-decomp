// sub_7CB4BC 
 
void sub_7CB4BC()
{
  int v0; // r4
  int *v1; // r6

  PnpRaiseNtPlugPlayDevicePropertyChangeEvent(*v1, *(_DWORD *)(v0 + 24), 28);
  JUMPOUT(0x76CCEA);
}
