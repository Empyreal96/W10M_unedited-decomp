// PnpCollectOpenHandlesCallBack 
 
int __fastcall PnpCollectOpenHandlesCallBack(const void *a1, int a2, const void *a3, int a4, int a5)
{
  if ( *(_BYTE *)(a5 + 20) )
    IopDebugPrint(
      20,
      (int)"  DeviceObject:%p ProcessID:%dT FileObject:%p Handle:%dT\n",
      a1,
      *(_DWORD *)(a2 + 176),
      a3,
      a4);
  if ( *(_BYTE *)(a5 + 21) )
    PnpAddVetoInformation(*(_DWORD **)a5, (_DWORD *)(a5 + 8), *(_DWORD *)(a2 + 176));
  ++*(_DWORD *)(a5 + 16);
  return 0;
}
