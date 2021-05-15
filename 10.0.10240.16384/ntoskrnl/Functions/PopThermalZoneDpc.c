// PopThermalZoneDpc 
 
int __fastcall PopThermalZoneDpc(int a1, int a2, int a3, int a4)
{
  int v4; // r5
  char v5; // r3
  int v6; // r9
  char v7; // r8
  char v8; // lr
  unsigned __int64 v9; // r2
  int v10; // lr
  unsigned __int64 v14; // [sp+F8h] [bp-64h]
  unsigned int v15; // [sp+110h] [bp-4Ch]
  unsigned int v16; // [sp+114h] [bp-48h]
  char v17; // [sp+130h] [bp-2Ch]

  v4 = a4;
  v5 = a3;
  v6 = a2;
  if ( (a2 & 3) != 0 )
  {
    *(_BYTE *)a1 = 0;
    *(_DWORD *)(a1 + 16) = (unsigned __int64)v4 >> 8;
    v17 = a3;
    v7 = a3 & 0x3F;
    v8 = 64 - (a3 & 0x3F);
    LODWORD(v9) = (a2 << (a3 & 0x3F)) | (a2 >> 31 << ((a3 & 0x3F) - 32)) | ((unsigned int)a2 >> v8) | ((unsigned int)(a2 >> 31) >> (32 - (a3 & 0x3F)));
    HIDWORD(v9) = (a2 << ((v5 & 0x3F) - 32)) | (a2 >> 31 << (v5 & 0x3F)) | ((unsigned int)a2 >> (32 - (v5 & 0x3F))) | ((unsigned int)(a2 >> 31) >> v8);
    v14 = v9;
    v15 = (a1 << v8) | ((unsigned __int64)a1 >> v7);
    v16 = ((unsigned __int64)((__int64)a1 << v8) >> 32) | ((unsigned int)(a1 >> 31) >> v7);
    *(_DWORD *)(a1 + 20) ^= a4;
    *(_DWORD *)(a1 + 24) ^= a3;
    KiCustomAccessRoutine3((unsigned int *)a2);
    v10 = (v15 >> (64 - (v17 & 0x3F))) | (v16 << ((v17 & 0x3F) - 32)) | (v16 >> (32 - (v17 & 0x3F))) | (v15 << (v17 & 0x3F));
    v6 = ((_DWORD)v14 << (64 - (v17 & 0x3F))) | (v14 >> (v17 & 0x3F));
    *(_DWORD *)(v10 + 16) = v6;
    *(_BYTE *)v10 = 19;
  }
  if ( (PoDebug & 0x20) != 0 )
    DbgPrint(
      "Thermal Zone %p: Passive cooling timeout in state %08lx\n",
      (const void *)v6,
      *(unsigned __int8 *)(v6 + 32));
  return IoCancelIrp(*(_DWORD *)(v6 + 28));
}
