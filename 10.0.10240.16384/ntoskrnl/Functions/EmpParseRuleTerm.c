// EmpParseRuleTerm 
 
int __fastcall EmpParseRuleTerm(int a1, _BYTE *a2, _DWORD *a3, int *a4, _DWORD *a5)
{
  int v8; // r5
  _BYTE *v9; // r0
  _BYTE *v10; // r10
  int v11; // r4
  _DWORD *v12; // r0
  __int64 v13; // r6
  int v14; // r8
  int v15; // r9
  int v16; // r0
  _DWORD *v18; // r0
  char v20[48]; // [sp+10h] [bp-30h] BYREF

  v8 = 0;
  v9 = strchr(a2 + 1, 40);
  v10 = v9;
  if ( !v9 )
    return -1073741811;
  *v9 = 0;
  if ( *a2 == 63 )
  {
    v11 = EmpInfParseGetGuidFromName(a1, "CallbackGuidDef", a2 + 1, v20);
    if ( v11 < 0 )
      return v11;
    v18 = EmpSearchCallbackDatabase((unsigned int)v20);
    if ( v18 )
    {
      *a3 = v18;
      v13 = *(_QWORD *)(v18 + 9);
      v14 = v18[11];
      goto LABEL_6;
    }
    return -1073741275;
  }
  v11 = EmpInfParseGetGuidFromName(a1, "RuleNameGuidDef", a2 + 1, v20);
  if ( v11 < 0 )
    return v11;
  v12 = EmpSearchRuleDatabase((unsigned int)v20);
  if ( !v12 )
    return -1073741275;
  *a3 = v12;
  v13 = *((_QWORD *)v12 + 4);
  v14 = v12[10];
LABEL_6:
  v15 = v14 + HIDWORD(v13) + v13;
  *v10 = 40;
  if ( v15 )
  {
    v16 = ExAllocatePoolWithTag(1, 4 * v15, 1953713477);
    v8 = v16;
    if ( !v16 )
      return -1073741670;
    if ( !EmpParseRuleTermArgMapping(v10, v16, v13, HIDWORD(v13), v14) )
      return sub_96BB3C();
  }
  *a4 = v8;
  *a5 = v15;
  return v11;
}
