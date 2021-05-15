// RtlpIsRangeAvailable 
 
int __fastcall RtlpIsRangeAvailable(__int64 **a1, unsigned __int64 a2, unsigned __int64 a3, unsigned __int8 a4, unsigned __int8 a5, char a6, char a7, int a8, int (__fastcall *a9)(int, unsigned __int64 *))
{
  unsigned __int64 *v11; // r4
  int (__fastcall *v13)(int, unsigned __int64 *); // lr
  int v14; // r0
  __int64 *v15; // r3
  unsigned __int64 v16; // r2
  __int64 *v17; // r1
  __int64 *v18; // r3
  __int64 *v19; // r3
  __int64 *v20; // r2
  int v22; // r3
  int v23; // r3

  v11 = (unsigned __int64 *)a1[2];
  if ( !v11 )
    return 1;
  v13 = (int (__fastcall *)(int, unsigned __int64 *))a9;
  v14 = a5;
  while ( 1 )
  {
    v15 = a1[1];
    if ( a7 )
    {
      if ( !v15 && a3 < *v11 )
        return 1;
    }
    else if ( !v15 && a2 > v11[1] )
    {
      return 1;
    }
    v16 = *v11;
    if ( (a2 >= *v11 || a3 >= v16)
      && (v16 >= a2 || v11[1] >= a2)
      && (!v14 || (*((_BYTE *)v11 + 25) & 1) == 0)
      && ((_BYTE)v11[3] & a4) == 0 )
    {
      if ( a6 )
        return sub_80E624();
      if ( !v13 || !v13(a8, v11) )
        return 0;
      v13 = (int (__fastcall *)(int, unsigned __int64 *))a9;
      v14 = a5;
    }
    v17 = *a1;
    if ( *((__int64 **)*a1 + 4) == a1[3] )
      break;
LABEL_18:
    if ( !v11 )
      return 1;
  }
  v18 = a1[2];
  if ( !v18 )
    return 1;
  if ( a7 )
    v19 = (__int64 *)*((_DWORD *)v18 + 7);
  else
    v19 = (__int64 *)*((_DWORD *)v18 + 8);
  v20 = a1[1];
  v11 = (unsigned __int64 *)((char *)v19 - 28);
  if ( !v20 )
    goto LABEL_14;
  if ( v19 != v20 )
  {
    a1[2] = (__int64 *)v11;
    goto LABEL_18;
  }
  if ( a7 )
    v22 = *((_DWORD *)v20 + 3);
  else
    v22 = *((_DWORD *)v20 + 4);
  v11 = (unsigned __int64 *)(v22 - 28);
  a1[1] = 0;
LABEL_14:
  if ( (__int64 *)((char *)v11 + 28) != v17 )
  {
    if ( (*((_WORD *)v11 + 13) & 1) != 0 )
    {
      a1[1] = (__int64 *)(v11 + 2);
      if ( a7 )
        v23 = *((_DWORD *)v11 + 4);
      else
        v23 = *((_DWORD *)v11 + 5);
      a1[2] = (__int64 *)(v23 - 28);
    }
    else
    {
      a1[2] = (__int64 *)v11;
    }
    v11 = (unsigned __int64 *)a1[2];
    goto LABEL_18;
  }
  a1[2] = 0;
  return 1;
}
