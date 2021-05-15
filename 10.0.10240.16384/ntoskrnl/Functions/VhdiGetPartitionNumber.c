// VhdiGetPartitionNumber 
 
int __fastcall VhdiGetPartitionNumber(int *a1, int a2, _DWORD *a3)
{
  unsigned int v5; // r9
  int v6; // r4
  unsigned int v7; // r7
  int v8; // r10
  _DWORD *v9; // r5
  __int64 v10; // kr00_8
  __int64 v11; // kr08_8
  bool v12; // zf

  if ( !a1 || !a2 || !a3 )
    return -1073741811;
  v5 = a1[1];
  v6 = -1073741198;
  v7 = 0;
  if ( v5 )
  {
    v8 = *a1;
    v9 = a1 + 12;
    do
    {
      if ( v8 )
      {
        if ( v8 != 1 )
          goto LABEL_12;
        v12 = memcmp((unsigned int)(v9 + 12), a2 + 48, 16) == 0;
      }
      else
      {
        v10 = *((_QWORD *)v9 + 1);
        v11 = *(_QWORD *)(a2 + 8);
        if ( (_DWORD)v10 != (_DWORD)v11 )
          goto LABEL_12;
        v12 = HIDWORD(v10) == HIDWORD(v11);
      }
      if ( v12 )
      {
        v6 = 0;
        *a3 = v9[6];
        return v6;
      }
LABEL_12:
      ++v7;
      v9 += 36;
    }
    while ( v7 < v5 );
  }
  return v6;
}
