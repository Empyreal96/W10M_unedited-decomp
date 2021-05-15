// sub_817F1C 
 
void __fastcall sub_817F1C(int a1, int a2, int a3, int a4, __int16 a5)
{
  int v5; // r4
  int v6; // r6
  _WORD *v7; // r7
  int v8; // r2
  _WORD *v9; // r1

  v8 = 0;
  if ( !*(_WORD *)(v5 + 6) )
LABEL_11:
    JUMPOUT(0x7B11E4);
  v9 = *(_WORD **)(v5 + 12);
  while ( 1 )
  {
    if ( (__int16)v9[3] == a5 )
    {
      if ( (*v9 & 0x1020) == 32 )
      {
        if ( v7 )
        {
          *v7 = v8;
          goto LABEL_12;
        }
      }
      else if ( (*v9 & 0x1000) != 0 )
      {
        v6 = 1;
      }
    }
    ++v8;
    v9 += 14;
    if ( v8 >= *(unsigned __int16 *)(v5 + 6) )
    {
      if ( !v6 )
        goto LABEL_11;
LABEL_12:
      JUMPOUT(0x7B11E6);
    }
  }
}
