// sub_530FB4 
 
void __fastcall sub_530FB4(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v7; // r4
  unsigned int v8; // r6
  int v9; // r0
  int v10; // r4
  unsigned int v11; // r0

  if ( v7 )
  {
    v9 = MiDeletePteRange(a7, ((v8 >> 10) & 0x3FFFFC) - 0x40000000, ((v8 >> 10) & 0x3FFFFC) - 0x40000000 + 4 * v7, 0);
    *(_DWORD *)(a7 + 80) -= v9;
    if ( (*(_BYTE *)(a7 + 112) & 7) != 1 )
    {
      v10 = -v9;
      do
        v11 = __ldrex(&dword_634DA0);
      while ( __strex(v11 + v10, &dword_634DA0) );
    }
  }
  JUMPOUT(0x48897A);
}
