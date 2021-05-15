// sub_50B7B8 
 
void __fastcall sub_50B7B8(int a1, int a2, int a3, int a4, int a5, int a6, char a7, int a8, char a9)
{
  int v9; // r2
  char *v10; // r1
  char *v11; // r0

  v9 = 0;
  while ( 1 )
  {
    if ( v9 )
    {
      v10 = &a7;
      v11 = &a9;
    }
    else
    {
      v10 = (char *)&a5;
      v11 = &a7;
    }
    do
    {
      *(_DWORD *)v10 &= 0xF00FFFFF;
      v10 += 4;
    }
    while ( v10 < v11 );
    if ( (unsigned int)++v9 >= 2 )
      JUMPOUT(0x463F60);
  }
}
