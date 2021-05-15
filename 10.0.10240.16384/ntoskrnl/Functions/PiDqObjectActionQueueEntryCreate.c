// PiDqObjectActionQueueEntryCreate 
 
int __fastcall PiDqObjectActionQueueEntryCreate(unsigned int *a1, int a2)
{
  int v4; // r5
  _BYTE *v5; // r0
  _BYTE *v6; // r4
  unsigned __int64 v7; // kr00_8
  unsigned int v8; // r2

  v4 = 0;
  v5 = (_BYTE *)ExAllocatePoolWithTag(1, 24, 1483763280);
  v6 = v5;
  *(_DWORD *)a2 = v5;
  if ( !v5 )
    return -1073741670;
  memset(v5, 0, 24);
  *((_DWORD *)v6 + 2) = a1;
  __dmb(0xBu);
  do
    v7 = __ldrexd(PiDqSequenceNumber);
  while ( __strexd(v7 + 1, PiDqSequenceNumber) );
  __dmb(0xBu);
  *(_QWORD *)(*(_DWORD *)a2 + 16) = v7 + 1;
  __dmb(0xBu);
  do
    v8 = __ldrex(a1);
  while ( __strex(v8 + 1, a1) );
  __dmb(0xBu);
  return v4;
}
