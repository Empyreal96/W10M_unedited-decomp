// KseDriverLoadImage 
 
int __fastcall KseDriverLoadImage(int a1)
{
  int v2; // r3
  int v3; // r4
  int v5; // r7
  unsigned int v6; // r1
  unsigned int v7; // r1
  char *v8; // r3
  unsigned int v9; // r1
  unsigned int v10; // r1
  _WORD *v11; // r3
  int v12; // [sp+8h] [bp-28h] BYREF
  int v13; // [sp+Ch] [bp-24h] BYREF
  __int16 v14[2]; // [sp+10h] [bp-20h] BYREF
  int v15; // [sp+14h] [bp-1Ch]
  __int16 v16[2]; // [sp+18h] [bp-18h] BYREF
  int v17; // [sp+1Ch] [bp-14h]

  v12 = 0;
  v13 = 0;
  v14[0] = 0;
  v14[1] = 0;
  v15 = 0;
  v16[0] = 0;
  v16[1] = 0;
  v17 = 0;
  if ( !a1 )
    return -1073741811;
  if ( !MmIsSessionAddress(*(_DWORD *)(a1 + 24)) )
  {
    v2 = dword_6416D4;
    __dmb(0xBu);
    if ( v2 != 2 || (KseEngine & 1) != 0 )
    {
      v3 = -1073741637;
    }
    else
    {
      v3 = KsepStringDuplicateUnicode(v14, a1 + 44);
      if ( v3 >= 0 )
      {
        v3 = KsepStringDuplicateUnicode(v16, a1 + 36);
        if ( v3 >= 0 )
        {
          v3 = KsepGetShimsForDriver((int)v14, (int)v16, *(_DWORD *)(a1 + 24), *(_DWORD *)(a1 + 32), &v12, &v13);
          if ( v3 >= 0 )
            return sub_7CD1C0();
        }
      }
      v5 = v13;
      if ( v3 == -1073741275 )
      {
        __dmb(0xBu);
        do
        {
          v6 = __ldrex(KsepHistoryMessagesIndex);
          v7 = v6 + 1;
        }
        while ( __strex(v7, KsepHistoryMessagesIndex) );
        __dmb(0xBu);
        v8 = (char *)&KsepHistoryMessages + 8 * (v7 & 0x3F);
        *((_DWORD *)v8 + 1) = 0;
        *((_WORD *)v8 + 1) = 7;
        *(_WORD *)v8 = 194;
        if ( (KsepDebugFlag & 1) != 0 )
          KsepDebugPrint(4, (int)"KSE: Applied %d shim(s) to [%ws].\n");
        KsepLogInfo(4, (int)"KSE: Applied %d shim(s) to [%ws].\n", v5, v15);
LABEL_15:
        KsepStringFree(v14);
        KsepStringFree(v16);
        return 0;
      }
    }
    if ( v15 )
    {
      __dmb(0xBu);
      do
      {
        v9 = __ldrex(&KsepHistoryErrorsIndex);
        v10 = v9 + 1;
      }
      while ( __strex(v10, &KsepHistoryErrorsIndex) );
      __dmb(0xBu);
      v11 = &KsepHistoryErrors[4 * (v10 & 0x3F)];
      *((_DWORD *)v11 + 1) = v3;
      v11[1] = 7;
      *v11 = 189;
      if ( (KsepDebugFlag & 2) != 0 )
        KsepDebugPrint(4, (int)"KSE: shimming failed for driver [%ws] - [0x%x] but we let the load succeed ...\n");
      KsepLogError(4, (int)"KSE: shimming failed for driver [%ws] - [0x%x] but we let the load succeed ...\n", v15, v3);
    }
    goto LABEL_15;
  }
  return -1073741637;
}
