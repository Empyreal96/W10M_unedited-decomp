// CmpCopyName 
 
int __fastcall CmpCopyName(int a1, unsigned __int16 *a2)
{
  int v2; // r2
  unsigned int v3; // r3

  v2 = 0;
  if ( (*a2 & 0xFFFE) == 0 )
    return *a2 >> 1;
  while ( 1 )
  {
    v3 = *(unsigned __int16 *)(*((_DWORD *)a2 + 1) + 2 * v2);
    if ( v3 > 0xFF )
      break;
    *(_BYTE *)(v2 + a1) = v3;
    if ( ++v2 >= (unsigned int)(*a2 >> 1) )
      return *a2 >> 1;
  }
  return sub_803B94();
}
