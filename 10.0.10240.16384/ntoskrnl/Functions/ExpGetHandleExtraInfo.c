// ExpGetHandleExtraInfo 
 
int __fastcall ExpGetHandleExtraInfo(int a1, unsigned int a2)
{
  int v2; // r4
  _DWORD *v3; // r0
  int result; // r0

  v2 = (a2 >> 2) & 0x1FF;
  v3 = (_DWORD *)ExpLookupHandleTableEntry(a1, a2 & 0xFFFFF803);
  if ( v3 && *v3 )
    result = *v3 + 4 * v2;
  else
    result = 0;
  return result;
}
