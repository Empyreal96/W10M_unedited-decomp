// IopSetDeviceSecurityDescriptors 
 
int __fastcall IopSetDeviceSecurityDescriptors(int a1, int a2, _DWORD *a3, int a4)
{
  int v7; // r6
  int v8; // r5
  int v9; // r0
  int v10; // r4

  v7 = a2;
  v8 = 0;
  ObfReferenceObject(a2);
  do
  {
    v9 = IopSetDeviceSecurityDescriptor(v7, a3, a4);
    if ( v7 == a1 )
      v8 = v9;
    v10 = *(_DWORD *)(v7 + 16);
    if ( v10 )
      ObfReferenceObject(*(_DWORD *)(v7 + 16));
    ObfDereferenceObject(v7);
    v7 = v10;
  }
  while ( v10 );
  return v8;
}
