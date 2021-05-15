// AuthzBasepGetOperandStringCaseForEvaluation 
 
int __fastcall AuthzBasepGetOperandStringCaseForEvaluation(_DWORD *a1, _BYTE *a2)
{
  int v3; // r3
  char v4; // r3
  unsigned int v5; // r0
  int result; // r0

  if ( a1[3] == 1 )
  {
    v3 = *(_DWORD *)(a1[11] + 16);
  }
  else
  {
    v3 = *(_DWORD *)(a1[4] + 16);
    if ( a1[10] != 1 )
    {
      v4 = (v3 & 2) != 0 || (*(_DWORD *)(a1[11] + 16) & 2) != 0;
      goto LABEL_9;
    }
  }
  v4 = v3 & 2;
LABEL_9:
  *a2 = v4;
  v5 = KeGetCurrentIrql(a1);
  if ( *a2 || v5 < 2 )
    result = 0;
  else
    result = -1073741637;
  return result;
}
