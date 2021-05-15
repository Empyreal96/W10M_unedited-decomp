// ExpCovReadFriendlyName 
 
int __fastcall ExpCovReadFriendlyName(int a1, int a2, unsigned __int16 *a3)
{
  int *v5; // r2
  int result; // r0
  int v7; // r3
  _DWORD v8[4]; // [sp+8h] [bp-10h] BYREF

  v8[0] = a3;
  v8[1] = 0;
  v5 = (int *)(*(_DWORD *)(a1 + 36) + a1);
  if ( *v5 == 327680 )
  {
    result = RtlInitAnsiStringEx((int)v8, a1 + v5[3]);
    if ( result >= 0 )
      result = RtlAnsiStringToUnicodeString(a3, (unsigned __int16 *)v8, 1, v7);
  }
  else
  {
    DbgPrintEx(
      126,
      2,
      (int)"COV: Instrumentation Version %ul is not yet supported in kernel hence defaulting to binary name instead of fr"
           "iendly name for %wZ\n",
      *v5);
    result = RtlDuplicateUnicodeString(1, a2, (int)a3);
  }
  return result;
}
