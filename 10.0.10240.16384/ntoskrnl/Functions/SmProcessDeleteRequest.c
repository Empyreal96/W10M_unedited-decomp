// SmProcessDeleteRequest 
 
int __fastcall SmProcessDeleteRequest(int a1, _DWORD *a2, int a3, int a4)
{
  int v4; // r4
  int v5; // r0
  int v6; // r1
  int varg_r3; // [sp+34h] [bp+14h]

  varg_r3 = a4;
  LOBYTE(varg_r3) = a4;
  if ( a3 != 8 )
    return -1073741306;
  if ( (_BYTE)a4 && ((unsigned __int8)a2 & 3) != 0 )
    ExRaiseDatatypeMisalignment(a1);
  if ( (unsigned __int8)*a2 != 1 || (*a2 & 0xFFFFFF00) != 0 )
    return -1073741811;
  v5 = SmKmStoreDelete(a1);
  v4 = v5;
  if ( v5 >= 0 )
    SmpUpdateCacheStatsBucketIndex(v5, v6);
  return v4;
}
