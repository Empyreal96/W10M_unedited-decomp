// sub_818230 
 
void sub_818230()
{
  int v0; // r4
  int *v1; // r6

  PnpRaiseNtPlugPlayDevicePropertyChangeEvent(*v1, *(_DWORD *)(v0 + 24), 29);
  JUMPOUT(0x7B2160);
}
