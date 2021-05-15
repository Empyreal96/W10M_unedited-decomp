// PfLogEvent 
 
int __fastcall PfLogEvent(int a1, int a2, int a3, unsigned int a4)
{
  unsigned int v5; // r6
  int v9; // r4
  _DWORD *v10; // r5
  int v11; // r0
  unsigned int v12; // r0
  int v14; // [sp+0h] [bp-28h] BYREF
  int v15[9]; // [sp+4h] [bp-24h] BYREF

  v15[1] = a4;
  v5 = 8 * ((a4 + 15) >> 3);
  v14 = 0;
  v15[0] = 0;
  v9 = PfFbLogEntryReserve(&qword_643A00, &v14, v15, v5);
  if ( v9 < 0 )
  {
    __dmb(0xBu);
    do
      v12 = __ldrex((unsigned int *)&dword_643B0C);
    while ( __strex(v12 + 1, (unsigned int *)&dword_643B0C) );
    __dmb(0xBu);
    if ( v14 )
      PfFbLogEntryComplete(v14);
  }
  else
  {
    v10 = (_DWORD *)v15[0];
    v11 = v15[0] + 8;
    *(_DWORD *)v15[0] = *(_DWORD *)v15[0] & 0xFFFFF003 | (((v5 + 7) & 0x1FF8 | 0x40006) >> 1);
    v10[1] = a2;
    *v10 ^= (*v10 ^ (a1 << 12)) & 0x1F000;
    memmove(v11, a3, a4);
    PfFbLogEntryComplete(v14);
    v9 = 0;
  }
  return v9;
}
