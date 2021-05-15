// ExpIsPoolTagPrintable 
 
int __fastcall ExpIsPoolTagPrintable(unsigned int a1, int a2, int a3, int a4)
{
  int result; // r0
  int v6; // r2
  unsigned int v7; // r1
  unsigned int v8; // r3
  unsigned int v9; // r3
  _DWORD v10[4]; // [sp+0h] [bp-10h] BYREF

  v10[0] = a3;
  v10[1] = a4;
  result = 0;
  v6 = 0;
  v7 = 0;
  while ( 1 )
  {
    v8 = (unsigned __int8)(a1 >> v7);
    *((_BYTE *)v10 + v6) = v8;
    if ( v8 >= 0x61 && v8 <= 0x7A )
      *((_BYTE *)v10 + v6) = v8 - 32;
    v9 = *((unsigned __int8 *)v10 + v6);
    if ( v9 >= 0x41 && v9 <= 0x5A )
      break;
    if ( v9 >= 0x30 && v9 <= 0x39 )
      break;
    v7 += 8;
    ++v6;
    if ( v7 >= 0x20 )
      return result;
  }
  return 1;
}
