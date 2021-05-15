// SmcCacheDelete 
 
int __fastcall SmcCacheDelete(int a1)
{
  _DWORD *v2; // r0
  int v3; // r4

  v2 = (_DWORD *)SmcCacheRemove();
  v3 = (int)v2;
  if ( !v2 )
    return -1073741735;
  SmcCacheCleanup(v2);
  ST_STORE<SM_TRAITS>::StDmSparseBitmapFree(v3);
  KeSetEvent(*(_DWORD *)(a1 + 276), 0, 0);
  return 0;
}
