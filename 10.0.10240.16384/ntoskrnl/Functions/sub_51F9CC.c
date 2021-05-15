// sub_51F9CC 
 
void __fastcall sub_51F9CC(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
  _DWORD *v11; // r5
  int v12; // r7

  v11[3] = KiInterruptMessageDispatch;
  v11[4] = v12;
  v11[5] = a11;
  JUMPOUT(0x450AA6);
}
