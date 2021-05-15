// ObpGrantAccess 
 
int __fastcall ObpGrantAccess(int a1, int a2, int a3, int a4, __int16 a5, _DWORD *a6)
{
  int v7; // lr
  int result; // r0
  int v9[8]; // [sp+8h] [bp-20h] BYREF

  v9[0] = a3;
  v9[1] = a4;
  v7 = (char)a4;
  if ( (a5 & 0x400) != 0 )
    v7 = 1;
  if ( a1 != 1 && a1 != 2 )
    return sub_7C4658();
  if ( !ObCheckObjectAccess(a2, a3, 1, v7, v9, a2) )
    return v9[0];
  result = 0;
  *a6 = *(_DWORD *)(a3 + 20);
  return result;
}
