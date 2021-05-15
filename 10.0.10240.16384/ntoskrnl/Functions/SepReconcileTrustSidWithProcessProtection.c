// SepReconcileTrustSidWithProcessProtection 
 
int __fastcall SepReconcileTrustSidWithProcessProtection(int a1, unsigned __int8 *a2, _BYTE *a3, int *a4)
{
  int result; // r0
  int v8; // r7
  int *v9; // r3
  unsigned int v10; // r3

  result = *a2;
  *a3 = 0;
  v8 = 0;
  *a4 = 0;
  if ( result >= 81 )
  {
    if ( result > 97 )
    {
      if ( result != 98 )
        goto LABEL_2;
      v9 = &SeProcTrustWinTcbSid;
    }
    else
    {
      if ( result != 97 )
        return sub_52C678();
      v9 = &SeProcTrustLiteWinTcbSid;
    }
    v8 = *v9;
    if ( *v9 )
    {
      result = RtlIsValidProcessTrustLabelSid(*v9);
      if ( !result )
        goto LABEL_10;
    }
  }
LABEL_2:
  if ( !a1 )
    return result;
  result = RtlIsValidProcessTrustLabelSid(a1);
  if ( !result )
  {
LABEL_10:
    *a3 = 1;
    *a4 = v8;
    return result;
  }
  v10 = *(_DWORD *)(a1 + 8);
  if ( !v8 )
  {
    if ( !v10 )
      return result;
    goto LABEL_10;
  }
  if ( *(_DWORD *)(v8 + 8) < v10 || *(_DWORD *)(v8 + 12) < *(_DWORD *)(a1 + 12) )
    goto LABEL_10;
  return result;
}
