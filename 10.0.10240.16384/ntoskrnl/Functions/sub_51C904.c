// sub_51C904 
 
void __fastcall sub_51C904(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  unsigned int v9; // r5
  char v10; // r7
  unsigned int v11; // r10
  unsigned int v12; // r1
  unsigned int v13; // r1

  v12 = v11 >> v10;
  while ( !(*(_DWORD *)(a9 + 104 * v12 + 4) | *(_DWORD *)(a9 + 104 * v12 + 60)) )
  {
    v13 = v12 + 1;
    if ( !v9 )
      __brkdiv0();
    v12 = v13 % v9;
    if ( v12 == v11 >> v10 )
      JUMPOUT(0x44847E);
  }
  JUMPOUT(0x44848A);
}
