// FsRtlHeatLogIo 
 
int __fastcall FsRtlHeatLogIo(int a1, int a2, int a3, int a4, int a5)
{
  int v5; // r5
  int v6; // r3
  int *v7; // r2
  __int64 v8; // r0

  v5 = 0;
  v6 = **(unsigned __int8 **)(a2 + 96);
  switch ( v6 )
  {
    case 3:
      if ( (Microsoft_Windows_Storage_Tiering_IoHeatEnableBits & 2) == 0 )
        return v5;
      v8 = Microsoft_Windows_Storage_Tiering_IoHeatHandle;
      v7 = TieredStorage_HeatRead;
LABEL_12:
      Template_xxxqq(v8, SHIDWORD(v8), (int)v7, a5);
      return v5;
    case 4:
      if ( (Microsoft_Windows_Storage_Tiering_IoHeatEnableBits & 4) == 0 )
        return v5;
      v7 = TieredStorage_HeatWrite;
LABEL_7:
      v8 = Microsoft_Windows_Storage_Tiering_IoHeatHandle;
      goto LABEL_12;
    case 18:
      if ( (Microsoft_Windows_Storage_Tiering_IoHeatEnableBits & 8) == 0 )
        return v5;
      v7 = TieredStorage_HeatDelete;
      goto LABEL_7;
  }
  return -1073741584;
}
