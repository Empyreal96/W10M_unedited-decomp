// ExDrainPoolLookasideList 
 
int __fastcall __spoils<R0,R2,R3,R12> ExDrainPoolLookasideList(int a1)
{
  int result; // r0
  _DWORD *v3; // r7
  int *v4; // r5
  unsigned int v5; // r4

  ExpRemoveGeneralLookaside((unsigned int *)&ExPagedLookasideLock, a1);
  result = RtlpInterlockedFlushSList((unsigned __int64 *)a1);
  v3 = (_DWORD *)result;
  if ( result )
  {
    do
    {
      v4 = v3 - 1;
      v5 = (unsigned int)(v3 - 3);
      if ( *(v3 - 1) != (ExpPoolQuotaCookie ^ (unsigned int)(v3 - 3)) )
        KeBugCheckEx(25, 15, (int)(v3 - 3), *v4, ExpPoolQuotaCookie ^ v5);
      v3 = (_DWORD *)*v3;
      *(_WORD *)(v5 + 2) = *(_WORD *)(v5 + 2) & 0x1FF | ((*(_WORD *)(a1 + 28) | 2) << 9);
      ExpInsertPoolTracker(*(_DWORD *)(v5 + 4));
      result = (*(int (__fastcall **)(int *))(a1 + 44))(v4);
    }
    while ( v3 );
  }
  return result;
}
