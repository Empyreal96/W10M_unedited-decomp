// KiUpdateMinimumWeight 
 
int __fastcall KiUpdateMinimumWeight(int a1, int a2, _DWORD *a3)
{
  int v5; // r4
  unsigned int v6; // r1
  int *v7; // lr
  int *v8; // r7
  int v9; // r0
  int v10; // r5
  unsigned int v11; // r3

  if ( a1 )
  {
    if ( a3 )
      v5 = a3[3];
    else
      v5 = KiGroupSchedulingMinimumRate;
    v6 = 10000;
  }
  else
  {
    if ( a3 )
      v5 = a3[4];
    else
      v5 = KiGroupSchedulingMinimumWeight;
    v6 = 9;
  }
  if ( a3 )
    v7 = a3 + 13;
  else
    v7 = &KiSchedulingGroupList;
  v8 = (int *)*v7;
  v9 = 0;
  v10 = 0;
  do
  {
    if ( (*(v8 - 9) & 1) == a1 )
    {
      if ( !a2 && *((unsigned __int16 *)v8 - 20) == v5 )
        return 0;
      v11 = *((unsigned __int16 *)v8 - 20);
      if ( v11 < v6 )
        v6 = *((unsigned __int16 *)v8 - 20);
      v9 += v11;
      ++v10;
    }
    v8 = (int *)*v8;
  }
  while ( v8 != v7 );
  if ( a1 )
  {
    if ( v10 )
    {
      if ( a3 )
        a3[3] = v6;
      else
        KiGroupSchedulingMinimumRate = v6;
    }
    else if ( a3 )
    {
      a3[3] = 0;
    }
    else
    {
      KiGroupSchedulingMinimumRate = 0;
    }
    return 1;
  }
  if ( !v10 )
  {
    if ( a3 )
    {
      a3[4] = 0;
      a3[5] = 0;
    }
    else
    {
      KiGroupSchedulingMinimumWeight = 0;
      KiGroupSchedulingTotalWeight = 0;
    }
    return 1;
  }
  if ( !a3 )
  {
    KiGroupSchedulingMinimumWeight = v6;
    if ( a2 )
      KiGroupSchedulingTotalWeight = v9;
    return 1;
  }
  return sub_515980(v9, v6);
}
