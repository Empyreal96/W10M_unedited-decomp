// IopAcquireReleaseConnectLockInternal 
 
int __fastcall IopAcquireReleaseConnectLockInternal(int a1, int a2, char a3)
{
  char *v3; // r0
  unsigned int v4; // r2
  int result; // r0
  unsigned int v6; // r1
  int v7; // r3

  if ( (a3 & 1) != 0 )
  {
    v3 = (char *)(a1 + 20);
  }
  else if ( (a3 & 2) != 0 )
  {
    v3 = &ActiveConnectListLock;
  }
  else
  {
    v3 = *(char **)(a1 + 12);
  }
  if ( a2 )
  {
    v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v4 + 308);
    result = KeWaitForSingleObject((unsigned int)v3, 0, 0, 0, 0);
  }
  else
  {
    result = KeSetEvent((int)v3, 0, 0);
    v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v7 = (__int16)(*(_WORD *)(v6 + 0x134) + 1);
    *(_WORD *)(v6 + 308) = v7;
    if ( !v7 && *(_DWORD *)(v6 + 100) != v6 + 100 )
      result = sub_7DF048(result);
  }
  return result;
}
