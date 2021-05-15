// MiSessionWsMetaPage 
 
int __fastcall MiSessionWsMetaPage(int a1)
{
  int result; // r0

  if ( dword_633790 && dword_633798 )
    result = MiPageInRange(
               a1,
               (((unsigned int)dword_633790 >> 10) & 0x3FFFFC) - 0x40000000,
               (((unsigned int)(dword_633798 - 1) >> 10) & 0x3FFFFC) - 0x40000000,
               1);
  else
    result = 0;
  return result;
}
