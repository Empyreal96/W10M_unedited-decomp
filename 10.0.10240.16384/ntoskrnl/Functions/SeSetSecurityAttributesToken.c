// SeSetSecurityAttributesToken 
 
int __fastcall SeSetSecurityAttributesToken(int a1, char a2, int *a3, int a4)
{
  return SepInternalSetSecurityAttributesToken(a1, a2, 0, a3, a4);
}
