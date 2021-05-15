// RtlULongLongMult 
 
int __fastcall RtlULongLongMult(unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4, _DWORD *a5)
{
  int v6; // r4
  int v9; // [sp+8h] [bp-18h] BYREF
  int v10; // [sp+Ch] [bp-14h]

  v6 = -1073741675;
  v9 = 0;
  v10 = 0;
  if ( a2 )
  {
    if ( a4 )
    {
LABEL_12:
      *a5 = -1;
      a5[1] = -1;
      return v6;
    }
  }
  else if ( !a4 )
  {
    *(_QWORD *)a5 = a3 * (unsigned __int64)a1;
    return 0;
  }
  if ( !is_mul_ok(a3, a2)
    || !is_mul_ok(a1, a4)
    || RtlULongLongAdd(0, a1 * a4, 0, a3 * a2, &v9) < 0
    || RtlULongLongAdd(v9, v10, a3 * a1, (a3 * (unsigned __int64)a1) >> 32, &v9) < 0 )
  {
    goto LABEL_12;
  }
  *a5 = v9;
  a5[1] = v10;
  return 0;
}
