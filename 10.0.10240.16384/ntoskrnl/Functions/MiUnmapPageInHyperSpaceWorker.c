// MiUnmapPageInHyperSpaceWorker 
 
unsigned int __fastcall MiUnmapPageInHyperSpaceWorker(int a1, int a2, int a3)
{
  unsigned int v4; // r3
  unsigned int result; // r0
  int v6; // r5
  _DWORD *v7; // r4
  unsigned int v8; // r7
  int v9; // [sp+0h] [bp-B0h] BYREF
  char v10; // [sp+4h] [bp-ACh]
  char v11; // [sp+5h] [bp-ABh]
  int v12; // [sp+8h] [bp-A8h]
  int v13; // [sp+Ch] [bp-A4h]
  int v14; // [sp+10h] [bp-A0h]
  int v15; // [sp+14h] [bp-9Ch]

  v4 = (unsigned int)KeGetPcr();
  result = ((a1 & 0xFFFFF000) >> 10) & 0x3FFFFC;
  v6 = (*(_DWORD *)((v4 & 0xFFFFF000) + 0x1384) & 0xFFF) + 1;
  v7 = (_DWORD *)(result - 0x40000000);
  v8 = *(_DWORD *)((v4 & 0xFFFFF000) + 0x1384) & 0xFFFFF000;
  if ( a3 >= 0 )
    JUMPOUT(0x50DA66);
  __dmb(0xBu);
  *v7 = 0;
  if ( (unsigned int)v7 >= 0xC0300000 )
    return sub_50DA5C();
  if ( v6 == 16 )
  {
    v13 = 0;
    v14 = 0;
    v9 = 0;
    v12 = 33;
    v10 = 1;
    v11 = 0;
    v15 = 0;
    MiInsertTbFlushEntry(&v9, v8, 16);
    result = MiFlushTbList(&v9);
    *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x1384) = v8;
  }
  else
  {
    *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x1384) = v6 | v8;
  }
  if ( a2 != 17 )
    result = KfLowerIrql(a2);
  return result;
}
