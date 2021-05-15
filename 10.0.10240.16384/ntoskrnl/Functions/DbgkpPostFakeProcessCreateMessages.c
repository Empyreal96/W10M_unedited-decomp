// DbgkpPostFakeProcessCreateMessages 
 
int __fastcall DbgkpPostFakeProcessCreateMessages(int a1, int a2, int *a3)
{
  int result; // r0
  int v7; // r3
  int v8; // [sp+8h] [bp-30h] BYREF
  int v9; // [sp+Ch] [bp-2Ch] BYREF
  char v10[40]; // [sp+10h] [bp-28h] BYREF

  result = DbgkpPostFakeThreadMessages(a1, a2, 0, &v8, &v9);
  if ( result < 0 )
  {
    v7 = 0;
  }
  else
  {
    KiStackAttachProcess(a1, 0, (int)v10);
    DbgkpPostModuleMessages(a1, v8, a2);
    KiUnstackDetachProcess((unsigned int)v10, 0);
    ObfDereferenceObjectWithTag(v8);
    v7 = v9;
    result = 0;
  }
  *a3 = v7;
  return result;
}
