// RtlpFreeAllAtom 
 
int __fastcall RtlpFreeAllAtom(int a1, int a2)
{
  int result; // r0
  int v4; // r5
  _DWORD *v5; // [sp+10h] [bp-18h] BYREF
  char v6[20]; // [sp+14h] [bp-14h] BYREF
  int vars8[2]; // [sp+30h] [bp+8h] BYREF

  vars8[1] = a2;
  vars8[0] = a1;
  result = RtlpHashStringToAtom(a2, a1 + 26, 0, &v5, 0, v6, vars8);
  if ( result >= 0 )
  {
    v4 = vars8[0];
    if ( vars8[0] )
    {
      if ( v5 )
        *v5 = *(_DWORD *)vars8[0];
      if ( *(_DWORD *)(v4 + 8) == v4 + 8 )
      {
        RtlpFreeHandleForAtom(a2, v4);
        result = RtlpFreeAtom(v4);
      }
      else
      {
        result = sub_50FE90();
      }
    }
  }
  return result;
}
