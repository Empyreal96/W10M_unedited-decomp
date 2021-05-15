// EmpEvaluateUpdateRuleEvalState 
 
int __fastcall EmpEvaluateUpdateRuleEvalState(_DWORD *a1, int a2)
{
  int v2; // r4
  int v3; // r7
  unsigned int v5; // r5
  int v6; // r9
  int result; // r0
  unsigned int v8; // r6
  unsigned int j; // r2
  int v10; // r3
  int v11; // r1
  _DWORD *v12; // r8
  _DWORD *v13; // r2
  unsigned int i; // r2
  int v15; // r1
  int v16; // r6
  int v17; // r2
  _DWORD *v18; // [sp+0h] [bp-20h]

  v2 = a1[1];
  v3 = 0;
  v5 = *(_DWORD *)(v2 + 40);
  v18 = a1;
  v6 = 0;
  if ( !*(_BYTE *)(v2 + 20) )
    return sub_554370();
  v8 = 0;
  if ( !v5 )
    goto LABEL_4;
  do
  {
    v11 = *(_DWORD *)(*(_DWORD *)(v2 + 44) + 4 * v8);
    if ( *(_DWORD *)(v11 + 36) != v11 + 36 )
    {
      v12 = *(_DWORD **)(v11 + 36);
      if ( v12 != (_DWORD *)(v11 + 36) )
      {
        do
        {
          ((void (__fastcall *)(_DWORD, _DWORD))*(v12 - 2))(*(_DWORD *)(*(_DWORD *)(v2 + 44) + 4 * v8), *(v12 - 1));
          v12 = (_DWORD *)*v12;
        }
        while ( v12 != (_DWORD *)(*(_DWORD *)(*(_DWORD *)(v2 + 44) + 4 * v8) + 36) );
      }
    }
    v13 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)(v2 + 44) + 4 * v8) + 28);
    if ( (_DWORD *)*v13 == v13 )
      JUMPOUT(0x554374);
    ++v8;
  }
  while ( v8 < v5 );
  result = ExAllocatePoolWithTag(1, 4 * v5);
  v3 = result;
  if ( result )
  {
    a1 = v18;
    for ( i = 0; i < *(_DWORD *)(v2 + 40); ++i )
    {
      v15 = *(_DWORD *)(*(_DWORD *)(v2 + 44) + 4 * i);
      if ( v15 != a2 )
        *(_DWORD *)(v15 + 24) = *(_DWORD *)(v15 + 28);
    }
    while ( 1 )
    {
LABEL_4:
      for ( j = 0; j < v5; ++j )
        *(_DWORD *)(v3 + 4 * j) = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v2 + 44) + 4 * j) + 24) - 8;
      result = EmpEvaluateTargetRule(a1, v3, v5);
      if ( result == 2 )
      {
        v6 = 2;
LABEL_9:
        *(_DWORD *)(v2 + 16) = v6;
        if ( v3 )
          result = ExFreePoolWithTag(v3, 1986350405);
        return result;
      }
      if ( !v5 )
      {
LABEL_7:
        v10 = 1;
        goto LABEL_8;
      }
      v16 = *(_DWORD *)(*(_DWORD *)(v2 + 44) + 4 * (v5 - 1));
      if ( v5 == 1 )
        result = 1;
      else
        result = EmpEvaluatePermuteRuleEntries(v2, v5 - 1, a2, 0);
      if ( v16 != a2 )
      {
        if ( !result )
          goto LABEL_34;
        v17 = **(_DWORD **)(v16 + 24);
        if ( v17 != v16 + 28 )
        {
          *(_DWORD *)(v16 + 24) = v17;
          goto LABEL_34;
        }
        *(_DWORD *)(v16 + 24) = *(_DWORD *)(v16 + 28);
      }
      if ( result )
        goto LABEL_7;
LABEL_34:
      v10 = 0;
LABEL_8:
      if ( v10 )
        goto LABEL_9;
      a1 = v18;
    }
  }
  return result;
}
