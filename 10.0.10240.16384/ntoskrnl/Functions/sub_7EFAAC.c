// sub_7EFAAC 
 
void __fastcall sub_7EFAAC(int a1, int a2, int a3, int a4, int a5, int a6, unsigned int a7)
{
  _DWORD *v7; // r4
  _DWORD *v8; // r5
  int v9; // r6
  int v10; // r3
  int v11; // r2

  if ( a7 )
  {
    if ( v8 )
      *v8 = *(_DWORD *)(a7 + 16);
    if ( v7 )
      *v7 = *(_DWORD *)(a7 + 20);
    ExFreePoolWithTag(a7);
  }
  else
  {
    v10 = *(_DWORD *)(*(_DWORD *)(v9 + 176) + 20);
    if ( v10 )
    {
      v11 = *(_DWORD *)(v10 + 8);
      if ( v11 )
      {
        if ( *(_DWORD *)(v11 + 32) )
        {
          DbgPrint("*** IopQueryLegacyBusInformation - Driver %wZ returned STATUS_SUCCESS\n", v11 + 28);
          DbgPrint("    for IRP_MN_QUERY_LEGACY_BUS_INFORMATION, and a NULL POINTER.\n");
        }
      }
    }
  }
  JUMPOUT(0x78452E);
}
