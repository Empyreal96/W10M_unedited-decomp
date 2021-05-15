// RtlStringCbCatW 
 
int __fastcall RtlStringCbCatW(unsigned __int16 *a1, unsigned int a2, int a3, int a4)
{
  int result; // r0
  unsigned int v7; // r6
  int v8; // r5
  unsigned int v9; // r4
  unsigned __int16 *v10; // r1
  int v11; // r3
  int v12; // r5
  int v13[6]; // [sp+0h] [bp-18h] BYREF

  v13[0] = a4;
  result = 0;
  v7 = a2 >> 1;
  if ( !(a2 >> 1) )
    result = -1073741811;
  if ( result < 0 )
  {
    v8 = 0;
  }
  else
  {
    result = sub_43E3D8(a1, a2 >> 1, v13);
    v8 = v13[0];
  }
  if ( result >= 0 )
  {
    v9 = v7 - v8;
    v10 = &a1[v8];
    result = 0;
    if ( v7 == v8 )
      goto LABEL_7;
    v11 = 2147483646;
    v12 = a3 - (_DWORD)v10;
    do
    {
      if ( !v11 )
        break;
      if ( !*(unsigned __int16 *)((char *)v10 + v12) )
        break;
      *v10 = *(unsigned __int16 *)((char *)v10 + v12);
      --v9;
      ++v10;
      --v11;
    }
    while ( v9 );
    if ( !v9 )
LABEL_7:
      result = sub_50A710(0, v10);
    else
      *v10 = 0;
  }
  return result;
}
