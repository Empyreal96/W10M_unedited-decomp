// MiComputeHash64 
 
unsigned int __fastcall MiComputeHash64(int a1)
{
  unsigned int v1; // r1
  unsigned int v2; // r2
  int v3; // r7
  int v4; // r6
  signed __int64 v5; // kr00_8
  signed __int64 v6; // kr08_8
  signed __int64 v7; // kr10_8
  signed __int64 v8; // kr18_8
  unsigned int v9; // r1
  unsigned int v10; // r2
  int v11; // r3
  int v12; // r2
  int v13; // r0
  __int64 v14; // t1

  v1 = -2021259019;
  v2 = -564268737;
  v3 = 512;
  v4 = a1 + 4096;
  do
  {
    v5 = *(_QWORD *)(v4 - 8) + __PAIR64__((v2 >> 2) | (v1 << 30), (v2 << 30) | (v1 >> 2));
    v6 = *(_QWORD *)(v4 - 16) + __PAIR64__((HIDWORD(v5) >> 3) | ((_DWORD)v5 << 29), v5 >> 3);
    v7 = *(_QWORD *)(v4 - 24) + __PAIR64__((HIDWORD(v6) >> 5) | ((_DWORD)v6 << 27), v6 >> 5);
    v8 = *(_QWORD *)(v4 - 32) + __PAIR64__((HIDWORD(v7) >> 7) | ((_DWORD)v7 << 25), v7 >> 7);
    v10 = (*(_QWORD *)(v4 - 56)
         + __PAIR64__(
             ((unsigned int)((__PAIR64__(
                                (((unsigned int)((HIDWORD(v8) >> 11) | ((_DWORD)v8 << 21)) ^ *(_DWORD *)(v4 - 36)) >> 13) | (((unsigned int)(v8 >> 11) ^ *(_DWORD *)(v4 - 40)) << 19),
                                ((((HIDWORD(v8) >> 11) | ((_DWORD)v8 << 21)) ^ *(_DWORD *)(v4 - 36)) << 19) | (((unsigned int)(v8 >> 11) ^ *(_DWORD *)(v4 - 40)) >> 13))
                            + *(_QWORD *)(v4 - 48)) >> 32) >> 17) | (((((((HIDWORD(v8) >> 11) | ((_DWORD)v8 << 21)) ^ *(_DWORD *)(v4 - 36)) << 19) | (((unsigned int)(v8 >> 11) ^ *(_DWORD *)(v4 - 40)) >> 13))
                                                                    + *(_DWORD *)(v4 - 48)) << 15),
             (__int64)(__PAIR64__(
                         (((unsigned int)((HIDWORD(v8) >> 11) | ((_DWORD)v8 << 21)) ^ *(_DWORD *)(v4 - 36)) >> 13) | (((unsigned int)(v8 >> 11) ^ *(_DWORD *)(v4 - 40)) << 19),
                         ((((HIDWORD(v8) >> 11) | ((_DWORD)v8 << 21)) ^ *(_DWORD *)(v4 - 36)) << 19) | (((unsigned int)(v8 >> 11) ^ *(_DWORD *)(v4 - 40)) >> 13))
                     + *(_QWORD *)(v4 - 48)) >> 17)) >> 32;
    v9 = *(_DWORD *)(v4 - 56)
       + ((__int64)(__PAIR64__(
                      (((unsigned int)((HIDWORD(v8) >> 11) | ((_DWORD)v8 << 21)) ^ *(_DWORD *)(v4 - 36)) >> 13) | (((unsigned int)(v8 >> 11) ^ *(_DWORD *)(v4 - 40)) << 19),
                      ((((HIDWORD(v8) >> 11) | ((_DWORD)v8 << 21)) ^ *(_DWORD *)(v4 - 36)) << 19) | (((unsigned int)(v8 >> 11) ^ *(_DWORD *)(v4 - 40)) >> 13))
                  + *(_QWORD *)(v4 - 48)) >> 17);
    v11 = v10 << 13;
    v12 = (v10 >> 19) | (v9 << 13);
    v13 = v11 | (v9 >> 19);
    v14 = *(_QWORD *)(v4 - 64);
    v4 -= 64;
    v1 = v14 + v13;
    v2 = HIDWORD(v14) + __CFADD__((_DWORD)v14, v13) + v12;
    v3 -= 8;
  }
  while ( v3 );
  return v1;
}
