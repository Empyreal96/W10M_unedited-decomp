// KiAssignAllNodesToGroup0 
 
void KiAssignAllNodesToGroup0()
{
  unsigned int v0; // r1
  int v1; // r2
  unsigned __int16 v2; // r5
  int v3; // r2
  char v4; // r3

  v0 = (unsigned __int16)KeNumberNodes;
  KiMaximumGroups = 1;
  v1 = 0;
  if ( KeNumberNodes )
  {
    v2 = 0;
    do
    {
      v3 = (int)*(&KeNodeBlock + v1);
      v4 = *(_BYTE *)(v3 + 289);
      *(_WORD *)(v3 + 264) = 0;
      *(_DWORD *)(v3 + 256) = (1 << v0) - 1;
      *(_BYTE *)(v3 + 289) = v4 | 2;
      v1 = ++v2;
    }
    while ( v2 < v0 );
  }
}
