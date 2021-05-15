// ExpCovIsModulePresent 
 
int __fastcall ExpCovIsModulePresent(int a1, int a2, int a3, unsigned __int16 *a4, unsigned __int8 *a5)
{
  int v6; // r5
  int v7; // r4
  int v9; // [sp+0h] [bp-18h] BYREF
  int v10; // [sp+4h] [bp-14h]

  v6 = 0;
  v7 = 0;
  v9 = 0;
  v10 = 0;
  if ( !a3 )
    goto LABEL_7;
  if ( a3 != 1 )
  {
    if ( a3 != 2 )
      return v7;
    if ( ExpCovReadFriendlyName(a2, a1, &v9) < 0 || RtlCompareUnicodeString(a4, (unsigned __int16 *)&v9, 1) )
    {
      v6 = v10;
LABEL_8:
      if ( v6 )
        RtlFreeAnsiString(&v9);
      return v7;
    }
    v6 = v10;
LABEL_7:
    v7 = 1;
    goto LABEL_8;
  }
  if ( RtlCompareMemory(a5, a2 + 8, 16) == 16 )
    v7 = 1;
  return v7;
}
