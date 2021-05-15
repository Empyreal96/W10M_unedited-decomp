// PiProcessRequeryDeviceState 
 
int __fastcall PiProcessRequeryDeviceState(int a1, int a2)
{
  int *v2; // r0
  int v3; // r3

  v2 = *(int **)(a1 + 8);
  v3 = *(_DWORD *)(v2[44] + 20);
  if ( *(_DWORD *)(v3 + 172) != 776 )
    return sub_819EC0();
  PiProcessQueryDeviceState(v2, a2, 776, v3);
  return 0;
}
