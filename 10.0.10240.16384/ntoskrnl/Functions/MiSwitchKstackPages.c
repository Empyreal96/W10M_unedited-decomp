// MiSwitchKstackPages 
 
int __fastcall MiSwitchKstackPages(int a1, int *a2)
{
  unsigned __int8 *v3; // r0
  unsigned int v4; // r2
  int result; // r0
  unsigned int *v6; // r2

  v3 = (unsigned __int8 *)(a1 + 15);
  do
    v4 = __ldrex(v3);
  while ( __strex(v4 | 0x80, v3) );
  __dmb(0xBu);
  if ( v4 >> 7 )
    return sub_514174();
  MiCopyPfnEntry(a1, a2);
  *(_BYTE *)(a1 + 18) = *(_BYTE *)(a1 + 18) & 0xF8 | 6;
  *(_DWORD *)(a1 + 20) = *(_DWORD *)(a1 + 20) & 0xF8FFFFFF | 0x2000000;
  __dmb(0xBu);
  v6 = (unsigned int *)(a1 + 12);
  do
    result = __ldrex(v6);
  while ( __strex(result & 0x7FFFFFFF, v6) );
  return result;
}
