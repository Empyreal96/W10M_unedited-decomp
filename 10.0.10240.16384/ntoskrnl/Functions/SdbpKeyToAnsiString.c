// SdbpKeyToAnsiString 
 
int __fastcall SdbpKeyToAnsiString(int a1, int a2, int a3, int a4)
{
  int v4; // r1
  char *v5; // r0
  char v6; // t1
  int varg_r1[3]; // [sp+Ch] [bp-Ch] BYREF

  HIBYTE(varg_r1[0]) = HIBYTE(a2);
  varg_r1[1] = a3;
  varg_r1[2] = a4;
  v4 = 0;
  v5 = (char *)varg_r1 + 3;
  do
  {
    v6 = *v5--;
    *(_BYTE *)(v4 + a3) = v6;
    ++v4;
  }
  while ( v4 < 8 );
  *(_BYTE *)(a3 + 8) = 0;
  return a3;
}
