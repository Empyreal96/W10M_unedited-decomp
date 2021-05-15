// sub_53A39C 
 
void __fastcall sub_53A39C(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  _DWORD *v9; // r4
  int v10; // r0

  a8 = a2;
  a9 = a2;
  while ( 1 )
  {
    v10 = MiCloneCompare(&a5, v9);
    if ( v10 >= 0 )
    {
      if ( v10 <= 0 )
        goto LABEL_7;
      v9 = (_DWORD *)v9[1];
    }
    else
    {
      v9 = (_DWORD *)*v9;
    }
    if ( !v9 )
LABEL_7:
      JUMPOUT(0x499ECA);
  }
}
