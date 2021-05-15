// ExpIsValidUILanguage 
 
int __fastcall ExpIsValidUILanguage(unsigned __int16 *a1)
{
  unsigned __int16 *v1; // r1
  int v2; // r4
  int v3; // r2
  int v4; // t1
  char v6[8]; // [sp+28h] [bp-128h] BYREF
  int v7; // [sp+3Ch] [bp-114h]
  __int16 v8; // [sp+44h] [bp-10Ch]

  v1 = a1;
  v2 = 0;
  v3 = 0;
  if ( *a1 )
  {
    do
    {
      v4 = a1[1];
      ++a1;
      ++v3;
    }
    while ( v4 );
    if ( v3 >= 8 )
      v1 += 4;
  }
  RtlInitUnicodeString((unsigned int)v6, v1);
  if ( ZwOpenKey() >= 0 )
  {
    if ( ZwQueryValueKey() >= 0 && v7 == 1 && v8 == 49 )
      v2 = 1;
    ZwClose();
  }
  return v2;
}
