// KseShimDriverIoCallbacks 
 
int __fastcall KseShimDriverIoCallbacks(int a1, int a2, int a3)
{
  int v4; // r5
  int v5; // r3
  unsigned int v7; // r1
  unsigned int v8; // r1
  char *v9; // r3
  __int16 v10[2]; // [sp+0h] [bp-A8h] BYREF
  int v11; // [sp+4h] [bp-A4h]
  char v12[8]; // [sp+8h] [bp-A0h] BYREF
  char v13[152]; // [sp+10h] [bp-98h] BYREF

  v4 = 0;
  v10[0] = 0;
  v10[1] = 0;
  v11 = 0;
  if ( a3 )
  {
    v5 = dword_6416D4;
    __dmb(0xBu);
    if ( v5 == 2 && (KseEngine & 1) == 0 )
    {
      v4 = KsepStringDuplicateUnicode(v10, a3);
      if ( v4 >= 0 )
      {
        v4 = KsepDriverPathTail(v10, v12);
        if ( v4 >= 0 )
        {
          v4 = KsepGetShimCallbacksForDriver(*(_DWORD *)(a1 + 12), v13);
          if ( v4 >= 0 )
            return sub_7CC110();
        }
      }
      KsepPoolFreeNonPaged(0);
    }
    KsepStringFree(v10);
  }
  else
  {
    __dmb(0xBu);
    do
    {
      v7 = __ldrex(KsepHistoryMessagesIndex);
      v8 = v7 + 1;
    }
    while ( __strex(v8, KsepHistoryMessagesIndex) );
    __dmb(0xBu);
    v9 = (char *)&KsepHistoryMessages + 8 * (v8 & 0x3F);
    *((_DWORD *)v9 + 1) = 0;
    *((_WORD *)v9 + 1) = 8;
    *(_WORD *)v9 = 148;
    if ( (KsepDebugFlag & 1) != 0 )
      KsepDebugPrint(0, (int)"KSE: Callback shimming - missing driver object or driver name.\n");
    KsepLogInfo(0, (int)"KSE: Callback shimming - missing driver object or driver name.\n");
    v4 = -1073741811;
  }
  return v4;
}
