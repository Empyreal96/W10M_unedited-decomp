// ExpCovDeleteUnloadedModuleEntry 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall ExpCovDeleteUnloadedModuleEntry(int a1)
{
  int v2; // r1 OVERLAPPED
  _DWORD *v3; // r2 OVERLAPPED
  int v4; // r4
  unsigned int v5; // r2

  if ( !a1 )
    return -1073741811;
  *(_QWORD *)&v2 = *(_QWORD *)a1;
  if ( *(_DWORD *)(*(_DWORD *)a1 + 4) != a1 || *v3 != a1 )
    __fastfail(3u);
  *v3 = v2;
  *(_DWORD *)(v2 + 4) = v3;
  v4 = -1;
  v5 = *(unsigned __int16 *)(a1 + 8) + 32 + *(unsigned __int16 *)(a1 + 16);
  if ( v5 < 0x20 )
    v5 = -1;
  if ( *(_DWORD *)(a1 + 24) + v5 >= v5 )
    v4 = *(_DWORD *)(a1 + 24) + v5;
  ExpCovFreeUnloadedModuleEntry(a1);
  ExpCovCurrentPagedPoolInUse -= v4;
  return 0;
}
