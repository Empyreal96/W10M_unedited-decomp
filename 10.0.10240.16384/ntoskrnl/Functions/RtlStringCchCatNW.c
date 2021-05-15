// RtlStringCchCatNW 
 
int __fastcall RtlStringCchCatNW(unsigned __int16 *a1, unsigned int a2, int a3, unsigned int a4)
{
  int result; // r0
  int v9; // r4
  unsigned int v10; // r1
  unsigned __int16 *v11; // r2
  unsigned int v12; // r3
  int v13; // r5
  int v14[6]; // [sp+0h] [bp-18h] BYREF

  v14[0] = a4;
  result = 0;
  if ( !a2 || a2 > 0x7FFFFFFF )
    result = -1073741811;
  if ( result < 0 )
  {
    v9 = 0;
  }
  else
  {
    result = sub_43E3D8(a1, a2, v14);
    v9 = v14[0];
  }
  if ( result >= 0 )
  {
    if ( a4 > 0x7FFFFFFE )
    {
      result = -1073741811;
    }
    else
    {
      v10 = a2 - v9;
      v11 = &a1[v9];
      result = 0;
      if ( a2 == v9 )
        goto LABEL_8;
      v12 = a4;
      v13 = a3 - (_DWORD)v11;
      do
      {
        if ( !v12 )
          break;
        if ( !*(unsigned __int16 *)((char *)v11 + v13) )
          break;
        *v11 = *(unsigned __int16 *)((char *)v11 + v13);
        --v10;
        ++v11;
        --v12;
      }
      while ( v10 );
      if ( !v10 )
LABEL_8:
        result = sub_50B524(0, v10, v11);
      else
        *v11 = 0;
    }
  }
  return result;
}
