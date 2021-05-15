// DbgkpLkmdEnumApcOrDpcDataCallback 
 
int __fastcall DbgkpLkmdEnumApcOrDpcDataCallback(int a1, int a2, int a3)
{
  return (*(int (__fastcall **)(int, int, int))(a3 + 168))(a3 + 128, a1, a2);
}
