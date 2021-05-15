// NtCreateKeyedEvent 
 
int __fastcall NtCreateKeyedEvent(_DWORD *a1, int a2, int a3, int a4)
{
  char v6; // r6
  int result; // r0
  int v8; // r0
  _DWORD *v9; // r3
  int v10; // r2
  int v11; // [sp+20h] [bp-28h] BYREF
  _DWORD _24[15]; // [sp+24h] [bp-24h] BYREF

  _24[14] = a4;
  _24[13] = a3;
  _24[12] = a2;
  _24[11] = a1;
  v6 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( v6 && ((unsigned __int8)a1 & 3) != 0 )
    ExRaiseDatatypeMisalignment(a1);
  *a1 = 0;
  if ( a4 )
    return -1073741582;
  result = ObCreateObject(v6, (_DWORD *)ExpKeyedEventObjectType, a3, v6, 0, 768, 0, 0, &v11);
  if ( result >= 0 )
  {
    v8 = v11;
    v9 = (_DWORD *)(v11 + 4);
    v10 = 64;
    do
    {
      *(v9 - 1) = 0;
      v9[1] = v9;
      *v9 = v9;
      v9 += 3;
      --v10;
    }
    while ( v10 );
    result = ObInsertObject(v8, 0, a2, 0, 0, (int)_24);
    if ( result >= 0 )
      *a1 = _24[0];
  }
  return result;
}
