// WdipSemAddScenarioToTable 
 
int __fastcall WdipSemAddScenarioToTable(unsigned int a1)
{
  int v2; // r4
  int v3; // r8
  unsigned int v4; // r7
  unsigned int *v5; // r10
  unsigned int v6; // r9
  unsigned int v7; // t1

  v2 = 0;
  if ( !a1 )
    return -1073741811;
  v3 = 0;
  v4 = dword_61C880;
  if ( dword_61C880 )
  {
    v5 = (unsigned int *)WdipSemScenarioTable;
    while ( 1 )
    {
      v7 = *v5++;
      v6 = v7;
      if ( !memcmp(v7, a1, 16) && *(unsigned __int16 *)(v6 + 16) == *(unsigned __int16 *)(a1 + 16) )
        break;
      if ( ++v3 >= v4 )
        goto LABEL_8;
    }
    v2 = WdipSemMergeScenarios(a1, v6);
    if ( v2 >= 0 )
    {
      WdipSemScenarioTable[v3] = a1;
      WdipSemFreeScenario(v6);
    }
  }
  else
  {
LABEL_8:
    if ( v4 < 0x40 )
    {
      WdipSemScenarioTable[v4] = a1;
      ++dword_61C880;
    }
    else
    {
      v2 = -1073741823;
    }
  }
  return v2;
}
