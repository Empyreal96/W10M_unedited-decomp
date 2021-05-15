// toupper 
 
int __fastcall toupper(int a1, int a2)
{
  __int16 v3; // [sp+8h] [bp-20h] BYREF
  char v4[4]; // [sp+Ch] [bp-1Ch] BYREF
  int *v5; // [sp+10h] [bp-18h] BYREF
  int v6; // [sp+14h] [bp-14h] BYREF
  int v7[2]; // [sp+20h] [bp-8h] BYREF

  v7[0] = a1;
  v7[1] = a2;
  v5 = v7;
  v3 = RtlAnsiCharToUnicodeChar(&v5);
  if ( RtlUpcaseUnicodeToMultiByteN(v4, 2, &v6, &v3, 2) < 0 )
    return v7[0];
  if ( v6 == 1 )
    return (unsigned __int8)v4[0];
  return (unsigned __int8)v4[1] | ((unsigned __int8)v4[0] << 8);
}
