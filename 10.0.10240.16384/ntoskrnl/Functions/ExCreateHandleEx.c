// ExCreateHandleEx 
 
int __fastcall ExCreateHandleEx(int a1, int a2, int a3, unsigned __int8 a4)
{
  int v4; // r1

  v4 = a2 ^ ((unsigned __int8)a2 ^ a4) & 6;
  if ( (a4 & 8) == 0 )
    JUMPOUT(0x7F7656);
  return sub_7F7650(a1, v4);
}
