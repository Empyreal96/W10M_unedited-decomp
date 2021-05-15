// KeBuildLogicalProcessorSystemInformation 
 
int __fastcall KeBuildLogicalProcessorSystemInformation(int a1, _DWORD *a2, unsigned int a3, unsigned int *a4)
{
  unsigned int v7; // r6
  int v9; // r10
  unsigned int v11; // r2
  unsigned int v12; // r4
  void **v13; // r0
  int v14; // r3
  int v15; // t1
  int v16; // r1

  v7 = 0;
  v9 = 0;
  if ( KeNumberProcessors_0 )
    return sub_7E833C();
  v11 = 0;
  v12 = (unsigned __int16)KeNumberNodes;
  if ( KeNumberNodes )
  {
    v13 = &KeNodeBlock;
    do
    {
      v15 = (int)*v13++;
      v14 = v15;
      v16 = *(_DWORD *)(v15 + 260);
      if ( v16 && *(unsigned __int16 *)(v14 + 264) == a1 )
      {
        v7 += 24;
        if ( v7 <= a3 )
        {
          *a2 = v16;
          a2[1] = 1;
          a2[4] = 0;
          a2[5] = 0;
          a2[2] = 0;
          a2[3] = 0;
          a2[2] = v11;
          a2 += 6;
        }
        else
        {
          v9 = -1073741820;
        }
      }
      ++v11;
    }
    while ( v11 < v12 );
  }
  *a4 = v7;
  return v9;
}
