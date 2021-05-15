// EmpInfParseGetStringIndexFromName 
 
int __fastcall EmpInfParseGetStringIndexFromName(int a1, int a2, _DWORD *a3)
{
  unsigned int *v4; // r9
  int v5; // r4
  int v6; // r5
  unsigned int v7; // r6
  int *v8; // r7
  int v9; // t1
  int result; // r0

  v4 = (unsigned int *)EmpInfParseGetValueFromSectionAndKeyName(a1, "Strings", a2);
  if ( !v4 )
    goto LABEL_10;
  v5 = 0;
  v6 = 0;
  v7 = EmpNumberOfStrings;
  if ( EmpNumberOfStrings )
  {
    v8 = (int *)EmpStringTable;
    while ( 1 )
    {
      v9 = *v8++;
      if ( !strcmp(v9, v4) )
        break;
      if ( ++v5 >= v7 )
        goto LABEL_8;
    }
    v6 = 1;
  }
LABEL_8:
  *a3 = v5;
  if ( v6 )
    result = 0;
  else
LABEL_10:
    result = -1073741275;
  return result;
}
