// RtlpFreeAllAtom 
 
void __fastcall RtlpFreeAllAtom(int a1, int a2)
{
  int v3; // r5
  int *v4; // [sp+10h] [bp-18h] BYREF
  char v5[20]; // [sp+14h] [bp-14h] BYREF
  int vars8[2]; // [sp+30h] [bp+8h] BYREF

  vars8[1] = a2;
  vars8[0] = a1;
  if ( RtlpHashStringToAtom(a2, (unsigned __int16 *)(a1 + 26), 0, &v4, 0, (int *)v5, vars8) >= 0 )
  {
    v3 = vars8[0];
    if ( vars8[0] )
    {
      if ( v4 )
        *v4 = *(_DWORD *)vars8[0];
      if ( *(_DWORD *)(v3 + 8) == v3 + 8 )
      {
        RtlpFreeHandleForAtom(a2, v3);
        RtlpFreeAtom(v3);
      }
      else
      {
        sub_50FE90();
      }
    }
  }
}
