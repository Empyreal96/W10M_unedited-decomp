// WheapReportPersistedErrorRecord 
 
int __fastcall WheapReportPersistedErrorRecord(int a1)
{
  int v2; // r6
  _BYTE *v3; // r0
  _BYTE *v4; // r4

  v2 = *(_DWORD *)(a1 + 20) + 28;
  v3 = (_BYTE *)ExAllocatePoolWithTag(1, v2);
  v4 = v3;
  if ( !v3 )
    return 0;
  memset(v3, 0, v2);
  *((_DWORD *)v4 + 4) = 2;
  *((_DWORD *)v4 + 2) = v2;
  memmove((int)(v4 + 28), a1, *(_DWORD *)(a1 + 20));
  WheapWorkQueueAddItem(*(_DWORD *)(*(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x1388) + 8), v4);
  return 1;
}
