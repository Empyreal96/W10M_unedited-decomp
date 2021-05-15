// IopInitializeActiveConnectBlock 
 
_BYTE *__fastcall IopInitializeActiveConnectBlock(int a1, int a2)
{
  _BYTE *result; // r0
  __int64 v5; // r6
  int v6; // r4

  result = memset((_BYTE *)a2, 0, 44);
  if ( !*(_DWORD *)(a1 + 8) )
  {
    *(_DWORD *)a2 = a2;
    *(_DWORD *)(a2 + 4) = a2;
    KeInitializeEvent(a2 + 20, 1, 1);
    __dmb(0xBu);
    *(_DWORD *)(a2 + 36) = 1;
    v6 = *(_DWORD *)(a1 + 56);
    *(_DWORD *)(a2 + 8) = v6;
    IopAcquireReleaseConnectLockInternal(0, 1, 2);
    if ( IopFindActiveConnectBlockLocked(v6) )
    {
      result = (_BYTE *)sub_7DF024();
    }
    else
    {
      LODWORD(v5) = a2 + 20;
      HIDWORD(v5) = a2 + 36;
      *(_QWORD *)(a2 + 12) = v5;
      IopInsertActiveConnectListLocked(a2);
      result = (_BYTE *)IopAcquireReleaseConnectLockInternal(0, 0, 2);
    }
  }
  return result;
}
