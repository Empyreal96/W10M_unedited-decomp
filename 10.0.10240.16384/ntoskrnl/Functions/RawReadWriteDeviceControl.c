// RawReadWriteDeviceControl 
 
int __fastcall RawReadWriteDeviceControl(int a1, int a2, unsigned __int8 *a3)
{
  int v4; // r2
  int v8; // r3
  int v9; // r4
  int v10; // r2

  v4 = *(_DWORD *)(a1 + 148);
  if ( !v4 || *((_DWORD *)a3 + 7) != v4 )
    return sub_7CFC2C();
  v8 = *a3;
  if ( v8 == 4 || v8 == 3 )
    JUMPOUT(0x7CFCE2);
  v9 = *(_DWORD *)(a2 + 96);
  memmove(v9 - 40, (int)a3, 0x28u);
  *(_BYTE *)(v9 - 38) |= 2u;
  v10 = *(_DWORD *)(a2 + 96);
  *(_DWORD *)(v10 - 8) = RawCompletionRoutine;
  *(_DWORD *)(v10 - 4) = a1;
  *(_BYTE *)(v10 - 37) = -32;
  return IofCallDriver(*(_DWORD *)(a1 + 136), a2);
}
