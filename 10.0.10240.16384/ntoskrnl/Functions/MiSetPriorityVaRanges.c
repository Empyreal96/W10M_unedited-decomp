// MiSetPriorityVaRanges 
 
_DWORD *__fastcall MiSetPriorityVaRanges(_DWORD *result, unsigned int *a2, int a3)
{
  unsigned int *v3; // r4
  __int64 v4; // kr00_8
  int v5; // r6
  unsigned int v6; // r1
  int v7; // r3
  bool v8; // zf
  unsigned int *v9; // [sp+8h] [bp-30h]
  _DWORD *v10; // [sp+Ch] [bp-2Ch]
  int v12[9]; // [sp+14h] [bp-24h] BYREF

  v3 = a2;
  v9 = a2;
  v10 = result;
  if ( result )
  {
    do
    {
      v4 = *(_QWORD *)v3;
      result = (_DWORD *)MiObtainReferencedVad(*v3, v12);
      v5 = (int)result;
      if ( result )
      {
        v6 = (HIDWORD(v4) + v4 - 1) | 0xFFF;
        if ( v6 >> 12 > result[4] )
          return (_DWORD *)sub_7E8A84();
        v7 = result[7] & 7;
        if ( v7 != 3 && v7 != 1 )
          MiWalkVaRange(v4, v6, result, 2, a3);
        result = (_DWORD *)MiUnlockAndDereferenceVad(v5);
      }
      v3 = v9 + 2;
      v8 = v10 == (_DWORD *)1;
      v9 += 2;
      v10 = (_DWORD *)((char *)v10 - 1);
    }
    while ( !v8 );
  }
  return result;
}
