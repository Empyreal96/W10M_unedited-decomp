// IopLiveDumpBufferDumpData 
 
int __fastcall IopLiveDumpBufferDumpData(int result, _DWORD *a2)
{
  int v2; // r4
  int v3; // r9
  int v4; // r10
  int v5; // r1
  unsigned int v6; // r5
  int v7; // r7
  int v8; // r2
  char *v9; // r8
  int v10; // t1
  unsigned int v11; // r10
  unsigned int v12; // r3
  int v13; // r2
  _DWORD *v14; // r2
  unsigned int v15; // r0
  int v16; // [sp+8h] [bp-130h]
  unsigned int v17; // [sp+Ch] [bp-12Ch]
  int v18; // [sp+10h] [bp-128h]
  int v19; // [sp+14h] [bp-124h]
  char v20[288]; // [sp+18h] [bp-120h] BYREF

  v2 = *(_DWORD *)result;
  v18 = *(_DWORD *)result;
  if ( *a2 < *(_DWORD *)(*(_DWORD *)result + 308) )
  {
    v3 = *(_DWORD *)(v2 + 312) + 8 * *a2;
    v4 = *(_DWORD *)(v3 + 4) + 28;
    v16 = v4;
    while ( 1 )
    {
      ReadTimeStampCounter();
      result = IopLiveDumpGetCapturePages(v2 + 220, v2 + 272, v20);
      if ( !v17 )
        break;
      v6 = 0;
      v7 = *(_DWORD *)(*(_DWORD *)(v2 + 304) + 4 * v19);
      v8 = 0;
      v9 = v20;
      do
      {
        v10 = *(_DWORD *)v9;
        v9 += 4;
        *(_DWORD *)(v4 + 4 * v8++) = v10;
        if ( v8 == 16 || v8 && v6 == v17 - 1 )
        {
          v11 = v8 << 12;
          v12 = (unsigned int)((v8 << 12) + 4095) >> 12;
          v13 = *(_DWORD *)(v3 + 4);
          *(_WORD *)(v13 + 4) = 4 * (v12 + 7);
          *(_DWORD *)v13 = 0;
          *(_WORD *)(v13 + 6) = 0;
          *(_DWORD *)(v13 + 16) = 0;
          *(_DWORD *)(v13 + 20) = v11;
          *(_DWORD *)(v13 + 24) = 0;
          MmMapMemoryDumpMdlEx(*(_DWORD *)v3, v5, *(_DWORD *)(v3 + 4), 0);
          v14 = *(_DWORD **)(*(_DWORD *)(v3 + 4) + 12);
          __dsb(0xFu);
          v15 = v11 >> 2;
          if ( v11 >> 2 )
          {
            v5 = v7 - (_DWORD)v14;
            do
            {
              --v15;
              *(_DWORD *)((char *)v14 + v5) = *v14;
              ++v14;
            }
            while ( v15 );
          }
          v7 += v11;
          v4 = v16;
          v8 = 0;
        }
        ++v6;
      }
      while ( v6 < v17 );
      v2 = v18;
    }
  }
  return result;
}
