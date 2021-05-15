// sub_7D2608 
 
void sub_7D2608()
{
  int v0; // r4
  int v1; // r5
  _DWORD **v2; // r2

  v2 = (_DWORD **)(*(_DWORD *)(*(_DWORD *)(v0 + 2004) + 8 * v1 + 4) + 8);
  if ( (_DWORD **)(*v2)[1] == v2 && (_DWORD **)*v2[1] == v2 )
    JUMPOUT(0x6D17FA);
  __fastfail(3u);
}
