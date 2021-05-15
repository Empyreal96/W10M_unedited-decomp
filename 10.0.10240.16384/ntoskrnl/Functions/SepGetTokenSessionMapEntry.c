// SepGetTokenSessionMapEntry 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall SepGetTokenSessionMapEntry(int a1, int a2, _DWORD *a3)
{
  _DWORD *v4; // r0
  _DWORD *i; // r2
  int v9; // r0
  int *v10; // r2 OVERLAPPED
  int v11; // r1 OVERLAPPED
  _DWORD *v12; // r3

  v4 = (_DWORD *)g_SessionLowboxMap;
  *a3 = 0;
  if ( v4 )
  {
LABEL_7:
    for ( i = (_DWORD *)*v4; i != v4; i = (_DWORD *)*i )
    {
      if ( i[2] == a1 )
      {
        v12 = i + 3;
LABEL_17:
        *a3 = v12;
        return 0;
      }
    }
    if ( !a2 )
      return -1073741275;
    v9 = ExAllocatePoolWithTag(1, 32);
    if ( v9 )
    {
      v10 = (int *)g_SessionLowboxMap;
      *(_BYTE *)(v9 + 28) = 0;
      *(_DWORD *)(v9 + 8) = a1;
      *(_DWORD *)(v9 + 12) = 0;
      v11 = *v10;
      *(_QWORD *)v9 = *(_QWORD *)&v11;
      if ( *(int **)(v11 + 4) != v10 )
        __fastfail(3u);
      *(_DWORD *)(v11 + 4) = v9;
      *v10 = v9;
      v12 = (_DWORD *)(v9 + 12);
      goto LABEL_17;
    }
    return -1073741670;
  }
  if ( !a2 )
    return -1073741275;
  v4 = (_DWORD *)ExAllocatePoolWithTag(1, 8);
  g_SessionLowboxMap = (int)v4;
  if ( v4 )
  {
    *v4 = v4;
    v4[1] = v4;
    goto LABEL_7;
  }
  return -1073741670;
}
