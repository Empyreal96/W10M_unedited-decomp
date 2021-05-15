// PpmAllocateQueryTable 
 
_DWORD *__fastcall PpmAllocateQueryTable(int a1)
{
  _BYTE *v2; // r0
  _DWORD *v3; // r4
  __int16 **v4; // r5
  _DWORD *v5; // r1
  _DWORD *v6; // r2
  int v7; // r6
  __int16 *v8; // t1

  v2 = (_BYTE *)ExAllocatePoolWithTag(1, 668, 1884115027);
  v3 = v2;
  if ( v2 )
  {
    memset(v2, 0, 668);
    v4 = &PpmPolicyAliasList;
    v5 = v3 + 147;
    v6 = v3;
    v7 = 20;
    do
    {
      v8 = *v4;
      v4 += 2;
      v6[2] = v8;
      v6[3] = v5;
      v6[5] = a1;
      v6[6] = 4;
      v6[4] = 67108868;
      v6[1] = 288;
      v6 += 7;
      ++v5;
      --v7;
    }
    while ( v7 );
  }
  return v3;
}
