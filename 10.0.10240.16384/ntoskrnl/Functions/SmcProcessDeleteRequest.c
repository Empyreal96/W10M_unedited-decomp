// SmcProcessDeleteRequest 
 
int __fastcall SmcProcessDeleteRequest(int a1, _DWORD *a2, int a3, int a4)
{
  int v4; // r4

  if ( a3 != 8 )
    return -1073741306;
  if ( (_BYTE)a4 && ((unsigned __int8)a2 & 3) != 0 )
    ExRaiseDatatypeMisalignment(a1);
  if ( (unsigned __int8)*a2 != 1 || (*a2 & 0xFFFFFF00) != 0 )
    return -1073741811;
  v4 = SmcCacheDelete(a1, a2[1]);
  if ( v4 >= 0 )
    v4 = 0;
  return v4;
}
