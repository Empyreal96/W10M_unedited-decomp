// sub_7BF2A4 
 
void __fastcall sub_7BF2A4(int a1, int a2, int a3, int a4)
{
  int v4; // r4
  _DWORD *v5; // r6

  PopSetSessionUserStatus(a1, 2, a3, a4);
  v5[1] = PopGetDisplayTimeout(v4);
  *v5 = PopInputTimeout;
  JUMPOUT(0x6A2F7A);
}
