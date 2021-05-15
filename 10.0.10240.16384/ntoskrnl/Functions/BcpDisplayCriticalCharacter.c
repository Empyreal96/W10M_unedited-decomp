// BcpDisplayCriticalCharacter 
 
int __fastcall BcpDisplayCriticalCharacter(int a1, int a2)
{
  int v2; // r2
  __int64 v3; // kr00_8
  unsigned int v4; // r6
  int result; // r0
  int v6; // [sp+10h] [bp-30h]
  int v7; // [sp+18h] [bp-28h] BYREF
  int v8; // [sp+1Ch] [bp-24h] BYREF
  __int64 v9; // [sp+20h] [bp-20h]
  int v10[6]; // [sp+28h] [bp-18h] BYREF

  v7 = 0;
  v8 = 0;
  v2 = *(_DWORD *)(dword_641660 + 20);
  *(_DWORD *)(v2 + 40) = a2;
  *(_DWORD *)(dword_641660 + 4) = a2;
  v3 = *(_QWORD *)&BcpCursor;
  v4 = dword_653574;
  v9 = *(_QWORD *)&BcpCursor;
  v10[0] = dword_653574;
  result = BgpDisplayCharacterEx(
             a1,
             (int *)dword_641660,
             BcpCursor,
             dword_653570,
             *(_DWORD *)(v2 + 28),
             -1,
             (int)&v8,
             (int)&v7,
             v6,
             (int)BcpWorkspace);
  if ( result >= 0 )
  {
    if ( v4 < v7 + HIDWORD(v3) )
      v10[0] = v7 + HIDWORD(v3);
    result = BcpSetCursorPosition(v3 + v8, HIDWORD(v3), v10);
  }
  return result;
}
