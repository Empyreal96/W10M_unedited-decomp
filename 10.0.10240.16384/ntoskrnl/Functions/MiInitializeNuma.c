// MiInitializeNuma 
 
void MiInitializeNuma()
{
  unsigned int v0; // lr
  _DWORD *v1; // r7
  _DWORD *v2; // r4
  unsigned int v3; // r5
  int *v4; // r9
  int i; // r8
  int v6; // r2
  _DWORD *v7; // r3
  int v8; // r2
  _DWORD *v9; // r3

  v0 = (unsigned __int16)KeNumberNodes;
  v1 = (_DWORD *)dword_63F718;
  v2 = (_DWORD *)dword_6337E8;
  v3 = 0;
  if ( KeNumberNodes )
  {
    v4 = &MxFreeDescriptor;
    for ( i = 0; ; i += 104 )
    {
      v1[19] = v3;
      v1[23] = 0;
      v1[25] = 0;
      v6 = 0;
      v1[18] = v3 << byte_6337F5;
      do
      {
        v7 = &v2[6 * v6];
        v7[14] = 0;
        v7[15] = 0;
        if ( v6 == 1 )
          v2[22] = 0;
        else
          v7[16] = 5;
        ++v6;
      }
      while ( v6 < 2 );
      *v2 = 0;
      v2[1] = 0;
      if ( dword_6337F8 )
        break;
      v8 = 3;
      v9 = v2 + 2;
      do
      {
        *v9 = 0;
        v9[1] = 0;
        v9[6] = 0;
        v9[7] = 0;
        v9 += 2;
        --v8;
      }
      while ( v8 );
      ++v3;
      v1 += 26;
      v2 += 44;
      v4 += 4;
      if ( v3 >= v0 )
        return;
    }
    sub_80FBC0(0);
  }
}
