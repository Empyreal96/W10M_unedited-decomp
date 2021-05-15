// MiInitializeNumaGraph 
 
int __fastcall MiInitializeNumaGraph(int result)
{
  unsigned int v1; // r5
  unsigned int v2; // r4
  unsigned int v3; // r6
  unsigned int v4; // r7
  int v5; // r8
  int v6; // r1

  v1 = (unsigned __int16)KeNumberNodes;
  if ( *(_DWORD *)(*(_DWORD *)(result + 132) + 116) )
    return sub_96B80C();
  v2 = 0;
  if ( KeNumberNodes )
  {
    v3 = (unsigned __int16)KeNumberNodes;
    do
    {
      v4 = v2;
      if ( v2 < v3 )
      {
        v5 = 2 * v1 * v2;
        do
        {
          if ( !v1 )
            __brkdiv0();
          v6 = v4 % v1;
          result = v4 / v1;
          ++v4;
          *(_WORD *)(v5 + dword_6337E4) = v6 & 0xF;
          v5 += 2;
        }
        while ( v4 < v3 );
      }
      ++v2;
      ++v3;
    }
    while ( v2 < v1 );
  }
  return result;
}
