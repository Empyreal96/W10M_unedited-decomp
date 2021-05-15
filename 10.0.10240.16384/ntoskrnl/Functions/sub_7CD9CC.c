// sub_7CD9CC 
 
void __fastcall sub_7CD9CC(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, _WORD *a11, int a12)
{
  int v12; // r5
  int v13; // r7
  int v14; // r2
  int v15; // r3
  int v16; // r5

  *(_DWORD *)(v12 + 1200) = -1;
  MI_INITIALIZE_COLOR_BASE(0, 0, (int)&a11);
  v13 = HIWORD(a12);
  v14 = (unsigned __int16)(*a11 + 1);
  v15 = (unsigned __int16)a12;
  *a11 = v14;
  v16 = v14 & v15;
  while ( MiGetPage((int)MiSystemPartition, v16 | v13, 0) == -1 )
  {
    if ( KeGetCurrentIrql(-1) == 2 )
      JUMPOUT(0x771AC0);
    MiWaitForFreePage((int)MiSystemPartition);
  }
  JUMPOUT(0x771ABE);
}
