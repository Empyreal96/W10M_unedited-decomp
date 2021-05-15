// PpmAllocWmiEvent 
 
_BYTE *__fastcall PpmAllocWmiEvent(int a1, _DWORD *a2, int a3)
{
  __int64 v5; // r4
  _BYTE *v6; // r0
  _BYTE *v7; // r8
  int v8; // r4
  int v9; // r5
  int v10; // r6

  LODWORD(v5) = a3 + 64;
  HIDWORD(v5) = a1;
  v6 = (_BYTE *)ExAllocatePoolWithTag(512, a3 + 64);
  v7 = v6;
  if ( v6 )
  {
    memset(v6, 0, v5);
    KeQuerySystemTime((_DWORD *)v7 + 4);
    *(_QWORD *)v7 = v5;
    v8 = a2[1];
    v9 = a2[2];
    v10 = a2[3];
    *((_DWORD *)v7 + 6) = *a2;
    *((_DWORD *)v7 + 7) = v8;
    *((_DWORD *)v7 + 8) = v9;
    *((_DWORD *)v7 + 9) = v10;
    *((_DWORD *)v7 + 11) = 138;
    *((_DWORD *)v7 + 14) = 64;
    *((_DWORD *)v7 + 15) = a3;
  }
  return v7;
}
