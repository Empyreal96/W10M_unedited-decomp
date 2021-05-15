// MiApplyBytestreamFixup 
 
int __fastcall MiApplyBytestreamFixup(int a1, int a2, int a3)
{
  int result; // r0

  if ( *(_WORD *)(a1 + 12) == 7 )
    result = MiApplyMov32Fixup(a2, a3);
  else
    result = sub_5218E0();
  return result;
}
