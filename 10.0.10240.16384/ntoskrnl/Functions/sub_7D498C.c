// sub_7D498C 
 
void sub_7D498C()
{
  int v0; // r8
  _DWORD *v1; // lr
  unsigned int v2; // r1
  __int64 v3; // kr00_8

  if ( !v0 )
LABEL_11:
    JUMPOUT(0x6D6156);
  while ( 1 )
  {
    v2 = v1[2];
    if ( !v2 )
      v2 = v1[4];
    v3 = *((_QWORD *)v1 + 2);
    if ( (unsigned int)(HIDWORD(v3) + v3) < HIDWORD(v3) )
      break;
    if ( HIDWORD(v3) != v1[3] || v2 > (unsigned int)v3 )
    {
      dword_632EE4 = 21;
      goto LABEL_12;
    }
    v1 += 10;
    if ( !--v0 )
      goto LABEL_11;
  }
  dword_632EE4 = 20;
LABEL_12:
  JUMPOUT(0x6D6158);
}
