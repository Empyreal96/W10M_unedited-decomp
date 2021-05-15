// PiDqQueryActionQueueEntryCreate 
 
int __fastcall PiDqQueryActionQueueEntryCreate(int a1, int a2, unsigned int *a3, int a4)
{
  int v8; // r6
  int v9; // r0
  unsigned int *v10; // r0
  unsigned int v11; // r4
  unsigned int v13; // r2

  v8 = 0;
  v9 = ExAllocatePoolWithTag(1, 20, 1483763280);
  *(_DWORD *)a4 = v9;
  if ( !v9 )
    return -1073741670;
  *(_DWORD *)(v9 + 16) = a1;
  *(_DWORD *)(v9 + 8) = a2;
  if ( a2 )
  {
    __dmb(0xBu);
    v10 = (unsigned int *)(a2 + 4);
    do
      v11 = __ldrex(v10);
    while ( __strex(v11 + 1, v10) );
    __dmb(0xBu);
  }
  *(_DWORD *)(*(_DWORD *)a4 + 12) = a3;
  if ( a3 )
  {
    __dmb(0xBu);
    do
      v13 = __ldrex(a3);
    while ( __strex(v13 + 1, a3) );
    __dmb(0xBu);
  }
  return v8;
}
