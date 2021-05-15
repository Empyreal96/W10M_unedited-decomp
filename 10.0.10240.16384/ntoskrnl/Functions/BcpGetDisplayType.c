// BcpGetDisplayType 
 
int __fastcall BcpGetDisplayType(unsigned int a1, unsigned int a2, int a3, int a4)
{
  int result; // r0
  _DWORD *v6; // r2
  unsigned int varg_r0; // [sp+10h] [bp+8h]

  varg_r0 = a1;
  result = 0;
  v6 = &unk_616188;
  do
  {
    if ( a1 < v6[12] )
      break;
    if ( a2 < v6[13] )
      break;
    ++result;
    v6 += 14;
  }
  while ( result < 4 );
  return result;
}
