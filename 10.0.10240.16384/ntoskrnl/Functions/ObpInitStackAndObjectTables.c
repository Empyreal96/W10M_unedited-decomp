// ObpInitStackAndObjectTables 
 
int ObpInitStackAndObjectTables()
{
  _BYTE *v0; // r0
  _BYTE *v1; // r4
  _BYTE *v2; // r0
  _BYTE *v3; // r0
  int v4; // r6
  _DWORD *v5; // r0
  _DWORD *v7; // r4
  unsigned int v8; // r0
  unsigned int v9; // r0

  v0 = (_BYTE *)ExAllocatePoolWithTag(512, 32832, 1951556175);
  v1 = v0;
  ObpStackTable = (int)v0;
  if ( v0 )
  {
    memset(v0, 0, 68);
    memset(v1 + 68, 255, 32762);
    v2 = (_BYTE *)ExAllocatePoolWithTag(512, 0x10000, 1951556175);
    *(_DWORD *)(ObpStackTable + 4) = v2;
    if ( v2 )
    {
      memset(v2, 0, 0x10000);
      *(_WORD *)(ObpStackTable + 2) = 1024;
      v3 = (_BYTE *)ExAllocatePoolWithTag(512, 1604, 1951556175);
      ObpObjectTable = (int)v3;
      if ( !v3 )
      {
LABEL_13:
        v9 = *(_DWORD *)(ObpStackTable + 4);
        if ( v9 )
          ExFreePoolWithTag(v9);
        ExFreePoolWithTag(ObpStackTable);
        return -1073741801;
      }
      memset(v3, 0, 1604);
      v4 = 0;
      ObpWorkItemFreeList = 0;
      *(_DWORD *)&word_61FE3C = 0;
      while ( 1 )
      {
        v5 = (_DWORD *)ExAllocatePoolWithTag(512, 88, 1951556175);
        if ( !v5 )
          break;
        RtlpInterlockedPushEntrySList((unsigned __int64 *)&ObpWorkItemFreeList, v5);
        if ( (unsigned int)++v4 >= 0x1F4 )
          return 0;
      }
      v7 = (_DWORD *)RtlpInterlockedFlushSList((unsigned __int64 *)&ObpWorkItemFreeList);
      while ( v7 )
      {
        v8 = (unsigned int)v7;
        v7 = (_DWORD *)*v7;
        ExFreePoolWithTag(v8);
      }
    }
    if ( ObpObjectTable )
      ExFreePoolWithTag(ObpObjectTable);
    goto LABEL_13;
  }
  return -1073741801;
}
