// sub_812E88 
 
void __fastcall sub_812E88(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
  int v10; // r5
  int v11; // r6
  int v12; // r7

  if ( (a4 & v11) != 0 )
  {
    if ( (a4 & 8) != 0 )
    {
      if ( BcdOpenObject(v10, (_DWORD *)(v12 + 8), &a10) < 0 )
        JUMPOUT(0x7A46FE);
      BcdDeleteObject(a10);
      *(_DWORD *)(v12 + 32) &= 0xFFFFFFF9;
    }
    else if ( !BiIsPortableWorkspaceBoot(a1, a2) && BiCreateEfiEntry(v10, v12) >= 0 )
    {
      BiAddBootEntryToNvramDisplayOrder(v12);
    }
    JUMPOUT(0x7A46F4);
  }
  JUMPOUT(0x7A46F8);
}
