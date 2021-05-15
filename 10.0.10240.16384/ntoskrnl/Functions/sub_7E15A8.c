// sub_7E15A8 
 
void __fastcall sub_7E15A8(int a1, int a2, int a3, int a4)
{
  int v4; // r5
  bool v5; // zf

  if ( v4 == 25 )
  {
    v5 = a4 == 18;
  }
  else
  {
    if ( !v4 )
      goto LABEL_7;
    v5 = v4 == 1;
  }
  if ( !v5 )
    JUMPOUT(0x779024);
LABEL_7:
  JUMPOUT(0x778FD6);
}
