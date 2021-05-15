// PspInitializeProcessSecurity 
 
int __fastcall PspInitializeProcessSecurity(int a1, int a2, int a3, int a4, _DWORD *a5)
{
  int v8; // r0
  int v9; // r1
  int v10; // r4
  int result; // r0
  char v12[4]; // [sp+8h] [bp-20h] BYREF
  int v13[7]; // [sp+Ch] [bp-1Ch] BYREF

  *a5 = 0;
  if ( a1 )
  {
    v8 = MmGetSessionId(a2);
    v10 = SeSubProcessToken(a2, a3, v13, v9, v8, v12);
    if ( v10 >= 0 )
    {
      ObInitializeFastReference(a2 + 244, v13[0]);
      if ( a4 || v12[0] )
        *a5 = 1;
    }
    result = v10;
  }
  else
  {
    *(_DWORD *)(a2 + 244) = 0;
    if ( SeAuditingWithTokenForSubcategory(133) )
      SepAuditAssignPrimaryToken(a2, a3);
    result = sub_7F6758();
  }
  return result;
}
