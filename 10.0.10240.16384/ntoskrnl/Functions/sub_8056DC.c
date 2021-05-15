// sub_8056DC 
 
void __fastcall sub_8056DC(int a1, int a2, int a3)
{
  int v3; // r6
  int v4; // r7
  int v5; // r10

  switch ( v4 )
  {
    case 18:
      if ( (v3 & a3) != 0 )
        goto LABEL_10;
      goto LABEL_9;
    case 19:
      if ( (v3 & a2) != 0 )
        goto LABEL_10;
      goto LABEL_9;
    case 20:
      if ( (v3 & v5) == 0 )
        goto LABEL_9;
      goto LABEL_10;
    default:
      if ( (v3 & a1) != 0 )
LABEL_10:
        JUMPOUT(0x7504D6);
LABEL_9:
      JUMPOUT(0x7504DA);
  }
}
