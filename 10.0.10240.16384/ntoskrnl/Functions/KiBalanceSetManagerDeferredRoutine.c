// KiBalanceSetManagerDeferredRoutine 
 
int __fastcall KiBalanceSetManagerDeferredRoutine(int a1, int a2, int a3, int a4)
{
  int v4; // r8
  char v5; // r6
  int v6; // lr
  unsigned int v8; // [sp+DFh] [bp-61h]
  unsigned int v9; // [sp+E3h] [bp-5Dh]
  unsigned __int64 v10; // [sp+F7h] [bp-49h]
  char v11; // [sp+117h] [bp-29h]

  v4 = a2;
  if ( (a2 & 3) != 0 )
  {
    *(_BYTE *)a1 = 0;
    *(_DWORD *)(a1 + 16) = (unsigned __int64)a4 >> 8;
    v11 = a3;
    v5 = 64 - (a3 & 0x3F);
    LODWORD(v10) = (a2 << (a3 & 0x3F)) | ((unsigned int)a2 >> v5) | (a2 >> 31 << ((a3 & 0x3F) - 32)) | ((unsigned int)(a2 >> 31) >> (32 - (a3 & 0x3F)));
    HIDWORD(v10) = (a2 << ((a3 & 0x3F) - 32)) | (a2 >> 31 << (a3 & 0x3F)) | ((unsigned int)a2 >> (32 - (a3 & 0x3F))) | ((unsigned int)(a2 >> 31) >> v5);
    v8 = ((unsigned __int64)a1 >> (a3 & 0x3F)) | (a1 << v5);
    v9 = ((unsigned int)(a1 >> 31) >> (a3 & 0x3F)) | (a1 >> 31 << v5) | ((unsigned int)a1 >> ((a3 & 0x3F) - 32)) | (a1 << (32 - (a3 & 0x3F)));
    *(_DWORD *)(a1 + 20) ^= a4;
    *(_DWORD *)(a1 + 24) ^= a3;
    KiCustomAccessRoutine6((unsigned int *)a2);
    v6 = (v8 >> (64 - (v11 & 0x3F))) | (v9 << ((v11 & 0x3F) - 32)) | (v9 >> (32 - (v11 & 0x3F))) | (v8 << (v11 & 0x3F));
    v4 = ((_DWORD)v10 << (64 - (v11 & 0x3F))) | (v10 >> (v11 & 0x3F));
    *(_DWORD *)(v6 + 16) = v4;
    *(_BYTE *)v6 = 19;
  }
  return KeSetEvent(v4, 10, 0);
}
