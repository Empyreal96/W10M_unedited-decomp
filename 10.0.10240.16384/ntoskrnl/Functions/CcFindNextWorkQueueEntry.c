// CcFindNextWorkQueueEntry 
 
int __fastcall CcFindNextWorkQueueEntry(_DWORD *a1)
{
  _DWORD *v1; // r2
  _DWORD *v2; // r4
  int v3; // r1
  __int64 v5; // r0

  v1 = (_DWORD *)*a1;
  v2 = 0;
  if ( (_DWORD *)*a1 != a1 )
  {
    v3 = *((unsigned __int8 *)v1 + 64);
    v2 = (_DWORD *)*a1;
    switch ( v3 )
    {
      case 4:
        return sub_522504();
      case 2:
        *(_DWORD *)(v1[2] + 352) = 0;
        break;
      case 1:
        *(_DWORD *)(*(_DWORD *)(v1[2] + 24) + 100) = 0;
        break;
    }
    v5 = *(_QWORD *)v1;
    if ( *(_DWORD **)(*v1 + 4) != v1 || *(_DWORD **)HIDWORD(v5) != v1 )
      __fastfail(3u);
    *(_DWORD *)HIDWORD(v5) = v5;
    *(_DWORD *)(v5 + 4) = HIDWORD(v5);
    *v1 = 0;
    v1[1] = 0;
  }
  return (int)v2;
}
