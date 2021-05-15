// PopPluginRequestDeviceIdleConstraints 
 
int __fastcall PopPluginRequestDeviceIdleConstraints(int a1, int a2, int a3, int a4)
{
  int v6; // r2
  int v7; // r4
  int v10; // [sp+0h] [bp-20h] BYREF
  int v11; // [sp+4h] [bp-1Ch]
  int v12; // [sp+8h] [bp-18h]
  int v13; // [sp+Ch] [bp-14h]

  v10 = a1;
  v11 = a2;
  v12 = a3;
  v13 = a4;
  v6 = *(_DWORD *)(a1 + 36);
  v7 = 0;
  if ( v6 == PopFxProcessorPlugin )
  {
    v10 = *(_DWORD *)(a1 + 40);
    v11 = a2;
    v12 = a3;
    v7 = (*(int (__fastcall **)(int, int *))(v6 + 64))(26, &v10);
    if ( v7 )
      PopDiagTraceFxDeviceIdleConstraints(a1, a2, a3);
  }
  return v7;
}
