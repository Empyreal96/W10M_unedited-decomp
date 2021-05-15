// sub_812C24 
 
void __fastcall sub_812C24(int a1, int a2, int a3, int a4, int a5)
{
  unsigned __int16 *v5; // r7
  int *v6; // r8
  unsigned int v7; // r0
  unsigned int v8; // r4
  int v9; // r5
  _DWORD *v10; // r0
  _DWORD *v11; // r6

  v7 = wcslen(v5);
  v8 = v7 + 1;
  v9 = 2 * (v7 + 7);
  v10 = (_DWORD *)ExAllocatePoolWithTag(1, v9, 1262764866);
  v11 = v10;
  if ( v10 )
  {
    *v10 = 1;
    v10[1] = v9;
    v10[2] = 3;
    memmove((int)(v10 + 3), (int)v5, 2 * v8);
    if ( BiAddStoreFromFile(v11) >= 0 )
    {
      if ( BiMarkTreatAsSystemStore(a5) >= 0 && BiIsSystemStore(a5) )
        *v6 = a5;
      else
        BcdCloseStore(a5);
    }
  }
  JUMPOUT(0x7A4468);
}
