// sub_81C5DC 
 
void __fastcall sub_81C5DC(int a1, int a2, int a3)
{
  char v3; // r2

  if ( a3 )
  {
    if ( a3 != 1 )
      goto LABEL_6;
    v3 = 0;
  }
  else
  {
    v3 = 1;
  }
  EtwpPagingDisabled = v3;
LABEL_6:
  JUMPOUT(0x7BCA5C);
}
