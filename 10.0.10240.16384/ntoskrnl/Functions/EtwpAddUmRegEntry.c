// EtwpAddUmRegEntry 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall EtwpAddUmRegEntry(int a1, int a2, __int16 a3, int a4, _DWORD *a5, int a6)
{
  int result; // r0
  int v11; // r4
  char v12; // r3
  int v13; // r0
  _DWORD *v14; // r2 OVERLAPPED
  int v15; // r1 OVERLAPPED
  int v16; // [sp+18h] [bp-40h]
  char v17[4]; // [sp+1Ch] [bp-3Ch] BYREF
  int v18[14]; // [sp+20h] [bp-38h] BYREF

  v18[0] = 24;
  v18[1] = 0;
  v18[3] = 64;
  v18[2] = 0;
  v18[4] = 0;
  v18[5] = 0;
  result = ObCreateObjectEx(0, EtwpRegistrationObjectType, v18, 1);
  if ( result >= 0 )
  {
    memset((_BYTE *)v16, 0, 60);
    v11 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
    ObfReferenceObjectWithTag(v11);
    *(_DWORD *)(v16 + 40) = v11;
    v12 = *(_BYTE *)(v16 + 50) | 2;
    *(_BYTE *)(v16 + 50) = v12;
    if ( a2 == 2 )
      *(_BYTE *)(v16 + 50) = v12 | 8;
    *(_WORD *)(v16 + 48) = a3;
    *(_DWORD *)(v16 + 44) = a4;
    v13 = EtwpReferenceGuidEntry(a1);
    v14 = (_DWORD *)(a1 + 28);
    *(_DWORD *)(v16 + 16) = a1;
    v15 = *(_DWORD *)(a1 + 28);
    *(_QWORD *)v16 = *(_QWORD *)&v15;
    if ( *(_DWORD *)(v15 + 4) != a1 + 28 )
      sub_7C4FF4(v13);
    *(_DWORD *)(v15 + 4) = v16;
    *v14 = v16;
    *(_DWORD *)(v16 + 8) = v16 + 8;
    *(_DWORD *)(v16 + 12) = v16 + 8;
    *(_BYTE *)(v16 + 50) |= 0x80u;
    result = ObInsertObjectEx(v16, 0, 2052, 1, 0, v17, a6);
    if ( result >= 0 )
      *a5 = v16;
  }
  return result;
}
