// VfHalAllocateMapRegisters 
 
int __fastcall VfHalAllocateMapRegisters(int a1, unsigned int a2, int a3, int *a4)
{
  int v8; // r4
  int v9; // r6
  int v10; // r0

  if ( !VfRealHalAllocateMapRegisters )
    return -1073741823;
  v8 = VfRealHalAllocateMapRegisters();
  if ( v8 >= 0 )
  {
    v9 = ViGetAdapterInformationInternal(a1, 1);
    if ( v9 )
    {
      for ( ; a3; --a3 )
      {
        if ( ViDoubleBufferDma && !*(_BYTE *)(v9 + 17) && (v10 = ViAllocateMapRegisterFile(v9, a2)) != 0 )
        {
          *(_DWORD *)(v10 + 28) = *a4;
          *a4 = v10;
        }
        else if ( !*a4 )
        {
          *a4 = -559026163;
        }
        ADD_MAP_REGISTERS(v9, a2, 1);
        a4 += 2;
      }
    }
  }
  return v8;
}
