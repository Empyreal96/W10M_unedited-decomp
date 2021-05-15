// KiPcToFileHeader 
 
unsigned int __fastcall KiPcToFileHeader(unsigned int a1, int *a2, int a3, _BYTE *a4)
{
  int *v7; // r6
  int *v8; // r4
  unsigned int v9; // r3
  unsigned int v10; // r5
  unsigned int v11; // r7
  unsigned int v12; // r1
  int v14; // [sp+0h] [bp-20h]

  v14 = a3;
  if ( (unsigned int)InitializationPhase >= 2 )
    v7 = &PsLoadedModuleList;
  else
    v7 = (int *)((char *)KeLoaderBlock_0 + 16);
  v8 = (int *)*v7;
  v9 = 0;
  v10 = 0;
  *a4 = 0;
  if ( v8 )
  {
    v11 = 0;
    while ( v8 != v7 )
    {
      if ( !MiIsAddressValid((unsigned int)v8, 0, a3, v9) )
        return 0;
      if ( ++v11 <= 2 && (v9 = v14, v14 == 1) )
      {
        v8 = (int *)*v8;
      }
      else
      {
        a3 = (int)v8;
        v12 = v8[6];
        v8 = (int *)*v8;
        if ( a1 >= v12 )
        {
          v9 = *(_DWORD *)(a3 + 32) + v12;
          if ( a1 < v9 )
          {
            *a2 = a3;
            v10 = v12;
            if ( v11 <= 2 )
              *a4 = 1;
            return v10;
          }
        }
      }
    }
  }
  return v10;
}
