// sub_8114F8 
 
void __fastcall sub_8114F8(int a1, int a2, int a3, int a4)
{
  int *v4; // r5
  int v5; // r1

  v5 = *(_DWORD *)(a4 + 24);
  if ( v5 )
    PnpRaiseNtPlugPlayDevicePropertyChangeEvent(*v4, v5, 25);
  JUMPOUT(0x7A1212);
}
