// CmpCleanUpKcbValueCache 
 
int __fastcall CmpCleanUpKcbValueCache(int result)
{
  int v1; // r4
  _DWORD *v2; // r2
  bool v3; // zf
  int v4; // r1
  int v5; // r2
  int v6; // r3
  int v7; // r0
  int v8; // r3

  v1 = result;
  if ( (*(_WORD *)(result + 106) & 0x40) == 0 )
  {
    v2 = *(_DWORD **)(result + 56);
    if ( ((unsigned __int8)v2 & 1) == 0 || v2 == (_DWORD *)-1 )
    {
      if ( (*(_DWORD *)(result + 4) & 8) != 0 )
      {
        if ( *v2 == 1 )
        {
          v8 = v2[1];
          if ( (v8 & 0x20000) == 0 )
            *((_WORD *)v2 + 2) = v8 | 0x20;
        }
        v3 = !ExIsResourceAcquiredExclusiveLite((int)&CmpRegistryLock);
        v7 = *(_DWORD *)(v1 + 56);
        if ( v3 )
          result = CmpDelayDerefKeyControlBlock(v7, v4, v5, v6);
        else
          result = CmpDereferenceKeyControlBlockWithLock(v7, 1);
        *(_WORD *)(v1 + 4) = *(_DWORD *)(v1 + 4) & 0xFFF7;
      }
    }
    else
    {
      result = sub_804E38();
    }
  }
  return result;
}
