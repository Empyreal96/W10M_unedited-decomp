// PsAssignImpersonationToken 
 
int __fastcall PsAssignImpersonationToken(int a1, int a2, int a3, int a4)
{
  int v5; // r2
  int v6; // r4
  int result; // r0
  int v8; // r6
  int v10[4]; // [sp+8h] [bp-10h] BYREF

  v10[0] = a4;
  v5 = __mrc(15, 0, 13, 0, 3);
  if ( !a2 )
  {
    PsImpersonateClient(a1, 0, 0, 0, 2, a3);
    return 0;
  }
  result = ObReferenceObjectByHandle(a2, 4, SeTokenObjectType, *(char *)((v5 & 0xFFFFFFC0) + 0x15A), v10);
  if ( result >= 0 )
  {
    v8 = v10[0];
    if ( *(_DWORD *)(v10[0] + 168) == 2 )
    {
      v6 = PsImpersonateClient(a1, v10[0], 0, 0, *(_DWORD *)(v10[0] + 172), 0);
      ObfDereferenceObject(v8);
      return v6;
    }
    result = sub_7F7BF0();
  }
  return result;
}
