// PiSwIrpInterfaceRegister 
 
int __fastcall PiSwIrpInterfaceRegister(int a1, int a2)
{
  int v2; // r9
  int v3; // r4

  v2 = a1;
  if ( *(_DWORD *)(a1 + 12) )
  {
    v3 = MesDecodeBufferHandleCreate_0();
    if ( v3 >= 0 )
    {
      NdrMesTypeDecode2_0();
      v3 = -1073741811;
    }
  }
  else
  {
    v3 = -1073741811;
  }
  *(_DWORD *)(v2 + 24) = v3;
  IofCompleteRequest(v2, 0);
  return v3;
}
