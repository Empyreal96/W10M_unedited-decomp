// MiAdjustCachedStacks 
 
int MiAdjustCachedStacks()
{
  int v0; // r9
  int result; // r0
  int i; // r6
  int v3; // r4
  __int64 v4; // kr00_8
  int v5; // r1
  int v6; // r3
  int v7; // r5
  int v8; // r8
  int v9; // r7
  int v10; // r2
  int v11; // r3
  int v12; // r3
  int v13; // r0
  unsigned __int16 v14; // [sp+0h] [bp-28h]
  unsigned int v15; // [sp+8h] [bp-20h]

  v0 = 0;
  v15 = (unsigned __int16)KeNumberNodes;
  v14 = 0;
  result = 256;
  do
  {
    for ( i = 0; i <= 1; ++i )
    {
      v3 = 176 * v0 + 24 * i + dword_6337E8;
      v4 = *(_QWORD *)(v3 + 68);
      if ( (_DWORD)v4 == HIDWORD(v4) )
      {
        if ( !*(_DWORD *)(v3 + 76) )
        {
          v5 = *(_DWORD *)(v3 + 64);
          v6 = v5 / 20;
          if ( !(v5 / 20) )
            v6 = v5 != 0;
          v7 = v5 - v6;
          if ( i != 1 && v7 < 5 )
            v7 = 5;
          *(_DWORD *)(v3 + 64) = v7;
          if ( i == 1 )
          {
            v8 = 16;
            v9 = 8;
          }
          else
          {
            v8 = 0;
            v9 = 0;
          }
          do
          {
            if ( *(unsigned __int16 *)(v3 + 60) <= v7 )
              break;
            v13 = MmCreateKernelStack(v8, v0, 0);
            if ( !v13 )
              break;
            MmDeleteKernelStack(v13, v9);
          }
          while ( (_DWORD)v4 == *(_DWORD *)(v3 + 68) );
          result = 256;
        }
      }
      else
      {
        v10 = *(_DWORD *)(v3 + 64);
        if ( v10 < 16 || (unsigned int)(v4 - HIDWORD(v4)) >= 0x10 )
        {
          v11 = v10 / 4;
        }
        else if ( v10 >= 64 )
        {
          v11 = v10 / 16;
        }
        else
        {
          v11 = v10 / 8;
        }
        if ( !v11 )
          v11 = 1;
        v12 = v11 + v10;
        if ( v12 > 256 )
          v12 = 256;
        *(_DWORD *)(v3 + 64) = v12;
        *(_DWORD *)(v3 + 72) = v4;
      }
      *(_DWORD *)(v3 + 76) = 0;
    }
    v0 = ++v14;
  }
  while ( v14 < v15 );
  return result;
}
