// ExpWnfQueryCurrentUserSID 
 
int __fastcall ExpWnfQueryCurrentUserSID(int a1, int a2, int a3, unsigned int *a4, _DWORD *a5)
{
  int v8; // r0
  int v9; // r6
  unsigned int v10; // r4
  int v11; // r5
  char v13[4]; // [sp+8h] [bp-20h] BYREF
  int v14; // [sp+Ch] [bp-1Ch] BYREF
  char v15[24]; // [sp+10h] [bp-18h] BYREF

  if ( a2 )
  {
    v8 = PsReferenceEffectiveToken(a2, &v14, v13, v15, 0);
    v9 = v14;
  }
  else
  {
    v8 = PsReferencePrimaryToken(a1);
    v9 = 1;
  }
  v10 = v8;
  v11 = SeQueryUserSidToken(v8, a3, *a4, a4);
  if ( v9 != 1 )
    return sub_7E9428();
  ObFastDereferenceObject((_DWORD *)(a1 + 244), v10);
  if ( v11 >= 0 )
    *a5 = 1;
  return v11;
}
