// SepRegQueryDwordValue 
 
int __fastcall SepRegQueryDwordValue(int a1, int a2, int a3, int a4)
{
  int v5; // r4
  int v8[4]; // [sp+8h] [bp-10h] BYREF

  v8[1] = a4;
  v8[0] = 0;
  v5 = SepRegOpenKey(L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Lsa", 513, v8);
  if ( v5 >= 0 )
  {
    v5 = SepRegQueryValue(v8[0], L"EveryoneIncludesAnonymous", 4, 4, a3, a2);
    ZwClose();
  }
  return v5;
}
