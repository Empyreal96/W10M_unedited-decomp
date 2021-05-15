// AuthzBasepEvaluateExpression 
 
int __fastcall AuthzBasepEvaluateExpression(int a1, _DWORD *a2, int *a3)
{
  int v6; // r5
  __int64 v7; // r0
  int v8; // r7
  int v9; // r3
  int v10; // r0
  int v12; // r0

  *a3 = 0;
  v6 = 0;
  v7 = AuthzBasepGetOperandTypeForEvaluation(a2);
  v8 = v7;
  if ( !AuthzBasepOperandValueTypesCompatible(HIDWORD(v7)) )
    goto LABEL_2;
  if ( a1 > 136 )
  {
    if ( a1 == 142 )
    {
LABEL_9:
      v10 = AuthzBasepEvaluateSetRelationship(1, a2, a3);
LABEL_10:
      v6 = v10;
      goto LABEL_11;
    }
    if ( a1 != 143 )
      return v6;
    goto LABEL_31;
  }
  if ( a1 == 136 )
  {
LABEL_31:
    v6 = AuthzBasepEvaluateSetRelationship(2, a2, a3);
    if ( v6 < 0 )
      goto LABEL_12;
    goto LABEL_11;
  }
  if ( a1 < 128 )
    return v6;
  if ( a1 > 129 )
  {
    if ( a1 > 133 )
    {
      if ( a1 != 134 )
        return v6;
      goto LABEL_9;
    }
    if ( v8 )
    {
      if ( v8 <= 2 )
      {
        v12 = AuthzBasepCompareIntegerOperands(a1, a2);
        goto LABEL_21;
      }
      switch ( v8 )
      {
        case 3:
          v10 = AuthzBasepCompareUnicodeStringOperands(a1, (int)a2, a3, v9);
          goto LABEL_10;
        case 4:
          v10 = AuthzBasepCompareFQBNOperands(a1, (int)a2, a3, v9);
          goto LABEL_10;
        case 5:
        case 16:
          v12 = AuthzBasepCompareOctetStringOperands(a1, a2);
LABEL_21:
          *a3 = v12;
          return v6;
      }
    }
LABEL_2:
    v6 = -1073741406;
LABEL_12:
    *a3 = -1;
    return v6;
  }
  v6 = AuthzBasepEvaluateSetRelationship(0, a2, a3);
  if ( v6 < 0 )
    goto LABEL_12;
  if ( a1 == 129 && *a3 != -1 )
    *a3 = *a3 == 0;
LABEL_11:
  if ( v6 < 0 )
    goto LABEL_12;
  return v6;
}
