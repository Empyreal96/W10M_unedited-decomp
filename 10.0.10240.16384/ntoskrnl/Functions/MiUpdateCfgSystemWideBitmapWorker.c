// MiUpdateCfgSystemWideBitmapWorker 
 
int __fastcall MiUpdateCfgSystemWideBitmapWorker(int a1, unsigned __int8 *a2, unsigned int a3, unsigned int a4)
{
  unsigned int v5; // r8
  unsigned int v6; // r9
  int v8; // r4
  unsigned int v9; // r10
  int v10; // r5
  int v11; // r8
  int v12; // r4
  int v13; // r0
  unsigned int *v14; // r0
  unsigned int i; // r0
  unsigned int v16; // r2
  int v18; // [sp+8h] [bp-48h] BYREF
  unsigned int v19; // [sp+Ch] [bp-44h] BYREF
  int v20; // [sp+10h] [bp-40h]
  unsigned int v21; // [sp+18h] [bp-38h] BYREF
  int v22; // [sp+1Ch] [bp-34h]
  unsigned int v23; // [sp+20h] [bp-30h]
  int v24; // [sp+24h] [bp-2Ch]
  int v25[10]; // [sp+28h] [bp-28h] BYREF

  v5 = a3 >> 3;
  v6 = (a4 >> 15) + ((((a3 >> 3) & 0xFFF) + ((a4 >> 3) & 0xFFF) + 4095) >> 12);
  v23 = a3 >> 3;
  v24 = 0;
  v20 = a1;
  v21 = a3 >> 3;
  v18 = a4 >> 3;
  v8 = MmMapViewInSystemSpaceEx(a1, (int)&v19, (int)&v18);
  if ( v8 >= 0 )
  {
    v9 = v19;
    v10 = (unsigned __int16)v5;
    v11 = v18;
    v12 = v10 | v19;
    v13 = MiSectionControlArea(v20);
    v21 >>= 12;
    v22 = 0;
    v14 = MiLocatePagefileSubsection((unsigned int *)(v13 + 80), (int)&v21);
    if ( MiChargeSegmentCommit((int **)v14, (int *)(v14[1] + 4 * v21), v6, 0) )
    {
      if ( a2 )
      {
        v21 = a4;
        v22 = v12;
        RtlClearAllBits((int)&v21);
        for ( i = MiCompressedRvaListFirst(a2, v25); i; i = MiCompressedRvaListNext(a2, v25) )
        {
          v16 = 1;
          if ( (i & 0xF) > 1 )
            v16 = 2;
          RtlSetBits(&v21, 2 * (i >> 4), v16);
        }
        MiCfgEliminateZeroPages((int)dword_634F00, v12 & 0xFFFFF000, v6 << 12, (int)MiState);
      }
      else
      {
        memset((_BYTE *)v12, 255, v11 - v10);
      }
      v8 = 0;
    }
    else
    {
      v8 = -1073741523;
    }
    MmUnmapViewInSystemSpace(v9);
  }
  return v8;
}
