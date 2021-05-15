// PopCompressHiberBlocks 
 
int __fastcall PopCompressHiberBlocks(unsigned int a1, int a2, char a3)
{
  int v6; // r0
  int v7; // r8
  int v8; // r0
  int v10[2]; // [sp+10h] [bp-C8h] BYREF
  char v11[12]; // [sp+18h] [bp-C0h] BYREF
  int v12; // [sp+24h] [bp-B4h]
  char v13[96]; // [sp+78h] [bp-60h] BYREF

  while ( 1 )
  {
    v6 = PopGetNextTable(a1, v10, (int)v13, (unsigned int)v11, a3, *(_DWORD *)(a2 + 4));
    v7 = v6;
    if ( !v6 )
      break;
    *(_QWORD *)(a2 + 40) += (unsigned int)v6;
    v8 = PopAddPagesToCompressedPageSet(a1, a2, v10, v12, a3, v6, 0);
    PopCountDataAsProduced(a2, v8, v10, v13, v7, 0);
  }
  return 0;
}
