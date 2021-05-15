// EtwpGetTraceGroupList 
 
int __fastcall EtwpGetTraceGroupList(_DWORD *a1, unsigned int *a2)
{
  unsigned int v2; // r9
  int v4; // r8
  unsigned int v5; // r7
  _DWORD *v6; // r0
  _DWORD *v7; // r8
  int v8; // r3
  int v9; // r4
  int v10; // r5

  v2 = *a2;
  v4 = 0;
  v5 = 0;
  v6 = (_DWORD *)EtwpGetNextGuidEntry(0, 2);
  if ( v6 )
  {
    v7 = a1;
    do
    {
      if ( ++v5 <= v2 >> 4 )
      {
        v8 = v6[4];
        v9 = v6[5];
        v10 = v6[6];
        *v7 = v6[3];
        v7[1] = v8;
        v7[2] = v9;
        v7[3] = v10;
        v7 += 4;
      }
      v6 = (_DWORD *)EtwpGetNextGuidEntry(v6, 2);
    }
    while ( v6 );
    v4 = 0;
  }
  *a2 = 16 * v5;
  if ( v5 > v2 >> 4 )
    v4 = -1073741789;
  return v4;
}
