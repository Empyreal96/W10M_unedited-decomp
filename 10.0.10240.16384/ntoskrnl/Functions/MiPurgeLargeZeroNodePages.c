// MiPurgeLargeZeroNodePages 
 
unsigned int MiPurgeLargeZeroNodePages()
{
  _DWORD *v0; // r4
  int v1; // r9
  int v2; // r7
  unsigned int v3; // r5
  int v4; // lr
  unsigned int v5; // r10
  int v6; // r6
  int v7; // r2
  int *v8; // r1
  __int64 v9; // kr00_8
  int v10; // r0
  unsigned int v11; // r4
  unsigned int result; // r0
  unsigned int v13; // [sp+0h] [bp-20h]

  v0 = (_DWORD *)dword_63F718;
  v1 = 0;
  v13 = dword_63F718 + 104 * (unsigned __int16)KeNumberNodes;
  if ( dword_63F718 < v13 )
  {
    do
    {
      if ( *v0 )
      {
        v2 = 0;
        v3 = 0;
        v1 += *v0;
        do
        {
          v4 = 0;
          v5 = v3;
          v6 = v2;
          do
          {
            v7 = (int)v0 + v6 + 8;
            v8 = *(int **)v7;
            if ( *(_DWORD *)v7 != v7 )
            {
              do
              {
                *((_BYTE *)v8 + 18) = *((_BYTE *)v8 + 18) & 0xF8 | 1;
                v8 = (int *)*v8;
              }
              while ( v8 != (int *)v7 );
              v9 = *(_QWORD *)v7;
              v10 = (int)v0 + v6 + 16;
              if ( *(_DWORD *)(*(_DWORD *)v7 + 4) != v7 || *(_DWORD *)HIDWORD(v9) != v7 )
                __fastfail(3u);
              *(_DWORD *)HIDWORD(v9) = v9;
              *(_DWORD *)(v9 + 4) = HIDWORD(v9);
              if ( *(_DWORD *)(*(_DWORD *)v10 + 4) != v10
                || **(_DWORD ***)((char *)v0 + v6 + 20) != (_DWORD *)((char *)v0 + v6 + 16) )
              {
                __fastfail(3u);
              }
              if ( *(_DWORD *)(*(_DWORD *)v9 + 4) != (_DWORD)v9 || **(_DWORD **)(v9 + 4) != (_DWORD)v9 )
                __fastfail(3u);
              *(_DWORD *)HIDWORD(v9) = v9;
              *(_DWORD *)((char *)v0 + v6 + 20) = *(_DWORD *)(v9 + 4);
              **(_DWORD **)(v9 + 4) = v10;
              *(_DWORD *)(v9 + 4) = HIDWORD(v9);
              *(_DWORD *)v7 = v7;
              *(_DWORD *)((char *)v0 + v6 + 12) = (char *)v0 + v6 + 8;
              v0[1] += *v0;
              *(_DWORD *)((char *)v0 + v5 + 44) += *(_DWORD *)((char *)v0 + v5 + 40);
              *v0 = 0;
              *(_DWORD *)((char *)v0 + v5 + 40) = 0;
            }
            ++v4;
            v6 += 16;
            v5 += 8;
          }
          while ( v4 <= 1 );
          v3 += 4;
          v2 += 8;
        }
        while ( v3 < 4 );
      }
      v0 += 26;
    }
    while ( (unsigned int)v0 < v13 );
  }
  do
    v11 = __ldrex((unsigned int *)&dword_63FB80);
  while ( __strex(v11 - (v1 << 10), (unsigned int *)&dword_63FB80) );
  do
    result = __ldrex((unsigned int *)&dword_63FC00);
  while ( __strex(result + (v1 << 10), (unsigned int *)&dword_63FC00) );
  return result;
}
