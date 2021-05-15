// MiVaIsPageFileHash 
 
int __fastcall MiVaIsPageFileHash(int a1, unsigned int a2)
{
  __int16 *v2; // r2
  unsigned int v3; // r6
  unsigned int v4; // r4
  int result; // r0
  unsigned int v6; // r5

  v2 = &MiSystemPartition;
  v3 = dword_64050C;
  __dmb(0xBu);
  v4 = 0;
  if ( !v3 )
    return 0;
  while ( 1 )
  {
    result = *((_DWORD *)v2 + 900);
    v6 = *(_DWORD *)(result + 108);
    if ( a2 >= v6 && v6 && a2 < v6 + 4 * *(_DWORD *)(result + 4) )
      break;
    ++v4;
    v2 += 2;
    if ( v4 >= v3 )
      return 0;
  }
  return result;
}
