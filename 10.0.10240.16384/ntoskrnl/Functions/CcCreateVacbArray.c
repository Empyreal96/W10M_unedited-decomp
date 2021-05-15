// CcCreateVacbArray 
 
int __fastcall CcCreateVacbArray(int a1, __int64 a2)
{
  int v3; // r10
  int v4; // r8
  unsigned int v6; // r4
  int v7; // r7
  _BYTE *v8; // r5
  int result; // r0
  _QWORD *v10; // r2
  unsigned int v11; // r4
  __int64 v12; // r0
  int varg_r0; // [sp+28h] [bp+8h]

  varg_r0 = a1;
  v3 = 0;
  v4 = 0;
  if ( HIDWORD(a2) )
  {
    v6 = -1;
  }
  else
  {
    if ( (unsigned int)a2 > 0x100000 )
    {
      v6 = 4 * ((unsigned int)a2 >> 18);
      v7 = v6;
      goto LABEL_5;
    }
    v6 = 16;
  }
  v7 = v6;
  if ( a2 < 0 )
    return -1073741760;
LABEL_5:
  if ( v6 == 16 )
  {
    v8 = (_BYTE *)(a1 + 48);
  }
  else
  {
    if ( v6 > 0x200 )
      return sub_7E78A4();
    if ( (*(_DWORD *)(a1 + 96) & 0x200) != 0 && a2 > 0x200000 )
    {
      v6 += (v6 + 7) & 0xFFFFFFF8;
      v3 = 1;
    }
    if ( v7 == 512 )
    {
      v6 += 8;
      v4 = 1;
    }
    v8 = (_BYTE *)ExAllocatePoolWithTag(512, v6, 1884709699);
    if ( !v8 )
    {
      result = -1073741670;
      *(_DWORD *)(a1 + 100) = -1073741670;
      return result;
    }
  }
  memset(v8, 0, v7);
  if ( v4 )
  {
    v6 -= 8;
    *(_DWORD *)&v8[v6] = 0;
    *(_DWORD *)&v8[v6 + 4] = 0;
  }
  if ( v3 )
  {
    v10 = &v8[v7];
    v11 = (unsigned int)&v8[v6];
    if ( (unsigned int)&v8[v7] < v11 )
    {
      HIDWORD(v12) = a1 + 16;
      do
      {
        LODWORD(v12) = *(_DWORD *)HIDWORD(v12);
        *v10 = v12;
        if ( *(_DWORD *)(v12 + 4) != HIDWORD(v12) )
          __fastfail(3u);
        *(_DWORD *)(v12 + 4) = v10;
        *(_DWORD *)HIDWORD(v12) = v10++;
      }
      while ( (unsigned int)v10 < v11 );
    }
  }
  *(_DWORD *)(a1 + 64) = v8;
  result = 0;
  *(_QWORD *)(a1 + 24) = a2;
  return result;
}
