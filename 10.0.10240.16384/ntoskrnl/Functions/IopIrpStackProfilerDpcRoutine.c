// IopIrpStackProfilerDpcRoutine 
 
unsigned int __fastcall IopIrpStackProfilerDpcRoutine(int a1, int a2, int a3, int a4)
{
  char v4; // lr
  int v5; // lr
  int v6; // r1
  unsigned int v7; // r10
  unsigned int v8; // r9
  unsigned int v9; // r6
  unsigned int v10; // r4
  void **v11; // lr
  _DWORD *v12; // r0
  int v13; // r3
  _QWORD *v14; // r5
  int v15; // r10
  int v16; // r2
  int v17; // r9
  unsigned int v18; // r5
  void **v19; // r6
  unsigned int result; // r0
  int v21; // [sp+4h] [bp-1E4h]
  int v22; // [sp+4h] [bp-1E4h]
  unsigned int v23; // [sp+Ch] [bp-1DCh]
  unsigned __int64 v24; // [sp+DBh] [bp-10Dh]
  unsigned int v25; // [sp+103h] [bp-E5h]
  unsigned int v26; // [sp+107h] [bp-E1h]
  char v27; // [sp+11Bh] [bp-CDh]
  _BYTE v28[192]; // [sp+128h] [bp-C0h] BYREF

  if ( (a2 & 3) != 0 )
  {
    *(_BYTE *)a1 = 0;
    *(_DWORD *)(a1 + 16) = (unsigned __int64)a4 >> 8;
    v27 = a3;
    v4 = 64 - (a3 & 0x3F);
    LODWORD(v24) = ((unsigned int)(a2 >> 31) >> (32 - (a3 & 0x3F))) | ((unsigned int)a2 >> v4) | (a2 >> 31 << ((a3 & 0x3F) - 32)) | (a2 << (a3 & 0x3F));
    HIDWORD(v24) = ((unsigned int)(a2 >> 31) >> v4) | ((unsigned __int64)((__int64)a2 << (a3 & 0x3F)) >> 32);
    v25 = (a1 << v4) | ((unsigned __int64)a1 >> (a3 & 0x3F));
    v26 = (a1 << (32 - (a3 & 0x3F))) | (a1 >> 31 << v4) | ((unsigned int)a1 >> ((a3 & 0x3F) - 32)) | ((unsigned int)(a1 >> 31) >> (a3 & 0x3F));
    *(_DWORD *)(a1 + 20) ^= a4;
    *(_DWORD *)(a1 + 24) ^= a3;
    KiCustomAccessRoutine2((unsigned int *)a2);
    v5 = (v25 >> (64 - (v27 & 0x3F))) | (v26 << ((v27 & 0x3F) - 32)) | (v26 >> (32 - (v27 & 0x3F))) | (v25 << (v27 & 0x3F));
    *(_DWORD *)(v5 + 16) = ((_DWORD)v24 << (64 - (v27 & 0x3F))) | (v24 >> (v27 & 0x3F));
    *(_BYTE *)v5 = 19;
  }
  memset(v28, 0, 160);
  v7 = 0;
  v8 = 0;
  v9 = 0;
  v10 = KeNumberProcessors_0;
  v21 = KeNumberProcessors_0;
  if ( KeNumberProcessors_0 )
  {
    v11 = &KiProcessorBlock;
    v6 = 17612;
    if ( !KeNumberProcessors_0 )
    {
      v12 = 0;
      goto LABEL_7;
    }
    do
    {
      v12 = *v11;
LABEL_7:
      if ( v12 )
      {
        v13 = v12[4382] - v12[4403];
        v23 = v7 + v13;
        v8 = (__PAIR64__(v8, v7) + (unsigned int)v13) >> 32;
        v14 = v28;
        v15 = 20;
        do
        {
          *v14 += (unsigned int)(v12[4362] - v12[4383]);
          ++v12;
          ++v14;
          --v15;
        }
        while ( v15 );
        v10 = v21;
        v7 = v23;
        v6 = 17612;
      }
      ++v9;
      ++v11;
    }
    while ( v9 < v10 );
  }
  v16 = 20;
  v22 = IopIrpStackProfilerSampleSize;
  if ( v8 || v7 > IopIrpStackProfilerSampleSize )
  {
    v16 = 0;
    v17 = IopIrpStackProfilerMinSizeThreshold;
    v6 = (int)v28;
    do
    {
      if ( *(_QWORD *)v6 > (unsigned __int64)(unsigned int)IopIrpStackProfilerMinSizeThreshold )
        break;
      ++v16;
      v6 += 8;
    }
    while ( v16 < 20 );
  }
  else
  {
    v17 = IopIrpStackProfilerMinSizeThreshold;
  }
  if ( v16 != 20 )
  {
    IopProcessIrpStackProfiler(v28, v6);
    IopIrpStackProfilerMinSizeThreshold = 2 * v17;
    if ( (unsigned int)(2 * v17) > 0x1900 )
      IopIrpStackProfilerMinSizeThreshold = 6400;
    IopIrpStackProfilerSampleSize = 2 * v22;
    if ( (unsigned int)(2 * v22) > 0x7D00 )
      IopIrpStackProfilerSampleSize = 32000;
    v18 = 0;
    if ( v10 )
    {
      v19 = &KiProcessorBlock;
      do
      {
        if ( *v19 )
        {
          memmove((int)*v19 + 17532, (int)*v19 + 17448, 0x54u);
          v10 = KeNumberProcessors_0;
        }
        ++v18;
        ++v19;
      }
      while ( v18 < v10 );
    }
  }
  __dmb(0xBu);
  do
    result = __ldrex((unsigned int *)&IopIrpStackProfilerFlags);
  while ( __strex(result | 4, (unsigned int *)&IopIrpStackProfilerFlags) );
  __dmb(0xBu);
  return result;
}
