// RtlIsNameInExpression 
 
int __fastcall RtlIsNameInExpression(int a1, int *a2, int a3, int a4)
{
  int v6; // r0
  unsigned __int8 v8; // [sp+0h] [bp-20h]
  int v9; // [sp+8h] [bp-18h] BYREF
  int v10; // [sp+Ch] [bp-14h]

  if ( !a3 || a4 )
  {
    v10 = 0;
  }
  else
  {
    v6 = RtlpUpcaseUnicodeStringPrivate(&v9, a2);
    if ( v6 < 0 )
      RtlRaiseStatus(v6);
    a2 = &v9;
    a3 = 0;
  }
  v8 = RtlpIsNameInExpressionPrivate(a1, a2, a3, a4, 0);
  if ( v10 )
    RtlFreeAnsiString(&v9);
  return v8;
}
