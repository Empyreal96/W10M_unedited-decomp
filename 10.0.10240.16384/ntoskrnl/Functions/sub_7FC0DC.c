// sub_7FC0DC 
 
void __fastcall sub_7FC0DC(int a1, int a2, unsigned int a3, unsigned int a4)
{
  int v4; // r4
  unsigned __int8 *v5; // r5

  if ( a4 == 4 )
  {
    if ( *v5 >= 3u && RtlpValidCompoundAce(v4) )
      goto LABEL_19;
  }
  else if ( (a4 < 5 || a4 > 8) && (a4 < 0xB || a4 > 0xC) && (a4 < 0xF || a4 > 0x10) )
  {
    if ( a4 == 18 )
    {
      if ( RtlpValidAttributeAce(v4) )
        goto LABEL_19;
    }
    else if ( a3 >= 4 )
    {
      goto LABEL_19;
    }
  }
  else if ( *v5 >= 4u && RtlpValidObjectAce(v4) )
  {
LABEL_19:
    JUMPOUT(0x730E86);
  }
  JUMPOUT(0x730EB6);
}
