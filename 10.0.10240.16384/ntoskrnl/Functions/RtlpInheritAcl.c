// RtlpInheritAcl 
 
int __fastcall RtlpInheritAcl(int a1, int a2, int a3, int a4, unsigned __int8 a5, unsigned __int8 a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, unsigned int *a15, _BYTE *a16, int *a17)
{
  int v21; // r2
  int result; // r0
  int v23; // r1
  int v24; // r0
  int v25; // r9
  int v26; // [sp+38h] [bp-28h] BYREF
  int v27; // [sp+3Ch] [bp-24h]

  if ( a3 || a1 )
  {
    v23 = 200;
    v26 = 200;
    v27 = 0;
    while ( 1 )
    {
      v24 = ExAllocatePoolWithTag(1, v23, 1665230163);
      *a15 = v24;
      if ( !v24 )
        break;
      v25 = RtlpInheritAcl2(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, &v26, v24, a16, a17);
      if ( v25 >= 0 )
      {
        if ( !v26 )
          return sub_7FB090();
        return v25;
      }
      ExFreePoolWithTag(*a15);
      *a15 = 0;
      if ( v25 != -1073741789 )
        return v25;
      if ( (unsigned int)++v27 >= 2 )
        return v25;
      v23 = v26;
    }
    result = -1073741801;
  }
  else
  {
    *a16 = 0;
    if ( a5 )
      v21 = 1024;
    else
      v21 = 0;
    *a17 = v21;
    *a15 = 0;
    result = -2147483637;
  }
  return result;
}
