// CmpEnableLazyFlushDpcRoutine 
 
int __fastcall CmpEnableLazyFlushDpcRoutine(int a1, int a2, int a3, int a4)
{
  char v4; // r6
  int v5; // lr
  unsigned __int64 v7; // [sp+F1h] [bp-5Bh]
  unsigned int v8; // [sp+F9h] [bp-53h]
  unsigned int v9; // [sp+FDh] [bp-4Fh]
  char v10; // [sp+121h] [bp-2Bh]

  if ( (a2 & 3) != 0 )
  {
    *(_BYTE *)a1 = 0;
    *(_DWORD *)(a1 + 16) = (unsigned __int64)a4 >> 8;
    v10 = a3;
    v4 = 64 - (a3 & 0x3F);
    LODWORD(v7) = (a2 << (a3 & 0x3F)) | ((unsigned int)a2 >> v4) | (a2 >> 31 << ((a3 & 0x3F) - 32)) | ((unsigned int)(a2 >> 31) >> (32 - (a3 & 0x3F)));
    HIDWORD(v7) = (a2 << ((a3 & 0x3F) - 32)) | (a2 >> 31 << (a3 & 0x3F)) | ((unsigned int)a2 >> (32 - (a3 & 0x3F))) | ((unsigned int)(a2 >> 31) >> v4);
    v8 = ((unsigned __int64)a1 >> (a3 & 0x3F)) | (a1 << v4);
    v9 = ((unsigned int)(a1 >> 31) >> (a3 & 0x3F)) | (a1 >> 31 << v4) | ((unsigned int)a1 >> ((a3 & 0x3F) - 32)) | (a1 << (32 - (a3 & 0x3F)));
    *(_DWORD *)(a1 + 20) ^= a4;
    *(_DWORD *)(a1 + 24) ^= a3;
    KiCustomAccessRoutine4((unsigned int *)a2);
    v5 = (v8 >> (64 - (v10 & 0x3F))) | (v9 << ((v10 & 0x3F) - 32)) | (v9 >> (32 - (v10 & 0x3F))) | (v8 << (v10 & 0x3F));
    *(_DWORD *)(v5 + 16) = ((_DWORD)v7 << (64 - (v10 & 0x3F))) | (v7 >> (v10 & 0x3F));
    *(_BYTE *)v5 = 19;
  }
  return CmpEnableLazyFlush(1);
}
