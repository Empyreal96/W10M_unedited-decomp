// KiAssignSchedulingGroupWeights 
 
int __fastcall KiAssignSchedulingGroupWeights(int result, int a2, int a3)
{
  int v3; // r7
  int *v5; // r3
  unsigned int v6; // r5
  int *v7; // r6
  int *v8; // r4
  unsigned int v9; // r1

  v3 = result;
  if ( result )
  {
    if ( a3 )
    {
      v6 = *(_DWORD *)(a3 + 12);
      goto LABEL_5;
    }
    v5 = &KiGroupSchedulingMinimumRate;
LABEL_4:
    v6 = *v5;
LABEL_5:
    if ( a3 )
    {
      v8 = *(int **)(a3 + 52);
      v7 = (int *)(a3 + 52);
    }
    else
    {
      v7 = &KiSchedulingGroupList;
      v8 = (int *)KiSchedulingGroupList;
    }
    do
    {
      if ( (*(v8 - 9) & 1) == v3 )
      {
        v9 = *((unsigned __int16 *)v8 - 20) << 7;
        if ( !v6 )
          __brkdiv0();
        result = v9 / v6;
        *(v8 - 8) = v9 / v6;
        if ( !v3 )
          result = KiUpdateCpuTargetByWeight(v8 - 10, a2);
      }
      v8 = (int *)*v8;
    }
    while ( v8 != v7 );
    return result;
  }
  if ( a3 )
    return sub_515970();
  if ( KiGroupSchedulingTotalWeight )
  {
    v5 = &KiGroupSchedulingMinimumWeight;
    goto LABEL_4;
  }
  return result;
}
