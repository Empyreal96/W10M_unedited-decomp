// IoInvalidateDeviceState 
 
int __fastcall IoInvalidateDeviceState(int result)
{
  int v1; // r2

  if ( !result )
    JUMPOUT(0x51FEB0);
  v1 = *(_DWORD *)(*(_DWORD *)(result + 176) + 20);
  if ( !v1 || (*(_DWORD *)(v1 + 268) & 0x20000) != 0 )
    sub_51FE10();
  if ( *(_DWORD *)(v1 + 172) == 776 )
    result = PnpRequestDeviceAction();
  return result;
}
