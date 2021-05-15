// CmpCheckCreateAccess 
 
int __fastcall CmpCheckCreateAccess(int a1, int a2, int a3, char a4, int a5, int a6)
{
  int v8; // r4
  int result; // r0
  int v10[6]; // [sp+18h] [bp-18h] BYREF

  v10[0] = 0;
  v8 = SeAccessCheck(a2, a3 + 28, 0, a5 | 4, 0, 0, (int)CmKeyObjectType + 52, a4, (int)v10, a6);
  if ( v8 && (a5 & 0x20) != 0 && RtlIsSandboxedToken((char *)(a3 + 28), a4) )
    result = sub_8056CC();
  else
    result = v8;
  return result;
}
