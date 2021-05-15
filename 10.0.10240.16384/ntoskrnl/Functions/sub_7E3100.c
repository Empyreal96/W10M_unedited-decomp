// sub_7E3100 
 
void __fastcall sub_7E3100(int a1, int a2, int a3, _DWORD *a4, int a5, int a6, int a7, int a8)
{
  char *v8; // r4
  int v9; // r5
  char v10; // r3

  *a4 = 1;
  if ( v8 && v9 )
  {
    if ( a1 != a2 )
    {
      if ( a8 )
        v10 = -1;
      else
        v10 = 0;
      *v8 = v10;
      JUMPOUT(0x77B9F4);
    }
    JUMPOUT(0x77BA36);
  }
  JUMPOUT(0x77BA24);
}
