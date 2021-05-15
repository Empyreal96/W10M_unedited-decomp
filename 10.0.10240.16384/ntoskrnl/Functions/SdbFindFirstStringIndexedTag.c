// SdbFindFirstStringIndexedTag 
 
int __fastcall SdbFindFirstStringIndexedTag(int a1, int a2, int a3, int a4, int a5)
{
  __int16 v6; // r5
  int v8; // r0
  int result; // r0
  int v10; // r1
  __int64 v11; // r0
  int v12; // r0
  int v13[6]; // [sp+8h] [bp-18h] BYREF

  v13[0] = 0;
  v6 = a3;
  v8 = SdbGetIndex(a1, a2, a3, v13);
  *(_DWORD *)a5 = v8;
  if ( !v8 )
    return sub_7CCA30();
  v10 = v13[0];
  *(_WORD *)(a5 + 12) = v6;
  *(_DWORD *)(a5 + 20) = v10;
  *(_DWORD *)(a5 + 32) = a4;
  v11 = SdbMakeIndexKeyFromStringEx(a4);
  *(_QWORD *)(a5 + 24) = v11;
  v12 = SdbpGetFirstIndexedRecord(a1, *(_DWORD *)a5, v11, HIDWORD(v11));
  if ( v12 )
    result = SdbpFindMatchingName(a1, v12, a5);
  else
    result = 0;
  return result;
}
