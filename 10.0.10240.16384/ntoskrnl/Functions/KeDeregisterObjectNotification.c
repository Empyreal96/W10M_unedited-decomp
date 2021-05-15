// KeDeregisterObjectNotification 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall KeDeregisterObjectNotification(unsigned __int8 *a1, _BYTE *a2)
{
  int v3; // r6
  int v5; // r0
  unsigned int v6; // r2
  int v7; // r1 OVERLAPPED
  _DWORD *v8; // r2 OVERLAPPED
  unsigned int v9; // r1

  v3 = 0;
  v5 = KfRaiseIrql(2);
  do
    v6 = __ldrex(a1);
  while ( __strex(v6 | 0x80, a1) );
  while ( 1 )
  {
    __dmb(0xBu);
    if ( !(v6 >> 7) )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
    }
    while ( (*(_DWORD *)a1 & 0x80) != 0 );
    do
      v6 = __ldrex(a1);
    while ( __strex(v6 | 0x80, a1) );
  }
  if ( a2[9] == 4 )
  {
    *(_QWORD *)&v7 = *(_QWORD *)a2;
    if ( *(_BYTE **)(*(_DWORD *)a2 + 4) != a2 || (_BYTE *)*v8 != a2 )
      sub_51B9B4(v5, v7);
    *v8 = v7;
    *(_DWORD *)(v7 + 4) = v8;
    a2[9] = 5;
    v3 = 1;
  }
  __dmb(0xBu);
  do
    v9 = __ldrex((unsigned int *)a1);
  while ( __strex(v9 & 0xFFFFFF7F, (unsigned int *)a1) );
  KfLowerIrql(v5);
  return v3;
}
