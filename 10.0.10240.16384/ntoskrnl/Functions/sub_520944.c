// sub_520944 
 
void __fastcall sub_520944(int a1, int a2, unsigned int a3, int a4)
{
  int v4; // r4
  _DWORD *v5; // r1
  _DWORD *v6; // r4
  _DWORD *v7; // t1
  unsigned int v8; // r3
  int *v9; // r1
  int *v10; // r4
  int *v11; // t1
  unsigned int v12; // r3

  if ( a4 == 4 )
  {
    v11 = *(int **)(v4 + 44);
    v10 = (int *)(v4 + 44);
    v9 = v11;
    while ( v9 != v10 )
    {
      v12 = *((unsigned __int16 *)v9 + 16) + a3;
      if ( v12 < a3 )
LABEL_16:
        JUMPOUT(0x452E20);
      v9 = (int *)*v9;
      a3 = v12;
    }
  }
  else
  {
    if ( a4 != 5 )
    {
      if ( a4 == 6 )
        goto LABEL_14;
      if ( a4 != 16 )
        JUMPOUT(0x452E1C);
    }
    v7 = *(_DWORD **)(v4 + 44);
    v6 = (_DWORD *)(v4 + 44);
    v5 = v7;
    while ( v5 != v6 )
    {
      v8 = v5[7] + a3;
      if ( v8 < a3 )
        goto LABEL_16;
      v5 = (_DWORD *)*v5;
      a3 = v8;
    }
  }
LABEL_14:
  JUMPOUT(0x452DF0);
}
