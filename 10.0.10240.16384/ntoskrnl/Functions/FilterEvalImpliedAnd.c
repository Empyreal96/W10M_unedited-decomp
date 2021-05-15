// FilterEvalImpliedAnd 
 
int __fastcall FilterEvalImpliedAnd(int (__fastcall *a1)(int, _DWORD *, int *, int *, int *), int a2, unsigned int a3, _DWORD *a4, _DWORD *a5)
{
  int v7; // r4
  int v8; // r6
  unsigned int v9; // r7
  int v10; // lr
  int v11; // r0
  int v13; // [sp+10h] [bp-30h] BYREF
  int v14; // [sp+14h] [bp-2Ch] BYREF
  int v15; // [sp+18h] [bp-28h] BYREF
  int (__fastcall *v16)(int, _DWORD *, int *, int *, int *); // [sp+1Ch] [bp-24h]
  int v17; // [sp+20h] [bp-20h]

  v14 = 0;
  v15 = 0;
  v13 = 0;
  v7 = 0;
  v8 = 1;
  v9 = 0;
  *a5 = 0;
  v10 = a2;
  v16 = a1;
  v17 = a2;
  if ( a3 )
  {
    while ( (*a4 & 0xFF00000) == 0 )
    {
      v11 = v16(v10, a4 + 1, &v15, &v13, &v14);
      v7 = v11;
      if ( v11 == -1073741275 )
      {
        v7 = 0;
        v8 = 0;
      }
      else
      {
        if ( v11 )
          goto LABEL_7;
        PropertyEval(v15, v14, v13, *a4, a4[8], a4[10], a4[9], a5);
        if ( !*a5 )
          return 0;
      }
      ++v9;
      v10 = v17;
      a4 += 11;
      if ( v9 >= a3 )
        goto LABEL_7;
    }
    v7 = -1073741811;
LABEL_7:
    if ( !v8 && !v7 )
      v7 = -1073741823;
  }
  return v7;
}
