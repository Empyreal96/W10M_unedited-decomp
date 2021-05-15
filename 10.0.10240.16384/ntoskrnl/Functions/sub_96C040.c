// sub_96C040 
 
void sub_96C040()
{
  int v0; // r4
  int v1; // r5
  _DWORD *v2; // r3
  bool v3; // zf

  v2 = *(_DWORD **)(v0 + 8);
  if ( v2 )
  {
    do
    {
      v3 = *v2 == 0;
      if ( !*v2 )
        break;
      v2 = (_DWORD *)*v2;
    }
    while ( !v3 );
  }
  *(_DWORD *)(v1 + 8) = v2;
  JUMPOUT(0x958E72);
}
