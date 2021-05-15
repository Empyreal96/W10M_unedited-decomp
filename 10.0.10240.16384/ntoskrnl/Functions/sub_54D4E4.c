// sub_54D4E4 
 
void __fastcall sub_54D4E4(int a1, int a2, int a3, int a4)
{
  _DWORD *v4; // r6
  int v5; // r7
  _DWORD **v6; // r10
  _DWORD *v7; // r4

  v7 = *v6;
  *v7 = a4;
  v7[1] = v4[1];
  v7[2] = v5;
  v7[4] = a1;
  v7[3] = v4[3];
  v7[5] = v4[5];
  JUMPOUT(0x4E19A2);
}
