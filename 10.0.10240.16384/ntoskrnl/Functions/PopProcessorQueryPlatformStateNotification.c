// PopProcessorQueryPlatformStateNotification 
 
int __fastcall PopProcessorQueryPlatformStateNotification(int a1, int a2, int a3)
{
  __int64 v3; // kr00_8
  int v5; // r5
  int v6; // r1
  int v8; // r2

  v3 = *(_QWORD *)(a1 + 36);
  if ( !(_DWORD)v3 || !*(_DWORD *)(v3 + 68) )
    return -1073741822;
  v5 = *(_DWORD *)(a2 + 24);
  if ( a3 )
    v6 = 22;
  else
    v6 = 19;
  if ( !((int (__fastcall *)(_DWORD, int, int))v3)(HIDWORD(v3), v6, a2) )
    return -1073741637;
  v8 = *(_DWORD *)(a2 + 4);
  if ( v8 )
    *(_DWORD *)(a2 + 4) = *(_DWORD *)(v8 + 88);
  PopTranslateDependencyArray(HIDWORD(v3), a2, 1795, v5);
  return 0;
}
