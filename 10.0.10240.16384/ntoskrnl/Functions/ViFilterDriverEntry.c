// ViFilterDriverEntry 
 
int __fastcall ViFilterDriverEntry(_DWORD *a1)
{
  int v1; // r2
  int (__fastcall **v2)(int, int); // r3

  v1 = a1[6];
  VfFilterDriverObject = (int)a1;
  *(_DWORD *)(v1 + 4) = ViFilterAddDevice;
  v2 = (int (__fastcall **)(int, int))(a1 + 14);
  do
    *v2++ = ViFilterDispatchGeneric;
  while ( v2 != a1 + 42 );
  a1[41] = ViFilterDispatchPnp;
  a1[36] = ViFilterDispatchPower;
  return 0;
}
