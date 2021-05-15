// KiExpireTimerTable 
 
int __fastcall KiExpireTimerTable(int a1, int a2, int a3, int a4, int a5, unsigned __int64 a6)
{
  unsigned int v7; // r4
  unsigned int v8; // r2
  int v9; // lr
  int result; // r0
  int v11; // r8
  int v12; // r3
  unsigned int *v13; // r5
  _DWORD *v14; // r6
  unsigned int v15; // r2
  _DWORD *v16; // r3
  unsigned int v17; // [sp+8h] [bp-48h]
  int v18; // [sp+10h] [bp-40h]
  unsigned int v19; // [sp+18h] [bp-38h]

  v7 = a4 + a3 - 1;
  v19 = v7;
  v8 = 0;
  v9 = v7 + a5;
  v18 = v7 + a5;
  result = HIDWORD(a6);
  v11 = a3 - 1;
  v17 = 0;
  while ( 1 )
  {
    v12 = a2 + 24 * (unsigned __int8)++v11;
    v13 = (unsigned int *)(v12 + 256);
    if ( v8 > v7 )
      break;
    v14 = (_DWORD *)(v12 + 260);
    if ( v12 + 260 != *(_DWORD *)(v12 + 260) )
    {
      do
        v15 = __ldrex(v13);
      while ( __strex(1u, v13) );
      __dmb(0xBu);
      if ( v15 )
        JUMPOUT(0x55331E);
      v16 = (_DWORD *)*v14;
      if ( v14 != (_DWORD *)*v14 )
      {
        if ( *((_QWORD *)v16 - 1) <= a6 )
          JUMPOUT(0x55332E);
        __disable_irq();
        v13[4] = *(v16 - 2);
        v13[5] = *(v16 - 1);
        __enable_irq();
      }
      __dmb(0xBu);
      *v13 = 0;
      v9 = v18;
      v8 = v17;
    }
    ++v8;
    v7 = v19;
    v17 = v8;
    if ( v11 == v9 )
      return result;
  }
  return sub_553300(HIDWORD(a6), a6);
}
