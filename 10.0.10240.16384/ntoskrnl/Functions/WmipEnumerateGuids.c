// WmipEnumerateGuids 
 
int __fastcall WmipEnumerateGuids(int a1, _DWORD *a2, int a3, _DWORD *a4)
{
  int v4; // r6
  _DWORD *v5; // r9
  __int64 v6; // kr00_8
  unsigned int v8; // r5
  _DWORD **v9; // r7
  _DWORD *v10; // lr
  _DWORD *v11; // r9
  int v12; // r1
  int v13; // r2
  int v14; // r3
  _DWORD *v15; // r1
  int v16; // r0

  v4 = 0;
  v5 = a4;
  v6 = 954437177i64 * (unsigned int)(a3 - 8);
  v8 = 0;
  KeWaitForSingleObject((unsigned int)&WmipSMMutex, 0, 0, 0, 0);
  v9 = (_DWORD **)WmipGEHeadPtr;
  v10 = *(_DWORD **)WmipGEHeadPtr;
  if ( *(_DWORD *)WmipGEHeadPtr != WmipGEHeadPtr )
  {
    v11 = a2 + 2;
    do
    {
      ++v4;
      if ( v8 < HIDWORD(v6) >> 3 )
      {
        v12 = v10[11];
        v13 = v10[12];
        v14 = v10[13];
        *v11 = v10[10];
        v11[1] = v12;
        v11[2] = v13;
        v11[3] = v14;
        v11 += 9;
        ++v8;
      }
      v10 = (_DWORD *)*v10;
    }
    while ( v10 != v9 );
    v5 = a4;
  }
  if ( a1 == 2244960 )
  {
    v15 = *v9;
    v4 = 0;
    v8 = 0;
    if ( *v9 != v9 )
    {
      v16 = (int)(a2 + 2);
      do
      {
        ++v4;
        if ( v8 < HIDWORD(v6) >> 3 )
        {
          ++v8;
          v16 = WmipGetGuidPropertiesFromGuidEntry(v16) + 36;
        }
        v15 = (_DWORD *)*v15;
      }
      while ( v15 != v9 );
    }
  }
  KeReleaseMutex((int)&WmipSMMutex);
  *v5 = 36 * v8 + 8;
  *a2 = v4;
  a2[1] = v8;
  return 0;
}
