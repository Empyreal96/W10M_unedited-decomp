// sub_5535FC 
 
void __fastcall sub_5535FC(int a1, int a2, int a3)
{
  _DWORD *v3; // r4
  _DWORD *v4; // r6
  unsigned int v5; // r3
  char v6; // r3

  v5 = *(_DWORD *)(a3 + 20);
  if ( v5 )
    v6 = __clz(__rbit(v5));
  else
    v6 = -1;
  *v3 = 0;
  v3[1] = 0;
  v3[2] = 0;
  *v3 = 1 << v6;
  *v4 = 3;
  dword_621818 |= 1 << v6;
  JUMPOUT(0x4F39FA);
}
