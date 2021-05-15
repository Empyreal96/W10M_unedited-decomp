// KiTimerExpiration 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall KiTimerExpiration(int result, int a2, unsigned int a3, unsigned int a4, int a5)
{
  int v7; // r5
  char *v8; // r9
  int v9; // r1
  int v10; // r4
  int v11; // r1
  int v12; // r2
  unsigned int v13; // r4
  unsigned __int64 v14; // r6
  int v15; // r3
  int v16; // r8
  unsigned int v17; // r3
  int v18; // [sp+4h] [bp-6Ch]
  int v20[2]; // [sp+20h] [bp-50h] BYREF
  unsigned int v21; // [sp+28h] [bp-48h]
  int v22; // [sp+2Ch] [bp-44h]
  unsigned int v23; // [sp+30h] [bp-40h]
  int v24[2]; // [sp+38h] [bp-38h] BYREF
  int v25[12]; // [sp+40h] [bp-30h] BYREF

  v21 = a4;
  v22 = a5;
  v23 = a3;
  v7 = result;
  if ( !KiSerializeTimerExpiration )
    return sub_5532BC();
  if ( *(_BYTE *)(result + 17) )
  {
    v8 = (char *)KiProcessorBlock + 4096;
    if ( KiProcessorBlock != (void *)-4096 )
    {
      v9 = *(_DWORD *)(result + 18232);
      v10 = result + 16 * v9 + 17976;
      *(_DWORD *)(result + 18232) = ((_BYTE)v9 + 1) & 0xF;
      *(_QWORD *)v10 = *(_QWORD *)&a3;
      KeQueryPerformanceCounter(v20, 0);
      *(_DWORD *)(v10 + 8) = v20[0];
      *(_DWORD *)(v10 + 12) = v20[1];
      v11 = (a4 << 14) | (a3 >> 18);
      v20[0] = v11;
      if ( (dword_682608 & 0x20000) != 0 )
      {
        v24[1] = a4;
        v25[0] = (int)v24;
        v25[1] = 0;
        v25[2] = 8;
        v25[3] = 0;
        v24[0] = a3;
        EtwTraceKernelEvent(v25, 1, 0x40020000u, 3920, 1538);
        v11 = v20[0];
      }
      v12 = a2;
      v13 = v11 - a2 + 1;
      if ( v13 <= 0x100 )
        goto LABEL_16;
      v14 = (((unsigned int)v11 + __PAIR64__(a4 >> 18, 1)) << 18) - __PAIR64__(v13 >> 14, v13 << 18);
      v12 = a2;
      do
      {
        if ( v13 <= 0x100 )
        {
LABEL_16:
          v15 = 256 - v13;
          v14 = __PAIR64__(v21, v23);
          v16 = v13;
          if ( 256 - v13 > 0x18 )
            v15 = 24;
        }
        else
        {
          v14 += 0x4000000i64;
          v15 = 0;
          v16 = 256;
        }
        result = KiExpireTimerTable(v7, v8, v12, v16, v15, v18, v14, HIDWORD(v14), v22);
        v13 -= v16;
        v12 = a2 + v16;
        a2 += v16;
      }
      while ( v13 );
      if ( (*(_WORD *)(v7 + 1756) & 8) == 0 )
      {
        v17 = *(_DWORD *)(v7 + 2344);
        *(_DWORD *)(v7 + 2340) = 0;
        if ( v17 >= KeTimeIncrement )
          *(_DWORD *)(v7 + 2344) = v17 - KeTimeIncrement;
        else
          *(_DWORD *)(v7 + 2344) = 0;
      }
    }
  }
  return result;
}
