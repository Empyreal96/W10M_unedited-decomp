// RtlpValidateKeyTrust 
 
int *__fastcall RtlpValidateKeyTrust(int *a1, __int16 a2, char a3, int a4)
{
  int v7; // [sp+Ch] [bp-4h] BYREF

  v7 = a4;
  if ( (a2 & 0x100) == 0 )
  {
    a1 = &v7;
    if ( ZwQueryKey() < 0 || (a3 & 1) == 0 )
      __fastfail(9u);
  }
  return a1;
}
