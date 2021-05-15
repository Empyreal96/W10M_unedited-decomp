// CcFindBitmapRangeToDirty 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall CcFindBitmapRangeToDirty(int a1, __int64 a2, _BYTE **a3)
{
  _DWORD *v4; // lr
  int result; // r0
  _DWORD *v6; // r7
  signed __int64 v7; // r8
  _DWORD *v8; // r6
  signed __int64 v9; // kr00_8
  int v10; // r1 OVERLAPPED
  _DWORD *v11; // r2 OVERLAPPED
  int v12; // r3
  int v13; // r4

  v4 = (_DWORD *)(a1 + 16);
  result = *(_DWORD *)(a1 + 16);
  v6 = v4;
  v7 = a2 & 0xFFFFFFFFFFFFF000ui64;
  v8 = 0;
  while ( 1 )
  {
    v9 = *(_QWORD *)(result + 8);
    if ( v7 == v9 )
      break;
    if ( *(_DWORD *)(result + 24) || v8 )
    {
      if ( v7 > v9 )
        v6 = (_DWORD *)result;
    }
    else
    {
      v8 = (_DWORD *)result;
    }
    result = *(_DWORD *)result;
    if ( (_DWORD *)result == v4 )
      return sub_53DA7C();
    if ( v7 < *(_QWORD *)(result + 8) && v8 )
    {
      *(_QWORD *)&v10 = *(_QWORD *)v8;
      if ( *(_DWORD **)(*v8 + 4) != v8 || (_DWORD *)*v11 != v8 )
        JUMPOUT(0x53DA98);
      *v11 = v10;
      *(_DWORD *)(v10 + 4) = v11;
      LODWORD(a2) = *v6;
      *v8 = *v6;
      v8[1] = v6;
      if ( *(_DWORD **)(a2 + 4) != v6 )
        __fastfail(3u);
      *(_DWORD *)(a2 + 4) = v8;
      *v6 = v8;
      v8[3] = HIDWORD(a2);
      v8[4] = -1;
      v12 = v8[7];
      v8[2] = v7;
      v8[5] = 0;
      if ( !v12 )
      {
        v13 = (int)*a3;
        memset(*a3, 0, 512);
        v8[7] = v13;
        *a3 = 0;
      }
      return (int)v8;
    }
  }
  return result;
}
