// sub_552EB0 
 
void __fastcall sub_552EB0(int a1, unsigned int a2)
{
  unsigned int v2; // r4
  int v3; // r8
  unsigned int v4; // r10
  unsigned __int16 *v5; // r6
  int v7; // r3
  unsigned int v8; // r3

  v5 = *(unsigned __int16 **)(v3 + 4);
  while ( 1 )
  {
    if ( *v5++ )
      v7 = 1;
    else
      v7 = 4;
    v8 = v7 + v2;
    if ( v8 < v2 )
      JUMPOUT(0x4F2D70);
    ++a2;
    v2 = v8;
    if ( a2 >= v4 )
      JUMPOUT(0x4F2D16);
  }
}
