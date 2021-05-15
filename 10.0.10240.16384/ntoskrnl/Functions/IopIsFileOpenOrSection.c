// IopIsFileOpenOrSection 
 
BOOL __fastcall IopIsFileOpenOrSection(int a1, unsigned int *a2, int a3, int *a4)
{
  unsigned int v5; // r7
  int v6; // r5
  BOOL v7; // r6
  void *v9; // r4
  int v10; // r2
  int v11; // r3
  unsigned int v12; // r1

  v5 = *a2 & 0xFFFFFFF8;
  v6 = *a4;
  v7 = 0;
  v9 = (void *)ObTypeIndexTable[BYTE1(v5) ^ (unsigned __int8)ObHeaderCookie ^ *(unsigned __int8 *)(v5 + 12)];
  if ( v9 == IoFileObjectType )
  {
    if ( v6 == v5 + 24 )
    {
      v7 = *((_BYTE *)a4 + 4) == 0;
      goto LABEL_13;
    }
    v10 = *(_DWORD *)(v6 + 20);
    if ( v10 )
    {
      v11 = *(_DWORD *)(v5 + 44);
    }
    else
    {
      v10 = *(_DWORD *)(v6 + 12);
      v11 = *(_DWORD *)(v5 + 36);
    }
    if ( v10 != v11 )
      goto LABEL_13;
LABEL_12:
    v7 = 1;
    goto LABEL_13;
  }
  if ( v9 == (void *)MmSectionObjectType
    && *(_DWORD *)(v6 + 20)
    && MmSectionToSectionObjectPointers(v5 + 24) == *(_DWORD *)(v6 + 20) )
  {
    goto LABEL_12;
  }
LABEL_13:
  __dmb(0xBu);
  do
    v12 = __ldrex(a2);
  while ( __strex(v12 + 1, a2) );
  __dmb(0xBu);
  __dmb(0xFu);
  if ( *(_DWORD *)(a1 + 32) )
    ExfUnblockPushLock(a1 + 32, 0);
  return v7;
}
