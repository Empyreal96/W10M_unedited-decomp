// PiSwIrpStartCreate 
 
int __fastcall PiSwIrpStartCreate(int a1, int a2)
{
  int v2; // r6
  int v3; // r5
  int v4; // r4
  int _30; // [sp+30h] [bp+8h]

  v2 = a1;
  _30 = a1;
  v3 = a1;
  if ( *(_DWORD *)(a1 + 12) )
  {
    if ( *(_DWORD *)(*(_DWORD *)(a1 + 96) + 8) >= 0xC8u )
    {
      v4 = MesDecodeBufferHandleCreate_0();
      if ( v4 >= 0 )
      {
        NdrMesTypeDecode2_0();
        v4 = PiSwIrpStartCreateWorker(0, v2);
        v3 = 0;
      }
    }
    else
    {
      v4 = -1073741789;
    }
  }
  else
  {
    v4 = -1073741811;
  }
  if ( v3 )
  {
    *(_DWORD *)(v3 + 24) = v4;
    *(_DWORD *)(v3 + 28) = 0;
    IofCompleteRequest(v3, 0);
  }
  return v4;
}
