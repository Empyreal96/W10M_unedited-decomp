// MiUpdatePfnProtection 
 
int __fastcall MiUpdatePfnProtection(int a1, int a2, int a3)
{
  unsigned __int8 *v4; // r1
  unsigned int v5; // r4
  int result; // r0
  unsigned int v7; // r4
  unsigned int *v8; // r2
  unsigned int v9; // r4

  v4 = (unsigned __int8 *)(a2 + 15);
  do
    v5 = __ldrex(v4);
  while ( __strex(v5 | 0x80, v4) );
  __dmb(0xBu);
  if ( v5 >> 7 )
    return sub_53EA9C();
  v7 = *(_DWORD *)(a2 + 8);
  result = MiSanitizePfnProtection(a1, (v7 >> 5) & 0x1F, a3);
  *(_DWORD *)(a2 + 8) = ((unsigned __int16)v7 ^ (unsigned __int16)(32 * result)) & 0x3E0 ^ v7;
  __dmb(0xBu);
  v8 = (unsigned int *)(a2 + 12);
  do
    v9 = __ldrex(v8);
  while ( __strex(v9 & 0x7FFFFFFF, v8) );
  return result;
}
