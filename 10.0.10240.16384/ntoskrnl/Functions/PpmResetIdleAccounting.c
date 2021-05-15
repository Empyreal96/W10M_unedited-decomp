// PpmResetIdleAccounting 
 
int __fastcall PpmResetIdleAccounting(int a1, int a2, int a3, int a4)
{
  int v6; // r1
  int v7; // [sp+0h] [bp-10h] BYREF
  int v8; // [sp+4h] [bp-Ch]
  int v9; // [sp+8h] [bp-8h]

  v7 = a2;
  v8 = a3;
  v9 = a4;
  if ( (PoDebug & 0x80000) != 0 )
    return sub_55244C();
  KeQueryPerformanceCounter(&v7, 0);
  return PpmResetProcessorIdleAccounting(*(_DWORD *)(a1 + 4), v6, v7, v8);
}
