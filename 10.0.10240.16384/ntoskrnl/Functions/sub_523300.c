// sub_523300 
 
void sub_523300()
{
  int *v0; // r4
  int v1; // r5
  _DWORD *v2; // r0

  do
  {
    v2 = (_DWORD *)*v0;
    if ( *(_DWORD *)(*v0 + 8) )
      break;
    v0 = (int *)*v0;
  }
  while ( *v2 != v1 );
  JUMPOUT(0x459390);
}
