// ObpDeferPushRefDerefInfo 
 
int __fastcall ObpDeferPushRefDerefInfo(int a1, char a2, __int16 a3, int a4, int a5, int a6)
{
  int result; // r0
  unsigned int *v11; // r4
  unsigned int v12; // r1
  unsigned int v13; // r2

  result = RtlpInterlockedPopEntrySList((unsigned __int64 *)&ObpWorkItemFreeList);
  if ( result )
  {
    v11 = (unsigned int *)(result + 4);
    *(_DWORD *)(result + 16) = a6;
    *(_DWORD *)(result + 20) = a4;
    *(_DWORD *)(result + 8) = a1;
    *(_BYTE *)(result + 12) = a2;
    *(_WORD *)(result + 14) = a3;
    memmove(result + 24, a5, 0x40u);
    result = ObpPushStackInfoList;
    *v11 = ObpPushStackInfoList;
    __dmb(0xBu);
    do
      v12 = __ldrex((unsigned int *)&ObpPushStackInfoList);
    while ( v12 == result && __strex((unsigned int)v11, (unsigned int *)&ObpPushStackInfoList) );
    while ( 1 )
    {
      __dmb(0xBu);
      if ( v12 == result )
        break;
      result = v12;
      *v11 = v12;
      __dmb(0xBu);
      do
        v13 = __ldrex((unsigned int *)&ObpPushStackInfoList);
      while ( v13 == v12 && __strex((unsigned int)v11, (unsigned int *)&ObpPushStackInfoList) );
      v12 = v13;
    }
    if ( !result )
      result = ExQueueWorkItem(&ObpPushStackInfoWorkItem, 0);
  }
  return result;
}
