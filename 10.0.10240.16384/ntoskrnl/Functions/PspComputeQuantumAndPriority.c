// PspComputeQuantumAndPriority 
 
int __fastcall PspComputeQuantumAndPriority(int a1, int a2, _BYTE *a3, int a4)
{
  _DWORD *v4; // r4
  int v7; // r5

  v4 = (_DWORD *)a4;
  if ( a2 == 1 )
    v7 = 2;
  else
    v7 = 0;
  if ( a4 )
  {
    if ( *(_BYTE *)(a1 + 606) == 2 )
      return sub_7F6724();
    a4 = 0;
    *v4 = 0;
  }
  if ( a2 != 2 )
    MmSetMemoryPriorityProcess(a1, v7, (int)a3, a4);
  *a3 = PspComputeQuantum(a1, v7);
  return PspPriorityTable[*(unsigned __int8 *)(a1 + 375)];
}
