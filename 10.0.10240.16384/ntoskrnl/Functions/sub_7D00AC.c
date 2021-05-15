// sub_7D00AC 
 
void __fastcall sub_7D00AC(_DWORD *a1)
{
  int v1; // r3

  if ( a1[1] )
  {
    v1 = a1[101];
    __dmb(0xBu);
    if ( !v1 && (_DWORD *)a1[10] == a1 + 10 )
      JUMPOUT(0x789F04);
  }
  JUMPOUT(0x789F02);
}
