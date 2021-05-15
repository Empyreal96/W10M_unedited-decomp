// MiComparePages 
 
int __fastcall MiComparePages(int a1, int a2)
{
  int v2; // r7
  int v3; // lr
  int v4; // r8
  int v5; // r6
  int v6; // r3
  __int64 v7; // t1
  int v8; // r5
  __int64 v9; // r2
  __int64 v10; // r0
  __int64 v11; // kr00_8
  __int64 v12; // kr08_8

  v2 = 512;
  v3 = a2 + 4096;
  v4 = a1 - a2;
  while ( 1 )
  {
    v5 = v4 + v3;
    v6 = *(_DWORD *)(v4 + v3 - 64);
    v7 = *(_QWORD *)(v3 - 64);
    v3 -= 64;
    v8 = v7 ^ v6;
    v9 = *(_QWORD *)(v5 - 60);
    v10 = *(_QWORD *)(v3 + 16);
    v11 = *(_QWORD *)(v5 - 48);
    v12 = *(_QWORD *)(v5 - 40);
    if ( *(_DWORD *)(v3 + 60) ^ *(_DWORD *)(v5 - 4) | HIDWORD(v7) ^ (unsigned int)v9 | *(_DWORD *)(v3 + 12) ^ *(_DWORD *)(v5 - 52) | HIDWORD(v10) ^ HIDWORD(v11) | *(_DWORD *)(v3 + 28) ^ HIDWORD(v12) | *(_DWORD *)(v3 + 36) ^ *(_DWORD *)(v5 - 28) | *(_DWORD *)(v3 + 44) ^ *(_DWORD *)(v5 - 20) | *(_DWORD *)(v3 + 52) ^ *(_DWORD *)(v5 - 12) | *(_DWORD *)(v3 + 56) ^ *(_DWORD *)(v5 - 8) | v8 | *(_DWORD *)(v3 + 8) ^ HIDWORD(v9) | (unsigned int)v10 ^ (unsigned int)v11 | *(_DWORD *)(v3 + 24) ^ (unsigned int)v12 | *(_DWORD *)(v3 + 32) ^ *(_DWORD *)(v5 - 32) | *(_DWORD *)(v3 + 40) ^ *(_DWORD *)(v5 - 24) | *(_DWORD *)(v3 + 48) ^ *(_DWORD *)(v5 - 16) )
      break;
    v2 -= 8;
    if ( !v2 )
      return 1;
  }
  return 0;
}
