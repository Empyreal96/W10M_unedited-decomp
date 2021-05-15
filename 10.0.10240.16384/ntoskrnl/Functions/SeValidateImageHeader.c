// SeValidateImageHeader 
 
int __fastcall SeValidateImageHeader(int a1, int a2, int a3, int a4, int a5, int a6, unsigned __int8 a7, int a8, int a9)
{
  int *v9; // r5
  int v11; // r4
  unsigned int v13; // r1
  int v14; // [sp+20h] [bp-20h] BYREF
  char v15[28]; // [sp+24h] [bp-1Ch] BYREF

  v9 = 0;
  v14 = 0;
  if ( !dword_61D890 )
    return -1073740760;
  if ( (a5 & 1) != 0 )
  {
    do
      v13 = __ldrex(&dword_641DC8);
    while ( !v13 && __strex(0, &dword_641DC8) );
    __dmb(0xBu);
    if ( v13 )
      v9 = &v14;
  }
  v11 = dword_61D890(a1, a2, a3, a4, a5, a6, a7, a8, a9, v9, v15);
  if ( v11 >= 0 && v14 )
    return sub_7D51E0();
  return v11;
}
