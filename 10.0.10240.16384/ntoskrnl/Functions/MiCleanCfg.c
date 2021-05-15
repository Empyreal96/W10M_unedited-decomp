// MiCleanCfg 
 
int __fastcall MiCleanCfg(int result, int a2, int a3)
{
  int v3; // r3

  v3 = __mrc(15, 0, 13, 0, 3);
  if ( MEMORY[0xC0402154] )
    result = sub_52633C(result, a2, a3, v3);
  return result;
}
