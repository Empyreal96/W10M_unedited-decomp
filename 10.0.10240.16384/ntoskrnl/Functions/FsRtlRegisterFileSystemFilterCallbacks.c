// FsRtlRegisterFileSystemFilterCallbacks 
 
int __fastcall FsRtlRegisterFileSystemFilterCallbacks(int a1, unsigned int *a2)
{
  int v3; // r6
  int v4; // r0
  int v5; // r5

  if ( !a1 || !a2 )
    return -1073741811;
  v3 = *(_DWORD *)(a1 + 24);
  v4 = ExAllocatePoolWithTag(512, *a2);
  v5 = v4;
  if ( !v4 )
    return -1073741670;
  memmove(v4, (int)a2, *a2);
  *(_DWORD *)(v3 + 24) = v5;
  return 0;
}
