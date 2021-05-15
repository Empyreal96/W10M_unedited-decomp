// PopConsoleSessionPassiveInput 
 
int __fastcall PopConsoleSessionPassiveInput(int a1, int a2, _DWORD *a3)
{
  _DWORD v6[2]; // [sp+0h] [bp-20h] BYREF
  int v7[6]; // [sp+8h] [bp-18h] BYREF

  v7[1] = 0;
  v6[0] = 0;
  v6[1] = 256;
  byte_61DE64 = 0;
  dword_61DE58 = a2;
  PopSetSessionUserStatus(a1, 2);
  v7[0] = dword_61DE4C;
  a3[1] = dword_61DE4C;
  *a3 = 0;
  return PopUpdateTimeouts(a1, v7, v6);
}
