// PiSwIrpInterfacePropertySet 
 
int __fastcall PiSwIrpInterfacePropertySet(_DWORD *a1, int a2, int a3, int a4)
{
  int v5; // r4
  _DWORD *v7; // [sp+8h] [bp-20h]
  int v8; // [sp+Ch] [bp-1Ch]
  int v9; // [sp+10h] [bp-18h]
  int v10; // [sp+14h] [bp-14h]
  _DWORD *anonymous4; // [sp+30h] [bp+8h]
  int anonymous5; // [sp+34h] [bp+Ch]

  anonymous5 = a2;
  v7 = a1;
  v8 = a2;
  v9 = a3;
  v10 = a4;
  anonymous4 = a1;
  v9 = *(_DWORD *)(*(_DWORD *)(a1[24] + 28) + 16);
  v8 = 0;
  v7 = 0;
  if ( a1[3] )
  {
    v5 = MesDecodeBufferHandleCreate_0();
    if ( v5 >= 0 )
    {
      NdrMesTypeDecode2_0();
      v5 = -1073741811;
    }
  }
  else
  {
    v5 = -1073741811;
  }
  a1[6] = v5;
  IofCompleteRequest((int)a1, 0);
  return v5;
}
