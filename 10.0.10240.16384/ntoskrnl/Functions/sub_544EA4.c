// sub_544EA4 
 
void __fastcall sub_544EA4(int a1, int a2, int a3, int a4, int a5, unsigned int a6, int a7, int a8)
{
  unsigned int v8; // r4
  _DWORD *v9; // r6
  _DWORD *v10; // r10
  unsigned int v11; // r1
  int v12; // r4
  unsigned int v13; // r6
  int v14; // r2
  int v15; // t1
  unsigned int v16; // [sp+4h] [bp-44h]
  int v17; // [sp+8h] [bp-40h]
  unsigned int v18; // [sp+1Ch] [bp-2Ch]

  if ( *(_BYTE *)a3 == 1 && !MiGetAvailablePagesBelowPriority(v10, ((*(_DWORD *)(a3 + 40) >> 3) & 7) + 1) )
  {
    v11 = a6;
    *v9 = -1;
    if ( a8 )
      *(_BYTE *)(a8 + 1) = 2;
    if ( v8 <= v18 )
    {
      if ( a6 )
      {
        v12 = v17;
        if ( a6 > 1 )
        {
          v13 = a6 - 1;
          while ( 1 )
          {
            v15 = *(_DWORD *)(v12 + 4);
            v12 += 4;
            v14 = v15;
            if ( v15 != dword_6348FC )
            {
              MiReleaseFreshPage(MmPfnDatabase + 24 * v14);
              v11 = v16;
            }
            v16 = --v11;
            if ( !--v13 )
              JUMPOUT(0x4BCBA2);
          }
        }
        JUMPOUT(0x4BCB9A);
      }
      JUMPOUT(0x4BCD02);
    }
    JUMPOUT(0x4BCB96);
  }
  JUMPOUT(0x4BCB52);
}
