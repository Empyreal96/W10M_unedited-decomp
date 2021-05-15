// MiGetPteMappingPair 
 
int __fastcall MiGetPteMappingPair(int a1, int a2)
{
  int result; // r0
  char v4; // r6
  unsigned int v5; // r5
  unsigned int v6; // r1
  int v7; // [sp+0h] [bp-B0h] BYREF
  char v8; // [sp+4h] [bp-ACh]
  char v9; // [sp+5h] [bp-ABh]
  int v10; // [sp+8h] [bp-A8h]
  int v11; // [sp+Ch] [bp-A4h]
  int v12; // [sp+10h] [bp-A0h]
  int v13; // [sp+14h] [bp-9Ch]

  if ( a1 != 1 || (result = MiCreatePteCopyList(2, 2, a2), !*(_DWORD *)(a2 + 4)) )
  {
    result = KfRaiseIrql(2);
    v4 = result;
    v5 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x1384);
    if ( 16 - (v5 & 0xFFF) <= 2 )
    {
      v11 = 0;
      v12 = 0;
      v7 = 0;
      v8 = 0;
      v9 = 0;
      v10 = 33;
      v5 &= 0xFFFFF000;
      v13 = 0;
      MiInsertTbFlushEntry(&v7, v5, 16);
      v8 |= 1u;
      result = MiFlushTbList(&v7);
      v6 = v5;
    }
    else
    {
      v6 = (v5 & 0xFFFFF000) + ((v5 & 0xFFF) << 12);
    }
    *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x1384) = v5 + 2;
    *(_DWORD *)a2 = 0;
    *(_DWORD *)(a2 + 4) = 2;
    *(_DWORD *)(a2 + 12) = ((v6 >> 10) & 0x3FFFFC) - 0x40000000;
    *(_BYTE *)(a2 + 8) = v4;
    *(_BYTE *)(a2 + 9) = 1;
  }
  return result;
}
