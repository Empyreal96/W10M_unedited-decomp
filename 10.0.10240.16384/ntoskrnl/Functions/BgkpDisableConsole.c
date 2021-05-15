// BgkpDisableConsole 
 
int __fastcall BgkpDisableConsole(int result)
{
  unsigned int v1; // r1
  unsigned int v2; // r2

  do
    v1 = __ldrex((unsigned int *)&dword_61646C);
  while ( !v1 && __strex(1u, (unsigned int *)&dword_61646C) );
  __dmb(0xBu);
  if ( v1 != 1 )
    return sub_54D4D4(result, v1, 1);
  __dmb(0xBu);
  do
    v2 = __ldrex((unsigned int *)&dword_61646C);
  while ( __strex(1u, (unsigned int *)&dword_61646C) );
  __dmb(0xBu);
  return result;
}
