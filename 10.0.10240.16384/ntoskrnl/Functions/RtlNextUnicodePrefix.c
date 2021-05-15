// RtlNextUnicodePrefix 
 
int __fastcall RtlNextUnicodePrefix(int a1, int a2)
{
  if ( !a2 )
    return sub_81CA34();
  if ( **(_WORD **)(a1 + 4) != 2048 )
    JUMPOUT(0x81CA84);
  return 0;
}
