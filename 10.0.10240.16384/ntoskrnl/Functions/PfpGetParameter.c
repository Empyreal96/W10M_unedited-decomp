// PfpGetParameter 
 
int __fastcall PfpGetParameter(int a1, unsigned __int16 *a2, int a3, int a4, unsigned int *a5)
{
  int result; // r0
  unsigned int v9; // r4
  char v10[8]; // [sp+10h] [bp-130h] BYREF
  int v11; // [sp+1Ch] [bp-124h]
  unsigned int v12; // [sp+20h] [bp-120h]
  char v13[284]; // [sp+24h] [bp-11Ch] BYREF

  RtlInitUnicodeString((unsigned int)v10, a2);
  if ( !a1 )
    return -1073741811;
  result = ZwQueryValueKey();
  if ( result >= 0 )
  {
    if ( v11 == a3 )
    {
      v9 = v12;
      if ( v12 > *a5 )
      {
        result = -1073741789;
      }
      else
      {
        memmove(a4, (int)v13, v12);
        *a5 = v9;
        result = 0;
      }
    }
    else
    {
      result = -1073741788;
    }
  }
  return result;
}
