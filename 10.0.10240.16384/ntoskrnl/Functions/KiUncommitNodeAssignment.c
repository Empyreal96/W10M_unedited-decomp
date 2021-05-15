// KiUncommitNodeAssignment 
 
void **__fastcall KiUncommitNodeAssignment(void **result)
{
  int v1; // r6
  int v2; // r2
  unsigned int v3; // r5
  unsigned __int16 v4; // r4
  int v5; // r2

  v1 = *((unsigned __int16 *)result + 132);
  v2 = 0;
  v3 = (unsigned __int16)KeNumberNodes;
  if ( KeNumberNodes )
  {
    result = &KeNodeBlock;
    v4 = 0;
    do
    {
      v5 = (int)*(&KeNodeBlock + v2);
      if ( (*(_BYTE *)(v5 + 289) & 2) != 0 && *(unsigned __int16 *)(v5 + 264) == v1 )
        *(_BYTE *)(v5 + 289) &= 0xFBu;
      *(_DWORD *)(v5 + 256) = 0;
      v2 = ++v4;
    }
    while ( v4 < v3 );
  }
  --word_6376C4;
  return result;
}
