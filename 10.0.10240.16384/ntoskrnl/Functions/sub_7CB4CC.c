// sub_7CB4CC 
 
void sub_7CB4CC()
{
  int v0; // r4
  int *v1; // r5

  PnpRaiseNtPlugPlayDevicePropertyChangeEvent(*v1, *(_DWORD *)(v0 + 24), 28);
  JUMPOUT(0x76CD4E);
}
