// ExpTimeRefreshDpcRoutine 
 
signed int __fastcall ExpTimeRefreshDpcRoutine(signed int result, int a2, int a3, int a4)
{
  int v4; // r5
  char v5; // r3
  unsigned int *v6; // r9
  char v7; // r8
  unsigned int v8; // r4
  int v9; // r1
  __int64 v10; // r2
  unsigned int v11; // lr
  unsigned int v12; // r2
  unsigned int v13; // r2
  __int64 v16; // [sp+F4h] [bp-68h]
  unsigned __int64 v17; // [sp+11Ch] [bp-40h]
  char v18; // [sp+134h] [bp-28h]

  v4 = a4;
  v5 = a3;
  v6 = (unsigned int *)a2;
  if ( (a2 & 3) != 0 )
  {
    *(_BYTE *)result = 0;
    *(_DWORD *)(result + 16) = (unsigned __int64)v4 >> 8;
    v18 = a3;
    v7 = 64 - (a3 & 0x3F);
    LODWORD(v17) = (a2 << (a3 & 0x3F)) | ((unsigned __int64)a2 >> v7);
    HIDWORD(v17) = ((unsigned int)a2 >> (32 - (a3 & 0x3F))) | (a2 >> 31 << (a3 & 0x3F)) | (a2 << ((a3 & 0x3F) - 32)) | ((unsigned int)(a2 >> 31) >> v7);
    v8 = (unsigned int)(result >> 31) >> (a3 & 0x3F);
    v9 = (result >> 31 << v7) | ((unsigned int)result >> ((a3 & 0x3F) - 32));
    LODWORD(v10) = (result << v7) | ((unsigned __int64)result >> (a3 & 0x3F));
    HIDWORD(v10) = (result << (32 - (v5 & 0x3F))) | v9 | v8;
    v16 = v10;
    *(_DWORD *)(result + 20) ^= a4;
    *(_DWORD *)(result + 24) ^= a3;
    KiCustomAccessRoutine7(v6);
    v11 = ((unsigned int)v16 >> (64 - (v18 & 0x3F))) | (HIDWORD(v16) << ((v18 & 0x3F) - 32)) | (HIDWORD(v16) >> (32 - (v18 & 0x3F))) | ((_DWORD)v16 << (v18 & 0x3F));
    result = (HIDWORD(v17) << (64 - (v18 & 0x3F))) | ((unsigned int)v17 >> ((v18 & 0x3F) - 32)) | ((_DWORD)v17 << (32 - (v18 & 0x3F)));
    v6 = (unsigned int *)(((_DWORD)v17 << (64 - (v18 & 0x3F))) | (v17 >> (v18 & 0x3F)));
    *(_DWORD *)(v11 + 16) = v6;
    *(_BYTE *)v11 = 19;
  }
  __dmb(0xBu);
  do
  {
    v12 = __ldrex(v6);
    v13 = v12 + 1;
  }
  while ( __strex(v13, v6) );
  __dmb(0xBu);
  if ( v13 == 1 )
    result = ExQueueWorkItem(&ExpTimeRefreshWorkItem, 1);
  return result;
}
