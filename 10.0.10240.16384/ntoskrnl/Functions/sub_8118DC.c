// sub_8118DC 
 
void sub_8118DC()
{
  _DWORD *v0; // r4
  int **v1; // r1

  v0[7] = v0 + 7;
  v0[8] = v0 + 7;
  v0[4] = v0 + 4;
  v0[5] = v0 + 4;
  v0[2] = v0 + 2;
  v0[3] = v0 + 2;
  v0[9] = v0 + 9;
  v0[10] = v0 + 9;
  v0[11] = 0;
  v0[12] = 0;
  v0[6] = 0;
  v1 = (int **)dword_630D8C;
  *v0 = &PiDependencyNodeListHead;
  v0[1] = v1;
  if ( *v1 != &PiDependencyNodeListHead )
    __fastfail(3u);
  JUMPOUT(0x7A1728);
}
