// PiDqIrpPropertySet 
 
int __fastcall PiDqIrpPropertySet(int a1, int a2)
{
  int v2; // r4
  int v4; // [sp+30h] [bp-30h]

  v4 = a1;
  if ( *(_DWORD *)(a1 + 12) )
  {
    v2 = MesDecodeBufferHandleCreate_0();
    if ( v2 >= 0 )
    {
      NdrMesTypeDecode2_0();
      v2 = -1073741811;
    }
  }
  else
  {
    v2 = -1073741811;
  }
  *(_DWORD *)(v4 + 24) = v2;
  IofCompleteRequest(v4, 0);
  return v2;
}
